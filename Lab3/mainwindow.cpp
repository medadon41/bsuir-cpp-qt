#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "outputcityinfodialog.h"
#include "outputnumberdialog.h"
#include "deletedialog.h"
#include "list.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit->setCalendarPopup(true);
    ui->timeEdit->setTime(QTime::currentTime());
    ui->timeEdit->setCalendarPopup(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::on_addNumberButton_clicked()
{
    bool isMistake = false;
    try {
        if (ui->dateEdit->text().size() == 0 || ui->codeEdit->text().size() == 0 || ui->cityEdit->text().size() == 0 ||
            ui->timeEdit->text().size() == 0 || ui->rateEdit->text().size() == 0 || ui->cityNumberEdit->text().size() == 0 ||
            ui->abonentNumberEdit->text().size() == 0) {
            throw "Вы не проинициализировали все поля";
        }
        int numCount = 0;
        QString cityCodeTestStr = ui->codeEdit->text();
        for (int i = 0; i < cityCodeTestStr.size(); i++) {
            for (int j = 0; j < digitSymbols.size(); j++) {
                if (cityCodeTestStr[i] == digitSymbols[j]) {
                    numCount++;
                    break;
                }
            }
        }
        if (numCount != cityCodeTestStr.size()) {
            throw "Были введены неверные символы";
        }
    } catch (const char *ex) {
        QMessageBox::critical(this, "Ошибка", ex);
        isMistake =true;
    }
        if (!isMistake) {
            QString date = ui->dateEdit->text();
            int cityCode = ui->codeEdit->text().toInt();
            QString cityName = ui->cityEdit->text();
            QString timeOfConv = ui->timeEdit->text();
            QString rate = ui->rateEdit->text();
            QString cityNumber = ui->cityNumberEdit->text();
            QString abonentNumber = ui->abonentNumberEdit->text();
            ConvInfo convInfo(date, cityCode, cityName, timeOfConv, rate, cityNumber, abonentNumber);
            convInfoList.push_back(convInfo);
            QMessageBox::information(this, "Информация", "Информация о добавленном номере: \n" + convInfo.convInfoData());
            ui->dateEdit->setDate(QDate::currentDate());
            ui->codeEdit->setText("");
            ui->cityEdit->setText("");
            ui->timeEdit->setTime(QTime::currentTime());
            ui->rateEdit->setText("");
            ui->cityNumberEdit->setText("");
            ui->abonentNumberEdit->setText("");
        }
}

void MainWindow::on_outputListButton_clicked()
{
    if (convInfoList.getSize() != 0) {
        QString message;
        for (int i = 0; i < convInfoList.getSize(); i++) {
            message += convInfoList[i].convInfoDataRecord();
        }
        QMessageBox::information(this, "Информация", "Вывод списка объектов класса: \n" + message);
    } else {
        QMessageBox::critical(this, "Ошибка", "Невозможно вывести пустой список");
    }

}

void MainWindow::on_outputNumberButton_clicked()
{
    QMessageBox::StandardButton searchReply = QMessageBox::information(this, "Внимательно прочтите"
                             , "Вы хотите осуществить вывести всю информацию о введёном номере?"
                             , QMessageBox::Ok | QMessageBox::Cancel);
    try {
        if (convInfoList.getSize() != 0) {
            if (searchReply == QMessageBox::Ok) {
                outputNumberDialog *wnd = new outputNumberDialog(this);
                wnd->show();

                connect(wnd, SIGNAL(number(QString)), this, SLOT(numberInfo(QString)));
            }
        } else {
            throw "Вывод данных по номеру абонента невозможен, когда список пуст";
        }
    } catch (const char *ex) {
        QMessageBox::critical(this, "Ошибка", ex);
    }
}

void MainWindow::numberInfo(const QString &number) {
    std::vector<int> index;
    index.push_back(-1);
    QString message = "";
    QString strIndex;
    for (int i = 0; i < convInfoList.getSize(); i++) {
        if (convInfoList[i].getAbonentNumber() == number) {
            index[0] = 1;
            index.push_back(i);
        }
    }
    if (index[0] == -1) {
        QMessageBox::information(this, "Результаты поиска", "Ни одного совпадения не найдено");
    } else {
        for (int i = 1; i < index.size(); i++) {
            strIndex.setNum(index[i]);
            message += "Номер " + strIndex + " \n" +convInfoList[index[i]].convInfoDataRecord();
        }
        QMessageBox::information(this, "Результаты поиска", "Совпадения найдены с элементами:\n" + message);
    }
}

void MainWindow::on_outputCityButton_clicked()
{
    QMessageBox::StandardButton searchReply = QMessageBox::information(this, "Внимательно прочтите"
                             , "Вы хотите осуществить вывести всю информацию о введёном номере?"
                             , QMessageBox::Ok | QMessageBox::Cancel);
    try {
        if (convInfoList.getSize() != 0) {
            if (searchReply == QMessageBox::Ok) {
                outputCityInfoDialog *wnd = new outputCityInfoDialog(this);
                wnd->show();

                connect(wnd, SIGNAL(cityName(QString)), this, SLOT(cityInfo(QString)));
            }
        } else {
            throw "Вывод данных обо всех разговорах в городе невозможен, когда список пуст";
        }
    } catch (const char *ex) {
        QMessageBox::critical(this, "Ошибка", ex);
    }
}

void MainWindow::cityInfo(const QString &cityName) {
    std::vector<int> index;
    index.push_back(-1);
    QString message = "";
    QString strIndex;
    for (int i = 0; i < convInfoList.getSize(); i++) {
        if (convInfoList[i].getCityName() == cityName) {
            index[0] = 1;
            index.push_back(i);
        }
    }
    if (index[0] == -1) {
        QMessageBox::information(this, "Результаты поиска", "Ни одного совпадения не найдено");
    } else {
        for (int i = 1; i < index.size(); i++) {
            strIndex.setNum(index[i]);
            message += "Номер " + strIndex + " \n" +convInfoList[index[i]].convInfoDataRecord();
        }
        QMessageBox::information(this, "Результаты поиска", "Совпадения найдены с элементами:\n" + message);
    }
}

void MainWindow::on_deleteButton_clicked()
{
    QMessageBox::StandardButton searchReply = QMessageBox::information(this, "Внимательно прочтите"
                             , "Вы хотите осуществить вывести всю информацию о введёном номере?"
                             , QMessageBox::Ok | QMessageBox::Cancel);
    try {
        if (convInfoList.getSize() != 0) {
            if (searchReply == QMessageBox::Ok) {
                deleteDialog *wnd = new deleteDialog(this);
                wnd->show();

                connect(wnd, SIGNAL(deleteNumber(int)), this, SLOT(deleteEl(int)));
            }
        } else {
            throw "Удаление невозможно, так список пуст!\n";
        }
    } catch (const char *ex) {
        QMessageBox::critical(this, "Ошибка", ex);
    }
}

void MainWindow::deleteEl(const int &index) {
    convInfoList.removeAt(index);
}
