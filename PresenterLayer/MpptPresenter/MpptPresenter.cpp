#include "MpptPresenter.h"
#include "../../DataLayer/MpptData/I_MpptData.h"

MpptPresenter::MpptPresenter(const I_MpptData& mpptData)
: mpptData_(mpptData)
{
   relayMpptData();
}

void MpptPresenter::relayMpptData()
{
   //nothing to connect
}
