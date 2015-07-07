/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsJobQueue.h
 *  @author Eduard Garcia
 *  @date   Thu Feb 21 16:30:11 CEST 2008
 *  @brief  ViewsJobQueue class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef VIEWSJOBQUEUE_H_
#define VIEWSJOBQUEUE_H_

#include <vector>
#include "JobManager/IViewsJobQueue.h"
#include "ViewsJob.h"
#include "JobManager.h"
#include "Logging.h"

/**
 * ViewsJobQueue inherit from std::vector for holds a ViewsJob instances.
 */
template<typename Te = JobManager::JobSummaryItemExt>
class ViewsJobQueue : protected std::vector<IViewsJob*>,
                      public IViewsJobQueue
                      
{
public:
  
  ViewsJobQueue(Logging* _log = 0);

  /**
   * Class destructor
   */
  virtual ~ViewsJobQueue();
 
  /**
   * You will be able to assign a vector of elements which will keep in this ViewsJobQueue instance.
   * 
   * @param std::vector<Te>
   */
  void assign(std::vector<Te> &_jobQueueExt);
  
  /**
   * Returns a ViewsIterator instance which holds a IViewsJob instances.
   * 
   * @return ViewsIterator<Ti>
   */
  ViewsIterator<IViewsJob*> getJobsIterator();
  
  /**
   * Returns a single IViewsJob interface implementation with Job id value passed through parameter.
   * 
   * @param tRedJMJobID
   * @return Ti
   */
  IViewsJob* getJob(uint16_t _jobId);

  /**
   * This method remove all instances holds in queue.
   */
  void clear();
 
protected:

private:
 
 /**
  * To write logs in the system
  */
  Logging *log_;
};


template<typename Te>
ViewsJobQueue<Te>::ViewsJobQueue(Logging *log):
  std::vector<IViewsJob*>()
{
  log_ = log;
}

template<typename Te>
ViewsJobQueue<Te>::~ViewsJobQueue()
{
  clear();
}

template<typename Te>
void ViewsJobQueue<Te>::assign(std::vector<Te> &jobQueue)
{
  ViewsIterator<Te> iterJobs(jobQueue);
  while (iterJobs.hasNext())
  {
    Te interJob = static_cast<Te>(iterJobs.next());
    push_back(new ViewsJob<Te>(interJob));
    if (log_!=NULL) log_->log(0,"Insert in queue a job which id value is:%d",((IViewsJob*)back())->getId());
  }
}

template<typename Te>
IViewsJob* ViewsJobQueue<Te>::getJob(uint16_t jobId)
{
  if (log_!=NULL) log_->log(0,"Getting job with id :%d",jobId);
  IViewsJob* retJob = NULL;

  ViewsJob<Te> auxJob(jobId);
  
  ViewsIterator<IViewsJob*> iterJob(*this);
  while (iterJob.hasNext())
  {
    retJob = iterJob.next();
    if (retJob==&auxJob)
    {
     if (log_!=NULL) log_->log(0,"Job has been found = %d",jobId);
      break;
    }
  }
  return retJob;
}

template<typename Te>
ViewsIterator<IViewsJob*> ViewsJobQueue<Te>::getJobsIterator()
{
  ViewsIterator<IViewsJob*> it(*this);
  return it;
}

template<typename Te>
void ViewsJobQueue<Te>::clear()
{
  ViewsIterator<IViewsJob*> it(*this);
  while (it.hasNext())
  {
    IViewsJob* aux = it.next();
    delete aux;
    aux = 0;
  }
}

#endif /*VIEWSJOBQUEUE_H_*/
