TEMPLATE = lib
CONFIG += create_prl link_prl staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
   DisplayView/DisplayView.h \
   EscapeDialog/EscapeDialog.h \
   EscapeDialog/I_EscapeDialog.h \
   EscapeDialogView/EscapeDialogView.h \
   FaultsUI/FaultsUI.h \
   FaultsUI/I_FaultsUI.h \
   FaultsView/FaultsView.h \
   I_SolarCarWindow/I_SolarCarWindow.h \
   OverlordWidget/I_OverlordWidget.h \
   OverlordWidget/OverlordWidget.h \
   PlaybackUI/I_PlaybackUI.h \
   PlaybackUI/PlaybackUI.h \
   PlaybackView/PlaybackView.h \
   PowerUI/I_PowerUI.h \
   PowerUI/PowerUI.h \
   PowerView/PowerView.h

SOURCES += \
   DisplayView/DisplayView.cpp \
   EscapeDialog/EscapeDialog.cpp \
   EscapeDialogView/EscapeDialogView.cpp \
   FaultsUI/FaultsUI.cpp \
   FaultsView/FaultsView.cpp \
   OverlordWidget/OverlordWidget.cpp \
   PlaybackUI/PlaybackUI.cpp \
   PlaybackView/PlaybackView.cpp \
   PowerUI/PowerUI.cpp \
   PowerView/PowerView.cpp \
   ViewContainer.cpp

FORMS += \
   EscapeDialog.ui \
   FaultsUI.ui \
   PlaybackUI.ui \
   PowerUI.ui

RESOURCES += \
   uiresources.qrc
