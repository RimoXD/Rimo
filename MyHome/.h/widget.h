#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui1.h"
#include "sorry.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void setbuild(int i);//进入分窗口槽函数

private:
    Ui::Widget *ui;

    //建立分功能窗口
    ui1 ui1;
    Sorry sorry;

    int i=1;//进入窗口条件

};
#endif // WIDGET_H
