#include "ViewsJobManagerNotifier.h"

ViewsJobManagerNotifier::ViewsJobManagerNotifier()
{
  
}

ViewsJobManagerNotifier::ViewsJobManagerNotifier(IObserver *_observer)
{
  observer_ = _observer;
}


ViewsJobManagerNotifier::~ViewsJobManagerNotifier()
{
  
}
 
void ViewsJobManagerNotifier::onJobEvent(tRedJMJobID jobid,JobManager::Event evt)
{
  notify(jobid);
/*
  case JobManager::PAUSED:
  case JobManager::RESUMED:
  case JobManager::JOB_EVENT_HOLD:
  case JobManager::JOB_EVENT_MODIFIED:    
  case JobManager::JOB_EVENT_PRINTED:
  case JobManager::JOB_EVENT_RESUMED:
  case JobManager::JOB_EVENT_NEW:
  case JobManager::JOB_EVENT_DELETED:
  */
}

/**
 * This method is called by the JobManager when it enters the
 * "paused" state.
 */
void ViewsJobManagerNotifier::paused()
{
  
}

/**
 * This method is called by the JobManager when it leaves the
 * "paused" state.
 */
void ViewsJobManagerNotifier::resumed()
{
  
}
  
/** pure virtual function declaration.
 *  @param observer object to be registered. Later will be notified.
 */
void ViewsJobManagerNotifier::registerObserver(IObserver& observer)
{
  
}

/** pure virtual function declaration.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void ViewsJobManagerNotifier::unregisterObserver(IObserver& observer)
{
  
}

/** pure virtual function declaration. 
 *  This method should be called by the observable to notify all the attached observers.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void ViewsJobManagerNotifier::notify(uint32_t reason)
{
  observer_->onChange((IObservable&)*this, reason);  
}

  
