#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lb_val1->setText("");
    ui->lb_val2->setText("");
    ui->lb_sign->setText("");
    ui->le_result->setText("");
    qsrand(QTime::currentTime().msec());
    timer = new QTimer();
    //connect(timer, &QTimer::timeout, this, &MainWindow::on_timer);
    connect(timer, SIGNAL(timeout), this,
            SLOT([this]{timer->stop(); check_ex(); generate_ex(); show_ex();}));
    timer->setInterval(5 * 1000);
    generate_ex();
    show_ex();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generate_ex(){
    val1 = qrand() % 20;
    val2 = qrand() % 20;
    sign = '+';
}

void MainWindow::show_ex(){
    ui->lb_val1->setText(QString("%0").arg(val1));
    ui->lb_val2->setText(QString("%0").arg(val2));
    ui->lb_sign->setText(QString(sign));
    timer->start();
}

void MainWindow::check_ex()
{
    bool is_convert = false;
    int res = (ui->le_result->text()).toInt(&is_convert);
    bool is_res = false;
    if(is_convert){
        switch(sign){
            case '+': is_res = (res == val1 + val2); break;
            default: is_res = false;
        }
    }
    if(is_res){
        ui->lb_color->setStyleSheet("background-color: rgb(0, 255, 0);");
        generate_ex();
        show_ex();
    } else {
        ui->lb_color->setStyleSheet("background-color: rgb(255, 0, 0);");
    }
}


void MainWindow::on_le_result_editingFinished()
{
    check_ex();
    ui->le_result->setText("");
}

void MainWindow::on_timer(){
    timer->stop();
    check_ex();
    generate_ex();
    show_ex();
}

