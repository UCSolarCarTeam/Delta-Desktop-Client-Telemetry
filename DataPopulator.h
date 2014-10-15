#pragma once
#include <QObject>

class I_DataParser;
class I_Data;

class DataPopulator : public QObject
{
  Q_OBJECT
public:
  DataPopulator(const I_DataParser& dataParser, I_Data& data);

private slots:
  void handleDataReceived(int id, int value);

private:
  const I_DataParser& dataParser_;
  I_Data& data_;
};
