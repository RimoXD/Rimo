#include "sorry.h"
#include "ui_sorry.h"

Sorry::Sorry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sorry)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//无边框
}

Sorry::~Sorry()
{
    delete ui;
}
