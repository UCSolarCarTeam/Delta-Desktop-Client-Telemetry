QT += serialport widgets network
CONFIG += c++11 debug staticlib create_prl link_prl

!win32 {
   # QMAKE_CXXFLAGS += -Werror
}

INCLUDEPATH += ..
! include ( /usr/local/qwt-6.1.2/features/qwt.prf ) {
   error("Can not find qwt.prf!" )
}

OBJECTS_DIR = ../../build/.obj
MOC_DIR = ../../build/.moc
RCC_DIR = ../../build/.rcc
UI_DIR = ../../build/.ui
