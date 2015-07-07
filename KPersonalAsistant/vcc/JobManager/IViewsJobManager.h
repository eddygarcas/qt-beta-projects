/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsJobManager.h
 *  @author Eduard Garcia
 *  @date   Thu Feb 21 16:30:11 CEST 2008
 *  @brief  IViewsJobManager interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////
#ifndef IVIEWSJOBMANAGER_H_
#define IVIEWSJOBMANAGER_H_

#include "IComponent.h"
#include "JobManager/IViewsJobQueue.h"
#include "IObserver.h"

/**
 * 
 */
class IViewsJobManager : public IObserver
{
public:
  
  /**
   *Returns a JobQueue instance.
   * 
   * @return IViewsJobQueue* 
   */
  virtual IViewsJobQueue* getJobQueue() = 0;
};

#endif /*IVIEWSJOBMANAGER_H_*/
