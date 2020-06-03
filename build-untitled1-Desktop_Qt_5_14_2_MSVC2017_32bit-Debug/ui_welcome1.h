/********************************************************************************
** Form generated from reading UI file 'welcome1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME1_H
#define UI_WELCOME1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome1
{
public:
    QLabel *label;

    void setupUi(QWidget *Welcome1)
    {
        if (Welcome1->objectName().isEmpty())
            Welcome1->setObjectName(QString::fromUtf8("Welcome1"));
        Welcome1->resize(440, 292);
        label = new QLabel(Welcome1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -20, 441, 331));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/\346\227\240\346\240\207\351\242\230.jpg")));

        retranslateUi(Welcome1);

        QMetaObject::connectSlotsByName(Welcome1);
    } // setupUi

    void retranslateUi(QWidget *Welcome1)
    {
        Welcome1->setWindowTitle(QCoreApplication::translate("Welcome1", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Welcome1: public Ui_Welcome1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME1_H
