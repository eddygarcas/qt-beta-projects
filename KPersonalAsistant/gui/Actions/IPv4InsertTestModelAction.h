#ifndef IPV4INSERTTESTMODELACTION_MOC_H_
#define IPV4INSERTTESTMODELACTION_MOC_H_

/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   MainMenuModelAction.h
 *  @author Eduard Garcia Castello
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#include "ModelAction.h"
//#include "LocalizationIdentifiers.h"
#include <QtCore/QString>
#include <iostream>

#include <string>

/**IP v4 address insert test model action*/
class IPv4InsertTestModelAction : public ModelAction
{
    Q_OBJECT
public:

    /**
     * Default constructor
     *
     * @param _priority
     * @param _templ
     * @param _label
     * @param _title
     * @param &image_on
     * @param &image_off
     * @param _log
     *
     */
    IPv4InsertTestModelAction(int32_t _priority,
            IScreenTemplate::screenTemplate_enum _templ,
            std::string _label, std::string _title,
            const std::string &_image_on = 0,
            const std::string &_image_off = 0);

    /**
    *Returns the action object name. This name will be used to create a menu option list.
    *
    * @return std::string
    */
    const std::string& getObjectName();

    /**
     * By means of this method we will be able to assign views common classes interfaces into
     * model actions.
     *
     * @param interfaceName
     * @param *interface
     */
    void setInterface(std::string interfaceName, void *interface);

    /**
     * Next method will contains the logical functionality.
     */
    void execute();

    /**
     * Determines if this option is a action option or otherwise as a menu option.
     *
     */
    bool hasMenuOption();

public slots:

/**
 * Give back the IP addres reported by screen template.
 *
 * @param _address
 */
void insertAddressInViews(QString _address);

protected:

private:

};

#endif /*IPV4INSERTTESTMODELACTION_MOC_H_*/
