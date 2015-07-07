#include "PaperListListener.h"
 
/**
 * Passing by parameter a IOberver interface implementation which will be called 
 * its onChange(...) when some  changes in media list.
 * 
 * @param IObserver*
 */
PaperListListener::PaperListListener(IObserver * observer)
{
  observer_ = observer;
}

/** pure virtual function declaration.
 *  @param observer object to be registered. Later will be notified.
 */
void PaperListListener::registerObserver(IObserver& observer)
{

}

/** virtual function declaration.
 *  @param observer object to be registered. Later will be notified.
 *  @param interest parameter allows registering observers only for specific events of interest.
 */
void PaperListListener::registerObserver(IObserver& observer, Aspect& interest)
{

}

/** pure virtual function declaration.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void PaperListListener::unregisterObserver(IObserver& observer)
{
  
}

/** pure virtual function declaration. 
 *  This method should be called by the observable to notify all the attached observers.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void PaperListListener::notify(uint32_t reason)
{

}

/**
 * This function will be called by OMES when some change in media list
 * event parameter can be null.
 * It returns true if changes ends well or false in otherwise.
 * 
 * @param Event
 * @return bool
 */
bool PaperListListener::onEventCore(Event const & event) const 
{
  observer_->onChange((IObservable&)*this, 1);
  return true;
}

