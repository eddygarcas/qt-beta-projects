/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IPaperList.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  IPaperList interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////


#ifndef IPAPERLIST_H_
#define IPAPERLIST_H_

#include "atlas_types.h"
#include "PaperList/IPaper.h"
#include "IObserver.h"
#include "IObservable.h"
#include "IPrinterCommands.h"
#include "ViewsIterator.h"
#include "ILocale.h"

#include <string>

/**
 * Contains all supported medias and provides a high-level functions for 
 * obtaining IPaper list or IPaper single instance.
 */ 
class IPaperList : public IObservable,
                   public IObserver,
                   public IPrinterCommands
                   
{
  
public:

  /**
   * Return an integer which contains a paper list version
   * 
   * @return uint32_t
   */
  virtual int32_t getPaperListVersion(void) = 0;
	  
  /**
   * Return a IPaper instance specified by parameter value.
   * 
   * @param _mediaKey Key value of paper item.
   * @param _locale Instance of ILocale interface with system locale value.
   * @return IPaper*
   */
  virtual IPaper* getPaper(const std::string& _mediaKey,ILocale& _locale) = 0;
    
  /**
   *Return a lista of IPaper instances.
   * 
   * @param _locale Instance of ILocale interface with system locale value.
   * @return ViewsIterator<IPaper*>
   */
  virtual ViewsIterator<IPaper*> getPaperIterator(ILocale& _locale) = 0;
};

#endif /*IPAPERLIST_H_*/
