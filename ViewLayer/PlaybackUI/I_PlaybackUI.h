#pragma once

#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QWidget>

class I_PlaybackUI : public QWidget
{
   Q_OBJECT
public:
   virtual ~I_PlaybackUI() {}

   virtual QLabel& playbackTimeLabel() = 0;
   virtual QSlider& playbackPositionSlider() = 0;
   virtual QPushButton& openButton() = 0;
   virtual QPushButton& exitButton() = 0;
};
