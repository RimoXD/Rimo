#include "ui1.h"
#include "ui_ui1.h"
#include "error.h"
#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QRegExp>
#include <qmath.h>
ui1::ui1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui1)
{
    ui->setupUi(this);
    setWindowTitle("MyHome");
    ui->groupBoxhunhe->hide();
    ui->groupBoxbenxi->hide();
    ui->groupBoxbenjin->hide();
    ui->groupBoxhunhebenxi->hide();
    ui->groupBoxhunhebenjin->hide();

    //选择商代公积金，与混合贷两个界面分离
    {
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
          [=](){
        leibie=ui->comboBox->currentIndex();
        if(leibie==2)
        {
            ui->comboBox_21->setCurrentIndex(leibie);
            ui->groupBoxshangye->hide();
            ui->groupBoxhunhe->show();
        }
    });
    connect(ui->comboBox_21, QOverload<int>::of(&QComboBox::currentIndexChanged),
          [=](){
        leibie=ui->comboBox_21->currentIndex();
        if(leibie==0||leibie==1)
        {
            ui->comboBox->setCurrentIndex(leibie);
            ui->groupBoxhunhe->hide();
            ui->groupBoxshangye->show();
        }
    });
    }

    //下拉条 
    {
    cb1=ui->comboBox;
    cb2=ui->comboBox_2;
    cb3=ui->comboBox_3;
    cb4=ui->comboBox_4;
    cb21=ui->comboBox_21;
    cb22=ui->comboBox_22;
    }

    //行输入
    {
    line1=ui->lineEdit;
    line2=ui->lineEdit_2;
    line3=ui->lineEdit_3;
    line21=ui->lineEdit_21;
    line22=ui->lineEdit_22;
    line23=ui->lineEdit_23;
    line24=ui->lineEdit_24;
    line31=ui->lineEdit_31;
    line32=ui->lineEdit_32;
    line33=ui->lineEdit_33;
    line34=ui->lineEdit_34;
    line35=ui->lineEdit_35;
    line36=ui->lineEdit_36;
    }

    //设置正则表达式，限制行编辑只能输入数字
    {
    QRegExp regExp("^[0-9]*[1-9][0-9]*$");//限制正整数
    QRegExp regExp1("^[0-9]+(.[0-9]{2})?$");//限制两位小数
    line1->setValidator(new QRegExpValidator(regExp,line1));
    line2->setValidator(new QRegExpValidator(regExp,line2));
    line3->setValidator(new QRegExpValidator(regExp1,line3));
    line21->setValidator(new QRegExpValidator(regExp,line3));
    line22->setValidator(new QRegExpValidator(regExp1,line3));
    line23->setValidator(new QRegExpValidator(regExp,line3));
    line24->setValidator(new QRegExpValidator(regExp1,line3));
    }

    //push按钮
    {
    pb1=ui->pushButton;
    pb2=ui->pushButton_2;
    pb3=ui->pushButton_3;
    pb21=ui->pushButton_21;
    pb22=ui->pushButton_22;
    }

    //radio按钮
    {
    rb1=ui->radioButton;
    rb2=ui->radioButton_2;
    rb21=ui->radioButton_5;
    rb22=ui->radioButton_6;
    }

    //敬请期待
    connect(cb2, QOverload<int>::of(&QComboBox::currentIndexChanged),
          [=](){
        if(cb2->currentIndex())
            cb2->setCurrentIndex(0);
    });

    //返回主界面信号机制
    {
    connect(pb3,&QPushButton::clicked,[=](){
        close();
        emit backmain();
    });
    }

    //选择还款方式
    {
    connect(rb1,&QRadioButton::clicked,[=](){
        hkfangshi1=1;
        Qingchu();
    });
    connect(rb2,&QRadioButton::clicked,[=](){
        hkfangshi1=2;
        Qingchu();
    });
    connect(rb21,&QRadioButton::clicked,[=](){
        hkfangshi2=1;
        Qingchu();
    });
    connect(rb22,&QRadioButton::clicked,[=](){
        hkfangshi2=2;
        Qingchu();
    });
    }

    //点击确定，传递参数
    connect(pb1,&QPushButton::clicked,[=](){
        Linetomath();
        jisuan(Chengshu(),Nianshu(),danjia,mianji,lilv,hkfangshi1);
    });
    connect(pb21,&QPushButton::clicked,[=](){
        Linetomath();
        jisuan2(Nianshu(),sdje,sdll,gjjje,gjjll,hkfangshi2);
    });

    //点击清除，清空界面
    connect(pb2,&QPushButton::clicked,[=](){
        Qingchu();
    });
    connect(pb22,&QPushButton::clicked,[=](){
        Qingchu();
    });

    ui->groupBoxbenxi->setStyleSheet("QGroupBox{border:none}");
    ui->groupBoxhunhe->setStyleSheet("QGroupBox{border:none}");
    ui->groupBoxbenjin->setStyleSheet("QGroupBox{border:none}");
    ui->groupBoxshangye->setStyleSheet("QGroupBox{border:none}");
    ui->groupBoxhunhebenxi->setStyleSheet("QGroupBox{border:none}");
    ui->groupBoxhunhebenjin->setStyleSheet("QGroupBox{border:none}");

}

