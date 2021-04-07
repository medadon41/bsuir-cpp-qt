#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "order.h"
#include "courier.h"
#include "orderadd.h"
#include "courieradd.h"
#include "ordersarray.h"
#include "couriersarray.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QString>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    //------ disabling all the fields until a file is opened--------
    ui->comboBox->setDisabled(true);
    ui->lineEdit_address->setDisabled(true);
    ui->lineEdit_weight->setDisabled(true);
    ui->dateEdit->setDisabled(true);
    ui->timeEdit_From->setDisabled(true);
    ui->timeEdit_To->setDisabled(true);
    ui->pushButtonSave->setDisabled(true);
    ui->pushButton_AddOrder->setDisabled(true);
    ui->pushButton_Dist->setDisabled(true);
    ui->pushButton_CrOrd->setDisabled(true);
    ui->pushButton_Unable->setDisabled(true);
    //----- couriers form -----
    ui->comboBox_2->setDisabled(true);
    ui->lineEdit_name->setDisabled(true);
    ui->lineEdit_capacity->setDisabled(true);
    ui->timeEdit_WorkFrom->setDisabled(true);
    ui->timeEdit_WorkTo->setDisabled(true);
    ui->pushButton_Save2->setDisabled(true);
    ui->pushButton_AddCr->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonOpen_clicked()
{
    ui->comboBox->clear();
    ordersFilename = QFileDialog::getOpenFileName(this,
        tr("Выберите текстовый файл"), "D://", tr("Text Files (*.txt)"));
    QFile file(ordersFilename);
    QTextStream in(&file);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
        return;
    } else {
        int linesAmount = 0;
         MainWindow::n = 0;
       while (!in.atEnd()) {
           int t_ordNumber;
           QString t_address;
           QString t_deliveryRange;
           double t_weight;
         for(int i = 0; i < 4; i++) {
             QString line = in.readLine();
             linesAmount += 1;
             switch(i) {
               case 0: {
                 t_ordNumber = line.toInt();
                 break;
               }
               case 1: {
                 t_address = line;
                 break;
               }
               case 2: {
                 t_deliveryRange = line;
                 break;
               }
               case 3: {
                 t_weight = line.toDouble();
                 break;
               }
            }
            o_arr->set_elem(n, t_ordNumber, t_address, t_deliveryRange, t_weight);
         }
         MainWindow::n++;
      }
       for (int j=0; j < n; j++) {
          QString number = QString::number(o_arr->get_elem(j).ordNumber);
          ui->comboBox->addItem(number);
       }
       ui->comboBox->setCurrentIndex(-1);
       ui->comboBox->setDisabled(false);
    }
    if(couriersFilename != nullptr) {
        ui->pushButton_Dist->setDisabled(false);
    }
    file.flush();
    file.close();
}

void MainWindow::on_comboBox_activated(int index)
{
    if(ui->comboBox->currentIndex() != -1) {
        ui->lineEdit_address->setDisabled(false);
        ui->lineEdit_weight->setDisabled(false);
        ui->dateEdit->setDisabled(false);
        ui->timeEdit_From->setDisabled(false);
        ui->timeEdit_To->setDisabled(false);
        ui->pushButtonSave->setDisabled(false);
        ui->pushButton_AddOrder->setDisabled(false);
    }
    ui->lineEdit_address->setText(o_arr->get_elem(index).address);
    ui->dateEdit->setDate(QDate::fromString(o_arr->get_elem(index).deliveryRange.mid(0, 10), "dd.MM.yyyy"));
    ui->dateEdit->setCalendarPopup(true);
    ui->timeEdit_From->setTime(QTime::fromString(o_arr->get_elem(index).deliveryRange.mid(11, 5), "hh:mm"));
    ui->timeEdit_To->setTime(QTime::fromString(o_arr->get_elem(index).deliveryRange.mid(19, 5), "hh:mm"));
    ui->lineEdit_weight->setText(QString::number(o_arr->get_elem(index).weight));
}

