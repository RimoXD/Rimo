#include "qingchu.h"
#include "ui_qingchu.h"

QingChu::QingChu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QingChu)
{
    ui->setupUi(this);
}

QingChu::~QingChu()
{
    delete ui;
}
