/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   views_util.cpp
 *  @author Xavier Santotomas
 *  @date  Tue Jun  3 15:33:49 CEST 2008
 *  @brief  This file contains  those global functions shared among VCC
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2008.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "views_util.h"


/**
 * Makes a CDS key value by means of parameters.
 * If _index parameter equals zero this function concate component parameter 
 * with element parameter, without index value.
 * 
 * @param const char*
 * @param int16_t
 * @param const char*
 * 
 * @return string
 */
std::string buildCdsKey(const char* component, int16_t index, const char* element)
{
  	std::ostringstream cdsKey;
  	if (index>0)
  	{
    		cdsKey << component << (int16_t) index << element;  
  	}
  	else
  	{
    		cdsKey << component << element;
  	}
  
  	return cdsKey.str();
}

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
 * @return string
 */
std::string buildCdsKey(const char* component, int16_t index1, const char* element1, int16_t index2, const char* element2)
{
  	std::ostringstream cdsKey;
  	if (index1 > 0 &&  index2 > 0)
  	{
    		cdsKey << component << (int16_t) index1 << element1 << (int16_t) index2 << element2;  
  	}
  	else
  	{
    		cdsKey << component << element1 << element2;
  	}
  
  	return cdsKey.str();
}


/** Method returning the localization identifier binded to the color
 *
 *   @param color is the identifier of the color as specified in the CDS 
 *   @param shortFlag indicate if we want the short version 
 *   @return localization identifier
 */
l10n::StringKey getColorAsStringKey(CDSColorId color, bool shortFlag)
{

         l10n::StringKey key;
         
         switch (color) 
         {
             case IInkConsumable::CYAN:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_CYAN;
                 else
                 	key = l10n::STRING_COLOR_NAME_CYAN;
                 break;
             case IInkConsumable::MAGENTA:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_MAGENTA;
                 else
                 	key = l10n::STRING_COLOR_NAME_MAGENTA;
                 break;
             case IInkConsumable::YELLOW:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_YELLOW;
                 else
                 	key = l10n::STRING_COLOR_NAME_YELLOW;
                 break;
             case IInkConsumable::BLACK:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_BLACK;
                 else
                 	key = l10n::STRING_COLOR_NAME_BLACK;
                 break;
             case IInkConsumable::RED:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_RED;
                 else
                 	key = l10n::STRING_COLOR_NAME_RED;
                 break;
             case IInkConsumable::GREEN:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_GREEN;
                 else
                 	key = l10n::STRING_COLOR_NAME_GREEN;
                 break;
             case IInkConsumable::BLUE:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_BLUE;
                 else
                 	key = l10n::STRING_COLOR_NAME_BLUE;
                 break;
             case IInkConsumable::LIGHT_CYAN:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_LIGHT_CYAN;
                 else
                 	key = l10n::STRING_COLOR_NAME_LIGHT_CYAN;
                 break;
             case IInkConsumable::LIGHT_MAGENTA:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_LIGHT_MAGENTA;
                 else
                 	key = l10n::STRING_COLOR_NAME_LIGHT_MAGENTA;
                 break;
             case IInkConsumable::ORANGE:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_ORANGE;
                 else
                 	key = l10n::STRING_COLOR_NAME_ORANGE;
                 break;
             case IInkConsumable::GRAY:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_GRAY;
                 else
                 	key = l10n::STRING_COLOR_NAME_GRAY;
                 break;
             case IInkConsumable::LIGHT_GRAY:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_LIGHT_GRAY;
                 else
                 	key = l10n::STRING_COLOR_NAME_LIGHT_GRAY;
                 break;
             case IInkConsumable::DARK_GRAY:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_DARK_GRAY;
                 else
                 	key = l10n::STRING_COLOR_NAME_DARK_GRAY;
                 break;
             case IInkConsumable::GLOSS_ENHANCER:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_GLOSS_ENHANCER;
                 else
                 	key = l10n::STRING_COLOR_NAME_GLOSS_ENHANCER;
                 break;
             case IInkConsumable::VIOLET:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_VIOLET;
                 else
                 	key = l10n::STRING_COLOR_NAME_VIOLET;
                 break;
              case IInkConsumable::MATTE_BLACK:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_MATTE_BLACK;
                 else
                 	key = l10n::STRING_COLOR_NAME_MATTE_BLACK;
                  break;
              case IInkConsumable::PHOTO_BLACK:
                 if (shortFlag) 
                 	key = l10n::STRING_COLOR_LETTER_PHOTO_BLACK;
                 else
                 	key = l10n::STRING_COLOR_NAME_PHOTO_BLACK;
                  break;
             default:                 	
                 key = (l10n::StringKey)-1;
                 break;
                 	
         }
        return key;

}
