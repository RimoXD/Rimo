/********************************************************************************
** Form generated from reading UI file 'error.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_H
#define UI_ERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Error
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Error)
    {
        if (Error->objectName().isEmpty())
            Error->setObjectName(QString::fromUtf8("Error"));
        Error->resize(417, 251);
        buttonBox = new QDialogButtonBox(Error);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 210, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Error);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 90, 211, 71));
        label_2 = new QLabel(Error);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, -20, 531, 291));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/timg (1).jfif")));
        label_2->raise();
        buttonBox->raise();
        label->raise();

        retranslateUi(Error);
        QObject::connect(buttonBox, SIGNAL(accepted()), Error, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Error, SLOT(reject()));

        QMetaObject::connectSlotsByName(Error);
    } // setupUi

    void retranslateUi(QDialog *Error)
    {
        Error->setWindowTitle(QCoreApplication::translate("Error", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Error", "\350\257\267\350\276\223\345\205\245\345\220\210\346\263\225\346\225\260\346\215\256(\342\227\217'\342\227\241'\342\227\217).AVI", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Error: public Ui_Error {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_H
