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

private slots:
	void mppt1VoltageInReceived(double);
	void mppt1CurrentInReceived(double);
	void mppt1VoltageOutReceived(double);
	void mppt1CurrentOutReceived(double);

	void mppt2VoltageInReceived(double);
	void mppt2CurrentInReceived(double);
	void mppt2VoltageOutReceived(double);
	void mppt2CurrentOutReceived(double);

	void mppt3VoltageInReceived(double);
	void mppt3CurrentInReceived(double);
	void mppt3VoltageOutReceived(double);
	void mppt3CurrentOutReceived(double);

	void mppt4VoltageInReceived(double);
	void mppt4CurrentInReceived(double);
	void mppt4VoltageOutReceived(double);
	void mppt4CurrentOutReceived(double);

	void mppt5VoltageInReceived(double);
	void mppt5CurrentInReceived(double);
	void mppt5VoltageOutReceived(double);
	void mppt5CurrentOutReceived(double);

	void mppt6VoltageInReceived(double);
	void mppt6CurrentInReceived(double);
	void mppt6VoltageOutReceived(double);
	void mppt6CurrentOutReceived(double);

	void mppt7VoltageInReceived(double);
	void mppt7CurrentInReceived(double);
	void mppt7VoltageOutReceived(double);
	void mppt7CurrentOutReceived(double);
};

