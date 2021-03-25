#ifndef COURIERADD_H
#define COURIERADD_H

#include <QDialog>
#include "courier.h"

namespace Ui {
class CourierAdd;
}

class CourierAdd : public QDialog
{
    Q_OBJECT

public:
    explicit CourierAdd(QWidget *parent = nullptr);
    ~CourierAdd();
    courier *cr_temp = new courier;

private slots:
    void on_pushButton_FormSave2_clicked();

    void on_lineEdit_FormCap_textEdited(const QString &arg1);

    void on_timeEdit_FormCrFrom_editingFinished();

    void on_timeEdit_FormCrTo_editingFinished();

    void on_lineEdit_FormName_textEdited(const QString &arg1);

    void on_lineEdit_FormNum_editingFinished();

private:
    Ui::CourierAdd *ui;
};

#endif // COURIERADD_H
