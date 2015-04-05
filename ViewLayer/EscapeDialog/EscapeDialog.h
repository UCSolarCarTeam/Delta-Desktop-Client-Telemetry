#pragma once

#include <QMainWindow>
#include "../I_SolarCarWindow/I_SolarCarWindow.h"
#include "I_EscapeDialog.h"
namespace Ui {
    class EscapeDialog;
}

class EscapeDialog : public I_SolarCarWindow, public I_EscapeDialog
{
    Q_OBJECT
public:
    explicit EscapeDialog();
    ~EscapeDialog();

    void hideHeaderBar();

    QPushButton& settingsButton();
    QPushButton& returnButton();
    QPushButton& aboutButton();
    QPushButton& exitButton();

private:
   Ui::EscapeDialog *ui;
};
