#pragma once

#include <QObject>
class QDateTime;
class QString;

class I_PlaybackService : public QObject
{
   Q_OBJECT
public:
   virtual ~I_PlaybackService() {}

   virtual void loadFile(const QString& fileName) = 0;
   virtual void loadPosition(int position) = 0;

signals:
   void positionRangeUpdated(int min, int max);
   void dateUpdated(const QDateTime& date);
};
