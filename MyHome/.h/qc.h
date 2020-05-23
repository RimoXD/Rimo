#ifndef QC_H
#define QC_H

#include <QDialog>
#include "ui1.h"
namespace Ui {
class QingC;
}

class QingC : public QDialog
{
    Q_OBJECT

public:
    explicit QingC(QWidget *parent = nullptr);
    ~QingC();

private:
    Ui::QingC *ui;
};

#endif // QC_H
