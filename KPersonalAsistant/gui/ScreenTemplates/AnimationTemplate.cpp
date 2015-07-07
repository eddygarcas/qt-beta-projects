#include "AnimationTemplate.h"

AnimationTemplate::AnimationTemplate(QWidget *parent): QWidget(parent, Qt::FramelessWindowHint)
{
  animationIndex_ = 0;
  setupUi(this);
  timer_ = new QTimer(this);
  connect(timer_,SIGNAL(timeout()),this,SLOT(next_animation_frame()));

}

void AnimationTemplate::addAnimation(QPixmap pixmapArray[])
{
  for (unsigned int i = 0; i < (sizeof(pixmapArray) / sizeof (*pixmapArray)); i++)
  {
    animation_.push_back(pixmapArray[i]);
  }
}

void AnimationTemplate::addAnimation(const QPixmap pixmap)
{
  animation_.push_back(pixmap);
}

void AnimationTemplate::time(int timeInMilis)
{
  timer_->setInterval(timeInMilis);
}

void AnimationTemplate::show()
{
  hasBeenShowed_ = true;
  timer_->start();
}

bool AnimationTemplate::clear()
{
  if (hasBeenShowed_)
  {
    hasBeenShowed_ = false;
    animation_.clear();
  }
  return true;
}

void AnimationTemplate::next_animation_frame()
{
  if (animationIndex_ == animation_.size())
  {
    animationIndex_ = 0;
  }
  animation->setPixmap(animation_.at(animationIndex_));
  animationIndex_++;
}

void AnimationTemplate::start_timer_interval()
{
  if (!timer_->isActive())
  {
    timer_->start();
  }
}

void AnimationTemplate::stop_timer_interval()
{
  timer_->stop();
}

void AnimationTemplate::setWindowTitle(const std::string &_windowTitle_)
{
  screentitle->setWindowTitle(QString::fromStdString(_windowTitle_));
}

AnimationTemplate::~AnimationTemplate()
{
  delete timer_;
  timer_ = 0;
}
