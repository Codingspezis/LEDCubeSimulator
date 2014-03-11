#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace ledcubesimulator::gui;

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    communicator(new network::Communicator(37373))
{
    ui->setupUi(this);
    connect(communicator, SIGNAL(receivedLEDCubeState(quint8*)), ui->cubeWidget, SLOT(setState(quint8*)));
    connect(ui->checkAxes, SIGNAL(toggled(bool)), ui->cubeWidget, SLOT(showAxes(bool)));
    connect(ui->checkGrid, SIGNAL(toggled(bool)), ui->cubeWidget, SLOT(showGrid(bool)));
    connect(ui->checkLEDs, SIGNAL(toggled(bool)), ui->cubeWidget, SLOT(showInactiveLEDs(bool)));
    connect(ui->spinLEDSize, SIGNAL(valueChanged(double)), this, SLOT(onLEDSizeChange(double)));
}

MainWindow::~MainWindow() {
    delete communicator;
    delete ui;
}

void MainWindow::onLEDSizeChange(double s) {
    ui->cubeWidget->setLedSize(s);
}
