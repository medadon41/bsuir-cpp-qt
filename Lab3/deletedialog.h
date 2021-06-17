#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>

namespace Ui {
class deleteDialog;
}

class deleteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit deleteDialog(QWidget *parent = nullptr);
    ~deleteDialog();

private:
    Ui::deleteDialog *ui;
signals:
    void deleteNumber(int index);
private slots:
    void on_inputButton_clicked();
};


#endif // DELETEDIALOG_H
