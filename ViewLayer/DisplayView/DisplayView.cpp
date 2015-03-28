#include "DisplayView.h"
#include "../../PresenterLayer/DisplayPresenter/DisplayPresenter.h"
#include "../OverlordWidget/OverlordWidget.h"

DisplayView::DisplayView(DisplayPresenter& presenter, OverlordWidget& ui)
: presenter_(presenter_)
, ui_(ui)
{
    ui_.show();
}

DisplayView::~DisplayView()
{
}