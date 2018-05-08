/********************************************************************************
** Form generated from reading UI file 'childwindow1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILDWINDOW1_H
#define UI_CHILDWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QComboBox *comboBox_2;
    QComboBox *comboBox;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLabel *label_2;
    QCommandLinkButton *backtomainwindow;
    QLabel *label;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(652, 489);
        comboBox_2 = new QComboBox(Form);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(167, 160, 201, 22));
        comboBox = new QComboBox(Form);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(167, 110, 201, 22));
        toolButton = new QToolButton(Form);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(377, 110, 51, 21));
        toolButton_2 = new QToolButton(Form);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(377, 160, 51, 21));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 160, 61, 20));
        backtomainwindow = new QCommandLinkButton(Form);
        backtomainwindow->setObjectName(QStringLiteral("backtomainwindow"));
        backtomainwindow->setGeometry(QRect(507, 420, 141, 41));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 110, 61, 20));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        toolButton->setText(QApplication::translate("Form", "...", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("Form", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "\350\276\223\345\207\272\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        backtomainwindow->setText(QApplication::translate("Form", "\350\277\224\345\233\236\344\270\273\347\252\227\345\217\243", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "\350\276\223\345\205\245\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILDWINDOW1_H
