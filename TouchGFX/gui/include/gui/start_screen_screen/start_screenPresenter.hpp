#ifndef START_SCREENPRESENTER_HPP
#define START_SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class start_screenView;

class start_screenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    start_screenPresenter(start_screenView& v);

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

    virtual ~start_screenPresenter() {};

private:
    start_screenPresenter();

    start_screenView& view;
};

#endif // START_SCREENPRESENTER_HPP
