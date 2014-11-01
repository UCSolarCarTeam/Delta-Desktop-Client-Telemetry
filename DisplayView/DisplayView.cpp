#include "../DisplayPresenter/DisplayPresenter.h"
#include "../SolarCarTestUi/SolarCarTestUI.h"
#include "DisplayView.h"

DisplayView::DisplayView(class DisplayPresenter& presenter, class SolarCarTestUI& ui)
: presenter_(presenter)
, ui_(ui)
{
   ui_.show();

    connect(&presenter_, SIGNAL(driverSetSpeedRPMReceived(double)),
            this, SLOT(driverSetSpeedRPMReceived(double)));
    connect(&presenter_, SIGNAL(driverSetCurrentReceived(double)),
            this, SLOT(driverSetCurrentReceived(double)));

    connect(&presenter_, SIGNAL(vehicleVelocityKphReceived(double)),
            this, SLOT(vehicleVelocityKphReceived(double)));
    connect(&presenter_, SIGNAL(busCurrentAReceived(double)),
            this, SLOT(busCurrentAReceived(double)));
    connect(&presenter_, SIGNAL(busVoltageReceived(double)),
            this, SLOT(busVoltageReceived(double)));

    connect(&presenter_, SIGNAL(mod0PcbTemperatureReceived(int)),
            this, SLOT(mod0PcbTemperatureReceived(int)));
    connect(&presenter_, SIGNAL(mod0CellVoltage0Received(int)),
            this, SLOT(mod0CellVoltage0Received(int)));
    connect(&presenter_, SIGNAL(mod0CellVoltage1Received(int)),
            this, SLOT(mod0CellVoltage1Received(int)));
    connect(&presenter_, SIGNAL(mod0CellVoltage2Received(int)),
            this, SLOT(mod0CellVoltage2Received(int)));
    connect(&presenter_, SIGNAL(mod0CellVoltage3Received(int)),
            this, SLOT(mod0CellVoltage3Received(int)));
    connect(&presenter_, SIGNAL(mod0CellVoltage4Received(int)),
            this, SLOT(mod0CellVoltage4Received(int)));
    connect(&presenter_, SIGNAL(mod0CellVoltage5Received(int)),
            this, SLOT(mod0CellVoltage5Received(int)));
    connect(&presenter_, SIGNAL(mod0CellVoltage6Received(int)),
            this, SLOT(mod0CellVoltage6Received(int)));
    connect(&presenter_, SIGNAL(mod0CellVoltage7Received(int)),
            this, SLOT(mod0CellVoltage7Received(int)));

    connect(&presenter_, SIGNAL(mod1PcbTemperatureReceived(int)),
            this, SLOT(mod1PcbTemperatureReceived(int)));
    connect(&presenter_, SIGNAL(mod1CellVoltage0Received(int)),
            this, SLOT(mod1CellVoltage0Received(int)));
    connect(&presenter_, SIGNAL(mod1CellVoltage1Received(int)),
            this, SLOT(mod1CellVoltage1Received(int)));
    connect(&presenter_, SIGNAL(mod1CellVoltage2Received(int)),
            this, SLOT(mod1CellVoltage2Received(int)));
    connect(&presenter_, SIGNAL(mod1CellVoltage3Received(int)),
            this, SLOT(mod1CellVoltage3Received(int)));
    connect(&presenter_, SIGNAL(mod1CellVoltage4Received(int)),
            this, SLOT(mod1CellVoltage4Received(int)));
    connect(&presenter_, SIGNAL(mod1CellVoltage5Received(int)),
            this, SLOT(mod1CellVoltage5Received(int)));
    connect(&presenter_, SIGNAL(mod1CellVoltage6Received(int)),
            this, SLOT(mod1CellVoltage6Received(int)));
    connect(&presenter_, SIGNAL(mod1CellVoltage7Received(int)),
            this, SLOT(mod1CellVoltage7Received(int)));

    connect(&presenter_, SIGNAL(mod2PcbTemperatureReceived(int)),
            this, SLOT(mod2PcbTemperatureReceived(int)));
    connect(&presenter_, SIGNAL(mod2CellVoltage0Received(int)),
            this, SLOT(mod2CellVoltage0Received(int)));
    connect(&presenter_, SIGNAL(mod2CellVoltage1Received(int)),
            this, SLOT(mod2CellVoltage1Received(int)));
    connect(&presenter_, SIGNAL(mod2CellVoltage2Received(int)),
            this, SLOT(mod2CellVoltage2Received(int)));
    connect(&presenter_, SIGNAL(mod2CellVoltage3Received(int)),
            this, SLOT(mod2CellVoltage3Received(int)));
    connect(&presenter_, SIGNAL(mod2CellVoltage4Received(int)),
            this, SLOT(mod2CellVoltage4Received(int)));
    connect(&presenter_, SIGNAL(mod2CellVoltage5Received(int)),
            this, SLOT(mod2CellVoltage5Received(int)));
    connect(&presenter_, SIGNAL(mod2CellVoltage6Received(int)),
            this, SLOT(mod2CellVoltage6Received(int)));
    connect(&presenter_, SIGNAL(mod2CellVoltage7Received(int)),
            this, SLOT(mod2CellVoltage7Received(int)));

    connect(&presenter_, SIGNAL(mod3PcbTemperatureReceived(int)),
            this, SLOT(mod3PcbTemperatureReceived(int)));
    connect(&presenter_, SIGNAL(mod3CellVoltage0Received(int)),
            this, SLOT(mod3CellVoltage0Received(int)));
    connect(&presenter_, SIGNAL(mod3CellVoltage1Received(int)),
            this, SLOT(mod3CellVoltage1Received(int)));
    connect(&presenter_, SIGNAL(mod3CellVoltage2Received(int)),
            this, SLOT(mod3CellVoltage2Received(int)));
    connect(&presenter_, SIGNAL(mod3CellVoltage3Received(int)),
            this, SLOT(mod3CellVoltage3Received(int)));
    connect(&presenter_, SIGNAL(mod3CellVoltage4Received(int)),
            this, SLOT(mod3CellVoltage4Received(int)));
    connect(&presenter_, SIGNAL(mod3CellVoltage5Received(int)),
            this, SLOT(mod3CellVoltage5Received(int)));
    connect(&presenter_, SIGNAL(mod3CellVoltage6Received(int)),
            this, SLOT(mod3CellVoltage6Received(int)));
    connect(&presenter_, SIGNAL(mod3CellVoltage7Received(int)),
            this, SLOT(mod3CellVoltage7Received(int)));

}

