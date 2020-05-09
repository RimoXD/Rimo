#include "qc.h"
#include "ui_qc.h"
#include "ui1.h"

QingC::QingC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QingC)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);//无边框

    connect(ui->pushButton,&QPushButton::clicked,&ui1,&ui1::Qingchu);

}

QingC::~QingC()
{
    delete ui;
}
