#pragma once

#include "I_PlaybackUI.h"

namespace Ui
{
   class PlaybackUI;
}

class PlaybackUI : public I_PlaybackUI
{
   Q_OBJECT
public:
   PlaybackUI();
   virtual ~PlaybackUI();

   QLabel& playbackTimeLabel();
   QSlider& playbackPositionSlider();
   QPushButton& openButton();
   QPushButton& exitButton();

private:
   Ui::PlaybackUI* ui_;
};
