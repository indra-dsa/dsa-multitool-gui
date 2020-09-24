#include "dsamainwindow.h"
#include "ui_dsamainwindow.h"
#include <QStatusBar>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QLabel>

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
    aboutMessage.information(this,"About","Double Shot Audio Multitool V0.1 (Alpha)\nProgrammed by Made Indrayana using Qt 5");
}
