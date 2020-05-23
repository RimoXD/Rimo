#include ".h/welcome1.h"
#include "ui_welcome1.h"
#include <QTime>

Welcome1::Welcome1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome1)
{
    ui->setupUi(this);


    setWindowFlags(Qt::FramelessWindowHint);//无边框

    this->show();

    QTime dieTime = QTime::currentTime().addMSecs(1500/*阻塞时间调节*/);

    while( QTime::currentTime() < dieTime )

    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

Welcome1::~Welcome1()
{
    delete ui;
}
