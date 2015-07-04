#pragma once

#include <QPushButton>
#include <QCheckBox>
#include <QStackedWidget>
#include <QWidget>
#include <QLineEdit>
class I_EscapeDialog
{
public:
    virtual ~I_EscapeDialog() {}

    void keyPressEvent(QKeyEvent * event);
    virtual QPushButton& fileDialogPushButton()=0;
    virtual QLineEdit& fileDialogText()=0;
    virtual QPushButton& settingsSelectionPushButton()=0;
    virtual QPushButton& aboutSelectionPushButton()=0;
    virtual QPushButton& exitPushButton()=0;
    virtual QPushButton& okPushButton()=0;
    virtual QPushButton& closePushButton()=0;
    virtual QCheckBox& fullscreenCheckBox()=0;
    virtual QCheckBox& multiWindowCheckBox()=0;
    virtual QStackedWidget& optionsDisplayWidget()=0;
    virtual QWidget& EscapeWidget()=0;
};
