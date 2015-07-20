#include "MpptView.h"
#include "../../PresenterLayer/MpptPresenter/MpptPresenter.h"
#include "../MpptUI/MpptUI.h"

MpptView::MpptView(MpptPresenter& presenter, MpptUI& ui)
: presenter_(presenter)
, ui_(ui)
{
   connect(&presenter_, SIGNAL(mppt1VoltageInReceived(double)),
      this, SLOT(mppt1VoltageInReceived(double)));
   connect(&presenter_, SIGNAL(mppt1CurrentInReceived(double)),
      this, SLOT(mppt1CurrentInReceived(double)));
   connect(&presenter_, SIGNAL(mppt1VoltageOutReceived(double)),
      this, SLOT(mppt1VoltageOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt1CurrentOutReceived(double)),
      this, SLOT(mppt1CurrentOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt1TypeReceived(QString)),
      this, SLOT(mppt1TypeReceived(QString)));
   connect(&presenter_, SIGNAL(mppt1ModeReceived(QString)),
      this, SLOT(mppt1ModeReceived(QString)));

   connect(&presenter_, SIGNAL(mppt2VoltageInReceived(double)),
      this, SLOT(mppt2VoltageInReceived(double)));
   connect(&presenter_, SIGNAL(mppt2CurrentInReceived(double)),
      this, SLOT(mppt2CurrentInReceived(double)));
   connect(&presenter_, SIGNAL(mppt2VoltageOutReceived(double)),
      this, SLOT(mppt2VoltageOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt2CurrentOutReceived(double)),
      this, SLOT(mppt2CurrentOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt2TypeReceived(QString)),
      this, SLOT(mppt2TypeReceived(QString)));
   connect(&presenter_, SIGNAL(mppt2ModeReceived(QString)),
      this, SLOT(mppt2ModeReceived(QString)));

   connect(&presenter_, SIGNAL(mppt3VoltageInReceived(double)),
      this, SLOT(mppt3VoltageInReceived(double)));
   connect(&presenter_, SIGNAL(mppt3CurrentInReceived(double)),
      this, SLOT(mppt3CurrentInReceived(double)));
   connect(&presenter_, SIGNAL(mppt3VoltageOutReceived(double)),
      this, SLOT(mppt3VoltageOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt3CurrentOutReceived(double)),
      this, SLOT(mppt3CurrentOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt3TypeReceived(QString)),
      this, SLOT(mppt3TypeReceived(QString)));
   connect(&presenter_, SIGNAL(mppt3ModeReceived(QString)),
      this, SLOT(mppt3ModeReceived(QString)));

   connect(&presenter_, SIGNAL(mppt4VoltageInReceived(double)),
      this, SLOT(mppt4VoltageInReceived(double)));
   connect(&presenter_, SIGNAL(mppt4CurrentInReceived(double)),
      this, SLOT(mppt4CurrentInReceived(double)));
   connect(&presenter_, SIGNAL(mppt4VoltageOutReceived(double)),
      this, SLOT(mppt4VoltageOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt4CurrentOutReceived(double)),
      this, SLOT(mppt4CurrentOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt4TypeReceived(QString)),
      this, SLOT(mppt4TypeReceived(QString)));
   connect(&presenter_, SIGNAL(mppt4ModeReceived(QString)),
      this, SLOT(mppt4ModeReceived(QString)));

   connect(&presenter_, SIGNAL(mppt5VoltageInReceived(double)),
      this, SLOT(mppt5VoltageInReceived(double)));
   connect(&presenter_, SIGNAL(mppt5CurrentInReceived(double)),
      this, SLOT(mppt5CurrentInReceived(double)));
   connect(&presenter_, SIGNAL(mppt5VoltageOutReceived(double)),
      this, SLOT(mppt5VoltageOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt5CurrentOutReceived(double)),
      this, SLOT(mppt5CurrentOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt5TypeReceived(QString)),
      this, SLOT(mppt5TypeReceived(QString)));
   connect(&presenter_, SIGNAL(mppt5ModeReceived(QString)),
      this, SLOT(mppt5ModeReceived(QString)));

   connect(&presenter_, SIGNAL(mppt6VoltageInReceived(double)),
      this, SLOT(mppt6VoltageInReceived(double)));
   connect(&presenter_, SIGNAL(mppt6CurrentInReceived(double)),
      this, SLOT(mppt6CurrentInReceived(double)));
   connect(&presenter_, SIGNAL(mppt6VoltageOutReceived(double)),
      this, SLOT(mppt6VoltageOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt6CurrentOutReceived(double)),
      this, SLOT(mppt6CurrentOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt6TypeReceived(QString)),
      this, SLOT(mppt6TypeReceived(QString)));
   connect(&presenter_, SIGNAL(mppt6ModeReceived(QString)),
      this, SLOT(mppt6ModeReceived(QString)));

   connect(&presenter_, SIGNAL(mppt7VoltageInReceived(double)),
      this, SLOT(mppt7VoltageInReceived(double)));
   connect(&presenter_, SIGNAL(mppt7CurrentInReceived(double)),
      this, SLOT(mppt7CurrentInReceived(double)));
   connect(&presenter_, SIGNAL(mppt7VoltageOutReceived(double)),
      this, SLOT(mppt7VoltageOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt7CurrentOutReceived(double)),
      this, SLOT(mppt7CurrentOutReceived(double)));
   connect(&presenter_, SIGNAL(mppt7TypeReceived(QString)),
      this, SLOT(mppt7TypeReceived(QString)));
   connect(&presenter_, SIGNAL(mppt7ModeReceived(QString)),
      this, SLOT(mppt7ModeReceived(QString)));
}