void DisplayView::driverSetSpeedRPMReceived(double driverSetSpeedRPMReceived)
{   ui_.setDriverSetSpeedRPM().display(driverSetSpeedRPMReceived);  }
void DisplayView::driverSetCurrentReceived(double driverSetCurrentReceived)
{   ui_.setDriverSetCurrent().display(driverSetCurrentReceived); }

void DisplayView::vehicleVelocityKphReceived(double vehicleVelocityKphReceived)
{   ui_.setVehicleVelocityKph().display(vehicleVelocityKphReceived);    }
void DisplayView::busCurrentAReceived(double busCurrentA)
{   ui_.setBusCurrentA().display(busCurrentA);  }
void DisplayView::busVoltageReceived(double busVoltage)
{   ui_.setBusVoltage().display(busVoltage);    }

void DisplayView::mod0PcbTemperatureReceived(int mod0PcbTemperature)
{   ui_.setMod0PcbTemperature().display(mod0PcbTemperature);  }
void DisplayView::mod0CellVoltage0Received(int mod0CellVoltage0)
{   ui_.setMod0CellVoltage0().display(mod0CellVoltage0);  }
void DisplayView::mod0CellVoltage1Received(int mod0CellVoltage1)
{   ui_.setMod0CellVoltage1().display(mod0CellVoltage1);  }
void DisplayView::mod0CellVoltage2Received(int mod0CellVoltage2)
{   ui_.setMod0CellVoltage2().display(mod0CellVoltage2);  }
void DisplayView::mod0CellVoltage3Received(int mod0CellVoltage2)
{   ui_.setMod0CellVoltage3().display(mod0CellVoltage2);  }
void DisplayView::mod0CellVoltage4Received(int mod0CellVoltage4)
{   ui_.setMod0CellVoltage4().display(mod0CellVoltage4);  }
void DisplayView::mod0CellVoltage5Received(int mod0CellVoltage5)
{   ui_.setMod0CellVoltage5().display(mod0CellVoltage5);  }
void DisplayView::mod0CellVoltage6Received(int mod0CellVoltage6)
{   ui_.setMod0CellVoltage6().display(mod0CellVoltage6);  }
void DisplayView::mod0CellVoltage7Received(int mod0CellVoltage7)
{   ui_.setMod0CellVoltage7().display(mod0CellVoltage7);  }

