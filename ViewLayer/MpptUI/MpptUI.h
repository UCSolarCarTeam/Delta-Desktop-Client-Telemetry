#pragma once

#include <QWidget>
#include "I_MpptUI.h"

namespace Ui {
	class MpptUI;
}

class MpptUI : public QWidget, public I_MpptUI 
{
	Q_OBJECT
public:
    explicit MpptUI(QWidget *parent = 0);
    ~MpptUI();

private:
	Ui::MpptUI *ui;
};

