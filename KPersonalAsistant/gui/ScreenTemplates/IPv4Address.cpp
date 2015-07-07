#include "IPv4Address.h"
//#include "views_types.h"

/**
 * Widget constructor
 * Defines widget visual aspect and default values.
 * @param *parent Widget parent
 */
IPv4Address::IPv4Address(QWidget *parent) :
    QWidget(parent)
{

    resize(QSize(0, 30));

    vboxLayout = new QVBoxLayout(this);
    vboxLayout->setSpacing(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(0, 0, 0, 0);
    spacerItem = new QSpacerItem(20, 39, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout->addItem(spacerItem);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(2);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    hboxLayout->setContentsMargins(6, -1, 6, 0);
    ipText = new QLabel(this);
    ipText->setObjectName(QString::fromUtf8("ipText"));

    hboxLayout->addWidget(ipText);

    octet_1 = new QLineEdit(this);
    octet_1->setObjectName(QString::fromUtf8("octet_1"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(octet_1->sizePolicy().hasHeightForWidth());
    octet_1->setSizePolicy(sizePolicy);
    octet_1->setAutoFillBackground(false);
    octet_1->setFrame(true);
    octet_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    octet_1->setFocusPolicy(Qt::NoFocus);

    hboxLayout->addWidget(octet_1);

    label_2 = new QLabel(this);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    hboxLayout->addWidget(label_2);

    octet_2 = new QLineEdit(this);
    octet_2->setObjectName(QString::fromUtf8("octet_2"));
    sizePolicy.setHeightForWidth(octet_2->sizePolicy().hasHeightForWidth());
    octet_2->setSizePolicy(sizePolicy);
    octet_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    octet_2->setFocusPolicy(Qt::NoFocus);

    hboxLayout->addWidget(octet_2);

    label_3 = new QLabel(this);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    hboxLayout->addWidget(label_3);

    octet_3 = new QLineEdit(this);
    octet_3->setObjectName(QString::fromUtf8("octet_3"));
    sizePolicy.setHeightForWidth(octet_3->sizePolicy().hasHeightForWidth());
    octet_3->setSizePolicy(sizePolicy);
    octet_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    octet_3->setFocusPolicy(Qt::NoFocus);

    hboxLayout->addWidget(octet_3);

    label_4 = new QLabel(this);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    hboxLayout->addWidget(label_4);

    octet_4 = new QLineEdit(this);
    octet_4->setObjectName(QString::fromUtf8("octet_4"));
    sizePolicy.setHeightForWidth(octet_4->sizePolicy().hasHeightForWidth());
    octet_4->setSizePolicy(sizePolicy);
    octet_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    octet_4->setFocusPolicy(Qt::NoFocus);

    hboxLayout->addWidget(octet_4);

    vboxLayout->addLayout(hboxLayout);

    spacerItem1 = new QSpacerItem(20, 39, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout->addItem(spacerItem1);

    octet_1->setInputMask(QApplication::translate("IPLineEdit", "###; ", 0,
            QApplication::UnicodeUTF8));

    label_2->setText(QApplication::translate("IPLineEdit", ".", 0,
            QApplication::UnicodeUTF8));

    octet_2->setInputMask(QApplication::translate("IPLineEdit", "###; ", 0,
            QApplication::UnicodeUTF8));

    label_3->setText(QApplication::translate("IPLineEdit", ".", 0,
            QApplication::UnicodeUTF8));

    octet_3->setInputMask(QApplication::translate("IPLineEdit", "###; ", 0,
            QApplication::UnicodeUTF8));

    label_4->setText(QApplication::translate("IPLineEdit", ".", 0,
            QApplication::UnicodeUTF8));

    octet_4->setInputMask(QApplication::translate("IPLineEdit", "###; ", 0,
            QApplication::UnicodeUTF8));

    parseIPAddress();

    QMetaObject::connectSlotsByName(this);
}

void IPv4Address::append_ip_address(QString _ipValue_)
{
    ipValue_ = _ipValue_;
    parseIPAddress();
}

void IPv4Address::append_ip_address_value(QChar _ipValue_)
{
    if (ipValue_.size() < IP_LENGHT)
    {
        ipValue_.append(_ipValue_);
        parseIPAddress();
    }
}

void IPv4Address::finished_edition()
{
    QWidget *aux;
    bool passfirstOctet_ = false;
    ipFormatedValue_.clear();

    if (ipValue_.size() == IP_LENGHT)
    {
        for (int32_t i = 0; i < hboxLayout->count(); i++)
        {
            aux = hboxLayout->itemAt(i)->widget();
            if (aux->metaObject()->className() == QLineEdit::staticMetaObject.className() )
            {
                if (passfirstOctet_)
                {
                    ipFormatedValue_.append(QString::fromUtf8("."));
                }
                ipFormatedValue_.append(static_cast<QLineEdit*>(aux)->text());
                passfirstOctet_ = true;
            }
        }
        emit ipAddressChanged(ipFormatedValue_);
    }
}

void IPv4Address::remove_last_ip_address_value()
{
    ipValue_.remove(ipValue_.size()-1, 1);
    parseIPAddress();
}

void IPv4Address::setIPAddress(QString _ipValue)
{
    ipValue_ = _ipValue;
}

QString IPv4Address::getIPAddress()
{
    return ipValue_;
}

void IPv4Address::setAddressTextLavel(QString _addressLavel)
{
    ipText->setText(_addressLavel);
}

QString IPv4Address::addressTextLavel()
{
    return ipText->text();
}

void IPv4Address::parseIPAddress()
{
    QWidget *aux;
    ipFormatedValue_ = ipValue_.leftJustified(IP_LENGHT, '_');

    int32_t index = 0;
    for (int32_t i = 0; i < hboxLayout->count(); i++)
    {
        aux = hboxLayout->itemAt(i)->widget();
        if (aux->metaObject()->className() == QLineEdit::staticMetaObject.className() )
        {
            static_cast<QLineEdit*>(aux)->setText(ipFormatedValue_.mid(index, OCTET_SIZE));
            index += (int32_t)OCTET_SIZE;
        }
    }
}

IPv4Address::~IPv4Address()
{
  delete vboxLayout;
  delete spacerItem;
  delete hboxLayout;
  delete ipText;
  delete octet_1;
  delete label_2;
  delete octet_2;
  delete label_3;
  delete octet_3;
  delete label_4;
  delete octet_4;
  delete spacerItem1;

  vboxLayout  = 0;
  spacerItem  = 0;
  hboxLayout  = 0;
  ipText      = 0;
  octet_1     = 0;
  label_2     = 0;
  octet_2     = 0;
  label_3     = 0;
  octet_3     = 0;
  label_4     = 0;
  octet_4     = 0;
  spacerItem1 = 0;
}