MpptView::~MpptView()
{
}
void MpptView::updateMppt1PowerIn()
{
   double powerIn = ui_.setMppt1CurrentIn().text().toDouble() * ui_.setMppt1PowerIn().text().toDouble();
   ui_.setMppt1PowerIn().setNum(powerIn);
}
void MpptView::updateMppt1PowerOut()
{
   double powerOut = ui_.setMppt1CurrentOut().text().toDouble() * ui_.setMppt1PowerOut().text().toDouble();
   ui_.setMppt1PowerIn().setNum(powerOut);
}
void MpptView::updateMppt1Efficiency()
{
   double powerIn = ui_.setMppt1PowerIn().text().toDouble();
   double powerOut = ui_.setMppt1PowerOut().text().toDouble();
   ui_.setMppt1Efficiency().setNum(powerOut / powerIn * 100);
}

void MpptView::updateMppt2PowerIn()
{
   double powerIn = ui_.setMppt2CurrentIn().text().toDouble() * ui_.setMppt2PowerIn().text().toDouble();
   ui_.setMppt2PowerIn().setNum(powerIn);
}
void MpptView::updateMppt2PowerOut()
{
   double powerOut = ui_.setMppt2CurrentOut().text().toDouble() * ui_.setMppt2PowerOut().text().toDouble();
   ui_.setMppt2PowerIn().setNum(powerOut);
}
void MpptView::updateMppt2Efficiency()
{
   double powerIn = ui_.setMppt2PowerIn().text().toDouble();
   double powerOut = ui_.setMppt2PowerOut().text().toDouble();
   ui_.setMppt2Efficiency().setNum(powerOut / powerIn * 100);
}

void MpptView::updateMppt3PowerIn()
{
   double powerIn = ui_.setMppt3CurrentIn().text().toDouble() * ui_.setMppt3PowerIn().text().toDouble();
   ui_.setMppt3PowerIn().setNum(powerIn);
}
void MpptView::updateMppt3PowerOut()
{
   double powerOut = ui_.setMppt3CurrentOut().text().toDouble() * ui_.setMppt3PowerOut().text().toDouble();
   ui_.setMppt3PowerIn().setNum(powerOut);
}
void MpptView::updateMppt3Efficiency()
{
   double powerIn = ui_.setMppt3PowerIn().text().toDouble();
   double powerOut = ui_.setMppt3PowerOut().text().toDouble();
   ui_.setMppt3Efficiency().setNum(powerOut / powerIn * 100);
}

