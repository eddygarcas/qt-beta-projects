#include "WidgetScroll.h"
#include "FrontPanelEnum.h"
#include <cstdlib>
#include <QKeyEvent>
#include <QDropEvent>
#include <QFocusEvent>
#include <iostream>
#include <sstream>

/*We remove  title and border window with FramelessWindowHint constructor parameter.*/
WidgetScroll::WidgetScroll(QWidget *parent) :
    QWidget(parent, Qt::FramelessWindowHint)
{

    sliderValue = 0;
    totalWidgets = 0;
    activeTimer_ = false;

    //QSize _size = QSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    QSize _size = size();
    //this->setMinimumSize(_size);
    //this->setMaximumSize(_size);
    //this->resize(_size);

    vboxLayout = new QVBoxLayout(this);
    vboxLayout->setSpacing(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(0, 0, 0, 0);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));

    widget = new QWidget(this);
    widget->setObjectName(QString::fromUtf8("widget"));
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
    widget->setSizePolicy(sizePolicy);
    widget->setMinimumSize(QSize((_size.width() - 20), INTERNAL_WIDGET_HEIGHT));
    widget->setMaximumSize(QSize(_size.width(), INTERNAL_WIDGET_HEIGHT));
    widget->setBaseSize(QSize(_size.width(), INTERNAL_WIDGET_HEIGHT));
    widget->setAutoFillBackground(false);
    widget->installEventFilter(this);

    hboxLayout->addWidget(widget);

    verticalScrollBar = new QScrollBar(this);
    verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
    verticalScrollBar->setAutoFillBackground(true);
    verticalScrollBar->setOrientation(Qt::Vertical);
    verticalScrollBar->setMinimum(0);
    verticalScrollBar->setMaximum(widget->height());
    verticalScrollBar->adjustSize();
    scrollBars_hidden(true);

    hboxLayout->addWidget(verticalScrollBar);



    vboxLayout->addLayout(hboxLayout);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(scroll_hidden_text()));
    timer->setInterval(INTERVAL);

    QMetaObject::connectSlotsByName(this);

}

/**
 * Returns the time interval.
 *
 * @return int32_t
 */
int32_t WidgetScroll::timerTime()
{
    return timer->interval();
}

/**
 * Sets the interval time
 *
 * @param time
 */
void WidgetScroll::setTimerTime(int32_t time)
{
    timer->setInterval(time);
}

/**
 * If the timer is active, this method returns true in otherwise returns false.
 *
 * @return bool
 */
bool WidgetScroll::activeTimer()
{
    return activeTimer_;
}

/**
 * Sets the active time value
 *
 * @param _activeTimer
 */
void WidgetScroll::setActiveTimer(bool _activeTimer)
{
    activeTimer_ = _activeTimer;
}

/**
 * Returns widget height
 *
 * @return int32_t
 */
int32_t WidgetScroll::widgetHeight()
{
    return this->height();
}

/**
 * Defines widget height
 *
 * @param widgetHeight
 */
void WidgetScroll::setWidgetHeight(int32_t widgetHeight)
{
    widgetResize(QSize(this->width(), widgetHeight));
}

/**
 * Returns widget width
 *
 * @return int32_t
 */
int32_t WidgetScroll::widgetWidth()
{
    return this->width();
}

/**
 * Defines widget size.
 *
 * @param widgetWidth
 */
void WidgetScroll::setWidgetWidth(int32_t widgetWidth)
{
    widgetResize(QSize(widgetWidth, this->height()));

}

/**
 * When widget resize is necessary to replace widgets position and re-calibrate the scroll bar.
 * _size paramter contains the new widget size.
 *
 * @param &_sieze
 */
void WidgetScroll::widgetResize(const QSize &_size)
{
    this->resize(_size);
    this->setMinimumSize(_size);
    this->setMaximumSize(_size);

    widget->setMinimumSize(QSize(_size.width()-verticalScrollBar->width(), INTERNAL_WIDGET_HEIGHT));
    widget->setMaximumSize(QSize(_size.width(), INTERNAL_WIDGET_HEIGHT));
    widget->setBaseSize(QSize(_size.width(), INTERNAL_WIDGET_HEIGHT));

    calibrate_scrollbars(findLastChild());
}

/**
 * This function do scrolling the option text.
 */
void WidgetScroll::scroll_hidden_text()
{
    QAbstractButton *focus_child = getFocusAbstractButton();
    if (focus_child!=0)
    {
        QString child_text = focus_child->text().right(focus_child->text().length()-1);
        focus_child->setText(child_text.append(focus_child->text().at(0)));
    }
}

/**
 * Add widget to widget container.
 *
 * @param *_child
 */
void WidgetScroll::addWidget(QWidget *_child, const QString &_objectName, QWidget *_parent)
{
    _child->adjustSize();
    if (verticalScrollBar->isHidden())
    {
        addWidget(_child, _objectName, QSize(widget->width() - verticalScrollBar->width(), _child->height()), _parent);
    }
    else
    {
        addWidget(_child, _objectName, QSize(widget->width(), _child->height()), _parent);
    }
}

/**
 * Add widget to widget container on specified position.
 *
 * @param *_child
 * @param &_size
 */
