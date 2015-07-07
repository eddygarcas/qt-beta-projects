/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsJob.h
 *  @author Eduard Garcia
 *  @date   Thu Feb 21 16:30:11 CEST 2008
 *  @brief  IViewsJob interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef IVIEWSJOB_H_
#define IVIEWSJOB_H_

#include "RedJM_pub_types.h"
#include "CDS/ViewsEnum.h"
#include <string>

/**
 * Represents Job definition.
 */
class IViewsJob
{
public:
  enum ViewsJobResult
  {
      VIEWS_RED_SUCCESS         =  RED_SUCCESS,
      VIEWS_RED_FAILURE         = RED_FAILURE, 
      VIEWS_RED_IO_TIMED_OUT    = RED_IO_TIMED_OUT, 
      VIEWS_RED_IO_BAD_SOCKET   = RED_IO_BAD_SOCKET 
  };
 

  /**
   * Returns Job id.
   * 
   * @return uint16_t
   */
  virtual uint16_t getId()             = 0;
  
  /**
   * Returns job name
   * 
   * @return std::string
   */
  virtual std::string getName()           = 0;
  
  /**
   * Returns job state
   * 
   * @return ulong
   */
  virtual ulong getState()          = 0;
  
  /**
   * Returns name of user which created the job.
   * 
   * @return std::string
   */
  virtual std::string getUser()           = 0;
  
  /**
   * It gives back job time stamp.
   * 
   * @return std::string
   */
  virtual std::string getTimestamp()      = 0;
  
  /**
   * Returns printed copies value
   * 
   * @return uint32_t
   */
  virtual uint32_t    getPrintedCopies()  = 0;
  
  /**
   * Returns requestes copies value
   * 
   * @return uint32_t
   */
  virtual uint32_t    getReqCopies()      = 0;
  
  /**
   * Returns total num pages.
   * 
   * @return uint32_t
   */
  virtual uint32_t    getNumPages()       = 0;
  
  /**
   * Returns true if preview oprtions is ready and false in otherwise.
   * 
   * @return bool
   */
  virtual bool        getPreviewReady()   = 0;
  
  /**
   * Returns true if permanent oprtions is ready and false in otherwise.
   * 
   * @return bool
   */
  virtual bool        getPermanent()      = 0;
  
  /**
   * Returns a hold reason value code.
   * 
   * @return int
   */
  virtual int         getHoldReason()     = 0;
  
  /**
   * Returns a job result
   * 
   * @return IViewsJob::ViewsJobResult
   */
  virtual IViewsJob::ViewsJobResult  getResult()         = 0;

protected:
  
private:
  
};

#endif /*IVIEWSJOB_H_*/
