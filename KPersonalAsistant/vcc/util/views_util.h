/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   views_util.h
 *  @author Xavier Santotomas
 *  @date  Tue Jun  3 15:28:27 CEST 2008
 *  @brief  This file contains the headers of all those global functions shared among VCC
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2008.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#ifndef VIEWS_UTIL_H_ 
#define VIEWS_UTIL_H_

#include <sstream>
#include <string>

#include "LocalizationIdentifiers.h"
#include "util/IInkConsumable.h"


/**
 * Makes a CDS key value by means of parameters.
 * If _index parameter equals zero this function concate component parameter 
 * with element parameter, without index value.
 * 
 * @param const char*
 * @param int16_t
 * @param const char*
 * 
 * @return std::string
 */
std::string buildCdsKey(const char* component,int16_t index,const char* element);


/**
 * Makes a CDS key value by means of parameters.
 * If _index parameter equals zero this function concate component parameter 
 * with element parameter, without index value.
 * 
 * @param const char*
 * @param int16_t
 * @param const char*
 * @param int16_t
 * @param const char*
 * 
 * @return std::string
 */
std::string buildCdsKey(const char* component, int16_t index1, const char* element1, int16_t index2, const char* element2);


/** Method returning the localization identifier binded to the color
 *
 *   @param color is the identifier of the color as specified in the CDS 
 *   @param shortFlag indicate if we want the short version 
 *   @return localization identifier
 */
l10n::StringKey getColorAsStringKey(CDSColorId color, bool shortFlag);


#endif /*VIEWS_TYPES_H_*/
