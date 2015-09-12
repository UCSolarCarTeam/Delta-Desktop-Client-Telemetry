#pragma once

#include <QByteArray>
#include <QString>
#include "MpptDefines.h"

class MpptDataMessage
{
public:
   MpptDataMessage(const QByteArray& messageData);

   quint8 mpptNumber() const;
   MpptDefines::Type type() const;

   bool isVoltageInValid() const;
   float voltageIn() const;
   bool isCurrentInValid() const;
   float currentIn() const;
   bool isVoltageOutValid() const;
   float voltageOut() const;
   bool isCurrentOutValid() const;
   float currentOut() const;

   bool isModeValid() const;
   MpptDefines::Mode mode() const;

   QString toString() const;

private:
   quint8 validityFlags() const;

   const QByteArray messageData_;
};
