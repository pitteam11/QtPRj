#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    void on_le_result_editingFinished();

private:
    Ui::MainWindow *ui;
    int val1;
    int val2;
    char sign;

    QTimer* timer;

    void generate_ex();
    void show_ex();
    void check_ex();

private slots:
    void on_timer();

};
#endif // MAINWINDOW_H
