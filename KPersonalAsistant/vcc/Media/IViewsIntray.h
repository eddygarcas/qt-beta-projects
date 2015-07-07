/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsTray.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  ViewsTray interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////


#ifndef IVIEWSINTRAY_H_
#define IVIEWSINTRAY_H_

#include "atlas_types.h"
#include "IObservable.h"
#include "MediaPath/IMediaPath.h"
#include <string>

/**
 * This interface definition contains all basic methods which define a in tray element. 
 */
class IViewsIntray : public IObservable
{
public:

  /** types of input media drivers, this needs to be known so that
      others can request if a certain type is installed.
      It is the order of the CDS objects INTRAY-x-
  */
  enum ViewsInputPath 
  {
    VIEWS_INPUT_MEDIA_FAKE        = IMediaPath::INPUT_MEDIA_FAKE,
    VIEWS_INPUT_MEDIA_SHEET       = IMediaPath::INPUT_MEDIA_SHEET,  
    VIEWS_INPUT_MEDIA_SPECIALROLL = IMediaPath::INPUT_MEDIA_SPECIALROLL,
    VIEWS_INPUT_MEDIA_MULTIROLL0  = IMediaPath::INPUT_MEDIA_MULTIROLL0,
    VIEWS_INPUT_MEDIA_MULTIROLL1  = IMediaPath::INPUT_MEDIA_MULTIROLL1,
    VIEWS_INPUT_MEDIA_MULTIROLL2  = IMediaPath::INPUT_MEDIA_MULTIROLL2,
    VIEWS_INPUT_MEDIA_DUPLEXER    = IMediaPath::INPUT_MEDIA_DUPLEXER,
    VIEWS_INPUT_MEDIA_MAX_NUM     = IMediaPath::INPUT_MEDIA_MAX_NUM        
  };

  /** Indicates the status of the media*/
  enum ViewsPathStatus
  {
    VIEWS_PS_NOT_INITIALIZED  = IMediaPath::PS_NOT_INITIALIZED,
    VIEWS_PS_NO_MEDIA         = IMediaPath::PS_NO_MEDIA,
    VIEWS_PS_PRINTING         = IMediaPath::PS_PRINTING,
    VIEWS_PS_READY            = IMediaPath::PS_READY,
    VIEWS_PS_INITIALIZING     = IMediaPath::PS_INITIALIZING,
    VIEWS_PS_CHECKING         = IMediaPath::PS_CHECKING,
    VIEWS_PS_NOT_ACTIVE       = IMediaPath::PS_NOT_ACTIVE,
    VIEWS_PS_ERROR            = IMediaPath::PS_ERROR,
    VIEWS_PS_STANDBY          = IMediaPath::PS_STANDBY
  };

 
  /**
   * It returns a intray max capacity expressed in inches.
   * 
   * @return uint32_t
   */
  virtual int32_t getMaxCapacity() = 0; // in inch
  
  
  /**
   * It return the views intray status.
   * 
   * @return long
   */
  virtual IViewsIntray::ViewsPathStatus getStatus() = 0;

  /**
   * Returns a source code. See IMediaPath for more information about souce codes.
   * 
   * @return unint32_t
   */
  virtual IViewsIntray::ViewsInputPath getSource() = 0;

  /**
   * It returns de model name.
   * 
   * @return std::string
   */
  virtual std::string getModel() = 0;

  /**
   * Number of pages printed from this intray.
   *
   * @return Number of pages printed from this intray
   */
  virtual int32_t getPageCount() = 0;
  
  /**
   * Number of pages currently stored (available) by tray n.  This
   * is only valid if the tray is of type 'tray', use length for
   * rolls.
   *
   * The value 0 means that there is no media available.  This value
   * does not apply for roll type, so -1 should be returned for this
   * type.
   *
   * @return pages currently stored (-1 if roll)
   */
  virtual int32_t getPageStore() = 0;
};

#endif /*IVIEWSINTRAY_H_*/
