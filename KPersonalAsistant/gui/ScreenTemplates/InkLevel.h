/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   InkLevel.h
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

#ifndef INKLEVEL_H_
#define INKLEVEL_H_

#include <QtGui/QWidget>
#include <QtCore/QObject>
#include <QtGui/QApplication>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtCore/QSize>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>

/**
 * This class defines a ink level widget. 
 */
class InkLevel : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int32_t widgetHeight READ widgetHeight WRITE setWidgetHeight)
    Q_PROPERTY(int32_t widgetWidth READ widgetWidth WRITE setWidgetWidth)
    Q_PROPERTY(int32_t minimumLevel READ inkMinimumLevel WRITE setInkMinimumLevel)
    Q_PROPERTY(int32_t maximumLevel READ inkMaximumLevel WRITE setInkMaximumLevel)
    Q_PROPERTY(QString colorText READ colorText WRITE setColorText)
    Q_PROPERTY(QColor colorRGBValue READ colorRGBValue WRITE setColorRGBValue)
    Q_PROPERTY(bool hasPercentValue READ hasPercentValue WRITE setHasPercentValue)

public:

    /**
     * Ink level widget constructor
     * 
     * @param width
     * @param height
     * @param *parent
     */
    InkLevel(int32_t width=0, int32_t height=0, QWidget *parent=0);
    
    /**
     * Specific filter for this widget. We want control the cursor movement and 'Ok' front panel button.
     * 
     * @param *target
     * @param *event
     * @return bool
     */
    bool eventFilter(QObject *target, QEvent *event);
    
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
     * Returns the top level ink value
     * 
     * @return int32_t
     */
    int32_t inkMaximumLevel();
    
    /**
     * With this method we cen define the maximum ink value.
     * 
     * @param maximumLevel
     */
    void setInkMaximumLevel(int maximumLevel);

    /**
     * Returns the minimum ink level value.
     * 
     * @return int32_t
     */
    int32_t inkMinimumLevel();
    
    /**
     * Through this method we can define a new minimum ink value.
     * 
     * @param minimumLevel
     */
    void setInkMinimumLevel(int minimumLevel);

    /**
     * Returns the color text value.
     * 
     * @return QString
     */
    QString colorText();
    
    /**
     *Through this method we can specify a new color.
     * 
     * @param colorText 
     */
    void setColorText(QString colorText);

    QColor colorRGBValue();
    void setColorRGBValue(QColor colorRGBValue);

    bool hasPercentValue();
    void setHasPercentValue(bool hasPercent);

    virtual ~InkLevel();

public slots:

    void change_ink_value(int value);

protected slots:

    void change_percent_value(int i);

signals:

    void percent_value(std::string _colorTitle, int _colorValue);

protected:

    /**
     * Changes widget size with the size specified through paramter 'size'.
     * 
     * @param &size
     */
    void widgetResize(const QSize &size);

private:

    bool hasPercentValue_;
    QColor barColor;
    QGridLayout *gridLayout;
    QLabel *colorTitle;
    QSpacerItem *spacerItem;
    QProgressBar *inkValue;
    QSpacerItem *spacerItem1;
    QLabel *percentValue;

};

#endif /*INKLEVEL_H_*/
