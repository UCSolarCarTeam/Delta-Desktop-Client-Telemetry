#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T12:01:32
#
#-------------------------------------------------

win32 {
  !include ( C:\Qwt-6.1.3\features\qwt.prf ) {
    error("Can not find qwt.prf!" )
   }
} else {
  !include ( /usr/local/qwt-6.1.3/features/qwt.prf ) {
    error("Can not find qwt.prf!" )
   }
}

TEMPLATE = subdirs
CONFIG += static

message(University of Calgary Solar Car Team Delta Desktop Telemetry)

SUBDIRS = \
   DataLayer \
   CommunicationLayer \
   BusinessLayer \
   PresenterLayer \
   ViewLayer \
   SchulichDeltaDesktopTelemetry
