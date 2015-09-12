#pragma once

#include <QObject>
#include "../PacketDecoder/I_PacketDecoder.h"
#include "../MessagingFramework/DriverControlDetails.h"
#include "../../DataLayer/VehicleData/I_VehicleData.h"
#include "../../DataLayer/PowerData/I_PowerData.h"

class DriverDetailsPopulator : public QObject
{
	Q_OBJECT
public: 
	DriverDetailsPopulator(I_PacketDecoder& packetDecoder,
		 				   I_VehicleData& vehicleData,
		 				   I_PowerData& powerData);

public slots:
	void populateData(const DriverControlDetails);

private:
	I_PacketDecoder& packetDecoder_;
	I_VehicleData& vehicleData_;
	I_PowerData& powerData_;
};