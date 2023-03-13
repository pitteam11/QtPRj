#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QThread>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    show_simple_nums(1000);
}

void MainWindow::show_simple_nums(int up_val)
{
    QString str;
    // const int up_val = 100;
    bool is_simple = true;
    for (int k = 2; k < up_val; ++k) {
        is_simple = true;
        for (int n = 2; n < (k/2+1); ++n) {
            if (k % n == 0) {
                is_simple = false;
                continue;
            }
        }
        if (is_simple){
            QThread::msleep(100);
            ui->textEdit->clear();
            ui->textEdit->append(QString("Numb: %1 %2").arg(k).arg(k*k));
            ui->textEdit->repaint();
        }
        //
        //cout << k << " ";

    }
    //	cout << endl;
    //ui->textEdit->append("Hello world");
}


void MainWindow::on_pushButton_2_clicked()
{
    //qDebug() << "hello I am console";
    if(login != nullptr){
        if(login->pas == "123"){
            ui->textEdit->append(QString("%1 login complite")
                                 .arg(login->log));
        } else {
            ui->textEdit->append(QString("wrong login"));
        }
        login->close();
        delete login;
        login = nullptr;
    }
}


void MainWindow::on_pb_login_clicked()
{
    if(login == nullptr){
        login = new Form();
        login->show();
    }
}

