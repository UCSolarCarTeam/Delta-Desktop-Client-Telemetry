#pragma once

#include <QObject>
#include "../PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/MpptData/I_MpptData.h"

class MpptPopulator : public QObject
{
	Q_OBJECT
public:
	MpptPopulator(I_PacketDecoder& packetDecoder,
				  I_MpptData& mpptData);

public slots:
	void populateData(const MpptDataMessage);

private:
	I_PacketDecoder& packetDecoder_;
	I_MpptData& mpptData_;
};
