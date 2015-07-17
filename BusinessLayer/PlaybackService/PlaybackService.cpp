#include <QByteArray>
#include <QDataStream>
#include <QDateTime>
#include <QDebug>
#include <QFile>

#include "PlaybackService.h"
#include "../../CommunicationLayer/PacketUnstuffer/I_DataInjectionService.h"

namespace
{
   const int NUMBER_OF_MESSAGES_TO_INJECT = 100;
}

PlaybackService::PlaybackService(I_DataInjectionService& injectionService)
: injectionService_(injectionService)
{
}

PlaybackService::~PlaybackService()
{
}

void PlaybackService::loadFile(const QString& fileName)
{
   QFile file(fileName);
   if (!file.open(QIODevice::ReadOnly))
   {
      const QString errorText = QString("Unable to open file for playback").arg(fileName);
      qWarning() << errorText;
      return;
   }

   data_.clear();
   QDataStream dataStreamIn(&file);

   while (!dataStreamIn.atEnd())
   {
      QDateTime date;
      QByteArray data;
      dataStreamIn >> date >> data;
      data_ << QPair<QDateTime, QByteArray>(date, data);
   }

   if (data_.length() == 0)
   {
      qWarning("Could not read data in file");
   }
   else
   {
      emit positionRangeUpdated(0, data_.length() - 1);
      emit dateUpdated(data_.at(0).first);
   }
}

void PlaybackService::loadPosition(int position)
{
   if (position < 0 || position >= data_.length())
   {
      return;
   }

   injectPriorMessagesBeforePosition(position);
   emit dateUpdated(data_.at(position).first);
}

void PlaybackService::injectPriorMessagesBeforePosition(int position)
{
   int positionOfFirstMessage = position - NUMBER_OF_MESSAGES_TO_INJECT;
   if (positionOfFirstMessage < 0)
   {
      positionOfFirstMessage = 0;
   }

   for (int i = positionOfFirstMessage; i <= position; i++)
   {
      injectionService_.injectFramedData(data_.at(i).second);
   }
}
