TEMPLATE = app

QT += qml quick widgets

SOURCES += \
    ../../TestDataParser.cpp \
    ../DataParser.cpp \
    ../../ConnectionService/FakeConnectionService.cpp

HEADERS += \
    ../../TestDataParser.h \
    ../DataParser.h \
    ../../ConnectionService/FakeConnectionService.h


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.

