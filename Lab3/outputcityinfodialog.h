#ifndef OUTPUTCITYINFODIALOG_H
#define OUTPUTCITYINFODIALOG_H

#include <QDialog>

namespace Ui {
class outputCityInfoDialog;
}

class outputCityInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit outputCityInfoDialog(QWidget *parent = nullptr);
    ~outputCityInfoDialog();

private:
    Ui::outputCityInfoDialog *ui;
signals:
    void cityName(const QString &cityName);
private slots:
    void on_inputButton_clicked();
};

#endif // OUTPUTCITYINFODIALOG_H