void MainWindow::on_pushButtonSave_clicked()
{
    QFile file(ordersFilename);
    QTextStream out(&file);
    file.open(QFile::WriteOnly);
    for (int i = 0; i < MainWindow::n; i++) {
        out << QString::number(o_arr->get_elem(i).ordNumber) << '\n';
        out << o_arr->get_elem(i).address << '\n';
        out << o_arr->get_elem(i).deliveryRange << '\n';
        out << QString::number(o_arr->get_elem(i).weight) << '\n';
    }
}

void MainWindow::on_lineEdit_address_textEdited(const QString &arg1)
{
    o_arr->set_adr(ui->comboBox->currentIndex(), ui->lineEdit_address->text());
}

void MainWindow::on_lineEdit_weight_textEdited(const QString &arg1)
{
    o_arr->set_double(ui->comboBox->currentIndex(), (ui->lineEdit_weight->text()).toDouble());
}


void MainWindow::on_dateEdit_editingFinished()
{
    o_arr->set_delRng(ui->comboBox->currentIndex(), (ui->dateEdit->date().toString("dd.MM.yyyy") + ' ' + ui->timeEdit_From->time().toString("HH:mm") + " - " + ui->timeEdit_To->time().toString("HH:mm")));
}


void MainWindow::on_timeEdit_From_editingFinished()
{
    o_arr->set_delRng(ui->comboBox->currentIndex(), (ui->dateEdit->date().toString("dd.MM.yyyy") + ' ' + ui->timeEdit_From->time().toString("HH:mm") + " - " + ui->timeEdit_To->time().toString("HH:mm")));
}

void MainWindow::on_timeEdit_To_editingFinished()
{
    o_arr->set_delRng(ui->comboBox->currentIndex(), (ui->dateEdit->date().toString("dd.MM.yyyy") + ' ' + ui->timeEdit_From->time().toString("HH:mm") + " - " + ui->timeEdit_To->time().toString("HH:mm")));
}

void MainWindow::on_pushButton_Open2_clicked()
{
    ui->comboBox->clear();
    couriersFilename = QFileDialog::getOpenFileName(this,
        tr("Выберите текстовый файл"), "D://", tr("Text Files (*.txt)"));
    QFile file(couriersFilename);
    QTextStream in(&file);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
        return;
    } else {
        int linesAmount = 0;
         MainWindow::k = 0;
       while (!in.atEnd()) {
           int t_crNumber;
           QString t_name;
           QString t_workTime;
           int t_capacity;
         for(int i = 0; i < 4; i++) {
             QString line = in.readLine();
             linesAmount += 1;
             switch(i) {
               case 0: {
                 t_crNumber = line.toInt();
                 break;
               }
               case 1: {
                 t_name = line;
                 break;
               }
               case 2: {
                 t_workTime = line;
                 break;
               }
               case 3: {
                 t_capacity = line.toInt();
                 break;
               }
            }
            c_arr->set_elem(k, t_crNumber, t_name, t_workTime, t_capacity);
         }
         MainWindow::k++;
      }
       for (int j=0; j < k; j++) {
          QString number = QString::number(c_arr->get_elem(j).crNumber);
          ui->comboBox_2->addItem(number);
       }
       ui->comboBox_2->setCurrentIndex(-1);
       ui->comboBox_2->setDisabled(false);
    }
    file.flush();
    file.close();
    if(ordersFilename != nullptr) {
        ui->pushButton_Dist->setDisabled(false);
    }
}

