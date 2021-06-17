#include "deletedialog.h"
#include "ui_deletedialog.h"

deleteDialog::deleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteDialog)
{
    ui->setupUi(this);
}

deleteDialog::~deleteDialog()
{
    delete ui;
}

void deleteDialog::on_inputButton_clicked()
{
    emit deleteNumber(ui->deleteNumberEdit->text().toInt());
    close();
}
