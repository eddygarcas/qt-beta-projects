#include "ScreenTemplate.h"

ScreenTemplate::ScreenTemplate()
{
  hasBeenShowed_ = false;
}

void ScreenTemplate::setData(void* _data)
{
  data_ = static_cast<void*>(_data);
}

void* ScreenTemplate::getData()
{
  return static_cast<void*>(data_);
}

bool ScreenTemplate::hasBeenShowed()
{
  return hasBeenShowed_;
}

ScreenTemplate::~ScreenTemplate()
{

}
