#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QDebug>
#include <QTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.setInterval(1000);
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));

    timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    int y0 = this->height()/2;
    int x0 = this->width()/2;
    int x1 = x0 + 100 * sin(angle);
    int y1 = y0 - 100 * cos(angle);
    painter.setPen(QPen(QColor(100, 79, 91),3));
    painter.drawLine(x0, y0, x1, y1);

    static const QPoint hourHand[3] = {
           QPoint(7, 8),
           QPoint(-7, 8),
           QPoint(0, -40)
       };
       static const QPoint minuteHand[3] = {
           QPoint(7, 8),
           QPoint(-7, 8),
           QPoint(0, -70)
       };

       QColor hourColor(127, 0, 127);
       QColor minuteColor(0, 127, 127, 191);

       int side = qMin(width(), height());
       QTime time = QTime::currentTime();
   //! [10]

   //! [11]
       //QPainter painter(this);
   //! [11] //! [12]
       painter.setRenderHint(QPainter::Antialiasing);
   //! [12] //! [13]
       painter.translate(width() / 2, height() / 2);
   //! [13] //! [14]
       painter.scale(side / 200.0, side / 200.0);
   //! [9] //! [14]

   //! [15]
       painter.setPen(Qt::NoPen);
   //! [15] //! [16]
       painter.setBrush(hourColor);
   //! [16]

   //! [17] //! [18]
       painter.save();
   //! [17] //! [19]
       painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
       painter.drawConvexPolygon(hourHand, 3);
       painter.restore();
   //! [18] //! [19]

   //! [20]
       painter.setPen(hourColor);
   //! [20] //! [21]

       for (int i = 0; i < 12; ++i) {
           painter.drawLine(88, 0, 96, 0);
           painter.rotate(30.0);
       }
   //! [21]

   //! [22]
       painter.setPen(Qt::NoPen);
   //! [22] //! [23]
       painter.setBrush(minuteColor);

   //! [24]
       painter.save();
       painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
       painter.drawConvexPolygon(minuteHand, 3);
       painter.restore();
   //! [23] //! [24]

   //! [25]
       painter.setPen(minuteColor);
   //! [25] //! [26]

   //! [27]
       for (int j = 0; j < 60; ++j) {
           if ((j % 5) != 0)
               painter.drawLine(92, 0, 96, 0);
           painter.rotate(6.0);
       }
   //! [27]

}

void MainWindow::on_timer(){
    angle += (2 * M_PI / 60);
    this->repaint();
    //qDebug() << angle;
}
