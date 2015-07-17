#pragma once

#include <QObject>
#include <QScopedPointer>
class QDateTime;
class QTimer;

class I_EscapeDialog;
class I_PlaybackUI;
class PlaybackPresenter;

class PlaybackView : public QObject
{
   Q_OBJECT
public:
   PlaybackView(PlaybackPresenter& playbackPresenter, I_PlaybackUI& ui,
      I_EscapeDialog& escapeDialog);
   virtual ~PlaybackView();

private slots:
   void handleOpenFile();
   void handleRequestToOpenPlaybackMode();
   void handleCloseButton();
   void handleSliderRangesUpdated(int min, int max);
   void handleDateUpdated(const QDateTime& date);
   void handleTimeout();

private:
   PlaybackPresenter& playbackPresenter_;
   I_PlaybackUI& ui_;
   int lastPosition_;
   QScopedPointer<QTimer> sliderUpdateTimer_;
};
