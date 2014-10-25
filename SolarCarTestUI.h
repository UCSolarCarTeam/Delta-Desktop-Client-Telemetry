#pragma once

#include <QMainWindow>

namespace Ui {
class SolarCarTestUI;
}

class SolarCarTestUI : public QMainWindow
{
   Q_OBJECT

public:
   explicit SolarCarTestUI(QWidget *parent = 0);
   ~SolarCarTestUI();

private:
   Ui::SolarCarTestUI *ui;
};

