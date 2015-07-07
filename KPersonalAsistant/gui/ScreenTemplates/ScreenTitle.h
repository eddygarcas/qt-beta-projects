/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ScreenTitle.h
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

#ifndef SCREENTITLE_MOC_H_
#define SCREENTITLE_MOC_H_

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QListWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtGui/QLabel>

#include <QtGui/QWidget>
#include <QtCore/QObject>

/**
 * With this class, we want to define a generic Screen Title, which contains a label, 
 * to write a title, and a horitzontal bar to separate this title from the rest of screen.
 */
class ScreenTitle : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString screenTitle READ screenTitle WRITE setScreenTitle)
public:

    /**
     * Object generic constructor
     * 
     * @param *parent
     */
    ScreenTitle(QWidget *parent=0);
    
    /**
     * Through this method you can to put a title in widget.
     * 
     * @param &_screenTitle.
     */
    void setScreenTitle(QString &_screenTitle);

    /**
     * Returns the screen title value
     * 
     * @return QString
     */
    QString screenTitle()
    {
        return aux_screenTitle;
    }

    /**
     * Through this method you can to put a title in widget.
     * 
     * @param textScreen
     */
    void setWindowTitle(const QString textScreen);

    /**
     * Class destructor
     */
    virtual ~ScreenTitle();

private:

    QString aux_screenTitle;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *screen_title;
    QFrame *separator;
};
#endif /*SCREENTITLE_MOC_H_*/