void DisplayView::mod1PcbTemperatureReceived(int mod1PcbTemperature)
{   ui_.setMod1PcbTemperature().display(mod1PcbTemperature);  }
void DisplayView::mod1CellVoltage0Received(int mod1CellVoltage0)
{   ui_.setMod1CellVoltage0().display(mod1CellVoltage0);  }
void DisplayView::mod1CellVoltage1Received(int mod1CellVoltage1)
{   ui_.setMod1CellVoltage1().display(mod1CellVoltage1);  }
void DisplayView::mod1CellVoltage2Received(int mod1CellVoltage2)
{   ui_.setMod1CellVoltage2().display(mod1CellVoltage2);  }
void DisplayView::mod1CellVoltage3Received(int mod1CellVoltage3)
{   ui_.setMod1CellVoltage3().display(mod1CellVoltage3);  }
void DisplayView::mod1CellVoltage4Received(int mod1CellVoltage4)
{   ui_.setMod1CellVoltage4().display(mod1CellVoltage4);  }
void DisplayView::mod1CellVoltage5Received(int mod1CellVoltage5)
{   ui_.setMod1CellVoltage5().display(mod1CellVoltage5);  }
void DisplayView::mod1CellVoltage6Received(int mod1CellVoltage6)
{   ui_.setMod1CellVoltage6().display(mod1CellVoltage6);  }
void DisplayView::mod1CellVoltage7Received(int mod1CellVoltage7)
{   ui_.setMod1CellVoltage7().display(mod1CellVoltage7);  }

void DisplayView::mod2PcbTemperatureReceived(int mod2PcbTemperature)
{   ui_.setMod2PcbTemperature().display(mod2PcbTemperature);  }
void DisplayView::mod2CellVoltage0Received(int mod2CellVoltage0)
{   ui_.setMod2CellVoltage0().display(mod2CellVoltage0);  }
void DisplayView::mod2CellVoltage1Received(int mod2CellVoltage1)
{   ui_.setMod2CellVoltage1().display(mod2CellVoltage1);  }
void DisplayView::mod2CellVoltage2Received(int mod2CellVoltage2)
{   ui_.setMod2CellVoltage2().display(mod2CellVoltage2);  }
void DisplayView::mod2CellVoltage3Received(int mod2CellVoltage3)
{   ui_.setMod2CellVoltage3().display(mod2CellVoltage3);  }
void DisplayView::mod2CellVoltage4Received(int mod2CellVoltage4)
{   ui_.setMod2CellVoltage4().display(mod2CellVoltage4);  }
void DisplayView::mod2CellVoltage5Received(int mod2CellVoltage5)
{   ui_.setMod2CellVoltage5().display(mod2CellVoltage5);  }
void DisplayView::mod2CellVoltage6Received(int mod2CellVoltage6)
{   ui_.setMod2CellVoltage6().display(mod2CellVoltage6);  }
void DisplayView::mod2CellVoltage7Received(int mod2CellVoltage7)
{   ui_.setMod2CellVoltage7().display(mod2CellVoltage7);  }

void DisplayView::mod3PcbTemperatureReceived(int mod3PcbTemperature)
{   ui_.setMod3PcbTemperature().display(mod3PcbTemperature);  }
void DisplayView::mod3CellVoltage0Received(int mod3CellVoltage0)
{   ui_.setMod3CellVoltage0().display(mod3CellVoltage0);  }
void DisplayView::mod3CellVoltage1Received(int mod3CellVoltage1)
{   ui_.setMod3CellVoltage1().display(mod3CellVoltage1);  }
void DisplayView::mod3CellVoltage2Received(int mod3CellVoltage2)
{   ui_.setMod3CellVoltage2().display(mod3CellVoltage2);  }
void DisplayView::mod3CellVoltage3Received(int mod3CellVoltage3)
{   ui_.setMod3CellVoltage3().display(mod3CellVoltage3);  }
void DisplayView::mod3CellVoltage4Received(int mod3CellVoltage4)
{   ui_.setMod3CellVoltage4().display(mod3CellVoltage4);  }
void DisplayView::mod3CellVoltage5Received(int mod3CellVoltage5)
{   ui_.setMod3CellVoltage5().display(mod3CellVoltage5);  }
void DisplayView::mod3CellVoltage6Received(int mod3CellVoltage6)
{   ui_.setMod3CellVoltage6().display(mod3CellVoltage6);  }
void DisplayView::mod3CellVoltage7Received(int mod3CellVoltage7)
{   ui_.setMod3CellVoltage7().display(mod3CellVoltage7);  }

DisplayView::~DisplayView()
{
}

