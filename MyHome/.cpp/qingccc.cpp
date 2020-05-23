#include ".h/qingccc.h"
#include "ui_qingccc.h"
Qingccc::Qingccc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Qingccc)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//无边框

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->close();
        emit qingccc();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->close();
    });
}

Qingccc::~Qingccc()
{
    delete ui;
}
