#include "SolarCarTelemetry.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SolarCarTelemetry w;

    return a.exec();
}
