#include "error.h"
#include "ui_error.h"

Error::Error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Error)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//无边框
}

Error::~Error()
{
    delete ui;
}
