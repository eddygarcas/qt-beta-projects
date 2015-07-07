#include "ViewsOutputTray.h"

/**Void constructor*/
ViewsOutputTray::ViewsOutputTray()
{
  
}

/**
 * It do the operations to obtain a outputtray information from engine.
 */
float ViewsOutputTray::getStatus()
{
  return 0.0;
}

/** Method to be called to register a new Observer.
 *  @param observer object to be registered. Later will be notified.
 */
void ViewsOutputTray::registerObserver(IObserver &observer)
{
  onChangeList_.push_back( &observer );
}

/** Method to be called to unregister an existant Observer.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void ViewsOutputTray::unregisterObserver(IObserver &observer)
{
  onChangeList_.remove(&observer);
}

/** This method should be called by the observable to notify all the attached observers.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void ViewsOutputTray::notify(uint32_t reason){

  for ( std::list <IObserver *>::iterator it = onChangeList_.begin() ; it != onChangeList_.end() ; it++ )
  {
    (*it)->onChange(*(static_cast<IObservable*>(this)), reason);
  }
}

ViewsOutputTray::~ViewsOutputTray()
{
  
}
