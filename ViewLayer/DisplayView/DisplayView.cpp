#include "DisplayView.h"
#include "ViewLayer/OverlordWidget/OverlordWidget.h"

DisplayView::DisplayView(OverlordWidget& ui)
: ui_(ui)
{
    ui_.show();
}

DisplayView::~DisplayView()
{
}
