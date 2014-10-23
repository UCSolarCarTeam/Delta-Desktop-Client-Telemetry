#pragma once

#include <QIODevice>

#include "I_DataParser.h"

class DataParser : public I_DataParser
{
    Q_OBJECT
public:
  explicit DataParser(QIODevice& device);
  virtual ~DataParser();

private slots:
  void connectionOK();
  void handleInformationIncoming();

private:
  QIODevice& ioDevice_;
  I_ConnectionService& connectionService_;
};
