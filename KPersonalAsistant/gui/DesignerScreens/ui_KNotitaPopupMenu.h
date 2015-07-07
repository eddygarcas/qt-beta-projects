/********************************************************************************
** Form generated from reading ui file 'KNotitaPopupMenu.ui'
**
** Created: Fri 21. Nov 11:31:22 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_KNOTITAPOPUPMENU_H
#define UI_KNOTITAPOPUPMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionDelete;
    QAction *actionTrash_nota;
    QAction *actionChange_font;
    QAction *actionInsert_text;
    QAction *actionInsert_image;
    QAction *actionTo_text_file;
    QAction *actionTo_e_mail;
    QAction *action_Information;
    QAction *action_KNotita_User;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QMenu *menu_New;
    QMenu *menuSend;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(283, 242);
    actionNew = new QAction(MainWindow);
    actionNew->setObjectName(QString::fromUtf8("actionNew"));
    actionDelete = new QAction(MainWindow);
    actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
    actionTrash_nota = new QAction(MainWindow);
    actionTrash_nota->setObjectName(QString::fromUtf8("actionTrash_nota"));
    actionChange_font = new QAction(MainWindow);
    actionChange_font->setObjectName(QString::fromUtf8("actionChange_font"));
    actionInsert_text = new QAction(MainWindow);
    actionInsert_text->setObjectName(QString::fromUtf8("actionInsert_text"));
    actionInsert_image = new QAction(MainWindow);
    actionInsert_image->setObjectName(QString::fromUtf8("actionInsert_image"));
    actionTo_text_file = new QAction(MainWindow);
    actionTo_text_file->setObjectName(QString::fromUtf8("actionTo_text_file"));
    actionTo_text_file->setMenuRole(QAction::TextHeuristicRole);
    actionTo_e_mail = new QAction(MainWindow);
    actionTo_e_mail->setObjectName(QString::fromUtf8("actionTo_e_mail"));
    action_Information = new QAction(MainWindow);
    action_Information->setObjectName(QString::fromUtf8("action_Information"));
    action_KNotita_User = new QAction(MainWindow);
    action_KNotita_User->setObjectName(QString::fromUtf8("action_KNotita_User"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 283, 19));
    menu_New = new QMenu(menubar);
    menu_New->setObjectName(QString::fromUtf8("menu_New"));
    menu_New->setContextMenuPolicy(Qt::CustomContextMenu);
    menuSend = new QMenu(menu_New);
    menuSend->setObjectName(QString::fromUtf8("menuSend"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    menubar->addAction(menu_New->menuAction());
    menu_New->addAction(actionNew);
    menu_New->addAction(actionDelete);
    menu_New->addAction(actionTrash_nota);
    menu_New->addSeparator();
    menu_New->addAction(actionChange_font);
    menu_New->addSeparator();
    menu_New->addAction(actionInsert_text);
    menu_New->addSeparator();
    menu_New->addAction(menuSend->menuAction());
    menu_New->addSeparator();
    menu_New->addAction(action_Information);
    menuSend->addAction(actionTo_text_file);
    menuSend->addAction(actionTo_e_mail);
    menuSend->addAction(action_KNotita_User);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionNew->setText(QApplication::translate("MainWindow", "&New note", 0, QApplication::UnicodeUTF8));
    actionDelete->setText(QApplication::translate("MainWindow", "&Delete text", 0, QApplication::UnicodeUTF8));
    actionTrash_nota->setText(QApplication::translate("MainWindow", "&Trash note", 0, QApplication::UnicodeUTF8));
    actionChange_font->setText(QApplication::translate("MainWindow", "&Change font", 0, QApplication::UnicodeUTF8));
    actionInsert_text->setText(QApplication::translate("MainWindow", "&Import...", 0, QApplication::UnicodeUTF8));
    actionInsert_image->setText(QApplication::translate("MainWindow", "Insert image...", 0, QApplication::UnicodeUTF8));
    actionTo_text_file->setText(QApplication::translate("MainWindow", "&Text file", 0, QApplication::UnicodeUTF8));
    actionTo_e_mail->setText(QApplication::translate("MainWindow", "&Mail recipient", 0, QApplication::UnicodeUTF8));
    action_Information->setText(QApplication::translate("MainWindow", "Note &Information", 0, QApplication::UnicodeUTF8));
    action_KNotita_User->setText(QApplication::translate("MainWindow", "&KNotita User", 0, QApplication::UnicodeUTF8));
    menu_New->setTitle(QApplication::translate("MainWindow", "&Menu", 0, QApplication::UnicodeUTF8));
    menuSend->setTitle(QApplication::translate("MainWindow", "&Send To", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KNOTITAPOPUPMENU_H
