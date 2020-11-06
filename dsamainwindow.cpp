#include "dsamainwindow.h"
#include "ui_dsamainwindow.h"

#include "fworker.h"
#include "aboutdialog.h"
#include "consoleoutput.h"

#include <QMessageBox>
#include <QFileDialog>


// Standard Functions ------------------------------------------------------------------------------------

DSAMainWindow::DSAMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DSAMainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Ready.");

    // initialize values for QSettings
    QSettings settings;
    getSettings();

    a = new AboutDialog();
    c = new ConsoleOutput();
}

DSAMainWindow::~DSAMainWindow()
{
    delete ui;
    delete a;
    delete c;
}

void DSAMainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void DSAMainWindow::on_actionAbout_triggered()
{
    a->show();
}

void DSAMainWindow::on_actionShow_Console_Output_triggered()
{
    c->show();
}

void DSAMainWindow::on_actionQSettings_status_triggered()
{
    qInfo() << settings.status();
}

// Main Functions ------------------------------------------------------------------------------------

void DSAMainWindow::getSettings()
{
    if(settings.value("ffmpegPath").toString() != nullptr)
    {
        ui->pathFfmpeg->setText(settings.value("ffmpegPath").toString());

    }
    else
    {
        QMessageBox::information(this,"FFmpeg not found!", "FFmpeg path not set, please set!");
    }
}

void DSAMainWindow::on_browseFfmpeg_clicked()
{
    QString fileName;

    fileName = QFileDialog::getOpenFileName(this,
        tr("Locate FFmpeg Binary Build"), QDir::homePath());

    //Null & Empty Check for FileName
    if(fileName.isNull() || fileName.isEmpty())
    {
        return;
    }
    else
    {
        ui->pathFfmpeg->setText(fileName);
        settings.setValue("ffmpegPath", fileName);
        settings.sync();
    }
}

void DSAMainWindow::on_pathFfmpeg_textChanged(const QString &arg1)
{
    settings.setValue("ffmpegPath", arg1);
    settings.sync();
    qInfo() << "Updated path to: " << settings.value("ffmpegPath").toString();
}

void DSAMainWindow::on_actionffmpeg_start_triggered()
{
    QThread* thread = new QThread;
    fWorker* fWorker = new class fWorker();
    fWorker->moveToThread(thread);
    connect(fWorker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), fWorker, SLOT(process()));
    connect(fWorker, SIGNAL(outputAvailable(QString)), c, SLOT(printToConsole(QString)));
    connect(fWorker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(fWorker, SIGNAL(finished()), fWorker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}




void DSAMainWindow::errorString(QString err)
{
    qDebug() << err;
}

void DSAMainWindow::on_browseFile_clicked()
{
    QString fileName;

    fileName = QFileDialog::getOpenFileName(this,
        tr("Locate File to convert"), QDir::homePath());

    //Null & Empty Check for FileName
    if(fileName.isNull() || fileName.isEmpty())
    {
        return;
    }
    else
    {
        ui->pathFile->setText(fileName);
    }
}

void DSAMainWindow::on_actionffmpeg_with_file_triggered()
{

    QString endFileName = ui->pathFile->text();
    endFileName.insert(endFileName.length()-4,"test");

    QThread* thread = new QThread;
    fWorker* fWorker = new class fWorker();
    fWorker->moveToThread(thread);
    connect(fWorker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), fWorker, SLOT(process()));
    connect(fWorker, SIGNAL(outputAvailable(QString)), c, SLOT(printToConsole(QString)));
    connect(fWorker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(fWorker, SIGNAL(finished()), fWorker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    // HARD CODED PARAMS with Frame Scrubber Enabler
    fWorker->params.append("-i");
    fWorker->params.append(ui->pathFile->text());
    fWorker->params.append("-bf");
    fWorker->params.append("0");
    fWorker->params.append("-g");
    fWorker->params.append("1");
    fWorker->params.append(endFileName);

    thread->start();
}

void DSAMainWindow::on_addItem_clicked()
{
    QStringList fileNames;

    fileNames = QFileDialog::getOpenFileNames(this,
        tr("Locate File to convert"), QDir::homePath());

    //Null & Empty Check for FileName
    if(fileNames.isEmpty())
    {
        return;
    }
    else
    {
        ui->pathFileList->addItems(fileNames);
    }
}



void DSAMainWindow::on_actionffmpeg_with_filelist_triggered()
{
    for (int row = 0; row < ui->pathFileList->count(); row++)
    {
        QListWidgetItem *item = ui->pathFileList->item(row);
        QString fileName = item->text();
        QString endFileName = item->text();
        endFileName.insert(endFileName.length()-4,"-test");
        //qDebug() << endFileName;

        QThread* thread = new QThread;
        fWorker* fWorker = new class fWorker();
        fWorker->moveToThread(thread);
        connect(fWorker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
        connect(thread, SIGNAL(started()), fWorker, SLOT(process()));
        connect(fWorker, SIGNAL(outputAvailable(QString)), c, SLOT(printToConsole(QString)));
        connect(fWorker, SIGNAL(finished()), thread, SLOT(quit()));
        connect(fWorker, SIGNAL(finished()), fWorker, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

        // HARD CODED PARAMS with Frame Scrubber Enabler
        fWorker->params.append("-i");
        fWorker->params.append(fileName);
        fWorker->params.append("-bf");
        fWorker->params.append("0");
        fWorker->params.append("-g");
        fWorker->params.append("1");
        fWorker->params.append(endFileName);

        thread->start();
    }


}
