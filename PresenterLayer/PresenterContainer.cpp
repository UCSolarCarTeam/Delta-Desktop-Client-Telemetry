#include "PresenterContainer.h"

#include "BusinessLayer/BusinessContainer.h"
#include "DisplayPresenter/DisplayPresenter.h"

PresenterContainer::PresenterContainer()
: businessLayer_(new BusinessContainer())
, displayPresenter_(new DisplayPresenter(*data_, *connectionService_, *debugHandler))
{
}

DisplayPresenter& displayPresenter()
{
	return displayPresenter_;
}

PresenterContainer::~PresenterContainer()
{
}

