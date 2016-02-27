#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "DataLayer/BatteryData/I_BatteryData.h"

class CmuPopulator : public QObject
{
	Q_OBJECT
public:
	CmuPopulator(I_PacketDecoder& packetDecoder,
				 I_BatteryData& batteryData);

public slots:
	void populateData(const CmuDataMessage);

private:
	QList<double> convertFloatListToDouble(QList<float> floatList);
	I_PacketDecoder& packetDecoder_;
	I_BatteryData& batteryData_; 
};
