#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "order.h"
#include "courier.h"
#include "ordersarray.h"
#include "couriersarray.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int n;
    int k;
    int o;
    QString ordersFilename;
    QString couriersFilename;

    OrdersArray *o_arr = new OrdersArray;
    CouriersArray *c_arr = new CouriersArray;

private slots:

    void on_pushButtonOpen_clicked();

    void on_pushButtonSave_clicked();

    void on_lineEdit_address_textEdited(const QString &arg1);

    void on_lineEdit_weight_textEdited(const QString &arg1);

    void on_dateEdit_editingFinished();

    void on_timeEdit_From_editingFinished();

    void on_timeEdit_To_editingFinished();

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_lineEdit_name_textEdited(const QString &arg1);

    void on_lineEdit_capacity_textEdited(const QString &arg1);

    void on_timeEdit_WorkFrom_editingFinished();

    void on_timeEdit_WorkTo_editingFinished();

    void on_pushButton_Open2_clicked();

    void on_pushButton_Save2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_AddOrder_clicked();

    void on_pushButton_AddCr_clicked();

    void distOrders();

    void on_pushButton_Dist_clicked();

    void on_pushButton_CrOrd_clicked();

    void on_pushButton_Unable_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
