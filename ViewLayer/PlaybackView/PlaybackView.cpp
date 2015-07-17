#include <QDateTime>
#include <QFileDialog>
#include <QTimer>

#include "../../PresenterLayer/PlaybackPresenter/PlaybackPresenter.h"
#include "../EscapeDialog/I_EscapeDialog.h"
#include "../PlaybackUI/I_PlaybackUI.h"
#include "PlaybackView.h"

namespace
{
   const int SLIDER_UPDATE_FREQUENCY = 400;
}

PlaybackView::PlaybackView(PlaybackPresenter& playbackPresenter,
   I_PlaybackUI& ui,
   I_EscapeDialog& escapeDialog)
: playbackPresenter_(playbackPresenter)
, ui_(ui)
, lastPosition_(0)
, sliderUpdateTimer_(new QTimer)
{
   connect(&ui_.openButton(), SIGNAL(clicked()), this, SLOT(handleOpenFile()));
   connect(&ui_.exitButton(), SIGNAL(clicked()), this, SLOT(handleCloseButton()));
   connect(&playbackPresenter_, SIGNAL(positionRangeUpdated(int, int)),
      this, SLOT(handleSliderRangesUpdated(int, int)));
   connect(&playbackPresenter_, SIGNAL(dateUpdated(const QDateTime&)),
      this, SLOT(handleDateUpdated(const QDateTime&)));
   connect(&escapeDialog.playbackModePushButton(), SIGNAL(clicked()),
      this, SLOT(handleRequestToOpenPlaybackMode()));

   sliderUpdateTimer_->setSingleShot(false);
   sliderUpdateTimer_->setInterval(SLIDER_UPDATE_FREQUENCY);
   sliderUpdateTimer_->start();

   connect(sliderUpdateTimer_.data(), SIGNAL(timeout()),
      this, SLOT(handleTimeout()));
}

PlaybackView::~PlaybackView()
{
}

void PlaybackView::handleOpenFile()
{
   QString fileName = QFileDialog::getOpenFileName();
   playbackPresenter_.loadFile(fileName);
}

void PlaybackView::handleRequestToOpenPlaybackMode()
{
   Qt::WindowFlags windowFlags = Qt::Tool | Qt::WindowStaysOnTopHint;
   ui_.setWindowFlags(windowFlags);
   ui_.show();
}

void PlaybackView::handleCloseButton()
{
   ui_.hide();
}

void PlaybackView::handleSliderRangesUpdated(int min, int max)
{
   ui_.playbackPositionSlider().setMinimum(min);
   ui_.playbackPositionSlider().setMaximum(max);
   ui_.playbackPositionSlider().setSliderPosition(0);
}

void PlaybackView::handleDateUpdated(const QDateTime& date)
{
   ui_.playbackTimeLabel().setText(date.toString("Thh:mm:ss:zzz"));
}

void PlaybackView::handleTimeout()
{
   if (lastPosition_ != ui_.playbackPositionSlider().sliderPosition())
   {
      lastPosition_ = ui_.playbackPositionSlider().sliderPosition();
      playbackPresenter_.loadPosition(lastPosition_);
   }
}
