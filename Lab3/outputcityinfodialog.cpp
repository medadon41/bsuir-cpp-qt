#include "outputcityinfodialog.h"
#include "ui_outputcityinfodialog.h"

outputCityInfoDialog::outputCityInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outputCityInfoDialog)
{
    ui->setupUi(this);
}

outputCityInfoDialog::~outputCityInfoDialog()
{
    delete ui;
}



void outputCityInfoDialog::on_inputButton_clicked()
{
    emit cityName(ui->cityEdit->text());
    close();
}
