#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T12:01:32
#
#-------------------------------------------------

QT       += core gui serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets svg

CONFIG += static

INCLUDEPATH += ..

win32 {
  !include ( C:\Qwt-6.1.3\features\qwt.prf ) {
    error("Can not find qwt.prf!" )
   }
} else {
  !include ( /usr/local/qwt-6.1.3/features/qwt.prf ) {
    error("Can not find qwt.prf!" )
   }
}

QMAKE_CXXFLAGS +=
RCC_DIR= ../release
DESTDIR = ../release
OBJECTS_DIR = ../release/.obj
MOC_DIR = ../release/.moc
RCC_DIR = ../release/.rcc
UI_DIR = ../release/.ui
