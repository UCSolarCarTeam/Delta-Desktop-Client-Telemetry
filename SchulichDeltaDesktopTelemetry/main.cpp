#include "SchulichDeltaDesktopTelemetry.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   QScopedPointer<SolarCarTelemetry> app;
   app.reset(new SolarCarTelemetry(argc, argv));
   return app->exec();
}
