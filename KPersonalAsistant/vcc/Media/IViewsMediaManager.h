/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsMediaManager.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  ViewsMediaManager singleton interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef IVIEWSMEDIAMANAGER_H_
#define IVIEWSMEDIAMANAGER_H_

#include "views_types.h"
#include "atlas_types.h"
#include "Media/IViewsIntray.h"
#include "Media/IViewsOutputTray.h"
#include "IObserver.h"
#include "IObservable.h"
#include "IPrinterCommands.h"
#include "CommonCalibration.h"
#include "MediaManager/IMediaManager.h"

typedef std::vector<IViewsIntray*> ViewsMediaCollection;

typedef ViewsMediaCollection::iterator ViewsMediaIterator;

typedef std::vector<int32_t> ViewsMediaPrintQualityCollection;

typedef ViewsMediaPrintQualityCollection::iterator ViewsMediaPrintQualityIterator;

typedef std::vector<int32_t> ViewsMediaPrintTypeCollection;

typedef ViewsMediaPrintTypeCollection::iterator ViewsMediaPrintTypeIterator;

/**
 * Contains main methods to obtain and manage tray objects.
 * It Will be Observer and Observable object it allows to see 
 * its state to other objects of class hierarchy. 
 */
class IViewsMediaManager : public IObserver, public IObservable,
  public IPrinterCommands

{
public:

  enum ViewsMediaStatus
  {
    VIEWS_MS_NOT_INITIALIZED = IMediaManager::MS_NOT_INITIALIZED,
    VIEWS_MS_INITIALIZING = IMediaManager::MS_INITIALIZING,
    VIEWS_MS_CHECKING = IMediaManager::MS_CHECKING,
    VIEWS_MS_NO_PAPER = IMediaManager::MS_NO_PAPER,
    VIEWS_MS_PRINTING = IMediaManager::MS_PRINTING,
    VIEWS_MS_READY = IMediaManager::MS_READY,
    VIEWS_MS_ERROR = IMediaManager::MS_ERROR
  };

  enum ViewsPrintQuality
  {
    FAST,
    NORMAL,
    BEST
  };

  enum ViewsPrintType
  {
    UNKNOWN,
    IMAGES,
    TEXT
  };
  /**
   * Load a intray element into list of papers
   * 
   * @param viewsIntray
   * @return Result
   */
  virtual Result loadPaper(IViewsIntray &_viewsIntray) = 0;

  /**
   * Returns a ViewsMediaCollection of IViewsIntrays pointers
   * 
   * @return ViewsMediaCollection
   */
  virtual ViewsMediaCollection getIntrays() = 0;

  /**
   * Return the active Intray object.
   * 
   * @return IViewsIntray
   */
  virtual IViewsIntray* getActiveIntray() = 0;

  /**
   * Return the actual status
   * 
   * @return ViewsMediaStatus
   */
  virtual ViewsMediaStatus getStatus() = 0;

  /**
   * Return the active output tray instance.
   * 
   * @return IViewsOutputTray 
   */
  virtual IViewsOutputTray* getActiveOutTray() = 0;

  /**
   * Total comsumption of media for print quality.
   * Iterator order makes relationship with ViewsPrintQuality sort enumeration 
   * 
   * @return ViewsMediaPrintQualityCollection
   */
  virtual ViewsMediaPrintQualityCollection getUsagePrintQuality() = 0;

  /**
   * Total consumption of media for print type
   * Iterator order makes relationship with ViewsPrintType sort enumeration
   * 
   * @return ViewsMediaPrintTypeCollection
   */
  virtual ViewsMediaPrintTypeCollection getUsagePrintType() = 0;

  /**
   * It returns the total media printed in inches.
   * 
   * @return uint32_t
   */
  virtual uint32_t getTotalMediaPrinted() = 0;

  /**
   * It returns total pages printed.
   * 
   * @return uint32_t
   */
  virtual uint32_t getTotalPagesPrinted() = 0;

  /**
   * Returns media advance calibration
   * 
   * @return CommonCalibration*
   */
  virtual CommonCalibration* getMediaAdvanceCalibration() = 0;
};

#endif /*IVIEWSMEDIAMANAGER_H_*/