ui1::~ui1()
{
    delete ui;
}

void ui1::jisuan(double chengshu,int nianshu,int danjia,int mianji,double lilv,int hkfangshi)
{
    float shoufu,yuegong,dkze,lixi,hkze,yueshu;
    int zj;
    if(danjia>0&&mianji>0&&lilv>0)
    {
    if(hkfangshi==1)//等额本息
    {
        yueshu=nianshu*12;
        zj=danjia*mianji;
        dkze=zj*chengshu;
        shoufu=zj-dkze;
        yuegong=dkze*(lilv/1200.0)*qPow((1+lilv/1200.0),yueshu)/(qPow((1+lilv/1200.0),yueshu)-1);
        hkze=yuegong*yueshu;
        lixi=hkze-dkze;
        line31->setText(QString::number((int)shoufu));
        line32->setText(QString::number((int)yuegong));
        line33->setText(QString::number((int)dkze));
        line34->setText(QString::number((int)lixi));
        line35->setText(QString::number((int)hkze));
        line36->setText(QString::number((int)yueshu));
        ui->groupBoxbenxi->show();
    }
    else if(hkfangshi==2)//等额本金
    {
        yueshu=nianshu*12;
        zj=danjia*mianji;
        dkze=zj*chengshu;
        shoufu=zj-dkze;
        lixi=(yueshu+1)*dkze*(lilv/2400.0);
        hkze=lixi+dkze;
        float i=yueshu;
        float ciyue,chae;
        yuegong=dkze/i+dkze*lilv/1200.0;
        ciyue=dkze/i+(dkze-dkze/i)*lilv/1200.0;
        chae=yuegong-ciyue;
        ui->lineEdit41->setText(QString::number((int)shoufu));
        ui->lineEdit42->setText(QString::number((int)yuegong));
        ui->lineEdit43->setText(QString::number((int)chae));
        ui->lineEdit44->setText(QString::number((int)dkze));
        ui->lineEdit45->setText(QString::number((int)lixi));
        ui->lineEdit46->setText(QString::number((int)hkze));
        ui->lineEdit47->setText(QString::number((int)yueshu));
        ui->groupBoxbenjin->show();

    }
    }
    else
        error.exec();
}

