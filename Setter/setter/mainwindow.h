#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialconnection.h"
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    SerialConnection serialConnection;
    void setPortNameFromSettings();
    void setPortSpeedFromSettings();
    void saveSetting(const QString & setName, const QString & setValue);
    QString readSetting(const QString & setName);
    void setValidators();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonRefresh_clicked();
    void savePortNameToSettings(int ind);
    void savePortSpeedToSettings();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
