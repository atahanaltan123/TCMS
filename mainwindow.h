#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ui_mainwindow.h"

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
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void on_stopButton_clicked();
    void updateTrainPosition();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int trainSpeed;
    int trainPosition;
};

#endif // MAINWINDOW_H