void MpptView::updateMppt4PowerIn()
{
   double powerIn = ui_.setMppt4CurrentIn().text().toDouble() * ui_.setMppt4PowerIn().text().toDouble();
   ui_.setMppt4PowerIn().setNum(powerIn);
}
void MpptView::updateMppt4PowerOut()
{
   double powerOut = ui_.setMppt4CurrentOut().text().toDouble() * ui_.setMppt4PowerOut().text().toDouble();
   ui_.setMppt4PowerIn().setNum(powerOut);
}
void MpptView::updateMppt4Efficiency()
{
   double powerIn = ui_.setMppt4PowerIn().text().toDouble();
   double powerOut = ui_.setMppt4PowerOut().text().toDouble();
   ui_.setMppt4Efficiency().setNum(powerOut / powerIn * 100);
}

void MpptView::updateMppt5PowerIn()
{
   double powerIn = ui_.setMppt5CurrentIn().text().toDouble() * ui_.setMppt5PowerIn().text().toDouble();
   ui_.setMppt5PowerIn().setNum(powerIn);
}
void MpptView::updateMppt5PowerOut()
{
   double powerOut = ui_.setMppt5CurrentOut().text().toDouble() * ui_.setMppt5PowerOut().text().toDouble();
   ui_.setMppt5PowerIn().setNum(powerOut);
}
void MpptView::updateMppt5Efficiency()
{
   double powerIn = ui_.setMppt5PowerIn().text().toDouble();
   double powerOut = ui_.setMppt5PowerOut().text().toDouble();
   ui_.setMppt5Efficiency().setNum(powerOut / powerIn * 100);
}

void MpptView::updateMppt6PowerIn()
{
   double powerIn = ui_.setMppt6CurrentIn().text().toDouble() * ui_.setMppt6PowerIn().text().toDouble();
   ui_.setMppt6PowerIn().setNum(powerIn);
}
void MpptView::updateMppt6PowerOut()
{
   double powerOut = ui_.setMppt6CurrentOut().text().toDouble() * ui_.setMppt6PowerOut().text().toDouble();
   ui_.setMppt6PowerIn().setNum(powerOut);
}
void MpptView::updateMppt6Efficiency()
{
   double powerIn = ui_.setMppt6PowerIn().text().toDouble();
   double powerOut = ui_.setMppt6PowerOut().text().toDouble();
   ui_.setMppt6Efficiency().setNum(powerOut / powerIn * 100);
}

void MpptView::updateMppt7PowerIn()
{
   double powerIn = ui_.setMppt7CurrentIn().text().toDouble() * ui_.setMppt7PowerIn().text().toDouble();
   ui_.setMppt7PowerIn().setNum(powerIn);
}
void MpptView::updateMppt7PowerOut()
{
   double powerOut = ui_.setMppt7CurrentOut().text().toDouble() * ui_.setMppt7PowerOut().text().toDouble();
   ui_.setMppt7PowerIn().setNum(powerOut);
}
void MpptView::updateMppt7Efficiency()
{
   double powerIn = ui_.setMppt7PowerIn().text().toDouble();
   double powerOut = ui_.setMppt7PowerOut().text().toDouble();
   ui_.setMppt7Efficiency().setNum(powerOut / powerIn * 100);
}

void MpptView::mppt1VoltageInReceived(double mppt1VoltageIn)
{
   ui_.setMppt1VoltageIn().setNum(mppt1VoltageIn);
   updateMppt1PowerIn();
   updateMppt1Efficiency();
}
void MpptView::mppt1CurrentInReceived(double mppt1CurrentIn)
{
   ui_.setMppt1CurrentIn().setNum(mppt1CurrentIn);
   updateMppt1PowerIn();
   updateMppt1Efficiency();
}
void MpptView::mppt1VoltageOutReceived(double mppt1VoltageOut)
{
   ui_.setMppt1VoltageOut().setNum(mppt1VoltageOut);
   updateMppt1PowerOut();
   updateMppt1Efficiency();
}
void MpptView::mppt1CurrentOutReceived(double mppt1CurrentOut)
{
   ui_.setMppt1CurrentOut().setNum(mppt1CurrentOut);
   updateMppt1PowerOut();
   updateMppt1Efficiency();
}
void MpptView::mppt1TypeReceived(QString mppt1Type)
{
   ui_.setMppt1Type().setText(mppt1Type);
}
void MpptView::mppt1ModeReceived(QString mppt1Mode)
{
   ui_.setMppt1Mode().setText(mppt1Mode);
}

