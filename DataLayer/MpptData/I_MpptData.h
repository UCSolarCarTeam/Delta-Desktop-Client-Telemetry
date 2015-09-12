#pragma once

#include <QObject>

class I_MpptData : public QObject
{
   Q_OBJECT

public:
	virtual ~I_MpptData() {}

   	/*ArrayData "Gets"*/
	virtual double mppt1VoltageIn() const = 0;
	virtual double mppt1CurrentIn() const = 0;
	virtual double mppt1VoltageOut() const = 0;
	virtual double mppt1CurrentOut() const = 0;
	virtual QString mppt1Type() const = 0;
	virtual QString mppt1Mode() const = 0;

	virtual double mppt2VoltageIn() const = 0;
	virtual double mppt2CurrentIn() const = 0;
	virtual double mppt2VoltageOut() const = 0;
	virtual double mppt2CurrentOut() const = 0;
	virtual QString mppt2Type() const = 0;
	virtual QString mppt2Mode() const = 0;

	virtual double mppt3VoltageIn() const = 0;
	virtual double mppt3CurrentIn() const = 0;
	virtual double mppt3VoltageOut() const = 0;
	virtual double mppt3CurrentOut() const = 0;
	virtual QString mppt3Type() const = 0;
	virtual QString mppt3Mode() const = 0;

	virtual double mppt4VoltageIn() const = 0;
	virtual double mppt4CurrentIn() const = 0;
	virtual double mppt4VoltageOut() const = 0;
	virtual double mppt4CurrentOut() const = 0;
	virtual QString mppt4Type() const = 0;
	virtual QString mppt4Mode() const = 0;

	virtual double mppt5VoltageIn() const = 0;
	virtual double mppt5CurrentIn() const = 0;
	virtual double mppt5VoltageOut() const = 0;
	virtual double mppt5CurrentOut() const = 0;
	virtual QString mppt5Type() const = 0;
	virtual QString mppt5Mode() const = 0;

	virtual double mppt6VoltageIn() const = 0;
	virtual double mppt6CurrentIn() const = 0;
	virtual double mppt6VoltageOut() const = 0;
	virtual double mppt6CurrentOut() const = 0;
	virtual QString mppt6Type() const = 0;
	virtual QString mppt6Mode() const = 0;

	virtual double mppt7VoltageIn() const = 0;
	virtual double mppt7CurrentIn() const = 0;
	virtual double mppt7VoltageOut() const = 0;
	virtual double mppt7CurrentOut() const = 0;
	virtual QString mppt7Type() const = 0;
	virtual QString mppt7Mode() const = 0;

   	/*ArrayData "Sets"*/
	virtual void setMppt1VoltageIn(double mppt1VoltageIn) = 0;
	virtual void setMppt1CurrentIn(double mppt1CurrentIn) = 0;
	virtual void setMppt1VoltageOut(double mppt1VoltageOut) = 0;
	virtual void setMppt1CurrentOut(double mppt1CurrentOut) = 0;
	virtual void setMppt1Type(QString mppt1Type) = 0;
	virtual void setMppt1Mode(QString mppt1Mode) = 0;

	virtual void setMppt2VoltageIn(double mppt2VoltageIn) = 0;
	virtual void setMppt2CurrentIn(double mppt2CurrentIn) = 0;
	virtual void setMppt2VoltageOut(double mppt2VoltageOut) = 0;
	virtual void setMppt2CurrentOut(double mppt2CurrentOut) = 0;
	virtual void setMppt2Type(QString mppt2Type) = 0;
	virtual void setMppt2Mode(QString mppt2Mode) = 0;

	virtual void setMppt3VoltageIn(double mppt3VoltageIn) = 0;
	virtual void setMppt3CurrentIn(double mppt3CurrentIn) = 0;
	virtual void setMppt3VoltageOut(double mppt3VoltageOut) = 0;
	virtual void setMppt3CurrentOut(double mppt3CurrentOut) = 0;
	virtual void setMppt3Type(QString mppt3Type) = 0;
	virtual void setMppt3Mode(QString mppt3Mode) = 0;

	virtual void setMppt4VoltageIn(double mppt4VoltageIn) = 0;
	virtual void setMppt4CurrentIn(double mppt4CurrentIn) = 0;
	virtual void setMppt4VoltageOut(double mppt4VoltageOut) = 0;
	virtual void setMppt4CurrentOut(double mppt4CurrentOut) = 0;
	virtual void setMppt4Type(QString mppt4Type) = 0;
	virtual void setMppt4Mode(QString mppt4Mode) = 0;

