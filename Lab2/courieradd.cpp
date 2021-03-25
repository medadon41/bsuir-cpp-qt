#include "courieradd.h"
#include "ui_courieradd.h"

CourierAdd::CourierAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourierAdd)
{
    ui->setupUi(this);
}

CourierAdd::~CourierAdd()
{
    delete ui;
}

void CourierAdd::on_pushButton_FormSave2_clicked()
{
    accept();
    return;
}

void CourierAdd::on_lineEdit_FormCap_textEdited(const QString &arg1)
{
     cr_temp->capacity = (ui->lineEdit_FormCap->text()).toInt();
}

void CourierAdd::on_timeEdit_FormCrFrom_editingFinished()
{
    cr_temp->workTime = ui->timeEdit_FormCrFrom->time().toString("HH:mm");
    cr_temp->workTime.append(" - " + ui->timeEdit_FormCrTo->time().toString("HH:mm"));
}

void CourierAdd::on_timeEdit_FormCrTo_editingFinished()
{
    cr_temp->workTime = ui->timeEdit_FormCrFrom->time().toString("HH:mm");
    cr_temp->workTime.append(" - " + ui->timeEdit_FormCrTo->time().toString("HH:mm"));
}

void CourierAdd::on_lineEdit_FormName_textEdited(const QString &arg1)
{
   cr_temp->crName = ui->lineEdit_FormName->text();
}

void CourierAdd::on_lineEdit_FormNum_editingFinished()
{
   cr_temp->crNumber = (ui->lineEdit_FormNum->text()).toInt();
}
