#include "ViewsJobManagerAtlas.h"
#include "ViewsJobQueue.h"

/** create a fake instance of a PrinterInformationFake.
 *  @param name instance name.
 *  @return a pointer to the instance.
*/
IComponent* getViewsJobManagerAtlas(std::string name)
{
  ViewsJobManagerAtlas * it;
  it = new ViewsJobManagerAtlas(name);
  assert_removable(it);
  return it;
}

/**
 * Class constructor, we must pass the instance name which we want to create.
 * 
 * @param std::string
 */
ViewsJobManagerAtlas::ViewsJobManagerAtlas(std::string _instanceName):
  IComponent(_instanceName,"ViewsJobManagerAtlas")
{
  monitor_ = RedOSMonitorCreate();
  assert_removable(monitor_ != 0);
  log_ = new Logging(componentName(), 3);
  log_->prefix("VCC");
  log_->set(0);
  log_->set(1);
  log_->set(2);
}

/**Virtual destructor*/
ViewsJobManagerAtlas::~ViewsJobManagerAtlas()
{
  delete log_;
}

/**
 * Returns a IViewsJobQueue interface instances holds in ViewsJobManager.
 * 
 * @return IViewsJobQueue* 
 */
IViewsJobQueue* ViewsJobManagerAtlas::getJobQueue()
{
  return viewsJobQueue_;
}

/** initialize the component.
 *  @note at initialization time components must ask for all the memory and
 *  Operating System services that they are suposed to use. No other component or
 *  hardware access is allowed.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsJobManagerAtlas::initialize (void)
{
  return RESULT_OK;
}

/** start the component. 
 *  @note components should perform the hardware related actions
 *  to turn into an operative status either through drivers or other
 *  components.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsJobManagerAtlas::start (void)
{
  obtainJobsList();
  /**
   * Next, we define a job notifier, passing though parameter this instance.
   */
  jobNotifier_ = new ViewsJobManagerNotifier(this);
  /**
   * Subscribe the notifier defined above to jobmanager singleton.
   */
  jobSubscribeKey_ = JobManager::subscribe(jobNotifier_);

  return RESULT_OK;
}

/** perform an emergency shutdown.
 *  @note only the indispensable actions should be performed.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsJobManagerAtlas::emergencyShutdown (void)
{
  // nothing indispensable to do...
  return RESULT_OK;
}

/** shutdown the component.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsJobManagerAtlas::shutdown (void)
{
  JobManager::unsubscribe(jobSubscribeKey_);
  delete jobNotifier_;
  jobNotifier_ = 0;
  
  clear();
  
  return RESULT_OK;
}

/** enter sleep mode.
 *  @note most likely this would mean doing some power saving activities on it.
 * 
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsJobManagerAtlas::enterSleepMode (void)
{
  return RESULT_OK;
}

/** abandon the sleep mode.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsJobManagerAtlas::exitSleepMode (void)
{
  return RESULT_OK;
}

/** provide a pointer of a named interface.
 * 
 *  @param instanceName the name of the component instance providing the interface.
 *  @param interfaceName the name of the provided interface.
 *  @param interface a pointer to the provided interface.
 */
void ViewsJobManagerAtlas::setInterface (std::string instanceName, std::string interfaceName, void *interface)
{
  log_->log(0,"Doing setInterface method %s\n",interfaceName.data());
}

/** query for an an interface that you implement.
 * 
 *  @param interfaceName the name of the interface that other is asking you to provide.
 *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
 */
void ViewsJobManagerAtlas::getInterface (std::string interfaceName, void **interface)
{
  assert (interfaceName == "IViewsJobManager");
  *interface = (void *)((IViewsJobManager*)this);
}

/**
 * Method to update a job list. The reason parameter is job id.
 * 
 * @param IObservable&
 * @param uint32_t
 */
void ViewsJobManagerAtlas::onChange (IObservable & observable, uint32_t reason)
{
  if (viewsJobQueue_->getJob(reason)!=NULL)
  {
    clear();
    obtainJobsList();
  }
}

/**
 * Gets from JobMananger the job list.
 * 
 * @return Result
 */
Result ViewsJobManagerAtlas::obtainJobsList()
{
  JobManager::JobQueueSummaryExt jobQueue;
  
  log_->log(0,"Start to get job queue values\n");
  JobManager::getJobQueueSummaryExt(jobQueue);
  /**
   * We make a ViewsJobQueue with JobQueueSummaryExt structures.
   */
  log_->log(0,"Creating Views job queue\n");
  viewsJobQueue_ = new ViewsJobQueue<JobManager::JobSummaryItemExt>(log_);
  log_->log(0,"Adding job instances to queue, total jobs: %d\n",jobQueue.jobs.size());
  static_cast<ViewsJobQueue<JobManager::JobSummaryItemExt>*>(viewsJobQueue_)->assign(jobQueue.jobs);
  
  
  return RESULT_OK;
}

/**
 * Clear elements holds in internal queue.
 */
void ViewsJobManagerAtlas::clear()
{
  viewsJobQueue_->clear();
  delete viewsJobQueue_;
  viewsJobQueue_ = 0;
}

/** This method should be called to lock access to a resource needing mutex access.
 */
void ViewsJobManagerAtlas::lock()
{
  tRedResult result;
    
  result = RedOSMonitorLock(monitor_, RED_WAIT_FOREVER);
  assert_removable(result == RED_SUCCESS);
}

/** This method should be called to unlock access to a resource needing mutex access.
 */
void ViewsJobManagerAtlas::unlock()
{
  RedOSMonitorUnlock(monitor_);
}
