#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // find the trainPositionLabel from statusBar
    trainPositionLabel = new QLabel(this);
    ui->statusbar->addWidget(trainPositionLabel);
    trainPositionLabel->setText(QString("Train Position: %1 km").arg(trainPosition));

    // timer initialization
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTrainPosition()));

    // start the timer with 1 second interval
    timer->start(1000);

    // initialize train speed and position
    trainSpeed = 0;
    trainPosition = 0;

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_startButton_clicked()));
    connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(on_pauseButton_clicked()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(on_stopButton_clicked()));

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
    trainPositionLabel->setText(QString("Train Position: %1 km").arg(trainPosition));
}

void MainWindow::updateTrainPosition()
{
    trainPosition += trainSpeed; // update train position
    trainPositionLabel->setText(QString("Train Position: %1 km").arg(trainPosition)); // update train position label
}
