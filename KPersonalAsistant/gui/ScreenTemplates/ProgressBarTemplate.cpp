#include "ProgressBarTemplate.h"

ProgressBarTemplate::ProgressBarTemplate(QWidget *parent) :
  QWidget(parent, Qt::FramelessWindowHint)
{
  setupUi(this);
}

bool ProgressBarTemplate::clear()
{
  hasBeenShowed_ = false;
  return changeProgressValue(0);
}

void ProgressBarTemplate::show()
{
  hasBeenShowed_ = true;
}

void ProgressBarTemplate::setWindowTitle(
    const std::string &_windowTitle_)
{
  screentitle->setWindowTitle(QString::fromStdString(_windowTitle_));
}

void ProgressBarTemplate::setProgressBarTitle(
    const std::string &_progressBarTitle_)
{
  progressBarTitle->setText(QString::fromStdString(_progressBarTitle_));
}

void ProgressBarTemplate::setMinimumRange(int32_t _minRange)
{
  progressBarElement->setMinimum(_minRange);
}

void ProgressBarTemplate::setMaximumRange(int32_t _maxRange)
{
  progressBarElement->setMaximum(_maxRange);
}

bool ProgressBarTemplate::changeProgressValue(int32_t _progressValue_)
{
  bool ret = false;
  if ((_progressValue_ >= progressBarElement->minimum()) && (_progressValue_
      <= progressBarElement->maximum()))
  {
    progressBarElement->setValue(_progressValue_);
    ret = true;
  }
  return ret;
}

ProgressBarTemplate::~ProgressBarTemplate()
{

}
