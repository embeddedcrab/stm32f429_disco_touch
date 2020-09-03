#ifndef HOME_SCREENPRESENTER_HPP
#define HOME_SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class home_screenView;

class home_screenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    home_screenPresenter(home_screenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~home_screenPresenter() {};

private:
    home_screenPresenter();

    home_screenView& view;
};

#endif // HOME_SCREENPRESENTER_HPP
