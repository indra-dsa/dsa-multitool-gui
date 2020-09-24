#include "dsamainwindow.h"
#include "ui_dsamainwindow.h"
#include <QStatusBar>
#include <QMessageBox>

QString versionNumber = "V0.1";

DSAMainWindow::DSAMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DSAMainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Ready.");
}

DSAMainWindow::~DSAMainWindow()
{
    delete ui;
}


void DSAMainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void DSAMainWindow::on_actionAbout_triggered()
{
    QMessageBox aboutMessage;
    aboutMessage.information(this,"About","Double Shot Audio Multitool V" + versionNumber);
}
