#include "mainwindow_g.h"
#include "ui_mainwindow_g.h"

#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*btn1 = new QPushButton(ui->centralwidget);
    btn1->setVisible(true);
    btn1->setGeometry(QRect(200,200, 150, 150));
    btn1->setText("New BUTTON0");
    ui->centralwidget->repaint();*/
}

MainWindow::~MainWindow()
{
    delete btn1;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
        QPainter painter(this);
        painter.setPen(QPen(Qt::blue,6));
        painter.drawLine(10, 10, 100, 100);
        painter.setPen(QPen(Qt::red,6));
        QBrush brush = painter.brush();
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        painter.setBrush(brush);
        painter.drawEllipse(140,140, 50, 170);
}

