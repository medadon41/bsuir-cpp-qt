#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QTimer>
#include <QScrollBar>
#include "figure.h"
#include "polygon.h"
#include "circle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsScene *scenePaint;

    bool isCircle;
    bool isGrid;
    double zoomLevel = 0;
    const double zoomFactor = 1.1;
    bool paintMode;

    QGraphicsItemGroup *grid;
    Polygon *polygon;
    Circle *circle;
    Figure *figure;

    void setPerimeter();
    void setArea();

    void setGrid();
    void setFigures();
    void setScene();
    void reset();

private slots:
    void on_radioButtonCircle_pressed();
    void on_radioButtonTriangle_pressed();
    void on_radioButtonSquare_pressed();
    void on_radioButtonPolygon_pressed();
    void on_radioButtonFigure_pressed();



    //
    void on_a1_pressed();
    //



    void on_horizontalSliderRotation_valueChanged(int value);
    void on_horizontalSliderSize_valueChanged(int value);
    void on_spinBox_valueChanged(int arg1);

    void applyChanges();
    void on_pushButton_clicked();
    void on_test_clicked();
};
#endif // MAINWINDOW_H
