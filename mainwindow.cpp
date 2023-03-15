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
    ui->pushButton->setIconSize(ui->pushButton->rect().size());

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
    QPixmap pic("C:\\Users\\Преподаватель\\Desktop\\756079611261831.jpg");
    //pic = pic.scaled(200,200);
    /*QMatrix rm;
    rm.rotate(45.0);
    */
    QTransform tm;
    tm.rotate(r);
    ui->label->setPixmap(pic.scaled(200,200).transformed(tm));
    r += 5;
}


void MainWindow::on_pb_login_clicked()
{
    if(login == nullptr){
        login = new Form();
        /*
        connect(login, SIGNAL(on_autorization()),
                this, SLOT(on_autorization_slot()));
        */

        connect(login, &Form::on_autorization,
                this, &MainWindow::on_autorization_slot);

        login->show();
    }
}

void MainWindow::on_autorization_slot()
{
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

