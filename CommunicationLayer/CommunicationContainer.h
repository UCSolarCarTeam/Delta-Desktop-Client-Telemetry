#pragma once

#include <QSharedPointer>
#include <QSerialPort>

class DataContainer;
class I_ConnectionService;
class I_DataParser;
class DataPopulator;

class CommunicationContainer
{
public:
    QSharedPointer<QSerialPort> port();
    QSharedPointer<I_ConnectionService> connectionService();
    QSharedPointer<I_DataParser> dataParser();
    QSharedPointer<DataPopulator> dataPopulator();

 	explicit CommunicationContainer(QSharedPointer<DataContainer> dataContainer);
    ~CommunicationContainer();

private:
	QSharedPointer<DataContainer> dataContainer_;    
    QSharedPointer<QSerialPort> port_;
    QSharedPointer<I_ConnectionService> connectionService_;
	QSharedPointer<I_DataParser> dataParser_;
    QSharedPointer<DataPopulator> dataPopulator_;

};

