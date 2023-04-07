#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // timer initialization
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTrainPosition()));

    // start the timer with 1 second interval
    timer->start(1000);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    trainSpeed = 5; // set train speed
    trainPosition = 0; // reset train position
    timer->start(1000); // start timer with 1 second interval
}

void MainWindow::on_pauseButton_clicked()
{
    timer->stop(); // stop timer
}

void MainWindow::on_stopButton_clicked()
{
    timer->stop(); // stop timer
    trainPosition = 0; // reset train position
    ui->trainPositionLabel->setText(QString::number(trainPosition) + " km");
}

void MainWindow::updateTrainPosition()
{
    trainPosition += trainSpeed; // update train position
    ui->trainPositionLabel->setText(QString::number(trainPosition) + " km"); // update train position label
}
