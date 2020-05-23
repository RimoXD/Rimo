#ifndef QINGCCC_H
#define QINGCCC_H

#include <QDialog>
namespace Ui {
class Qingccc;
}

class Qingccc : public QDialog
{
    Q_OBJECT

public:
    explicit Qingccc(QWidget *parent = nullptr);
    ~Qingccc();

signals:
    void qingccc();
private:
    Ui::Qingccc *ui;
};

#endif // QINGCCC_H
