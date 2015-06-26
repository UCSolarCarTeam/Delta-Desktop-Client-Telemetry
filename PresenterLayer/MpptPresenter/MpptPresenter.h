#pragma once

#include <QObject>
class I_MpptData;

class MpptPresenter : public QObject
{
	Q_OBJECT
public:
	explicit MpptPresenter(const I_MpptData& mpptData);

private:
	void relayMpptData();

	const I_MpptData& mpptData_;

signals:
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

	void power1VoltageValueReceived(double);
	void power1CurrentValueReceived(double);

	void power2VoltageValueReceived(double);
	void power2CurrentValueReceived(double);

	void power3VoltageValueReceived(double);
	void power3CurrentValueReceived(double);

	void power4VoltageValueReceived(double);
	void power4CurrentValueReceived(double);

	void power5VoltageValueReceived(double);
	void power5CurrentValueReceived(double);

	void power6VoltageValueReceived(double);
	void power6CurrentValueReceived(double);

	void power7VoltageValueReceived(double);
	void power7CurrentValueReceived(double);
};