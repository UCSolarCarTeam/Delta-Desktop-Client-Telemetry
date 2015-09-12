#include "CommunicationsMonitoringService.h"
#include "CommunicationLayer/PacketChecksumChecker/I_PacketChecksumChecker.h"
#include <QDebug>

CommunicationsMonitoringService::CommunicationsMonitoringService(I_PacketChecksumChecker& packetChecksumChecker)
: packetChecksumChecker_(packetChecksumChecker)
, secondsSinceLastPacketReceived_(0)
, packetsReceivedInLastMinute_(0)
, secondsSinceLastValidPacketReceived_(0)
, validPacketsReceivedInLastMinute_(0)
, invalidPacketsReceivedInLastMinute_(0)
{
	connect(&packetChecksumChecker_, SIGNAL(validDataReceived(QByteArray)),
			this, SLOT(validPacketReceived()));
	connect(&packetChecksumChecker_, SIGNAL(invalidDataReceived()),
			this, SLOT(invalidPacketReceived()));
	connect(&updateTimer_, SIGNAL(timeout()),
			this, SLOT(update()));

	updateTimer_.setInterval(1000); // update every second
	updateTimer_.setSingleShot(false);
}

void CommunicationsMonitoringService::start()
{
  	secondsSinceLastPacketReceived_ = 0;
  	packetsReceivedInLastMinute_ = 0;
  	secondsSinceLastValidPacketReceived_ = 0;
  	validPacketsReceivedInLastMinute_ = 0;
  	invalidPacketsReceivedInLastMinute_ = 0;
	updateTimer_.start();
}

void CommunicationsMonitoringService::stop()
{
	updateTimer_.stop();
}

void CommunicationsMonitoringService::validPacketReceived()
{
	validPacketsReceivedInLastMinute_++;
	secondsSinceLastValidPacketReceived_ = 0;
	QTimer::singleShot(60000, this, SLOT(decrementValidPacketsReceivedInLastMinute()));

	packetsReceivedInLastMinute_++;
	secondsSinceLastPacketReceived_ = 0;
	QTimer::singleShot(60000, this, SLOT(decrementPacketsReceivedInLastMinute()));
}
void CommunicationsMonitoringService::invalidPacketReceived()
{
	invalidPacketsReceivedInLastMinute_++;
	QTimer::singleShot(60000, this, SLOT(decrementInvalidPacketsReceivedInLastMinute()));

	packetsReceivedInLastMinute_++;
	secondsSinceLastPacketReceived_ = 0;
	QTimer::singleShot(60000, this, SLOT(decrementPacketsReceivedInLastMinute()));
}

void CommunicationsMonitoringService::update()
{
	secondsSinceLastPacketReceived_++;
	secondsSinceLastValidPacketReceived_++;

	emit secondsSinceLastPacketReceivedUpdate(secondsSinceLastPacketReceived_);
	emit packetsReceivedInLastMinuteUpdate(packetsReceivedInLastMinute_);
	emit secondsSinceLastValidPacketReceivedUpdate(secondsSinceLastValidPacketReceived_);
	emit validPacketsReceivedInLastMinuteUpdate(validPacketsReceivedInLastMinute_);
	emit invalidPacketsReceivedInLastMinuteUpdate(invalidPacketsReceivedInLastMinute_);
}

void CommunicationsMonitoringService::decrementPacketsReceivedInLastMinute()
{
	packetsReceivedInLastMinute_--;
}
void CommunicationsMonitoringService::decrementValidPacketsReceivedInLastMinute()
{
	validPacketsReceivedInLastMinute_--;
}
void CommunicationsMonitoringService::decrementInvalidPacketsReceivedInLastMinute()
{
	invalidPacketsReceivedInLastMinute_--;
}

