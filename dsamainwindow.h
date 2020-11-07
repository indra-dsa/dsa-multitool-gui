#ifndef DSAMAINWINDOW_H
#define DSAMAINWINDOW_H

#include <QtCore/QtCore>
#include <QMainWindow>
#include "consoleoutput.h"
#include "aboutdialog.h"


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
    QProcess p;

private slots:
    void errorString(QString);
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_browseFfmpeg_clicked();
    void on_actionffmpeg_start_triggered();
    void on_pathFfmpeg_textChanged(const QString &arg1);
    void on_actionQSettings_status_triggered();
    void on_addItem_clicked();
    void on_actionffmpeg_with_filelist_triggered();

private:
    Ui::DSAMainWindow *ui;
    AboutDialog *a;
};
#endif // DSAMAINWINDOW_H
