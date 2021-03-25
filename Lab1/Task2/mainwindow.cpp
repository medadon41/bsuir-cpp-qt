#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900, 550);
    setWindowTitle("Task2");

    setScene();
    setFigures();
    setGrid();

    ui->radioButtonCircle->setChecked(true);
    ui->spinBox->setEnabled(false);
    isCircle = true;
    applyChanges();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setScene()
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-ui->graphicsView->width()/2, -ui->graphicsView->height()/2, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->verticalScrollBar()->setEnabled(false);
    ui->graphicsView->horizontalScrollBar()->setEnabled(false);
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}

void MainWindow::setFigures()
{
    circle = new Circle();
    circle->setCenter({0,0});
    circle->setFlags();

    polygon = new Polygon();
    polygon->setCenter({0,0});
    polygon->setFlags();

    figure = new Figure();
    figure->setCenter({0,0});
    figure->setFlags();
    figure->paintMode = false;

    connect(polygon, SIGNAL(signalChanges()),this, SLOT(applyChanges()));
    connect(circle, SIGNAL(signalChanges()),this, SLOT(applyChanges()));
    connect(figure, SIGNAL(signalChanges()),this, SLOT(applyChanges()));
}

void MainWindow::reset()
{
    circle->~Circle();
    polygon->~Polygon();
    figure->~Figure();

    setFigures();

    ui->labelPerimeter->setText("Периметр: - мм");
    ui->labelArea->setText("Площадь: - мм кв");
    ui->horizontalSliderRotation->setValue(0);
    ui->horizontalSliderSize->setValue(6);
}


void MainWindow::setPerimeter()
{
    if (isCircle)
        ui->labelPerimeter->setText("Периметр: " + (QString::number(circle->getPerimeter()))  + " мм");
    else
        ui->labelPerimeter->setText("Периметр: " + (QString::number(polygon->getPerimeter()))  + " мм");
}

// S
void MainWindow::setArea()
{
    if (isCircle)
        ui->labelArea->setText("Площадь: " + QString::number(circle->getArea())  + " мм кв");
    else
        ui->labelArea->setText("Площадь: " + QString::number(polygon->getArea())  + " мм кв");
}


void MainWindow::on_horizontalSliderRotation_valueChanged(int value)
{
    ui->labelRotation->setText("Поворот: " + QString::number(value) + "'");
    if (!figure->paintMode)
    {
        if (isCircle)
            circle->rotation(value);
        else
            polygon->rotation(value);
    }
    else
        figure->rotation(value);

}

void MainWindow::on_horizontalSliderSize_valueChanged(int value)
{
    if (!figure->paintMode)
        ui->labelSize->setText("Радиус: " + QString::number(value/6) + " мм");
    else
        ui->labelSize->setText("Процент: " + QString::number((double)value/6/0.3) + " %");
    applyChanges();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    applyChanges();
}

void MainWindow::on_radioButtonCircle_pressed()
{
    reset();
    isCircle = true;

    ui->spinBox->setMinimum(0);
    ui->spinBox->setValue(0);
    ui->spinBox->setEnabled(false);
    ui->horizontalSliderSize->setValue(6);
    ui->horizontalSliderSize->setEnabled(true);
    ui->horizontalSliderRotation->setEnabled(true);

    applyChanges();
}

void MainWindow::on_radioButtonTriangle_pressed()
{
    reset();
    isCircle = false;

    ui->spinBox->setValue(3);
    ui->spinBox->setEnabled(false);
    ui->horizontalSliderSize->setValue(6);
    ui->horizontalSliderSize->setEnabled(true);
    ui->horizontalSliderRotation->setEnabled(true);

    applyChanges();
}

void MainWindow::on_radioButtonSquare_pressed()
{
    reset();
    isCircle = false;

    ui->spinBox->setValue(4);
    ui->spinBox->setEnabled(false);
    ui->horizontalSliderSize->setValue(6);
    ui->horizontalSliderSize->setEnabled(true);
    ui->horizontalSliderRotation->setEnabled(true);

    applyChanges();
}

void MainWindow::on_radioButtonPolygon_pressed()
{
    reset();
    isCircle = false;

    ui->spinBox->setValue(3);
    ui->spinBox->setEnabled(true);
    ui->spinBox->setMinimum(3);
    ui->horizontalSliderSize->setValue(6);
    ui->horizontalSliderSize->setEnabled(true);
    ui->horizontalSliderRotation->setEnabled(true);

    applyChanges();
}

void MainWindow::on_radioButtonFigure_pressed()
{
    reset();
    isCircle = false;

    figure->paintMode = true;
    figure->paintDone = false;

    ui->spinBox->setValue(0);
    ui->spinBox->setEnabled(false);
    ui->horizontalSliderSize->setValue(180); //середина - 100%
    ui->horizontalSliderSize->setEnabled(false);
    ui->horizontalSliderRotation->setEnabled(false);

    applyChanges();
}


void MainWindow::applyChanges()
{
    scene->removeItem(circle);
    scene->removeItem(polygon);
    scene->removeItem(figure);

    int n = ui->spinBox->value(); // для многоугольника
    int R = ui->horizontalSliderSize->value(); // для Радиуса и %

    if (!figure->paintMode)
    {
        if (isCircle)
        {
            circle->changeSize(n, R);
            scene->addItem(circle);
        }
        else
        {
            polygon->changeSize(n, R);
            scene->addItem(polygon);
        }

        setPerimeter();
        setArea();
    }
    else
    {
        if (figure->paintDone)
        {
            ui->horizontalSliderRotation->setEnabled(true);
            ui->horizontalSliderSize->setEnabled(true);
        }
        figure->changeSize(n, R/6);
        scene->addItem(figure);
    }
}


void MainWindow::setGrid()
{
    isGrid = true;
    grid = new QGraphicsItemGroup();
    QPen *penGrid = new QPen();
    penGrid->setBrush(QBrush(QColor(107,163,212)));
    penGrid->setStyle(Qt::SolidLine);
    penGrid->setCapStyle(Qt::RoundCap);
    penGrid->setWidth(1);
    for (int i = -820; i <= 820; i += 1) grid->addToGroup(scene->addLine(i, -630, i, 630, *penGrid));
    for (int i = -630; i <= 630; i += 1) grid->addToGroup(scene->addLine(-820, i, 820, i, *penGrid));
    scene->addItem(grid);
}


void MainWindow::on_test_clicked()
{
    ui->test->setText("Text2");
}
