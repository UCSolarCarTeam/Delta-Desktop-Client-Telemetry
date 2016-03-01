TEMPLATE = subdirs
CONFIG += ordered

message(University of Calgary Solar Car Team Delta Client Telemetry)

DESTDIR = ../../build/.lib

SUBDIRS = \
   DataLayer \
   CommunicationLayer \
   BusinessLayer \
   PresenterLayer \
   ViewLayer \
   SchulichDeltaDesktopTelemetry
