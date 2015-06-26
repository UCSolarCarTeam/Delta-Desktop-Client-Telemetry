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

	double mppt2VoltageIn() const;
	double mppt2CurrentIn() const;
	double mppt2VoltageOut() const;
	double mppt2CurrentOut() const;

	double mppt3VoltageIn() const;
	double mppt3CurrentIn() const;
	double mppt3VoltageOut() const;
	double mppt3CurrentOut() const;

	double mppt4VoltageIn() const;
	double mppt4CurrentIn() const;
	double mppt4VoltageOut() const;
	double mppt4CurrentOut() const;

	double mppt5VoltageIn() const;
	double mppt5CurrentIn() const;
	double mppt5VoltageOut() const;
	double mppt5CurrentOut() const;

	double mppt6VoltageIn() const;
	double mppt6CurrentIn() const;
	double mppt6VoltageOut() const;
	double mppt6CurrentOut() const;

	double mppt7VoltageIn() const;
	double mppt7CurrentIn() const;
	double mppt7VoltageOut() const;
	double mppt7CurrentOut() const;

   	/*ArrayData "Sets"*/
	void setMppt1VoltageIn(double mppt1VoltageIn);
	void setMppt1CurrentIn(double mppt1CurrentIn);
	void setMppt1VoltageOut(double mppt1VoltageOut);
	void setMppt1CurrentOut(double mppt1CurrentOut);

	void setMppt2VoltageIn(double mppt2VoltageIn);
	void setMppt2CurrentIn(double mppt2CurrentIn);
	void setMppt2VoltageOut(double mppt2VoltageOut);
	void setMppt2CurrentOut(double mppt2CurrentOut);

	void setMppt3VoltageIn(double mppt3VoltageIn);
	void setMppt3CurrentIn(double mppt3CurrentIn);
	void setMppt3VoltageOut(double mppt3VoltageOut);
	void setMppt3CurrentOut(double mppt3CurrentOut);

	void setMppt4VoltageIn(double mppt4VoltageIn);
	void setMppt4CurrentIn(double mppt4CurrentIn);
	void setMppt4VoltageOut(double mppt4VoltageOut);
	void setMppt4CurrentOut(double mppt4CurrentOut);

	void setMppt5VoltageIn(double mppt5VoltageIn);
	void setMppt5CurrentIn(double mppt5CurrentIn);
	void setMppt5VoltageOut(double mppt5VoltageOut);
	void setMppt5CurrentOut(double mppt5CurrentOut);

	void setMppt6VoltageIn(double mppt6VoltageIn);
	void setMppt6CurrentIn(double mppt6CurrentIn);
	void setMppt6VoltageOut(double mppt6VoltageOut);
	void setMppt6CurrentOut(double mppt6CurrentOut);

	void setMppt7VoltageIn(double mppt7VoltageIn);
	void setMppt7CurrentIn(double mppt7CurrentIn);
	void setMppt7VoltageOut(double mppt7VoltageOut);
	void setMppt7CurrentOut(double mppt7CurrentOut);

private:
	double mppt1VoltageIn_;
	double mppt1CurrentIn_;
	double mppt1VoltageOut_;
	double mppt1CurrentOut_;

	double mppt2VoltageIn_;
	double mppt2CurrentIn_;
	double mppt2VoltageOut_;
	double mppt2CurrentOut_;

	double mppt3VoltageIn_;
	double mppt3CurrentIn_;
	double mppt3VoltageOut_;
	double mppt3CurrentOut_;

	double mppt4VoltageIn_;
	double mppt4CurrentIn_;
	double mppt4VoltageOut_;
	double mppt4CurrentOut_;

	double mppt5VoltageIn_;
	double mppt5CurrentIn_;
	double mppt5VoltageOut_;
	double mppt5CurrentOut_;

	double mppt6VoltageIn_;
	double mppt6CurrentIn_;
	double mppt6VoltageOut_;
	double mppt6CurrentOut_;

	double mppt7VoltageIn_;
	double mppt7CurrentIn_;
	double mppt7VoltageOut_;
	double mppt7CurrentOut_;
};
