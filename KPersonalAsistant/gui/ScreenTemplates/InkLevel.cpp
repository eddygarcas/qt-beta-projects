#include "InkLevel.h"
#include <string>
/*We remove  title and border window with FramelessWindowHint constructor parameter.*/
InkLevel::InkLevel(int32_t width,int32_t height, QWidget *parent) :
  QWidget(parent, Qt::FramelessWindowHint)
{

  if (width > 0 && height > 0)
  {
    this->resize(QSize(width,height));
    this->setMinimumSize(QSize(width,height));
  }

  gridLayout = new QGridLayout(this);
  gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
  gridLayout->setHorizontalSpacing(0);
  gridLayout->setVerticalSpacing(0);
  gridLayout->setContentsMargins(0, 0, 0, 0);
  colorTitle = new QLabel(this);
  colorTitle->setObjectName(QString::fromUtf8("colorTitle"));
  QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(colorTitle->sizePolicy().hasHeightForWidth());
  colorTitle->setSizePolicy(sizePolicy);
  colorTitle->setTextFormat(Qt::AutoText);
  colorTitle->setAlignment(Qt::AlignCenter);
  colorTitle->setWordWrap(false);

  gridLayout->addWidget(colorTitle, 0, 0, 1, 3);

  spacerItem = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

  gridLayout->addItem(spacerItem, 1, 0, 1, 1);

  inkValue = new QProgressBar(this);
  inkValue->setObjectName(QString::fromUtf8("inkValue"));
  QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
  sizePolicy1.setHorizontalStretch(0);
  sizePolicy1.setVerticalStretch(0);
  sizePolicy1.setHeightForWidth(inkValue->sizePolicy().hasHeightForWidth());
  inkValue->setSizePolicy(sizePolicy1);
  QPalette palette;
  QBrush brush(QColor(255, 0, 0, 255));
  brush.setStyle(Qt::SolidPattern);
  palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
  palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
  QBrush brush1(QColor(172, 172, 172, 255));
  brush1.setStyle(Qt::SolidPattern);
  palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
  inkValue->setPalette(palette);
  inkValue->setLayoutDirection(Qt::LeftToRight);
  inkValue->setAutoFillBackground(false);
  inkValue->setMinimum(0);
  inkValue->setMaximum(100);
  inkValue->setValue(0);
  inkValue->setAlignment(Qt::AlignCenter);
  inkValue->setTextVisible(true);
  inkValue->setOrientation(Qt::Vertical);
  inkValue->setInvertedAppearance(false);
  inkValue->setTextDirection(QProgressBar::BottomToTop);

  gridLayout->addWidget(inkValue, 1, 1, 1, 1);

  spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

  gridLayout->addItem(spacerItem1, 1, 2, 1, 1);

  percentValue = new QLabel(this);
  percentValue->setObjectName(QString::fromUtf8("percentValue"));
  sizePolicy.setHeightForWidth(percentValue->sizePolicy().hasHeightForWidth());
  percentValue->setSizePolicy(sizePolicy);
  percentValue->setScaledContents(false);
  percentValue->setAlignment(Qt::AlignCenter);
  percentValue->setWordWrap(false);
  gridLayout->addWidget(percentValue, 2, 0, 1, 3);

  percentValue->setText(QString::fromUtf8(""));
  hasPercentValue_ = false;

  QObject::connect(inkValue, SIGNAL(valueChanged(int32_t)), this, SLOT(change_percent_value(int32_t)));
  QMetaObject::connectSlotsByName(this);

}

void InkLevel::change_ink_value(int32_t value)
{
  inkValue->setValue(value);
}

void InkLevel::change_percent_value(int32_t i)
{
  if (hasPercentValue_){
    percentValue->setNum(i);
    percentValue->setText(percentValue->text().append("%"));
  }
  emit percent_value(colorTitle->text().toStdString(), i);
}

/**
 * Returns widget height
 *
 * @return int32_t
 */
int32_t InkLevel::widgetHeight()
{
  return this->height();
}

/**
 * Defines widget height
 *
 * @param widgetHeight
 */
void InkLevel::setWidgetHeight(int32_t widgetHeight)
{
  widgetResize(QSize(this->width(), widgetHeight));
}

/**
 * Returns widget width
 *
 * @return int32_t
 */
int32_t InkLevel::widgetWidth()
{
  return this->width();
}

/**
 * Defines widget size.
 *
 * @param widgetWidth1
 */
void InkLevel::setWidgetWidth(int32_t widgetWidth)
{
  widgetResize(QSize(widgetWidth, this->height()));

}

/**
 * When widget resize is necessary to replace widgets position and re-calibrate the scroll bar.
 * _size paramter contains the new widget size.
 *
 * @param &_sieze
 */
void InkLevel::widgetResize(const QSize &_size)
{
  this->resize(_size);
  this->setMinimumSize(_size);
  this->setMaximumSize(_size);
}

int32_t InkLevel::inkMaximumLevel()
{
  return inkValue->maximum();
}

void InkLevel::setInkMaximumLevel(int32_t _maximumLevel)
{
  inkValue->setMaximum(_maximumLevel);
}

int32_t InkLevel::inkMinimumLevel()
{
  return inkValue->minimum();
}

void InkLevel::setInkMinimumLevel(int32_t _minimumLevel)
{
  inkValue->setMinimum(_minimumLevel);
}

QString InkLevel::colorText()
{
  return colorTitle->text();
}
void InkLevel::setColorText(QString _colorText)
{
  colorTitle->setText(_colorText);
}

QColor InkLevel::colorRGBValue()
{
  return barColor;
}
void InkLevel::setColorRGBValue(QColor colorRGBValue)
{
  barColor = colorRGBValue;
  QPalette palette;
  QBrush brush(colorRGBValue);
  brush.setStyle(Qt::SolidPattern);
  palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
  palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
  inkValue->setPalette(palette);

}

bool InkLevel::hasPercentValue()
{
  return hasPercentValue_;
}

void InkLevel::setHasPercentValue(bool _hasPercent)
{
  hasPercentValue_ = _hasPercent;
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
bool InkLevel::eventFilter(QObject *target, QEvent *event)
{
  return true;
}

InkLevel::~InkLevel()
{
  delete gridLayout;
  delete colorTitle;
  delete spacerItem;
  delete inkValue;
  delete spacerItem1;
  delete percentValue;

  gridLayout   = 0;
  colorTitle   = 0;
  spacerItem   = 0;
  inkValue     = 0;
  spacerItem1  = 0;
  percentValue = 0;
}
