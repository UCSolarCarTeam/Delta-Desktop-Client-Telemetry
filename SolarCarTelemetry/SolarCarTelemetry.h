#pragma once

#include <QApplication>
#include <QScopedPointer>

class ViewContainer;

class SolarCarTelemetry : public QApplication
{
public:
   explicit SolarCarTelemetry(int &argc, char **argv);
   ~SolarCarTelemetry();
};
