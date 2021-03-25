#include "orderadd.h"
#include "ui_orderadd.h"

OrderAdd::OrderAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderAdd)
{
    ui->setupUi(this);
    ui->dateEdit_Form->setCalendarPopup(true);
    ui->dateEdit_Form->setDate(QDate::currentDate());
}

OrderAdd::~OrderAdd()
{
    delete ui;
}

void OrderAdd::on_pushButton_FormSave_clicked()
{
    accept();
    return;
}

void OrderAdd::on_lineEdit_FormNum_textEdited(const QString &arg1)
{
    or_temp->ordNumber = (ui->lineEdit_FormNum->text()).toInt();
}

void OrderAdd::on_lineEdit_FormAdr_textEdited(const QString &arg1)
{
    or_temp->address = ui->lineEdit_FormAdr->text();
}

void OrderAdd::on_dateEdit_Form_editingFinished()
{
    or_temp->deliveryRange = ui->dateEdit_Form->date().toString("dd.MM.yyyy");
    or_temp->deliveryRange.append(' ' + ui->timeEdit_FormOrFrom->time().toString("HH:mm"));
    or_temp->deliveryRange.append(" - " + ui->timeEdit_FormOrFrom->time().toString("HH:mm"));
}

void OrderAdd::on_timeEdit_FormOrFrom_editingFinished()
{
    or_temp->deliveryRange = ui->dateEdit_Form->date().toString("dd.MM.yyyy");
    or_temp->deliveryRange.append(' ' + ui->timeEdit_FormOrFrom->time().toString("HH:mm"));
    or_temp->deliveryRange.append(" - " + ui->timeEdit_FormOrTo->time().toString("HH:mm"));
}

void OrderAdd::on_timeEdit_FormOrTo_editingFinished()
{
    or_temp->deliveryRange = ui->dateEdit_Form->date().toString("dd.MM.yyyy");
    or_temp->deliveryRange.append(' ' + ui->timeEdit_FormOrFrom->time().toString("HH:mm"));
    or_temp->deliveryRange.append(" - " + ui->timeEdit_FormOrTo->time().toString("HH:mm"));
}

void OrderAdd::on_lineEdit_FormWeight_textEdited(const QString &arg1)
{
    or_temp->weight = (ui->lineEdit_FormWeight->text()).toInt();
}
