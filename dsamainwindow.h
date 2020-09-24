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

private:
    Ui::DSAMainWindow *ui;
    QString versionNumber;
};
#endif // DSAMAINWINDOW_H
