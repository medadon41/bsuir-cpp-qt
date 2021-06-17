#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    queue = new RandomQueue();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAdd_clicked()
{
    queue->push(ui->lineEditAdd->text().toInt());

    ui->lineEditAdd->clear();
    update();
}

void MainWindow::on_pushButtonRemove_clicked()
{
    queue->pop();

    update();
}

void MainWindow::on_pushButtonNewRandomQueue_clicked()
{
    int count = ui->lineEditAmount->text().toInt();
    int lowerBound = ui->lineEditMin->text().toInt();
    int upperBound = ui->lineEditMax->text().toInt();

    queue = new RandomQueue(count, lowerBound, upperBound);

    ui->lineEditAmount->clear();
    ui->lineEditMax->clear();
    ui->lineEditMin->clear();
    update();
}

void MainWindow::on_pushButtonDeleteBetwMaxMin_clicked()
{
    queue->clearBetweenMinAndMax();

    update();
}

void MainWindow::on_lineEditAdd_textChanged()
{
    if (ui->lineEditAdd->text() != "")
        ui->pushButtonAdd->setEnabled(true);
    else
        ui->pushButtonAdd->setEnabled(false);
}

void MainWindow::update()
{
    QStringListModel *model = new QStringListModel(this);
    QStringList List;

    Node *current = queue->first;

    while (current != nullptr)
    {
        List << QString::number(current->value);
        current = current->next;
    }

    model->setStringList(List);

    ui->listView->setModel(model);
}


void MainWindow::on_checkEmpty_clicked()
{
    if(queue->isEmpty())
    {
        ui->lineEdit2->setText("В очереди нет элементов");
    }
    else
    {
        ui->lineEdit2->setText("В очереди есть элементы");
    }
}


void MainWindow::on_ouptutFirstEl_clicked()
{
    if(queue->isEmpty())
    {
        ui->lineEdit2->setText("Пусто, нету ничего, ни первого, ни второго...");
    }
    else
    {
        int str = queue->front();
        ui->lineEdit2->setText(QString::number(str));
    }
}
