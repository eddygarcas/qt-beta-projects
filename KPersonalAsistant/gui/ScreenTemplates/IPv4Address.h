#ifndef IPV4ADDRESS_MOC_H_
#define IPV4ADDRESS_MOC_H_

/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IPv4Address.h
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


#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtCore/QString>
#include <QtGui/QKeyEvent>
#include <QtCore/QtDebug>

#define IP_LENGHT 12
#define OCTET_SIZE 3

/**This widget is used to edit a IP v4 address.*/
class IPv4Address : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString addressTextLavel READ addressTextLavel WRITE setAddressTextLavel)

public:
  /**
   * Widget constructor
   * 
   * @param *parent Widget parent
   */
  IPv4Address(QWidget *parent = 0);

  /**
   * Class destructor
   */
  virtual ~IPv4Address();
  
  /**
   * Inserts a ip address in line edit box
   */
  void setIPAddress(QString _ipValue);
  
  /**
   * Retreives the ip address value
   */
  QString getIPAddress();

  /**
   * Defines a text value of ip address line edit.
   * 
   * @param _addressLavel 
   */
  void setAddressTextLavel(QString _addressLavel);
  
  /**
   * Returns the address text labvel
   * 
   * @return QString
   */
  QString addressTextLavel();

  

public slots:

  /**
   * Addes full IP address value
   * 
   * @param _ipValue
   */
  void append_ip_address(QString _ipValue);

  /**
   * Adds a character into IP line edit
   * 
   * @param QChar 
   */
  void append_ip_address_value(QChar _ipValue);

  /**
   * Removes last character
   */
  void remove_last_ip_address_value();

  /**
   * Sends the end edition signal.
   */
  void finished_edition();
  
signals:

    /**
     * This signal will be called each time value IP change.
     * 
     * @para QString
     */
  void ipAddressChanged(QString);

protected:
  
  /**
   * It Join IP line edit boxes into unique string 
   */
  void parseIPAddress();
 
private:
  
  QVBoxLayout *vboxLayout;
  QSpacerItem *spacerItem;
  QHBoxLayout *hboxLayout;
  QLabel *ipText;
  QLineEdit *octet_1;
  QLabel *label_2;
  QLineEdit *octet_2;
  QLabel *label_3;
  QLineEdit *octet_3;
  QLabel *label_4;
  QLineEdit *octet_4;
  QSpacerItem *spacerItem1;
  QString ipFormatedValue_;
  QString ipValue_;
  
};

#endif //IPV4ADDRESS
