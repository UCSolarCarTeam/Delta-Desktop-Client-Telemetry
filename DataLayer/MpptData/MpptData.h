#pragma once

#include "I_MpptData.h"

class MpptData : public I_MpptData
{
	Q_OBJECT
public:
    MpptData();
    virtual ~MpptData();

private:
   	/*ArrayData "Gets"*/
	double mppt1VoltageIn() const;
	double mppt1CurrentIn() const;
	double mppt1VoltageOut() const;
	double mppt1CurrentOut() const;
	QString mppt1Type() const;
	QString mppt1Mode() const;

	double mppt2VoltageIn() const;
	double mppt2CurrentIn() const;
	double mppt2VoltageOut() const;
	double mppt2CurrentOut() const;
	QString mppt2Type() const;
	QString mppt2Mode() const;

	double mppt3VoltageIn() const;
	double mppt3CurrentIn() const;
	double mppt3VoltageOut() const;
	double mppt3CurrentOut() const;
	QString mppt3Type() const;
	QString mppt3Mode() const;

	double mppt4VoltageIn() const;
	double mppt4CurrentIn() const;
	double mppt4VoltageOut() const;
	double mppt4CurrentOut() const;
	QString mppt4Type() const;
	QString mppt4Mode() const;

	double mppt5VoltageIn() const;
	double mppt5CurrentIn() const;
	double mppt5VoltageOut() const;
	double mppt5CurrentOut() const;
	QString mppt5Type() const;
	QString mppt5Mode() const;

	double mppt6VoltageIn() const;
	double mppt6CurrentIn() const;
	double mppt6VoltageOut() const;
	double mppt6CurrentOut() const;
	QString mppt6Type() const;
	QString mppt6Mode() const;

	double mppt7VoltageIn() const;
	double mppt7CurrentIn() const;
	double mppt7VoltageOut() const;
	double mppt7CurrentOut() const;
	QString mppt7Type() const;
	QString mppt7Mode() const;

   	/*ArrayData "Sets"*/
	void setMppt1VoltageIn(double mppt1VoltageIn);
	void setMppt1CurrentIn(double mppt1CurrentIn);
	void setMppt1VoltageOut(double mppt1VoltageOut);
	void setMppt1CurrentOut(double mppt1CurrentOut);
	void setMppt1Type(QString mppt1Type);
	void setMppt1Mode(QString mppt1Mode);

	void setMppt2VoltageIn(double mppt2VoltageIn);
	void setMppt2CurrentIn(double mppt2CurrentIn);
	void setMppt2VoltageOut(double mppt2VoltageOut);
	void setMppt2CurrentOut(double mppt2CurrentOut);
	void setMppt2Type(QString mppt2Type);
	void setMppt2Mode(QString mppt2Mode);

	void setMppt3VoltageIn(double mppt3VoltageIn);
	void setMppt3CurrentIn(double mppt3CurrentIn);
	void setMppt3VoltageOut(double mppt3VoltageOut);
	void setMppt3CurrentOut(double mppt3CurrentOut);
	void setMppt3Type(QString mppt3Type);
	void setMppt3Mode(QString mppt3Mode);

	void setMppt4VoltageIn(double mppt4VoltageIn);
	void setMppt4CurrentIn(double mppt4CurrentIn);
	void setMppt4VoltageOut(double mppt4VoltageOut);
	void setMppt4CurrentOut(double mppt4CurrentOut);
	void setMppt4Type(QString mppt4Type);
	void setMppt4Mode(QString mppt4Mode);

	void setMppt5VoltageIn(double mppt5VoltageIn);
	void setMppt5CurrentIn(double mppt5CurrentIn);
	void setMppt5VoltageOut(double mppt5VoltageOut);
	void setMppt5CurrentOut(double mppt5CurrentOut);
	void setMppt5Type(QString mppt5Type);
	void setMppt5Mode(QString mppt5Mode);

	void setMppt6VoltageIn(double mppt6VoltageIn);
	void setMppt6CurrentIn(double mppt6CurrentIn);
	void setMppt6VoltageOut(double mppt6VoltageOut);
	void setMppt6CurrentOut(double mppt6CurrentOut);
	void setMppt6Type(QString mppt6Type);
	void setMppt6Mode(QString mppt6Mode);

	void setMppt7VoltageIn(double mppt7VoltageIn);
	void setMppt7CurrentIn(double mppt7CurrentIn);
	void setMppt7VoltageOut(double mppt7VoltageOut);
	void setMppt7CurrentOut(double mppt7CurrentOut);
	void setMppt7Type(QString mppt7Type);
	void setMppt7Mode(QString mppt7Mode);

private:
	double mppt1VoltageIn_;
	double mppt1CurrentIn_;
	double mppt1VoltageOut_;
	double mppt1CurrentOut_;
	QString mppt1Type_;
	QString mppt1Mode_;

	double mppt2VoltageIn_;
	double mppt2CurrentIn_;
	double mppt2VoltageOut_;
	double mppt2CurrentOut_;
	QString mppt2Type_;
	QString mppt2Mode_;

	double mppt3VoltageIn_;
	double mppt3CurrentIn_;
	double mppt3VoltageOut_;
	double mppt3CurrentOut_;
	QString mppt3Type_;
	QString mppt3Mode_;

	double mppt4VoltageIn_;
	double mppt4CurrentIn_;
	double mppt4VoltageOut_;
	double mppt4CurrentOut_;
	QString mppt4Type_;
	QString mppt4Mode_;

	double mppt5VoltageIn_;
	double mppt5CurrentIn_;
	double mppt5VoltageOut_;
	double mppt5CurrentOut_;
	QString mppt5Type_;
	QString mppt5Mode_;

	double mppt6VoltageIn_;
	double mppt6CurrentIn_;
	double mppt6VoltageOut_;
	double mppt6CurrentOut_;
	QString mppt6Type_;
	QString mppt6Mode_;

	double mppt7VoltageIn_;
	double mppt7CurrentIn_;
	double mppt7VoltageOut_;
	double mppt7CurrentOut_;
	QString mppt7Type_;
	QString mppt7Mode_;
};
