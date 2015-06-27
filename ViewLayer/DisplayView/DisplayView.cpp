#include "DisplayView.h"
#include "../OverlordWidget/OverlordWidget.h"

DisplayView::DisplayView(OverlordWidget& ui)
: ui_(ui)
{
    ui_.show();
}

DisplayView::~DisplayView()
{
}