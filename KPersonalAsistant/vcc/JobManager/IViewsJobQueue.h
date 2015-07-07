/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsJobQueue.h
 *  @author Eduard Garcia
 *  @date   Thu Feb 21 16:30:11 CEST 2008
 *  @brief  IViewsJobQueue interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef IVIEWSJOBQUEUE_H_
#define IVIEWSJOBQUEUE_H_

#include "atlas_types.h"
#include "JobManager/IViewsJob.h"
#include "ViewsIterator.h"

/**
 * IViewsJobQueue interface, defines a standard methods to implement a Views queue.
 */
class IViewsJobQueue
{
public:
  
  /**
   * Returns a ViewsIterator instance which holds a IViewsJob instances.
   * 
   * @return ViewsIterator<Ti>
   */
  virtual ViewsIterator<IViewsJob*> getJobsIterator() = 0;
  
  /**
   * Returns a single IViewsJob interface implementation with Job id value passed through parameter.
   * 
   * @param tRedJMJobID
   * @return Ti
   */
  virtual IViewsJob* getJob(uint16_t _jobId) = 0;
  
  /**
   * This method remove all instances holds in queue.
   */
  virtual void clear() = 0;
};
#endif /*IVIEWSJOBQUEUE_H_*/