void MainWindow::on_comboBox_2_activated(int index)
{
    if(ui->comboBox_2->currentIndex() != -1) {
        ui->lineEdit_name->setDisabled(false);
        ui->lineEdit_capacity->setDisabled(false);
        ui->timeEdit_WorkFrom->setDisabled(false);
        ui->timeEdit_WorkTo->setDisabled(false);
        ui->pushButton_Save2->setDisabled(false);
        ui->pushButton_AddCr->setDisabled(false);
    }
    ui->lineEdit_name->setText(c_arr->get_elem(index).crName);
    ui->timeEdit_WorkFrom->setTime(QTime::fromString(c_arr->get_elem(index).workTime.mid(0, 5), "hh:mm"));
    ui->timeEdit_WorkTo->setTime(QTime::fromString(c_arr->get_elem(index).workTime.mid(8, 5), "hh:mm"));
    ui->lineEdit_capacity->setText(QString::number(c_arr->get_elem(index).capacity));
}

void MainWindow::on_lineEdit_name_textEdited(const QString &arg1)
{
   c_arr->set_name(ui->comboBox_2->currentIndex(), ui->lineEdit_name->text());
}

void MainWindow::on_lineEdit_capacity_textEdited(const QString &arg1)
{
   c_arr->set_int(ui->comboBox_2->currentIndex(), (ui->lineEdit_capacity->text()).toInt());
}

void MainWindow::on_timeEdit_WorkFrom_editingFinished()
{
   c_arr->set_workTime(ui->comboBox_2->currentIndex(), (ui->timeEdit_WorkFrom->time().toString("HH:mm") + " - " + ui->timeEdit_WorkTo->time().toString("HH:mm")));
}

void MainWindow::on_timeEdit_WorkTo_editingFinished()
{
    c_arr->set_workTime(ui->comboBox_2->currentIndex(), (ui->timeEdit_WorkFrom->time().toString("HH:mm") + " - " + ui->timeEdit_WorkTo->time().toString("HH:mm")));
}

void MainWindow::on_pushButton_Save2_clicked()
{
    QFile file(couriersFilename);
    QTextStream out(&file);
    file.open(QFile::WriteOnly);
    for (int i = 0; i < MainWindow::k; i++) {
        out << QString::number(c_arr->get_elem(i).crNumber) << '\n';
        out << c_arr->get_elem(i).crName << '\n';
        out << c_arr->get_elem(i).workTime << '\n';
        out << QString::number(c_arr->get_elem(i).capacity) << '\n';
    }
}


void MainWindow::on_pushButton_clicked()
{
    o_arr->del_arr();
    c_arr->del_arr();
    qApp->exit();
}

void MainWindow::on_pushButton_AddOrder_clicked()
{
    OrderAdd dlg(this);

    if(dlg.exec() == QDialog::Accepted) {
    int _n = MainWindow::n++;
    int f_ordNumber = dlg.or_temp->ordNumber;
    QString f_address = dlg.or_temp->address;
    QString f_deliveryRange = dlg.or_temp->deliveryRange;
    double f_weight = dlg.or_temp->weight;
    o_arr->set_elem(_n, f_ordNumber, f_address, f_deliveryRange, f_weight);
    QString _number = QString::number(o_arr->get_elem(_n).ordNumber);
    ui->comboBox->addItem(_number);
    }


}

void MainWindow::on_pushButton_AddCr_clicked()
{
    CourierAdd dlg(this);

    if(dlg.exec() == QDialog::Accepted) {
    int _k = MainWindow::k++;
    int f_crNumber = dlg.cr_temp->crNumber;
    QString f_crName = dlg.cr_temp->crName;
    QString f_workTime = dlg.cr_temp->workTime;
    int f_capacity = dlg.cr_temp->capacity;
    c_arr->set_elem(_k, f_crNumber, f_crName, f_workTime, f_capacity);
    QString _number = QString::number(c_arr->get_elem(_k).crNumber);
    ui->comboBox_2->addItem(_number);
    }
}

