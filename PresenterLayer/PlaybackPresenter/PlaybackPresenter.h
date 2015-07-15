#pragma once

#include <QObject>
class QString;
class QDateTime;

class I_PlaybackService;

class PlaybackPresenter : public QObject
{
   Q_OBJECT
public:
   PlaybackPresenter(I_PlaybackService& playbackService);
   virtual ~PlaybackPresenter();

   void loadFile(const QString& fileName);
   void loadPosition(int position);

signals:
   void positionRangeUpdated(int min, int max);
   void dateUpdated(const QDateTime& date);

private:
   I_PlaybackService& playbackService_;
};
