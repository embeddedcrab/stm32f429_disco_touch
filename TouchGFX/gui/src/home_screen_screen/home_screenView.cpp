#include <gui/home_screen_screen/home_screenView.hpp>

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_rtc.h>

#include <logger.h>


/* RTC handle */
extern RTC_HandleTypeDef hrtc;


/* Need to have global variables for all clock which shall be updated using RTC */
static uint8_t scurrentHour = 10;
static uint8_t scurrentMinute = 10;
static uint8_t scurrentSecond = 0;


home_screenView::home_screenView()
{

}

void home_screenView::setupScreen()
{
    home_screenViewBase::setupScreen();

    /* Update time using RTC */
    if( HAL_RTC_STATE_READY == hrtc.State )
    {
        /* Update time from RTC */
        RTC_TimeTypeDef rtc_time;
        if( HAL_OK == HAL_RTC_GetTime( &hrtc, &rtc_time, RTC_FORMAT_BIN ) )
        {
            digitalClock1.setCurrentHour( rtc_time.Hours );
            digitalClock1.setCurrentMinute( rtc_time.Minutes );
            digitalClock1.setCurrentSecond( rtc_time.Seconds );
        }
    }
    else	/* Update time using Internet or local variables */
    {
    	digitalClock1.setCurrentHour( scurrentHour );
    	digitalClock1.setCurrentMinute( scurrentMinute );
    	digitalClock1.setCurrentSecond( scurrentSecond );
    }
    digitalClock1.updateClock();
}

void home_screenView::tearDownScreen()
{
    home_screenViewBase::tearDownScreen();
}


void home_screenView::handleGestureEvent(const GestureEvent& evt)
{
	/* Screen transition using gesture */
	switch( evt.getType() )
	{
	default:
	case GestureEvent::GestureType::SWIPE_HORIZONTAL:
		logger<< "Home Screen -> Horizontal Swipe " << "X = " << evt.getX() << " Y = " << evt.getY() << "\r\n" << logger.endl;
		application().gotostart_screenScreenNoTransition();
		break;

	case GestureEvent::GestureType::SWIPE_VERTICAL:
		logger<< "Home Screen -> Vertical Swipe Occurred, not entertained!!\r\n" << logger.endl;
		break;
	}
}

void home_screenView::handleTickEvent()
{
	static unsigned long clock_ticks = 0;

	/* Check clock tick counts and update clock data, this time ticks varies because of GUI ticks
	 * Time shall always be updated from RTC.
	 * Make RTC variables global and access it in setup screen so that whenever screen setup is done
	 * variables should be updated with last one not the fresh one! */

	/* Take a semaphore and create RTC interrupt for time update.
	 * Trigger semaphore for events and get it in this tick handler and update clock data.
	 * Data updated shall be Minutes and Hours, Seconds not to be updated for every tick Event.
	 */
	if( 64 == ++clock_ticks )	/* Needs to be accurate w.r.t. one second */
	{
		/* Check second hand */
		if( (digitalClock1.getCurrentSecond() < 59) || (0 == digitalClock1.getCurrentSecond()) )
		{
			digitalClock1.setCurrentSecond( digitalClock1.getCurrentSecond() + 1 );
			scurrentSecond = digitalClock1.getCurrentSecond();
		}
		else
		{
			digitalClock1.setCurrentSecond( 0 );
			scurrentSecond = 0;
			if( (digitalClock1.getCurrentMinute() < 59) || (0 == digitalClock1.getCurrentMinute()) )
			{
				digitalClock1.setCurrentMinute( digitalClock1.getCurrentMinute() + 1 );
				scurrentMinute = digitalClock1.getCurrentMinute();
			}
			else
			{
				digitalClock1.setCurrentMinute( 0 );
				scurrentMinute = 0;
				if( (digitalClock1.getCurrentHour() < 11) || (0 == digitalClock1.getCurrentHour()) )
				{
					digitalClock1.setCurrentHour( digitalClock1.getCurrentHour() + 1 );
					scurrentHour = digitalClock1.getCurrentHour();
				}
				else
				{
					digitalClock1.setCurrentHour( 0 );
					scurrentHour = 0;
				}
			}
		}
		/* Update clock GUI */
		digitalClock1.updateClock();
		clock_ticks = 0;
	}
}