void MainWindow::distOrders() {
    for(int i = 0; i < MainWindow::k; i++) {
        int _o = 0;
        QTime _workFrom = QTime::fromString(c_arr->get_elem(i).workTime.mid(0, 5), "hh:mm");
        QTime _workTo = QTime::fromString(c_arr->get_elem(i).workTime.mid(8, 5), "hh:mm");
        for(int j = 0; j < MainWindow::n; j++) {
            QTime _deliverFrom = QTime::fromString(o_arr->get_elem(j).deliveryRange.mid(11, 5), "hh:mm");
            QTime _deliverTo= QTime::fromString(o_arr->get_elem(j).deliveryRange.mid(19, 5), "hh:mm");
            if(!o_arr->get_elem(j).isDistributed) {
            if(o_arr->get_elem(j).weight < c_arr->get_elem(i).capacity && _workFrom <= _deliverFrom && _workTo >= _deliverTo) {
                if(c_arr->get_elem(i).currCap + o_arr->get_elem(j).weight <= c_arr->get_elem(i).capacity) {
                    c_arr->set_ord(i, _o++, o_arr->get_elem(j));
                    o_arr->set_bool(j, true);
                    c_arr->add_cap(i, o_arr->get_elem(j).weight);
                    c_arr->inc_ords(i);
             }
            }
        }
    }
    }
}

void MainWindow::on_pushButton_Dist_clicked()
{
    distOrders();
    ui->textEditInfo->clear();
    for(int i = 0; i < MainWindow::k; i++) {
    ui->textEditInfo->insertPlainText("Номер курьера: ");
    ui->textEditInfo->insertPlainText(QString::number(c_arr->get_elem(i).crNumber) + "\n");
    ui->textEditInfo->insertPlainText("Заказы на доставку: ");
    for(int j = 0; j < c_arr->get_elem(i).distdOr; j++) {
    ui->textEditInfo->insertPlainText(QString::number(c_arr->get_elem(i).orders[j].ordNumber) + " ");
    }
    ui->textEditInfo->insertPlainText("\n~~~~~~~~~~~~~~~~~\n");
    }
    ui->pushButton_CrOrd->setDisabled(false);
    ui->pushButton_Unable->setDisabled(false);
}

void MainWindow::on_pushButton_CrOrd_clicked()
{
    for(int r = 0; r < MainWindow::k; r++) {
    for (int i = 0; i < c_arr->get_elem(r).distdOr - 1; i++) {
            for (int j = 0; j < c_arr->get_elem(r).distdOr - i - 1; j++) {
                if (QTime::fromString(c_arr->get_elem(r).orders[j].deliveryRange.mid(11, 5), "hh:mm") > QTime::fromString(c_arr->get_elem(r).orders[j+1].deliveryRange.mid(11, 5), "hh:mm")) {
                    order temp = c_arr->get_elem(r).orders[j];
                    c_arr->set_ord(r, j, c_arr->get_elem(r).orders[j+1]);
                    c_arr->set_ord(r, ++j, temp);
                }
            }
        }
    }
    ui->textEditInfo->clear();
    ui->textEditInfo->insertPlainText("Заказы курьера №" + QString::number(c_arr->get_elem(ui->comboBox_2->currentIndex()).crNumber) + ":");
    for(int j = 0; j < c_arr->get_elem(ui->comboBox_2->currentIndex()).distdOr; j++) {
    ui->textEditInfo->insertPlainText('\n' + QString::number(c_arr->get_elem(ui->comboBox_2->currentIndex()).orders[j].ordNumber));
    ui->textEditInfo->insertPlainText('\n' + c_arr->get_elem(ui->comboBox_2->currentIndex()).orders[j].deliveryRange.mid(11));
    ui->textEditInfo->insertPlainText("\n~~~~~~~~~~~~~~~~~");
    }
}

void MainWindow::on_pushButton_Unable_clicked()
{
    ui->textEditInfo->clear();
    ui->textEditInfo->insertPlainText("Заказы, которые не могут быть доставлены в срок: \n");
    for(int i = 0; i < MainWindow::n; i++) {
        if(o_arr->get_elem(i).isDistributed == false) {
            ui->textEditInfo->insertPlainText(QString::number(o_arr->get_elem(i).ordNumber) + "\n");
        }
    }
}

