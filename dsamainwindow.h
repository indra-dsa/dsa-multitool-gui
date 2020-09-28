#ifndef DSAMAINWINDOW_H
#define DSAMAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QLabel>
#include <QDir>
#include <QFileDialog>
#include <QLineEdit>
#include <QProcess>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class DSAMainWindow; }
QT_END_NAMESPACE

class DSAMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    DSAMainWindow(QWidget *parent = nullptr);
    ~DSAMainWindow();
    QSettings settings;
    void getSettings();

private slots:
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_browseFfmpeg_clicked();
    void on_actionffmpeg_start_triggered();

private:
    Ui::DSAMainWindow *ui;
};
#endif // DSAMAINWINDOW_H
