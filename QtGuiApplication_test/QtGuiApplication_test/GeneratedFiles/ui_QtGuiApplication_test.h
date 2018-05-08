/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication_test.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION_TEST_H
#define UI_QTGUIAPPLICATION_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication_testClass
{
public:
    QWidget *centralWidget;
    QPushButton *fileselect;
    QPushButton *functionkey;
    QPushButton *report;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication_testClass)
    {
        if (QtGuiApplication_testClass->objectName().isEmpty())
            QtGuiApplication_testClass->setObjectName(QStringLiteral("QtGuiApplication_testClass"));
        QtGuiApplication_testClass->resize(751, 469);
        centralWidget = new QWidget(QtGuiApplication_testClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        fileselect = new QPushButton(centralWidget);
        fileselect->setObjectName(QStringLiteral("fileselect"));
        fileselect->setGeometry(QRect(0, 360, 111, 51));
        functionkey = new QPushButton(centralWidget);
        functionkey->setObjectName(QStringLiteral("functionkey"));
        functionkey->setGeometry(QRect(310, 360, 111, 51));
        report = new QPushButton(centralWidget);
        report->setObjectName(QStringLiteral("report"));
        report->setGeometry(QRect(640, 360, 111, 51));
        QtGuiApplication_testClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplication_testClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 751, 23));
        QtGuiApplication_testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication_testClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApplication_testClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplication_testClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiApplication_testClass->setStatusBar(statusBar);

        retranslateUi(QtGuiApplication_testClass);

        QMetaObject::connectSlotsByName(QtGuiApplication_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication_testClass)
    {
        QtGuiApplication_testClass->setWindowTitle(QApplication::translate("QtGuiApplication_testClass", "QtGuiApplication_test", Q_NULLPTR));
        fileselect->setText(QApplication::translate("QtGuiApplication_testClass", "\346\226\207\344\273\266\351\200\211\346\213\251", Q_NULLPTR));
        functionkey->setText(QApplication::translate("QtGuiApplication_testClass", "\345\212\237\350\203\275\351\224\256", Q_NULLPTR));
        report->setText(QApplication::translate("QtGuiApplication_testClass", "\350\257\212\346\226\255\346\212\245\345\221\212", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication_testClass: public Ui_QtGuiApplication_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION_TEST_H
