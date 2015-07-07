/********************************************************************************
** Form generated from reading ui file 'test.ui'
**
** Created: Tue 30. Jun 16:08:16 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>

QT_BEGIN_NAMESPACE

class Ui_testClass
{
public:

    void setupUi(QDialog *testClass)
    {
    if (testClass->objectName().isEmpty())
        testClass->setObjectName(QString::fromUtf8("testClass"));
    testClass->resize(400, 300);

    retranslateUi(testClass);

    QMetaObject::connectSlotsByName(testClass);
    } // setupUi

    void retranslateUi(QDialog *testClass)
    {
    testClass->setWindowTitle(QApplication::translate("testClass", "test", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(testClass);
    } // retranslateUi

};

namespace Ui {
    class testClass: public Ui_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
