#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

void MainWindow::setPortNameFromSettings()
{
    QString portName = readSetting("COM");
    for(int i = ui->comboBox->count() - 1; i >= 0; --i)
    {
        ui->comboBox->setCurrentIndex(i);
        if(ui->comboBox->currentText() == portName)
        {
            break;
        }
    }
}

void MainWindow::setPortSpeedFromSettings()
{
    QString speed = readSetting("COM_Speed");
    bool ok;
    int value = speed.toInt(&ok);
    if(!ok)
    {
        value = 115200;
    }
    ui->lineEditSpeed->setText(QString::number(value));
}

void MainWindow::saveSetting(const QString & setName, const QString & setValue)
{
    QSettings settings("SetterSettings.ini", QSettings::IniFormat);
    settings.setValue(setName, setValue);
}

QString MainWindow::readSetting(const QString &setName)
{
    QSettings settings("SetterSettings.ini", QSettings::IniFormat);
    return settings.value(setName).toString();
}

void MainWindow::setValidators()
{
    QRegularExpression rx("[0-9]+");
    QValidator * validator = new QRegularExpressionValidator(rx, this);
    ui->lineEditSpeed->setValidator(validator);
}

void MainWindow::savePortNameToSettings(int ind)
{
    QString value = ui->comboBox->itemText(ind);
    saveSetting("COM", value);
}

void MainWindow::savePortSpeedToSettings()
{
    saveSetting("COM_Speed", ui->lineEditSpeed->text());
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setValidators();
    on_pushButtonRefresh_clicked();
    setPortNameFromSettings();
    setPortSpeedFromSettings();
    connect(ui->comboBox, &QComboBox::activated, this, &MainWindow::savePortNameToSettings);
    connect(ui->lineEditSpeed, &QLineEdit::editingFinished, this, &MainWindow::savePortSpeedToSettings);
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

