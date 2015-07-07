/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   MenuPushButton.h
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

#ifndef MENUPUSHBUTTON_H_
#define MENUPUSHBUTTON_H_

#include "IViewsAction.h"

#include <QtCore/QObject>
#include <QtGui/QWidget>
#include <QtGui/QApplication>

#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QIcon>
#include <QtGui/QKeyEvent>
#include <QtGui/QMouseEvent>
#include <QtGui/QHoverEvent>
#include <QtGui/QFocusEvent>
#include <QtCore/QSize>

/**
 * Defines a generic menu push button. This button definition is used in main menu screen.
 */
class MenuPushButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QIcon onfocusIcon READ onfocusIcon WRITE setOnfocusIcon)
    Q_PROPERTY(QIcon outfocusIcon READ outfocusIcon WRITE setOutfocusIcon)
    Q_PROPERTY(QSize buttonSize READ buttonSize WRITE setButtonSize)
    Q_PROPERTY(bool buttonEnabled READ buttonEnabled WRITE setButtonEnabled)
    Q_PROPERTY(QString buttonInformation READ buttonInformation WRITE setButtonInformation)

public:

    /**
     * Generic constructor
     *
     * @param &size
     * @param *parent
     */
    MenuPushButton(const QSize &size, QWidget *parent=0);

    /**
     * Returns icon when the mouse is over the button
     *
     * @return QIcon
     */
    QIcon onfocusIcon();

    /**
     * Defines a mouse over icon
     *
     * @param &_iconOn
     */
    void setOnfocusIcon(const QIcon &_iconOn);

    /**
     * Returns icon when the mouse is out of button
     *
     * @return QIcon
     */
    QIcon outfocusIcon();

    /**
     * Defines a mouse out of button icon
     *
     * @param &_iconOut
     */
    void setOutfocusIcon(const QIcon &_iconOut);

    /**
     * Returns the button size
     *
     * @return QSize
     */
    QSize buttonSize();

    /**
     * Defines the button size
     *
     * @param &_buttonSize
     */
    void setButtonSize(QSize &_buttonSize);

    /**
     * Returns true if the button is enables and false in otherwise.
     *
     * @return bool
     */
    bool buttonEnabled();

    /**
     * Defines the button enabled value
     *
     * @param _buttonEnabled
     */
    void setButtonEnabled(bool _buttonEnabled);

    /**
     * Returns the button information
     *
     * @return QString
     */
    QString buttonInformation();

    /**
     * Defines the button information
     *
     * @param &_buttonInformation
     */
    void setButtonInformation(const QString &_buttonInformation);

    /**
     * Defines the model action which will be launched when user clicks over button
     *
     * @param *_actionModel
     */
    void setActionModel(IViewsAction *_actionModel);

    /**
     * Makes a event behavior for this component.
     *
     * @param *target
     * @param *event
     * @return bool
     */
    bool eventFilter(QObject *target,QEvent *event);

    /**
     * Destructor
     */
    virtual ~MenuPushButton();

public slots:

    /**
     * When the button is clicked, this methos receives the event.
     *
     * @param checked
     */
    void menu_button_clicked(bool checked);

signals:

    /**
     * This signal send a text to status bar.
     *
     * @param _test
     */
    void text_to_status_bar(QString _test);

private:

    QIcon mouseOverIcon_;
    QIcon mouseOutIcon_;

    IViewsAction::actionType_enum actionType_;
    IViewsAction *menuAction_;

};

#endif /*MENUBUTTON_H_*/
