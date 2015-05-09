#pragma once

#include <QObject>
#include "../PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/BatteryData/I_BatteryData.h"

class BatteryPopulator : public QObject
{
	Q_OBJECT
public:
	BatteryPopulator(I_PacketDecoder& packetDecoder,
					 I_BatteryData& batteryData);
public slots:
	void populateData(const BatteryDataMessage);

private:
	I_PacketDecoder& packetDecoder_;
	I_BatteryData& batteryData_;
};
