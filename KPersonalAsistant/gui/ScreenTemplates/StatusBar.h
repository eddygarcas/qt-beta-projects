/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   StatusBar.h
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

#ifndef STATUSBAR_MOC_H_
#define STATUSBAR_MOC_H_

#include <QtGui/QWidget>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtCore/QString>
#include <QtCore/QSize>

/**
 * By means of this class we want to define a status bar for main menu screen in particular but too for all widgets.
 */
class StatusBar : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString statusText WRITE statusText)

public:
    
    /**
     * Status bar generic constructor
     * 
     * @param *parent
     */
    StatusBar(QWidget *parent=0);

    /**
     * Class destructor
     */
    virtual ~StatusBar();

public slots:

    /**
     * By means of this slot, you will be able to put a test on status bar.
     * 
     * @param QString
     */
    void statusText(QString);

signals:

private:
    
    QVBoxLayout *vboxLayout;
    QFrame *statusBar;
    QVBoxLayout *vboxLayout1;
    QLabel *status_text;

};

#endif /*STATUSBAR_H_*/
