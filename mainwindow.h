#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
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
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void on_stopButton_clicked();
    void updateTrainPosition();

private:
    QLabel *trainPositionLabel;
    Ui::MainWindow *ui;
    QTimer *timer;
    int trainSpeed;
    int trainPosition;
};
#endif // MAINWINDOW_H
