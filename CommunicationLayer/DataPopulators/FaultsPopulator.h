#pragma once

#include <QObject>
#include "../PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/FaultsData/I_FaultsData.h"

class FaultsPopulator : public QObject
{
	Q_OBJECT
public:
	FaultsPopulator(I_PacketDecoder& packetDecoder,
					I_FaultsData& faultsData);

public slots:
	void populateData(const FaultsMessage&);

private:
	I_PacketDecoder& packetDecoder_;
	I_FaultsData& faultsData_; 
};