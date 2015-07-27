#pragma once

#include "I_CommunicationsMonitoringService.h"
#include <QObject>
#include <QTimer>

class I_PacketChecksumChecker;

class CommunicationsMonitoringService : public I_CommunicationsMonitoringService
{
	Q_OBJECT
public:
	CommunicationsMonitoringService(I_PacketChecksumChecker& packetChecksumChecker);
    virtual ~CommunicationsMonitoringService() {}

    void start();
    void stop();

private slots:
	void validPacketReceived();
	void invalidPacketReceived();
	void update();
	void decrementPacketsReceivedInLastMinute();
	void decrementValidPacketsReceivedInLastMinute();
	void decrementInvalidPacketsReceivedInLastMinute();

private:
	I_PacketChecksumChecker& packetChecksumChecker_;	

	QTimer updateTimer_;
	int secondsSinceLastPacketReceived_;
	int packetsReceivedInLastMinute_;
	int secondsSinceLastValidPacketReceived_;
	int validPacketsReceivedInLastMinute_;
	int invalidPacketsReceivedInLastMinute_;

};