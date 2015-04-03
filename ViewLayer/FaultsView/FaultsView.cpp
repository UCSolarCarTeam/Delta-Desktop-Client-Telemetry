#include "FaultsView.h"
#include "../../PresenterLayer/DisplayPresenter/DisplayPresenter.h"
#include "../FaultsUI/FaultsUI.h"

FaultsView::FaultsView(DisplayPresenter& presenter, FaultsUI& ui)
: presenter_(presenter)
, ui_(ui)
{
}

FaultsView::~FaultsView()
{
}

