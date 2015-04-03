#pragma once

#include <QObject>

class DisplayPresenter;
class MpptUI;

class MpptView : public QObject
{
	Q_OBJECT
public:
    MpptView(DisplayPresenter& presenter, MpptUI& ui);
    ~MpptView();

private:
	DisplayPresenter& presenter_;
	MpptUI& ui_;
};

