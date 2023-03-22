#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Parametrs{
    double h;
    double r;
    double R;
    double n;
    //QString metall_name;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_cb_metall_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    Parametrs ini;

    void read_ini();
    void write_ini();

    const QString ini_file_name = "config.ini";

    double ro, ppg;
};
#endif // MAINWINDOW_H
