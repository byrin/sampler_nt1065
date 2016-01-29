#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cy3device.h"
#include "dataprocessor.h"
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    bool filedumping;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_buttonOpenDevice_clicked();
    void DebugParser(QString Message);

    void handleAbortDump();

    void on_buttonCloseDevice_clicked();

    void on_buttonReadID_clicked();

    void on_buttonStartStream_clicked();

    void on_buttonStopStream_clicked();

    void on_buttonFileDump_clicked();

    void on_buttonSetFileName_clicked();

private:
    Ui::MainWindow *ui;

    cy3device *Device;
    QThread *DeviceThread;

    DataProcessor *Proc;
    QThread *ProcThread;
};

#endif // MAINWINDOW_H
