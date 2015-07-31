#include "MpptPopulator.h"
#include "../MessagingFramework/MpptDefines.h"
#include <QDebug>

MpptPopulator::MpptPopulator(I_PacketDecoder& packetDecoder,
                      I_MpptData& mpptData)
: packetDecoder_(packetDecoder)
, mpptData_(mpptData)
{
   connect(&packetDecoder_, SIGNAL(packetDecoded(const MpptDataMessage)),
         this, SLOT(populateData(const MpptDataMessage)));
}

void MpptPopulator::populateData(const MpptDataMessage message)
{
   qDebug () << "Mppt Number : " << message.mpptNumber();   
   qDebug () << "Mppt Type : " << message.type();
   qDebug () << "Mppt Voltage In : " << message.voltageIn();
   qDebug () << "Mppt Voltage Out : " << message.voltageOut();
   qDebug () << "Mppt Current In : " << message.currentIn();
   qDebug () << "Mppt Current Out : " << message.currentOut();
   switch(message.mpptNumber())
   {
      case 0:
         mpptData_.setMppt1Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt1VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt1CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt1VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt1CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt1Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 1:
         mpptData_.setMppt2Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt2VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt2CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt2VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt2CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt2Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 2:
         mpptData_.setMppt3Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt3VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt3CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt3VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt3CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt3Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 3:
         mpptData_.setMppt4Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt4VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt4CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt4VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt4CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt4Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 4:
         mpptData_.setMppt5Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt5VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt5CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt5VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt5CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt5Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 5:
         mpptData_.setMppt6Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt6VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt6CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt6VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt6CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt6Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 6:
         mpptData_.setMppt7Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt7VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt7CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt7VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt7CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt7Mode(MpptDefines::modeToString(message.mode()));
         }
   }
}
