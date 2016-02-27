#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "CommunicationLayer/MessagingFramework/KeyDriverControlTelemetry.h"
#include "DataLayer/VehicleData/I_VehicleData.h"
#include "DataLayer/PowerData/I_PowerData.h"

class KeyDriverControlPopulator : public QObject
{
	Q_OBJECT
public:
	KeyDriverControlPopulator(I_PacketDecoder& packetDecoder,
							  I_VehicleData& vehicleData,
							  I_PowerData& powerData);

public slots:
	void populateData(const KeyDriverControlTelemetry);
	
private:
	I_PacketDecoder& packetDecoder_;
	I_VehicleData& vehicleData_;
	I_PowerData& powerData_;
};
