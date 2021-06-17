#ifndef OUTPUTNUMBERDIALOG_H
#define OUTPUTNUMBERDIALOG_H

#include <QDialog>

namespace Ui {
class outputNumberDialog;
}

class outputNumberDialog : public QDialog
{
    Q_OBJECT

public:
    explicit outputNumberDialog(QWidget *parent = nullptr);
    ~outputNumberDialog();

private:
    Ui::outputNumberDialog *ui;
signals:
    void number(const QString &number);
private slots:
    void on_inputButton_clicked();
};

#endif // OUTPUTNUMBERDIALOG_H
