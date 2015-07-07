/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Aspect.h
 *  @author Xavier Santotomas
 *  @date   Mon Apr  7 13:31:14 CEST 2008
 *  @brief  Aspect header file
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2008.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __Aspect_h_
#define __Aspect_h_

#include "atlas_types.h"

#include <map>
#include <string>


typedef std::map<std::string, std::string> propertiesMapType;

/** Describes in which kind of 'stuff' could be interested a generic observer.
 *   Finally, it is just an agreement between the two parts (observer & observable).
 */
class Aspect
{
public:

    /** Method returning the kind of change
     *   @return the integer value representing the kind of change
     */
    int16_t getKindOfChange() const { return kindOfChange_; }

    /** Method setting the kind of change
     *   @param kindOfChange is the integer value representing the kind of change
     */
    void setKindOfChange(int16_t kindOfChange) { kindOfChange_ = kindOfChange; }

    /** Method returning if the observer is interested in getting the reason when notified
     *   @return a boolean value representing the flag
     */
    bool getInterestedInReason() const { return interestedInReason_; }
    
    /** Method setting if the observer is interested in getting the reason when notified
     *   @param interestedInReason is a boolean value representing the flag
     */
    void setInterestedInReason(bool interestedInReason) { interestedInReason_ = interestedInReason; }
    
    /** Method to add a (key, value) entry in the map
     *   @param key is the value to be used as key in the map
     *   @param value is the value to be assigned as associated to the key in the map
     */
    void setProperty(std::string key, std::string value) { propertiesMap_[key]=value; } 

    /** Method returning the value associated to the key
     *   @param key is the value to be used as key in the map
     *   @return the value
     */
    std::string getProperty(std::string key) { return propertiesMap_[key]; }
    
    /** Method returning a reference in order to allow access to the map
     *   @return a reference to the associative array
     */
    propertiesMapType &getPropertiesMap() { return propertiesMap_; }
	
private:

    /** It can be an enumerated listing the different kind of changes in which an observer could be interested.
     *   As the kind of change is of integer type, it's also open to store any enumeration defined in order to achieve an agreement.
     */
    int16_t kindOfChange_;
	
    /** If some of the changes enumerated previously needs more specific information, you can use this properties map in order to refine them.
     *   The map allows to keep a list of (key,value) pairs, where the key is a string and the value is also a string.
     *   As the value is of string type, it's open to store any string in order to achieve an agreement.
     */
    propertiesMapType propertiesMap_; 
	
    /** if true, the observer is interested in getting a reason when notified (Through the onChange method). 
     *   if false, then the observer is not interested in the reason.
     */
    bool interestedInReason_; 

};


#endif
