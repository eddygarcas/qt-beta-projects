#ifndef VIEWSJOBMANAGERNOTIFIER_H_
#define VIEWSJOBMANAGERNOTIFIER_H_

#include "JobManager.h"
#include "IObservable.h"
#include "IObserver.h"


class ViewsJobManagerNotifier : public IJobManagerNotifier,
                                public IObservable
{
public:

 
  ViewsJobManagerNotifier(IObserver *_observer);
  
  /** @name JobManager::IJobManagerNotifier public methods.
      @{
  */
 
  void onJobEvent(tRedJMJobID jobid,JobManager::Event evt);

  /**
   * This method is called by the JobManager when it enters the
   * "paused" state.
   */
  void paused();

  /**
   * This method is called by the JobManager when it leaves the
   * "paused" state.
   */
  void resumed();

  /** @}
   */

  /** @name Views Observable public methods.
    @{
  */
  
  /** pure virtual function declaration.
   *  @param observer object to be registered. Later will be notified.
   */
  void registerObserver(IObserver& observer);

  

  /** pure virtual function declaration.
   *  @param observer object to be unregistered. No more notifications will be received.
   */
  void unregisterObserver(IObserver& observer);


  /** @}
   */
  virtual ~ViewsJobManagerNotifier();

protected:
  
  /** pure virtual function declaration. 
   *  This method should be called by the observable to notify all the attached observers.
   *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
   */
  void notify(uint32_t reason);

private:
  
  ViewsJobManagerNotifier();
  
  IObserver *observer_;
};
#endif /*VIEWSJOBMANAGERNOTIFIER_H_*/