void ui1::jisuan2(float nianshu,float sdje,float sdll,float gjjje,float gjjll,int hkfangshi)
{
    float zdk=sdje+gjjje;
    float yueshu=nianshu*12;
    float yuegong1,yuegong2;
    float zlixi,zhk;
    if(sdje>0&&sdll>0&&gjjje>0&&gjjll>0)
    {
    if(hkfangshi==1)//等额本息
    {
        yuegong1=sdje*(sdll/1200.0)*qPow((1+sdll/1200.0),yueshu)/(qPow((1+sdll/1200.0),yueshu)-1);
        yuegong2=gjjje*(gjjll/1200.0)*qPow((1+gjjll/1200.0),yueshu)/(qPow((1+gjjll/1200.0),yueshu)-1);
        zlixi=(yuegong1+yuegong2)*yueshu-zdk;
        zhk=zdk+zlixi;
        ui->lineEdit_50->setText(QString::number((int)(yuegong1+yuegong2)));
        ui->lineEdit_51->setText(QString::number((int)zdk));
        ui->lineEdit_52->setText(QString::number((int)zlixi));
        ui->lineEdit_53->setText(QString::number((int)zhk));
        ui->lineEdit_54->setText(QString::number((int)yueshu));
        ui->groupBoxhunhebenxi->show();
    }
    else if(hkfangshi==2)//等额本金
    {
        float cyue1,cyue2,chae,lixi1,lixi2;
        yuegong1=sdje/yueshu+sdje*sdll/1200.0;
        cyue1=sdje/yueshu+(sdje-sdje/yueshu)*sdll/1200.0;
        yuegong2=gjjje/yueshu+gjjje*gjjll/1200.0;
        cyue2=gjjje/yueshu+(gjjje-gjjje/yueshu)*gjjll/1200.0;
        chae=yuegong1+yuegong2-cyue1-cyue2;
        lixi1=(yueshu+1)*sdje*(sdll/2400.0);
        lixi2=(yueshu+1)*gjjje*(gjjll/2400.0);
        zlixi=lixi1+lixi2;
        zhk=zlixi+zdk;
        ui->lineEdit_55->setText(QString::number((int)yuegong1+(int)yuegong2));
        ui->lineEdit_56->setText(QString::number((int)chae));
        ui->lineEdit_57->setText(QString::number((int)zdk));
        ui->lineEdit_58->setText(QString::number((int)zlixi));
        ui->lineEdit_59->setText(QString::number((int)zhk));
        ui->lineEdit_60->setText(QString::number((int)yueshu));
        ui->groupBoxhunhebenjin->show();
    }
    }
    else
        error.exec();
}

float ui1::Leibie()
{
    //传递贷款类型
    return cb1->currentIndex();
}

float ui1::Fangshi()
{
    //传递贷款方式
    if(cb2->currentIndex()==0)
    fangshi=1;
    else if(cb2->currentIndex()==1)
    fangshi=2;
    return fangshi;
}

float ui1::Chengshu()
{
    //传递按揭成数
    float i;
    if(leibie==3)
    {
        i=cb22->currentIndex();
        chengshu=0.8-i*0.05;
    }
    else
    {
        i=cb3->currentIndex();
        chengshu=0.8-i*0.05;
    }
    return chengshu;
}

float ui1::Nianshu()
{
    //传递按揭年数
    float i=0;
    if(Leibie()==2)
        i=ui->comboBox_22->currentIndex();
    else
        i=cb4->currentIndex();
    nianshu=25-i;
    return nianshu;
}

void ui1::Linetomath()
{
    danjia=line1->text().toFloat();
    mianji=line2->text().toFloat();
    lilv=line3->text().toFloat();
    sdje=line21->text().toFloat();
    sdll=line22->text().toFloat();
    gjjje=line23->text().toFloat();
    gjjll=line24->text().toFloat();
}

void ui1::Qingchu()
{
    line1->setText("");
    line2->setText("");
    line3->setText("");
    line21->setText("");
    line22->setText("");
    line23->setText("");
    line24->setText("");
    line31->setText("");
    line32->setText("");
    line33->setText("");
    line34->setText("");
    line35->setText("");
    line36->setText("");
    ui->lineEdit41->setText("");
    ui->lineEdit42->setText("");
    ui->lineEdit43->setText("");
    ui->lineEdit44->setText("");
    ui->lineEdit45->setText("");
    ui->lineEdit46->setText("");
    ui->lineEdit47->setText("");
    ui->lineEdit_50->setText("");
    ui->lineEdit_51->setText("");
    ui->lineEdit_52->setText("");
    ui->lineEdit_53->setText("");
    ui->lineEdit_54->setText("");
    ui->lineEdit_55->setText("");
    ui->lineEdit_56->setText("");
    ui->lineEdit_57->setText("");
    ui->lineEdit_58->setText("");
    ui->lineEdit_59->setText("");
    ui->lineEdit_60->setText("");
    ui->groupBoxbenxi->hide();
    ui->groupBoxbenjin->hide();
    ui->groupBoxhunhebenxi->hide();
    ui->groupBoxhunhebenjin->hide();
}
