#include ".h/widget.h"
#include <QApplication>
#include <QTime>
#include ".h/welcome1.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //显示开始界面
    Welcome1 *wel=new Welcome1;
    delete wel;

    Widget w;
    w.show();

    return a.exec();
}