void WidgetScroll::addWidget(QWidget *_child, const QString &_objectName, const QSize &_size, QWidget *_parent)
{
    QWidget *aux;

    _child->setParent(widget);
    _child->resize(_size);

    if ((aux = findLastChild())!=0)
    {
        _child->move(aux->x(), aux->y()+aux->height());
    }
    totalWidgets++;

    _child->setFocus();
    _child->setObjectName(_objectName);
    _child->installEventFilter(this);
    if (_parent!=0)
        _child->metaObject()->connectSlotsByName(_parent);
    connect(_child, SIGNAL(clicked(bool)), this, SLOT(on_widget_clicked(bool)));

    calibrate_scrollbars(_child);

}

void WidgetScroll::removeAll()
{
    QListIterator<QObject*> it(widget->children());
    while (it.hasNext())
    {
        dynamic_cast<QWidget*>(it.next())->deleteLater();
    }

    verticalScrollBar->setMaximum(widget->height());
    verticalScrollBar->setValue(0);

    sliderValue  = 0;
    totalWidgets = 0;
}

/**
 * It find last added widget.
 *
 * @return QWidget*
 */
QWidget* WidgetScroll::findLastChild()
{
    if (totalWidgets>=1)
    {
        /* TODO:
         * The last() widget method doesn't work, i guess which is a bug.
         * If we try to receive a last() object it returns the pointer to the first memory position of internal objects array.
         */
        return qobject_cast<QWidget*>(widget->children().at(totalWidgets-1));
    }
    else
    {
        return 0;
    }
}

/**
 * Calibrate scroll bar position, using for that a position of widget child passed through parameter.
 *
 * @param *_child
 */
void WidgetScroll::calibrate_scrollbars(QWidget *_child)
{
    if (isOutOfRect(_child, this))
    {
        this->scrollBars_hidden(false);
        verticalScrollBar->setMaximum((_child->y()+_child->height())-this->height());
    }
}

/**
 * Implements a eventFilter to control the keys that will be pressed.
 *
 * In every key press event this function re-calculate the scroll bar position to show the virtual
 * object in visible rectangle. If the object which we will show is out of visible rectangle,
 * will change a widgets positions to allow a correct visualization.
 *
 * Note:
 *  parentWidget->focusWidget() returns a widget child which its values are relative to super-parent, such as y(),x() methods
 *  however the widget->children() method returns QObject list which its values are relative to parent.
 *
 * @param QObject* Object that we want apply the event filter.
 * @param QEvent* Relased event
 */
bool WidgetScroll::eventFilter(QObject *target, QEvent *event)
{
    bool ret = false;
    if (event->type()==QEvent::KeyPress)
    {
        QKeyEvent *aux = static_cast<QKeyEvent*>(event);
        switch (aux->key())
        {
        case Qt::Key_Down:
            ret = focusNextChild();
            break;
        case Qt::Key_Up:
            ret = focusPreviousChild();
            break;
        case Qt::Key_Enter:
            ret = false;
            break;
        default:
            break;
        }

        QListIterator<QObject*> it(widget->children());
        QWidget *obj;

        while (it.hasNext() && ret)
        {
            obj = dynamic_cast<QWidget*>(it.next());
            if (obj->objectName() == widget->focusWidget()->objectName() && isOutOfRect(widget->focusWidget(), this))
            {
                verticalScrollBar->setValue(verticalScrollBar->value()+ obj->y());
                break;
            }
        }

    }
    return ret;
}

/**
 * It hidden or show the scroll bar according to parameter value.
 *
 * @param hidden
 */
void WidgetScroll::scrollBars_hidden(bool hidden)
{
    if (hidden!=verticalScrollBar->isHidden())
    {
        verticalScrollBar->setHidden(hidden);
        if (verticalScrollBar->isHidden())
        {
            widget->resize(this->width(), widget->height());
        }
        else
        {
            widget->resize(widget->width() - verticalScrollBar->width(), widget->height());
        }
    }
}

/**
 * Event raised when the scroll bar value changed.
 *
 * @param y
 */
void WidgetScroll::on_verticalScrollBar_valueChanged(int32_t y)
{
    QList<QObject*> l = widget->children();
    QListIterator<QObject*> it(l );
    QWidget *obj;
    int32_t dif_chords = abs(sliderValue) - abs(y);
    while (it.hasNext())
    {
        obj = dynamic_cast<QWidget*>(it.next());
        obj->move(obj->x(), obj->y()+dif_chords);
    }
    sliderValue = abs(y);
}

/**
 * Event raised when the scroll bar value changed.
 *
 * @param clk_value
 */
void WidgetScroll::on_widget_clicked(bool clk_value)
{
    emit send_selected_information(getFocusAbstractButton()->text(), clk_value);
}

/**
 * It Returns true if element paramter is out of parent size.
 *
 * @param element_
 * @param parent_
 * @return bool
 */
bool WidgetScroll::isOutOfRect(QWidget *element_, QWidget *parent_)
{
    return (((element_->y()+element_->height()) >= parent_->height())|| (element_->y() < 0));
}

/**
 * Returns the object which has the focus.
 *
 * @return QAbstractButton*
 */
QAbstractButton* WidgetScroll::getFocusAbstractButton()
{
    return dynamic_cast<QAbstractButton*>(widget->focusWidget());
}

WidgetScroll::~WidgetScroll()
{
    delete timer;
    timer = 0;
    delete vboxLayout;
    vboxLayout = 0;
    delete hboxLayout;
    hboxLayout = 0;
    delete widget;
    widget = 0;
    delete verticalScrollBar;
    verticalScrollBar = 0;
    delete hboxLayout1;
    hboxLayout1 = 0;
    delete vboxLayout1;
    vboxLayout1 = 0;
}
