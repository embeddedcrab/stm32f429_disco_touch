#include <gui/start_screen_screen/start_screenView.hpp>

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_rtc.h>

#include <logger.h>


/* RTC handle */
extern RTC_HandleTypeDef hrtc;


/* Need to have global variables for all clock which shall be updated using RTC */
static uint8_t scurrentHour = 10;
static uint8_t scurrentMinute = 10;
static uint8_t scurrentSecond = 0;


start_screenView::start_screenView()
{

}

void start_screenView::setupScreen()
{
    start_screenViewBase::setupScreen();

    /* Update time using RTC */
    if( HAL_RTC_STATE_READY == hrtc.State )
    {
        /* Update time from RTC */
        RTC_TimeTypeDef rtc_time;
        if( HAL_OK == HAL_RTC_GetTime( &hrtc, &rtc_time, RTC_FORMAT_BIN ) )
        {
            analogClock1.setCurrentHour( rtc_time.Hours );
            analogClock1.setCurrentMinute( rtc_time.Minutes );
            analogClock1.setCurrentSecond( rtc_time.Seconds );
        }
    }
    else	/* Update time using Internet or local variables */
    {
    	analogClock1.setCurrentHour( scurrentHour );
    	analogClock1.setCurrentMinute( scurrentMinute );
    	analogClock1.setCurrentSecond( scurrentSecond );
    }
    analogClock1.updateClock();
}

void start_screenView::tearDownScreen()
{
    start_screenViewBase::tearDownScreen();
}

void start_screenView::handleGestureEvent(const GestureEvent& evt)
{
	/* Screen transition using gesture */
	switch( evt.getType() )
	{
	default:
	case GestureEvent::GestureType::SWIPE_HORIZONTAL:
		logger<< "Start Screen -> Horizontal Swipe Occurred, not entertained!!\r\n" << logger.endl;
		break;

	case GestureEvent::GestureType::SWIPE_VERTICAL:
		logger<< "Start Screen -> Vertical Swipe " << "X = " << evt.getX() << " Y = " << evt.getY() << "\r\n" << logger.endl;
		application().gotohome_screenScreenNoTransition();
		break;
	}
}

void start_screenView::handleTickEvent()
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
		if( (analogClock1.getCurrentSecond() < 59) || (0 == analogClock1.getCurrentSecond()) )
		{
			analogClock1.setCurrentSecond( analogClock1.getCurrentSecond() + 1 );
			scurrentSecond = analogClock1.getCurrentSecond();
		}
		else
		{
			analogClock1.setCurrentSecond( 0 );
			scurrentSecond = 0;
			if( (analogClock1.getCurrentMinute() < 59) || (0 == analogClock1.getCurrentMinute()) )
			{
				analogClock1.setCurrentMinute( analogClock1.getCurrentMinute() + 1 );
				scurrentMinute = analogClock1.getCurrentMinute();
			}
			else
			{
				analogClock1.setCurrentMinute( 0 );
				scurrentMinute = 0;
				if( (analogClock1.getCurrentHour() < 11) || (0 == analogClock1.getCurrentHour()) )
				{
					analogClock1.setCurrentHour( analogClock1.getCurrentHour() + 1 );
					scurrentHour = analogClock1.getCurrentHour();
				}
				else
				{
					analogClock1.setCurrentHour( 0 );
					scurrentHour = 0;
				}
			}
		}
		/* Update clock GUI */
		analogClock1.updateClock();
		clock_ticks = 0;
	}
}
