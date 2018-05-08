/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *centralWidget;
    QPushButton *fileselect;
    QPushButton *functionkey;
    QPushButton *report;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QStringLiteral("main_window"));
        main_window->resize(789, 631);
        centralWidget = new QWidget(main_window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        fileselect = new QPushButton(centralWidget);
        fileselect->setObjectName(QStringLiteral("fileselect"));
        fileselect->setGeometry(QRect(50, 360, 111, 51));
        functionkey = new QPushButton(centralWidget);
        functionkey->setObjectName(QStringLiteral("functionkey"));
        functionkey->setGeometry(QRect(590, 360, 111, 51));
        report = new QPushButton(centralWidget);
        report->setObjectName(QStringLiteral("report"));
        report->setGeometry(QRect(320, 360, 111, 51));
        main_window->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(main_window);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        main_window->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(main_window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        main_window->setStatusBar(statusBar);

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QMainWindow *main_window)
    {
        main_window->setWindowTitle(QApplication::translate("main_window", "QtGuiApplication_test", Q_NULLPTR));
        fileselect->setText(QApplication::translate("main_window", "\346\226\207\344\273\266\351\200\211\346\213\251", Q_NULLPTR));
        functionkey->setText(QApplication::translate("main_window", "\345\212\237\350\203\275\351\224\256", Q_NULLPTR));
        report->setText(QApplication::translate("main_window", "\350\257\212\346\226\255\346\212\245\345\221\212", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
