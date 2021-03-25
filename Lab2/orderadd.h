#ifndef ORDERADD_H
#define ORDERADD_H

#include <QDialog>
#include "mainwindow.h"
#include "order.h"

namespace Ui {
class OrderAdd;
}

class OrderAdd : public QDialog
{
    Q_OBJECT

public:
    explicit OrderAdd(QWidget *parent = nullptr);
    ~OrderAdd();
    order *or_temp = new order;

private slots:

    void on_pushButton_FormSave_clicked();

    void on_lineEdit_FormNum_textEdited(const QString &arg1);

    void on_lineEdit_FormAdr_textEdited(const QString &arg1);

    void on_dateEdit_Form_editingFinished();

    void on_timeEdit_FormOrFrom_editingFinished();

    void on_timeEdit_FormOrTo_editingFinished();

    void on_lineEdit_FormWeight_textEdited(const QString &arg1);

private:
    Ui::OrderAdd *ui;
};

#endif // ORDERADD_H
