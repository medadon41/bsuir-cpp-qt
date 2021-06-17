#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"
#include <vector>
#include "convinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exitButton_clicked();

    void on_addNumberButton_clicked();

    void on_outputListButton_clicked();

    void on_outputNumberButton_clicked();

    void numberInfo(const QString &number);

    void cityInfo(const QString &cityName);

    void deleteEl(const int &index);

    void on_outputCityButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<char> digitSymbols = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    List<ConvInfo> convInfoList;

};
#endif // MAINWINDOW_H
