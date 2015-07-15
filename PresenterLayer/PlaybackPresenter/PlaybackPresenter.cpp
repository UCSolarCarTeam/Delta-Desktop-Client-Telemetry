#include "PlaybackPresenter.h"
#include "../../BusinessLayer/PlaybackService/I_PlaybackService.h"

PlaybackPresenter::PlaybackPresenter(I_PlaybackService& playbackService)
: playbackService_(playbackService)
{
   connect(&playbackService, SIGNAL(positionRangeUpdated(int, int)),
      this, SIGNAL(positionRangeUpdated(int, int)));
   connect(&playbackService, SIGNAL(dateUpdated(const QDateTime&)),
      this, SIGNAL(dateUpdated(const QDateTime&)));
}

PlaybackPresenter::~PlaybackPresenter()
{
}

void PlaybackPresenter::loadFile(const QString& fileName)
{
   playbackService_.loadFile(fileName);
}

void PlaybackPresenter::loadPosition(int position)
{
   playbackService_.loadPosition(position);
}