	virtual void setMppt5VoltageIn(double mppt5VoltageIn) = 0;
	virtual void setMppt5CurrentIn(double mppt5CurrentIn) = 0;
	virtual void setMppt5VoltageOut(double mppt5VoltageOut) = 0;
	virtual void setMppt5CurrentOut(double mppt5CurrentOut) = 0;
	virtual void setMppt5Type(QString mppt5Type) = 0;
	virtual void setMppt5Mode(QString mppt5Mode) = 0;

	virtual void setMppt6VoltageIn(double mppt6VoltageIn) = 0;
	virtual void setMppt6CurrentIn(double mppt6CurrentIn) = 0;
	virtual void setMppt6VoltageOut(double mppt6VoltageOut) = 0;
	virtual void setMppt6CurrentOut(double mppt6CurrentOut) = 0;
	virtual void setMppt6Type(QString mppt6Type) = 0;
	virtual void setMppt6Mode(QString mppt6Mode) = 0;

	virtual void setMppt7VoltageIn(double mppt7VoltageIn) = 0;
	virtual void setMppt7CurrentIn(double mppt7CurrentIn) = 0;
	virtual void setMppt7VoltageOut(double mppt7VoltageOut) = 0;
	virtual void setMppt7CurrentOut(double mppt7CurrentOut) = 0;
	virtual void setMppt7Type(QString mppt7Type) = 0;
	virtual void setMppt7Mode(QString mppt7Mode) = 0;

signals:
	void mppt1VoltageInReceived(double mppt1VoltageIn);
	void mppt1CurrentInReceived(double mppt1CurrentIn);
	void mppt1VoltageOutReceived(double mppt1VoltageOut);
	void mppt1CurrentOutReceived(double mppt1CurrentOut);
	void mppt1TypeReceived(QString mppt1Type);
	void mppt1ModeReceived(QString mppt1Mode);

	void mppt2VoltageInReceived(double mppt2VoltageIn);
	void mppt2CurrentInReceived(double mppt2CurrentIn);
	void mppt2VoltageOutReceived(double mppt2VoltageOut);
	void mppt2CurrentOutReceived(double mppt2CurrentOut);
	void mppt2TypeReceived(QString mppt2Type);
	void mppt2ModeReceived(QString mppt2Mode);

	void mppt3VoltageInReceived(double mppt3VoltageIn);
	void mppt3CurrentInReceived(double mppt3CurrentIn);
	void mppt3VoltageOutReceived(double mppt3VoltageOut);
	void mppt3CurrentOutReceived(double mppt3CurrentOut);
	void mppt3TypeReceived(QString mppt3Type);
	void mppt3ModeReceived(QString mppt3Mode);

	void mppt4VoltageInReceived(double mppt4VoltageIn);
	void mppt4CurrentInReceived(double mppt4CurrentIn);
	void mppt4VoltageOutReceived(double mppt4VoltageOut);
	void mppt4CurrentOutReceived(double mppt4CurrentOut);
	void mppt4TypeReceived(QString mppt4Type);
	void mppt4ModeReceived(QString mppt4Mode);

	void mppt5VoltageInReceived(double mppt5VoltageIn);
	void mppt5CurrentInReceived(double mppt5CurrentIn);
	void mppt5VoltageOutReceived(double mppt5VoltageOut);
	void mppt5CurrentOutReceived(double mppt5CurrentOut);
	void mppt5TypeReceived(QString mppt5Type);
	void mppt5ModeReceived(QString mppt5Mode);

	void mppt6VoltageInReceived(double mppt6VoltageIn);
	void mppt6CurrentInReceived(double mppt6CurrentIn);
	void mppt6VoltageOutReceived(double mppt6VoltageOut);
	void mppt6CurrentOutReceived(double mppt6CurrentOut);
	void mppt6TypeReceived(QString mppt6Type);
	void mppt6ModeReceived(QString mppt6Mode);

	void mppt7VoltageInReceived(double mppt7VoltageIn);
	void mppt7CurrentInReceived(double mppt7CurrentIn);
	void mppt7VoltageOutReceived(double mppt7VoltageOut);
	void mppt7CurrentOutReceived(double mppt7CurrentOut);
	void mppt7TypeReceived(QString mppt7Type);
	void mppt7ModeReceived(QString mppt7Mode);
};


