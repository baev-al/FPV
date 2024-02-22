#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_pushButtonRefresh_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonRefresh_clicked()
{
    QStringList list = serialConnection.listPort();
    ui->comboBox->clear();
    for(const auto & item : list)
    {
        ui->comboBox->addItem(item);
    }
}

