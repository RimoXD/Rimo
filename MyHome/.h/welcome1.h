#ifndef WELCOME1_H
#define WELCOME1_H

#include <QWidget>

namespace Ui {
class Welcome1;
}

class Welcome1 : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome1(QWidget *parent = nullptr);
    ~Welcome1();

private:
    Ui::Welcome1 *ui;
};

#endif // WELCOME1_H
