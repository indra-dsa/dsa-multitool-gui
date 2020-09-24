#include "dsamainwindow.h"
#include "ui_dsamainwindow.h"
#include <QStatusBar>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QLabel>
#include <QDir>
#include <QFileDialog>
#include <QLineEdit>

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

void DSAMainWindow::getFfmpeg()
{
    QString fileName = nullptr;
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
    ui->pathFfmpeg->setPlaceholderText("this should be ffmpeg path");
    ui->pathFfmpeg->setText(fileName);
}

void DSAMainWindow::on_browseFfmpeg_clicked()
{
    getFfmpeg();
}
