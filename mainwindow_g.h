#ifndef MAINWINDOW_G_H
#define MAINWINDOW_G_H

#include <QMainWindow>
#include <QPushButton>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton* btn1 = nullptr;
    void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_G_H
