#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialconnection.h"
#include <QSettings>
#include "structs.h"
#include "workerthread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    SetterMode mode;

    SerialConnection serialConnection;
    WorkerThread workerThread;

    void setPortNameFromSettings();
    void setPortSpeedFromSettings();
    void saveSetting(const QString & setName, const QString & setValue);
    QString readSetting(const QString & setName);
    void setValidators();
    void setMode();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonRefresh_clicked();
    void savePortNameToSettings(int ind);
    void savePortSpeedToSettings();
    void on_pushButtonConnect_clicked();
    void parse();
    void requestAccGyroDataSlot();

signals:
    void modeIsChanged(SetterMode mode);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
