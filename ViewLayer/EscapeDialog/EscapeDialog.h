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
    void keyPressEvent(QKeyEvent * event);
    void paintEvent(QPaintEvent* e);
    QPushButton& settingsSelectionPushButton();
    QPushButton& aboutSelectionPushButton();
    QPushButton& exitPushButton();
    QPushButton& okPushButton();
    QPushButton& closePushButton();
    QCheckBox& fullscreenCheckBox();
    QCheckBox& multiWindowCheckBox();
    QStackedWidget& optionsDisplayWidget();

private:
   Ui::EscapeDialog *ui;
};
