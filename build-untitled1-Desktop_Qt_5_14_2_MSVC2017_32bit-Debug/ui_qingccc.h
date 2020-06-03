/********************************************************************************
** Form generated from reading UI file 'qingccc.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QINGCCC_H
#define UI_QINGCCC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Qingccc
{
public:
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Qingccc)
    {
        if (Qingccc->objectName().isEmpty())
            Qingccc->setObjectName(QString::fromUtf8("Qingccc"));
        Qingccc->resize(419, 241);
        label_2 = new QLabel(Qingccc);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 90, 101, 41));
        label = new QLabel(Qingccc);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -30, 441, 301));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/timg (1).jfif")));
        pushButton = new QPushButton(Qingccc);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 190, 61, 24));
        pushButton_2 = new QPushButton(Qingccc);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 190, 61, 24));
        label->raise();
        label_2->raise();
        pushButton->raise();
        pushButton_2->raise();

        retranslateUi(Qingccc);

        QMetaObject::connectSlotsByName(Qingccc);
    } // setupUi

    void retranslateUi(QDialog *Qingccc)
    {
        Qingccc->setWindowTitle(QCoreApplication::translate("Qingccc", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Qingccc", "\345\215\263\345\260\206\346\270\205\351\231\244\346\225\260\346\215\256\357\274\201", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Qingccc", "YES", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Qingccc", "NO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qingccc: public Ui_Qingccc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QINGCCC_H
