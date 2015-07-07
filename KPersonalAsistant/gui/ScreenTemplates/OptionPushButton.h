#ifndef OPTIONPUSHBUTTON_MOC_H_
#define OPTIONPUSHBUTTON_MOC_H_

/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   OptionPushButton.h
 *  @author Hewlett-Packard
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


#include "IViewsAction.h"
#include "MenuPushButton.h"

/**
 * This class is used to represent a internal menu option.
 */
class OptionPushButton : public MenuPushButton
{
    Q_OBJECT
public:
    /**
     * Basic constructor, you must pass through parameter a option text value and widget parent.
     * 
     * @param const std::string& 
     * @param *_parent
     */
    OptionPushButton(const std::string &_optionText, QWidget *_parent=0);

    /**
     * Sets the option text value
     * 
     * @param const std::string&
     */
    void setOptionText(const std::string &_optionText);
    
    /**
     * Object destructor
     */
    virtual ~OptionPushButton();

public slots:

signals:

protected:

private:

};

#endif /*OPTIONPUSHBUTTON_MOC_H_*/
