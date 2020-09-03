#ifndef START_SCREENVIEW_HPP
#define START_SCREENVIEW_HPP

#include <gui_generated/start_screen_screen/start_screenViewBase.hpp>
#include <gui/start_screen_screen/start_screenPresenter.hpp>

class start_screenView : public start_screenViewBase
{
public:
    start_screenView();
    virtual ~start_screenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleGestureEvent(const GestureEvent& evt);
    virtual void handleTickEvent();

protected:
};

#endif // START_SCREENVIEW_HPP
