#pragma once

#include <QIODevice>

#include "I_DataParser.h"

class DataParser : public I_DataParser
{
public:
  explicit DataParser(QIODevice& device);
  virtual ~DataParser();

private slots:
  void handleInformationIncomming();

private:
  QIODevice& ioDevice_;
};
