#ifndef SORRY_H
#define SORRY_H

#include <QDialog>

namespace Ui {
class Sorry;
}

class Sorry : public QDialog
{
    Q_OBJECT

public:
    explicit Sorry(QWidget *parent = nullptr);
    ~Sorry();

private:
    Ui::Sorry *ui;
};

#endif // SORRY_H
