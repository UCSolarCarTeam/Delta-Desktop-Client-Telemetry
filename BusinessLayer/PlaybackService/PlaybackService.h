#pragma once

#include <QList>
#include <QPair>

#include "I_PlaybackService.h"
class I_DataInjectionService;

class PlaybackService : public I_PlaybackService
{
   Q_OBJECT
public:
   explicit PlaybackService(I_DataInjectionService& injectionService);
   virtual ~PlaybackService();

   void loadFile(const QString& fileName);
   void loadPosition(int position);

private:
   void injectPriorMessagesBeforePosition(int position);

   I_DataInjectionService& injectionService_;
   QList<QPair<QDateTime, QByteArray> > data_;
};