void MpptView::mppt2VoltageInReceived(double mppt2VoltageIn)
{
   ui_.setMppt2VoltageIn().setNum(mppt2VoltageIn);
   updateMppt2PowerIn();
   updateMppt2Efficiency();
}
void MpptView::mppt2CurrentInReceived(double mppt2CurrentIn)
{
   ui_.setMppt2CurrentIn().setNum(mppt2CurrentIn);
   updateMppt2PowerIn();
   updateMppt2Efficiency();
}
void MpptView::mppt2VoltageOutReceived(double mppt2VoltageOut)
{
   ui_.setMppt2VoltageOut().setNum(mppt2VoltageOut);
   updateMppt2PowerOut();
   updateMppt2Efficiency();
}
void MpptView::mppt2CurrentOutReceived(double mppt2CurrentOut)
{
   ui_.setMppt2CurrentOut().setNum(mppt2CurrentOut);
   updateMppt2PowerOut();
   updateMppt2Efficiency();
}
void MpptView::mppt2TypeReceived(QString mppt2Type)
{
   ui_.setMppt2Type().setText(mppt2Type);
}
void MpptView::mppt2ModeReceived(QString mppt2Mode)
{
   ui_.setMppt2Mode().setText(mppt2Mode);
}

void MpptView::mppt3VoltageInReceived(double mppt3VoltageIn)
{
   ui_.setMppt3VoltageIn().setNum(mppt3VoltageIn);
   updateMppt3PowerIn();
   updateMppt3Efficiency();
}
void MpptView::mppt3CurrentInReceived(double mppt3CurrentIn)
{
   ui_.setMppt3CurrentIn().setNum(mppt3CurrentIn);
   updateMppt3PowerIn();
   updateMppt3Efficiency();
}
void MpptView::mppt3VoltageOutReceived(double mppt3VoltageOut)
{
   ui_.setMppt3VoltageOut().setNum(mppt3VoltageOut);
   updateMppt3PowerOut();
   updateMppt3Efficiency();
}
void MpptView::mppt3CurrentOutReceived(double mppt3CurrentOut)
{
   ui_.setMppt3CurrentOut().setNum(mppt3CurrentOut);
   updateMppt3PowerOut();
   updateMppt3Efficiency();
}
void MpptView::mppt3TypeReceived(QString mppt3Type)
{
   ui_.setMppt3Type().setText(mppt3Type);
}
void MpptView::mppt3ModeReceived(QString mppt3Mode)
{
   ui_.setMppt3Mode().setText(mppt3Mode);
}

void MpptView::mppt4VoltageInReceived(double mppt4VoltageIn)
{
   ui_.setMppt4VoltageIn().setNum(mppt4VoltageIn);
   updateMppt4PowerIn();
   updateMppt4Efficiency();
}
void MpptView::mppt4CurrentInReceived(double mppt4CurrentIn)
{
   ui_.setMppt4CurrentIn().setNum(mppt4CurrentIn);
   updateMppt4PowerIn();
   updateMppt4Efficiency();
}
void MpptView::mppt4VoltageOutReceived(double mppt4VoltageOut)
{
   ui_.setMppt4VoltageOut().setNum(mppt4VoltageOut);
   updateMppt4PowerOut();
   updateMppt4Efficiency();
}
void MpptView::mppt4CurrentOutReceived(double mppt4CurrentOut)
{
   ui_.setMppt4CurrentOut().setNum(mppt4CurrentOut);
   updateMppt4PowerOut();
   updateMppt4Efficiency();
}
void MpptView::mppt4TypeReceived(QString mppt4Type)
{
   ui_.setMppt4Type().setText(mppt4Type);
}
void MpptView::mppt4ModeReceived(QString mppt4Mode)
{
   ui_.setMppt4Mode().setText(mppt4Mode);
}

