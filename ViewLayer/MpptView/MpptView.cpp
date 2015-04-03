#include "MpptView.h"
#include "../../PresenterLayer/DisplayPresenter/DisplayPresenter.h"
#include "../MpptUI/MpptUI.h"

MpptView::MpptView(DisplayPresenter& presenter, MpptUI& ui)
: presenter_(presenter)
, ui_(ui)
{
}

MpptView::~MpptView()
{
}

