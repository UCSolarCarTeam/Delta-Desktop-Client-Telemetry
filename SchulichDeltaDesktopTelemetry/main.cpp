#include "SchulichDeltaDesktopTelemetry.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   QScopedPointer<SchulichDeltaDesktopTelemetry> app;
   app.reset(new SchulichDeltaDesktopTelemetry(argc, argv));
   return app->exec();
}