void MpptView::mppt5VoltageInReceived(double mppt5VoltageIn)
{
   ui_.setMppt5VoltageIn().setNum(mppt5VoltageIn);
   updateMppt5PowerIn();
   updateMppt5Efficiency();
}
void MpptView::mppt5CurrentInReceived(double mppt5CurrentIn)
{
   ui_.setMppt5CurrentIn().setNum(mppt5CurrentIn);
   updateMppt5PowerIn();
   updateMppt5Efficiency();
}
void MpptView::mppt5VoltageOutReceived(double mppt5VoltageOut)
{
   ui_.setMppt5VoltageOut().setNum(mppt5VoltageOut);
   updateMppt5PowerOut();
   updateMppt5Efficiency();
}
void MpptView::mppt5CurrentOutReceived(double mppt5CurrentOut)
{
   ui_.setMppt5CurrentOut().setNum(mppt5CurrentOut);
   updateMppt5PowerOut();
   updateMppt5Efficiency();
}
void MpptView::mppt5TypeReceived(QString mppt5Type)
{
   ui_.setMppt5Type().setText(mppt5Type);
}
void MpptView::mppt5ModeReceived(QString mppt5Mode)
{
   ui_.setMppt5Mode().setText(mppt5Mode);
}

void MpptView::mppt6VoltageInReceived(double mppt6VoltageIn)
{
   ui_.setMppt6VoltageIn().setNum(mppt6VoltageIn);
   updateMppt6PowerIn();
   updateMppt6Efficiency();
}
void MpptView::mppt6CurrentInReceived(double mppt6CurrentIn)
{
   ui_.setMppt6CurrentIn().setNum(mppt6CurrentIn);
   updateMppt6PowerIn();
   updateMppt6Efficiency();
}
void MpptView::mppt6VoltageOutReceived(double mppt6VoltageOut)
{
   ui_.setMppt6VoltageOut().setNum(mppt6VoltageOut);
   updateMppt6PowerOut();
   updateMppt6Efficiency();
}
void MpptView::mppt6CurrentOutReceived(double mppt6CurrentOut)
{
   ui_.setMppt6CurrentOut().setNum(mppt6CurrentOut);
   updateMppt6PowerOut();
   updateMppt6Efficiency();
}
void MpptView::mppt6TypeReceived(QString mppt6Type)
{
   ui_.setMppt6Type().setText(mppt6Type);
}
void MpptView::mppt6ModeReceived(QString mppt6Mode)
{
   ui_.setMppt6Mode().setText(mppt6Mode);
}

void MpptView::mppt7VoltageInReceived(double mppt7VoltageIn)
{
   ui_.setMppt7VoltageIn().setNum(mppt7VoltageIn);
   updateMppt7PowerIn();
   updateMppt7Efficiency();
}
void MpptView::mppt7CurrentInReceived(double mppt7CurrentIn)
{
   ui_.setMppt7CurrentIn().setNum(mppt7CurrentIn);
   updateMppt7PowerIn();
   updateMppt7Efficiency();
}
void MpptView::mppt7VoltageOutReceived(double mppt7VoltageOut)
{
   ui_.setMppt7VoltageOut().setNum(mppt7VoltageOut);
   updateMppt7PowerOut();
   updateMppt7Efficiency();
}
void MpptView::mppt7CurrentOutReceived(double mppt7CurrentOut)
{
   ui_.setMppt7CurrentOut().setNum(mppt7CurrentOut);
   updateMppt7PowerOut();
   updateMppt7Efficiency();
}
void MpptView::mppt7TypeReceived(QString mppt7Type)
{
   ui_.setMppt7Type().setText(mppt7Type);
}
void MpptView::mppt7ModeReceived(QString mppt7Mode)
{
   ui_.setMppt7Mode().setText(mppt7Mode);
}
