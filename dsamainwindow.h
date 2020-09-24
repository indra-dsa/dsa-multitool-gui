#ifndef DSAMAINWINDOW_H
#define DSAMAINWINDOW_H

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

private slots:
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void getFfmpeg();

    void on_browseFfmpeg_clicked();

private:
    Ui::DSAMainWindow *ui;
};
#endif // DSAMAINWINDOW_H
