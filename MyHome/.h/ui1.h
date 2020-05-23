#ifndef UI1_H
#define UI1_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QRadioButton>
#include "error.h"
#include "qingccc.h"

namespace Ui {
class ui1;
}

class ui1 : public QWidget
{
    Q_OBJECT

public:
    explicit ui1(QWidget *parent = nullptr);
    ~ui1();

    //计算函数
    int leibie,fangshi,nianshu,danjia,mianji;
    int hkfangshi1=1;
    double chengshu,lilv;
    void jisuan(double chengshu,int nianshu,int danjia,int mianji,double lilv=4.75,int hkfangshi=1);
    float nianshu2,sdje,sdll,gjjje,gjjll;
    int hkfangshi2=1;
    void jisuan2(float nianshu,float sdje,float sdll,float gjjje,float gjjll,int hkfangshi=1);

    //转化数据
    float Leibie();
    float Fangshi();
    float Chengshu();
    float Nianshu();

    //行编辑中的QString转化为float
    void Linetomath();

    //清理数据
    void Qingchu();
signals:
    void backmain();//返回主界面信号
private:
    Ui::ui1 *ui;
    Error error;
    Qingccc woyao;
    QComboBox *cb1,*cb2,*cb3,*cb4,*cb21,*cb22;
    QLineEdit *line1,*line2,*line3,*line21,*line22,*line23,*line24;
    QLineEdit *line31,*line32,*line33,*line34,*line35,*line36;
    QPushButton *pb1,*pb2,*pb3,*pb21,*pb22;
    QRadioButton *rb1,*rb2,*rb21,*rb22;

};

#endif // UI1_H
