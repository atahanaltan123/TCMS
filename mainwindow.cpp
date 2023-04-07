#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // find the trainPositionLabel from statusBar
    trainPositionLabel = ui->statusbar->findChild<QLabel*>("trainPositionLabel");

    // timer initialization
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTrainPosition()));

    // start the timer with 1 second interval
    timer->start(1000);

    // initialize train speed and position
    trainSpeed = 0;
    trainPosition = 0;

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_startButton_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pauseButton_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_stopButton_clicked()));
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
    trainPositionLabel->setText(QString::number(trainPosition) + " km");
}

void MainWindow::updateTrainPosition()
{
    trainPosition += trainSpeed; // update train position
    trainPositionLabel->setText(QString::number(trainPosition) + " km"); // update train position label
}
