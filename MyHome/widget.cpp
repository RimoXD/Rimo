#include "widget.h"
#include "./ui_widget.h"

#include <QDebug>
#include <QRadioButton>
#include <QTime>//实践阻塞头文件

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("MyHome");
    setFixedSize(328,394);
    ui->groupBox->setStyleSheet("QGroupBox{border:none}");


    //分窗口入口
    connect(ui->radioButton_1,&QRadioButton::clicked,[=](){
        i=1;
    });
    connect(ui->radioButton_2,&QRadioButton::clicked,[=](){
        i=2;
    });
    connect(ui->radioButton_3,&QRadioButton::clicked,[=](){
        i=3;
    });
    connect(ui->radioButton_4,&QRadioButton::clicked,[=](){
        i=4;
    });
    connect(ui->radioButton_5,&QRadioButton::clicked,[=](){
        i=5;
    });
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->setbuild(i);
    });

    //接收分界面返回信号，返回主界面
    connect(&ui1,&ui1::backmain,this,&QWidget::show);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::setbuild(int i)
{
    switch (i)
    {
        case 1:ui1.show();this->hide();break;
        case 2:
        case 3:
        case 4:
        case 5:sorry.exec();break;
        default:break;
    }

}
