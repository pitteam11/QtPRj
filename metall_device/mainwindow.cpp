#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    read_ini();
    ui->cb_metall->currentTextChanged("Сталь");
}

MainWindow::~MainWindow()
{
    bool ok = false;
    double h = ui->le_h->text().replace(',','.').toDouble(&ok);
    if(!ok) h = 0;
    double R = ui->le_R->text().replace(',','.').toDouble(&ok);
    if(!ok) R = 0;
    double r = ui->le_r->text().replace(',','.').toDouble(&ok);
    if(!ok) r = 0;
    double n = ui->le_n->text().replace(',','.').toInt(&ok);
    if(!ok) n = 0;
    QString metall = ui->cb_metall->currentText();

    //ini.metall_name = metall;
    ini.n = n;
    ini.R = R;
    ini.r = r;
    ini.h = h;
    write_ini();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool ok = false;
    double h = ui->le_h->text().replace(',','.').toDouble(&ok);
    if(!ok) return;
    double R = ui->le_R->text().replace(',','.').toDouble(&ok);
    if(!ok) return;
    double r = ui->le_r->text().replace(',','.').toDouble(&ok);
    if(!ok) return;
    double n = ui->le_n->text().replace(',','.').toInt(&ok);
    if(!ok) return;
    QString metall = ui->cb_metall->currentText();
    double S = (M_PI*R*R - n * M_PI*r*r);
    if (S < 0)
        return;
    double V = S * h;
    double m = ro * V;
    double price = m * ppg;

    ui->le_V->setText(QString("%0").arg(V));
    ui->le_m->setText(QString("%0").arg(m));
    ui->le_price->setText(QString("%0").arg(price));
}


void MainWindow::on_cb_metall_currentTextChanged(const QString &metall)
{
    if(metall == "Сталь"){
        ro = 7750;
        ppg = 52.07;
    } else if(metall == "Алюминий"){
        ro = 2700;
        ppg = 175.24;
    }
    ui->le_ro->setText(QString("%0").arg(ro));
    ui->le_ppg->setText(QString("%0").arg(ppg));
    ui->pushButton->click();
}

void MainWindow::read_ini(){
    FILE* pf = std::fopen(ini_file_name.toStdString().data(), "rb");
    std::fread(&ini, sizeof(ini), 1, pf);
    std::fclose(pf);
    ui->le_h->setText(QString("%0").arg(ini.h));
    ui->le_r->setText(QString("%0").arg(ini.r));
    ui->le_R->setText(QString("%0").arg(ini.R));
    ui->le_n->setText(QString("%0").arg(ini.n));
    //ui->cb_metall->currentTextChanged(ini.metall_name);
}

void MainWindow::write_ini(){
    FILE* pf = std::fopen(ini_file_name.toStdString().data(), "wb");
    std::fwrite(&ini, sizeof(ini), 1, pf);
    std::fclose(pf);
}

