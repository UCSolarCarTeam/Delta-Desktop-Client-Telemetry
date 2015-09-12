#pragma once

#include <QObject>

class I_CommunicationsMonitoringService : public QObject
{
	Q_OBJECT
public:
	virtual ~I_CommunicationsMonitoringService() {}
	virtual void start() = 0;
	virtual void stop() = 0;

signals:
	void secondsSinceLastPacketReceivedUpdate(int secondsSinceLastPacketReceived);
	void packetsReceivedInLastMinuteUpdate(int packetsReceivedInLastMinute);
	
	void secondsSinceLastValidPacketReceivedUpdate(int secondsSinceLastValidPacketReceived);
	void validPacketsReceivedInLastMinuteUpdate(int validPacketsReceivedInLastMinute);
	
	void invalidPacketsReceivedInLastMinuteUpdate(int invalidPacketsReceivedInLastMinute);
};