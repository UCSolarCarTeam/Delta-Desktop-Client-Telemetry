#pragma once

#include <QScopedPointer>

class QSerialPort;
class DataContainer;
class I_ConnectionService;
class I_DataParser;
class DataPopulator;

class CommunicationContainer
{
public:
   explicit CommunicationContainer(DataContainer& dataContainer);
   ~CommunicationContainer();

   I_ConnectionService& connectionService();
   I_DataParser& dataParser();

private:
   QScopedPointer<QSerialPort> port_;
   QScopedPointer<I_ConnectionService> connectionService_;
   QScopedPointer<I_DataParser> dataParser_;
   QScopedPointer<DataPopulator> dataPopulator_;
};
