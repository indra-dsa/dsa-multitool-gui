#ifndef DSAMAINWINDOW_H
#define DSAMAINWINDOW_H

#include <QtCore/QtCore>
#include <QMainWindow>


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
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_browseFfmpeg_clicked();
    void on_actionffmpeg_start_triggered();
    void on_pathFfmpeg_textChanged(const QString &arg1);
    void on_actionQSettings_status_triggered();


    void on_pushButton_2_clicked();

private:
    Ui::DSAMainWindow *ui;
};
#endif // DSAMAINWINDOW_H
