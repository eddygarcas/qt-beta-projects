#ifndef IPV4ADDRESSTEMPLATE_MOC_H_
#define IPV4ADDRESSTEMPLATE_MOC_H_

/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IPv4AddressTemplate.h
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

#include "ui_IPAddressScreen.h"
#include "ScreenTemplate.h"

#include <QtGui/QWidget>
#include <QtCore/QString>

using namespace Ui;

/**
 * Defines a IP v4 address template
 */
class IPv4AddressTemplate : public QWidget, protected Ui::IPv4AddressScreen, public ScreenTemplate
{
    Q_OBJECT
public:

    /**
     * Generic constructor
     *
     * @param *parent
     */
    IPv4AddressTemplate(QWidget *parent = 0);

    /**
     * Class destructor
     */
    ~IPv4AddressTemplate();

    /**
     * Puts in screen template a window title.
     *
     * @param &_windowTitle
     */
    void setWindowTitle(const std::string &_windowTitle);

    /**
     * Shows the screen template in front panel.
     */
    void show();

    /**
     * Removes all components which are in screen template.
     *
     * @return bool
     */
    bool clear();

signals:

    /**
     * Gives back the IP address value
     *
     * @param _address
     */
    void giveBackAddress(QString _address);

private:

};

#endif /*IPV4ADDRESSTEMPLATE_MOC_H_*/
