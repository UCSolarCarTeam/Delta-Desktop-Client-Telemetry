#include "PowerUI.h"
#include "ui_PowerUI.h"

PowerUI::PowerUI(QWidget *parent) :
QWidget(parent),
ui(new Ui::PowerUI)
{
    ui->setupUi(this);
}

PowerUI::~PowerUI()
{
    delete ui;
}

QPushButton& PowerUI::connectButton()
{
   return *ui->connectButton;
}
QLabel& PowerUI::setConnectionStatus()
{
    return *ui->connectionStatusPlaceHolder;
}
QLineEdit& PowerUI::getSerialPortName()
{
   return *ui->serialPortName;
}
QLineEdit& PowerUI::getBaudRate()
{
   return *ui->baudrate;
}
QTextEdit& PowerUI::setDebugLog()
{
    return *ui->connectionOutput;
}

QLabel& PowerUI::setSetSpeed()
{
    return *ui->setSpeed;
}
QLabel& PowerUI::setSetCurrent()
{
    return *ui->setCurrent;
}
QLabel& PowerUI::setActualSpeed()
{
    return *ui->actualSpeed;
}    
QLabel& PowerUI::setBusVoltage()
{
    return *ui->busVoltage;
}
// QLabel& PowerUI::setArrayCurrentIn()
// {
//     return *ui->arrayCurrentIn;
// }
// QLabel& PowerUI::setArrayCurrentOut()
// {
//     return *ui->arrayCurrentOut;
// }
// QLabel& PowerUI::setNetCurrent()
// {
//     return *ui->netCurrent;
// }

QLabel& PowerUI::setBatteryCMU1Temp()
{
    return *ui->batteryCMU1Temp;
}
QLabel& PowerUI::setBatteryCMU1Cell1Voltage()
{
    return *ui->batteryCMU1Cell1Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell2Voltage()
{
    return *ui->batteryCMU1Cell2Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell3Voltage()
{
    return *ui->batteryCMU1Cell3Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell4Voltage()
{
    return *ui->batteryCMU1Cell4Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell5Voltage()
{
    return *ui->batteryCMU1Cell5Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell6Voltage()
{
    return *ui->batteryCMU1Cell6Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell7Voltage()
{
    return *ui->batteryCMU1Cell7Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell8Voltage()
{
    return *ui->batteryCMU1Cell8Voltage;
}

QLabel& PowerUI::setBatteryCMU2Temp()
{
    return *ui->batteryCMU2Temp;
}
QLabel& PowerUI::setBatteryCMU2Cell1Voltage()
{
    return *ui->batteryCMU2Cell1Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell2Voltage()
{
    return *ui->batteryCMU2Cell2Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell3Voltage()
{
    return *ui->batteryCMU2Cell3Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell4Voltage()
{
    return *ui->batteryCMU2Cell4Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell5Voltage()
{
    return *ui->batteryCMU2Cell5Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell6Voltage()
{
    return *ui->batteryCMU2Cell6Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell7Voltage()
{
    return *ui->batteryCMU2Cell7Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell8Voltage()
{
    return *ui->batteryCMU2Cell8Voltage;
}

QLabel& PowerUI::setBatteryCMU3Temp()
{
    return *ui->batteryCMU3Temp;
}
QLabel& PowerUI::setBatteryCMU3Cell1Voltage()
{
    return *ui->batteryCMU3Cell1Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell2Voltage()
{
    return *ui->batteryCMU3Cell2Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell3Voltage()
{
    return *ui->batteryCMU3Cell3Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell4Voltage()
{
    return *ui->batteryCMU3Cell4Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell5Voltage()
{
    return *ui->batteryCMU3Cell5Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell6Voltage()
{
    return *ui->batteryCMU3Cell6Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell7Voltage()
{
    return *ui->batteryCMU3Cell7Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell8Voltage()
{
    return *ui->batteryCMU3Cell8Voltage;
}

QLabel& PowerUI::setBatteryCMU4Temp()
{
    return *ui->batteryCMU4Temp;
}
QLabel& PowerUI::setBatteryCMU4Cell1Voltage()
{
    return *ui->batteryCMU4Cell1Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell2Voltage()
{
    return *ui->batteryCMU4Cell2Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell3Voltage()
{
    return *ui->batteryCMU4Cell3Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell4Voltage()
{
    return *ui->batteryCMU4Cell4Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell5Voltage()
{
    return *ui->batteryCMU4Cell5Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell6Voltage()
{
    return *ui->batteryCMU4Cell6Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell7Voltage()
{
    return *ui->batteryCMU4Cell7Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell8Voltage()
{
    return *ui->batteryCMU4Cell8Voltage;
}
