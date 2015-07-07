/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   WidgetScroll.h
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

#ifndef WIDGETSCROLL_H_
#define WIDGETSCROLL_H_

#include <QtGui/QWidget>
#include <QtCore/QObject>
#include <QtGui/QApplication>
#include <QtGui/QHBoxLayout>
#include <QtGui/QScrollBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QAbstractButton>
#include <QtCore/QTimer>
#include <QtCore/QSize>

#define INTERVAL      200
#define INTERNAL_WIDGET_HEIGHT 1677

/**
 * This class defines a scroll screen widget. 
 * With this object we can do a screen where  we may put  any QObject, and this manage it automatically. 
 */
class WidgetScroll : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int32_t timerTime READ timerTime WRITE setTimerTime)
    Q_PROPERTY(bool activeTimer READ activeTimer WRITE setActiveTimer)
    Q_PROPERTY(int32_t widgetHeight READ widgetHeight WRITE setWidgetHeight)
    Q_PROPERTY(int32_t widgetWidth READ widgetWidth WRITE setWidgetWidth)

public:

    /**
     * Constructor by default
     * 
     * @param *parent Widget parent
     */
    WidgetScroll(QWidget *parent=0);

    /**
     * Specific filter for this widget. We want control the cursor movement and 'Ok' front panel button.
     * 
     * @param *target
     * @param *event
     * @return bool
     */
    bool eventFilter(QObject *target, QEvent *event);

    /**
     * With this method you can add in main widget other widgets, such as QPushBotton,QLabel,QCheckBox,etc...
     * 
     * @param *child Object which we want add to scroll widget
     * @param &objectName Name of the object inside widget Hierarchy
     * @param *parent Widget parent.
     */
    void addWidget(QWidget *child, const QString &objectName,
            QWidget *parent = 0);
    /**
     * With this method you can add in main widget other widgets, such as QPushBotton,QLabel,QCheckBox,etc...
     * 
     * @param *child Object which we want add to scroll widget
     * @param &objectName Name of the object inside widget Hierarchy
     * @param &size Predefined widget size
     * @param *parent Widget parent.
     */
    void addWidget(QWidget *child, const QString &objectName,
            const QSize &size, QWidget *parent = 0);

    /**
     * Removes all widgets in widgetContainer 
     */
    void removeAll();
    
    /**
     * Returns the interval time in miliseconds.
     * 
     * @reuturn int32_t
     */
    int32_t timerTime();
    
    /**
     * You will be able to define a new interval time with this method.
     * 
     * @param time Interval time in miliseconds
     */
    void setTimerTime(int time);

    /**
     * Returns the timer state. If it returns true, the timer is on, otherwise returns false.
     * 
     * @return bool
     */
    bool activeTimer();
    
    /**
     * If you want to deactivate the timer, pass false value to this function.
     * 
     * @param _activateTimer
     */
    void setActiveTimer(bool _activeTimer);

    /**
     * 
     * Return the widget height
     * 
     * @return int32_t
     */
    int32_t widgetHeight();
    
    /**
     * You will be able to define a new widget height with this function.
     * 
     * @param widgetHeight
     */
    void setWidgetHeight(int widgetHeight);

    /**
     * Returns the widget width.
     * 
     * @return int32_t
     */
    int32_t widgetWidth();
    
    /**
     * With this methos we will be able to define a new widget width.
     * 
     * @param widgetWidth
     */
    void setWidgetWidth(int widgetWidth);
    
    /**
     * Object destructor
     */
    virtual ~WidgetScroll();

public slots:
    
    /**
     * When the position of vertical scroll bar changes, this method will be called and _value parameter
     * contains the last position.
     * 
     * @param _value
     */
    void on_verticalScrollBar_valueChanged(int _value);
    /**
     * If any button was clicked, this method will be called.
     * 
     * @param clk_value 
     */
    void on_widget_clicked(bool clk_value);
    
    /**
     * If you want hidd the scroll bars, put in hidden parameter the false value, otherwise true.
     */
    void scrollBars_hidden(bool hidden);
    
    /**
     * Scroll selected widget text.
     */
    void scroll_hidden_text();

signals:

    /**
     * With this signal this widget sends the log information 
     */
    void send_widget_information(QString logInfo);
    
    /**
     * The widget sends the information about the button which has been pushed 
     * 
     * @param str_value Text of button which has been pushed.
     * @param selected
     */
    void send_selected_information(QString str_value, bool selected);

protected:
    
    /**
     * With this function we can determine if the widget is out of paint zone.
     * 
     * @param *element Element to check
     * @param *parent  Widget parent which we want to compare.
     * @return bool
     */
    bool isOutOfRect(QWidget *element, QWidget *parent);

    /**
     * Changes widget size with the size specified through paramter 'size'.
     * 
     * @param &size
     */
    void widgetResize(const QSize &size);
    
    /**
     * Recalculates de scroll bars position.
     * 
     * @param *child
     */
    void calibrate_scrollbars(QWidget *child);
    
    /**
     * Finds the last child widget in hierarchy.
     * 
     * @return QWidget*
     */
    QWidget* findLastChild();

private:

    /**
     * Obtains the abstract instance of selected widget, whatever the selected widget as a QPushButton.
     * 
     * @return QAbstractButton*
     */
    QAbstractButton* getFocusAbstractButton();

    int32_t sliderValue;
    int32_t totalWidgets;
    bool activeTimer_;
    QTimer *timer;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QWidget *widget;
    QScrollBar *verticalScrollBar;
    QHBoxLayout *hboxLayout1;
    QVBoxLayout *vboxLayout1;

};

#endif /*WIDGETSCROLL_H_*/
