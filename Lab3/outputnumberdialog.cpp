#include "outputnumberdialog.h"
#include "ui_outputnumberdialog.h"

outputNumberDialog::outputNumberDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outputNumberDialog)
{
    ui->setupUi(this);
}

outputNumberDialog::~outputNumberDialog()
{
    delete ui;
}

void outputNumberDialog::on_inputButton_clicked()
{
    emit number(ui->numberEdit->text());
    close();
}
