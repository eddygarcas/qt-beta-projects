/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsJob.h
 *  @author Eduard Garcia
 *  @date   Thu Feb 21 16:30:11 CEST 2008
 *  @brief  ViewsJob class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef VIEWSJOB_H_
#define VIEWSJOB_H_

#include "JobManager/IViewsJob.h"
#include "JobManager.h"

/**
 */
template<typename Tn = JobManager::JobSummaryItemExt>
class ViewsJob : public IViewsJob
{
public:
  /**
   * 
   */
  ViewsJob(Tn &_jobExtended);
  
  /**
   * 
   */
  ViewsJob(uint16_t _id);
  
  /**
   * 
   */
  uint16_t getId();
  
  /**
   * 
   */
  std::string getName();
  
  /**
   * 
   */
  ulong getState();
  
  /**
   * 
   */
  std::string getUser();
  
  /**
   * 
   */
  std::string getTimestamp();
  
  /**
   * 
   */
  uint32_t    getPrintedCopies();
  
  /**
   * 
   */
  uint32_t    getReqCopies();
  
  /**
   * 
   */
  uint32_t    getNumPages();
  
  /**
   * 
   */
  bool        getPreviewReady();
  
  /**
   * 
   */
  bool        getPermanent();
  
  /**
   * 
   */
  int         getHoldReason();
  
  /**
   * 
   */
  IViewsJob::ViewsJobResult  getResult();
  
  /**
   * 
   */
  bool operator==(IViewsJob &_jobViews);
  
  
  /**
   * 
   */
  virtual ~ViewsJob();
  
protected:
  
private:
  
  ViewsJob();
  
  /** */
  Tn jobExtended_;
};

template<typename Tn>
ViewsJob<Tn>::ViewsJob()
{

}

template<typename Tn>
ViewsJob<Tn>::ViewsJob(Tn &_jobExtended):
  jobExtended_(_jobExtended)
{
  
}
  
template<typename Tn>
ViewsJob<Tn>::ViewsJob(uint16_t _id)
{
  jobExtended_.id = _id;
}

template<typename Tn>
ViewsJob<Tn>::~ViewsJob()
{
  
}

template<typename Tn>
uint16_t ViewsJob<Tn>::getId()
{
  return (ulong)jobExtended_.id;
}

template<typename Tn>
std::string ViewsJob<Tn>::getName()
{
  return jobExtended_.name;
}

template<typename Tn>
ulong ViewsJob<Tn>::getState()
{
  return (ulong)jobExtended_.state;
}
  
template<typename Tn>
std::string ViewsJob<Tn>::getUser()
{
  return jobExtended_.user;
}

template<typename Tn>
std::string ViewsJob<Tn>::getTimestamp()
{
  return jobExtended_.timestamp;
}

template<typename Tn>
uint32_t    ViewsJob<Tn>::getPrintedCopies()
{
  return jobExtended_.printedCopies; 
}

template<typename Tn>
uint32_t    ViewsJob<Tn>::getReqCopies()
{
  return jobExtended_.reqCopies;
}

template<typename Tn>
uint32_t    ViewsJob<Tn>::getNumPages()
{
  return jobExtended_.numPages;
}

template<typename Tn>
bool        ViewsJob<Tn>::getPreviewReady()
{
  return jobExtended_.previewReady;   
}

template<typename Tn>
bool        ViewsJob<Tn>::getPermanent()
{
  return jobExtended_.permanent; 
}

template<typename Tn>
int         ViewsJob<Tn>::getHoldReason()
{
  return jobExtended_.holdReason;
}

template<typename Tn>
IViewsJob::ViewsJobResult ViewsJob<Tn>::getResult()
{
  IViewsJob::ViewsJobResult res;// = jobExtended_.result; 
  return res;
}
  
template<typename Tn>
bool ViewsJob<Tn>::operator==(IViewsJob& _jobViews)
{
  return (_jobViews.getId()==getId());
}

#endif /*VIEWSJOB_H_*/
