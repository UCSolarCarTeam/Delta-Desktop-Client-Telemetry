QT += serialport widgets network svg
CONFIG += c++11 debug console static

!win32 {
   QMAKE_CXXFLAGS += -Werror
}

INCLUDEPATH += ..

win32 {
   ! include ( C:\Qwt-6.1.2\features\qwt.prf ) {
      error("Can not find windows qwt.prf!" )
   }
} else {
   ! include ( /usr/local/qwt-6.1.2/features/qwt.prf ) {
      error("Can not find linux qwt.prf!" )
   }
}

OBJECTS_DIR = ../../build/.obj
MOC_DIR = ../../build/.moc
RCC_DIR = ../../build/.rcc
UI_DIR = ../../build/.ui
