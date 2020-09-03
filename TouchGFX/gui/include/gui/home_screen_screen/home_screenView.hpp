#ifndef HOME_SCREENVIEW_HPP
#define HOME_SCREENVIEW_HPP

#include <gui_generated/home_screen_screen/home_screenViewBase.hpp>
#include <gui/home_screen_screen/home_screenPresenter.hpp>

class home_screenView : public home_screenViewBase
{
public:
    home_screenView();
    virtual ~home_screenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleGestureEvent(const GestureEvent& evt);
    virtual void handleTickEvent();

protected:
};

#endif // HOME_SCREENVIEW_HPP
