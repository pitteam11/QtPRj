#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);



}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    log = ui->lineEdit->text();
    pas = ui->lineEdit_2->text();
    if(log.length() > 0 && pas.length() > 0){
        this->hide();
        emit on_autorization();
    }
}

