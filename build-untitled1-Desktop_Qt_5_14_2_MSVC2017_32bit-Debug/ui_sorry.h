/********************************************************************************
** Form generated from reading UI file 'sorry.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORRY_H
#define UI_SORRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Sorry
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Sorry)
    {
        if (Sorry->objectName().isEmpty())
            Sorry->setObjectName(QString::fromUtf8("Sorry"));
        Sorry->resize(420, 262);
        buttonBox = new QDialogButtonBox(Sorry);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 200, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Sorry);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 90, 201, 71));
        label_2 = new QLabel(Sorry);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 541, 261));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/timg (1).jfif")));
        label_2->raise();
        buttonBox->raise();
        label->raise();

        retranslateUi(Sorry);
        QObject::connect(buttonBox, SIGNAL(accepted()), Sorry, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Sorry, SLOT(reject()));

        QMetaObject::connectSlotsByName(Sorry);
    } // setupUi

    void retranslateUi(QDialog *Sorry)
    {
        Sorry->setWindowTitle(QCoreApplication::translate("Sorry", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Sorry", "\345\267\245\347\250\213\345\270\210\346\255\243\345\234\250\345\212\252\345\212\233\345\274\200\345\217\221ing.JPG", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Sorry: public Ui_Sorry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORRY_H
