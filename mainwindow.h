#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pb_login_clicked();
    void on_autorization_slot();

private:
    Ui::MainWindow *ui;
    Form *login = nullptr;

    void show_simple_nums(int up_val);
    int r = 0;
};
#endif // MAINWINDOW_H
