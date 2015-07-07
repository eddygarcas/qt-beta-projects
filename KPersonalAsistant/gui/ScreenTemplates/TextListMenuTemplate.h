
/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   MainMenuTemaplte.h
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

#ifndef TEXTLISTMENUTEMPLATE_H_
#define TEXTLISTMENUTEMPLATE_H_

#include "IMenuTemplate.h"
#include "ui_TextListScreen.h"
#include "ScreenTemplate.h"
#include "MenuPushButton.h"

#include <QtCore/QObject>
#include <QtGui/QWidget>
#include <QtGui/QApplication>

#include <QtCore/QString>
#include <QtGui/QPixmap>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>

using namespace Ui;

class TextListMenuTemplate : public QWidget, protected Ui::TextListScreen,
    public ScreenTemplate, public IMenuTemplate
{
    Q_OBJECT
public:

    /**
     * Generic constructor
     *
     * @param *parent
     */
    TextListMenuTemplate(QWidget *parent = 0);

    /**
     * Class destructor
     */
    ~TextListMenuTemplate();

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

    /**
      *
      *data_ variable should contain a vector of MenuPushButton instances.
      *You must cover the vector and for each instance put it in menu grid.
      *Class:
      * QGridLayout
      *Moethod which will be called:
      * void addWidget ( QWidget * widget, int row, int column, Qt::Alignment alignment = 0 )
      *
      */
    bool addMenuPushButton(MenuPushButton *_pushButton);

    /**
     * Adds an option to menu action. The menu action implementation performs the operations to show this option in screen template.
     *
     * @param &_label Text which will show in option
     * @param *_action  Action which this option calls when someone pick up it.
     */
    void addOption(const std::string &_label, IViewsAction *_action);
    /**
     * Adds an option to menu action. The menu action implementation performs the operations to show this option in screen template.
     *
     * @param *_menuPushButton Instance of MenuPushButton, which contains the operations to perform the action
     */
    void addOption(MenuPushButton *_menuPushButton);

    /**
     * With this method we want take the control of key event process of front panel. This method will assign a action to each allowed key.
     *
     * @param _key
     * @param *_action
     */
    void addHidden(Qt::Key _key, IViewsAction *_action);

public slots:

signals:

private:

};

#endif /*TEXTLISTMENUTEMPLATE_H_*/
