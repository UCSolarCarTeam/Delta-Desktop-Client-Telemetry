TEMPLATE = subdirs
CONFIG += ordered static

message(University of Calgary Solar Car Team Delta Client Telemetry)

SUBDIRS = \
   DataLayer \
   CommunicationLayer \
   BusinessLayer \
   PresenterLayer \
   ViewLayer \
   Tests \
   SchulichDeltaDesktopTelemetry
