#include "PlaybackUI.h"
#include "ui_PlaybackUI.h"

PlaybackUI::PlaybackUI()
: ui_(new Ui::PlaybackUI)
{
   ui_->setupUi(this);
}

PlaybackUI::~PlaybackUI()
{
}

QLabel& PlaybackUI::playbackTimeLabel()
{
   return *ui_->playbackTimeLabel;
}

QSlider& PlaybackUI::playbackPositionSlider()
{
   return *ui_->playbackPositionSlider;
}

QPushButton& PlaybackUI::openButton()
{
   return *ui_->openButton;
}

QPushButton& PlaybackUI::exitButton()
{
   return *ui_->exitButton;
}
