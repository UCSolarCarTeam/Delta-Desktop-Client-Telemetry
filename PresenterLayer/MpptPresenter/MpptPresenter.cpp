#include "MpptPresenter.h"
#include "../../DataLayer/ArrayData/I_ArrayData.h"

MpptPresenter::MpptPresenter(const I_ArrayData& arrayData)
: arrayData_(arrayData)
{
   relayArrayData();
}

void MpptPresenter::relayArrayData()
{
   //nothing to connect
}
