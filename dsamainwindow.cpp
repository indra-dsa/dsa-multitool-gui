#include "dsamainwindow.h"
#include "ui_dsamainwindow.h"


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

// Main Functions ------------------------------------------------------------------------------------

void DSAMainWindow::getSettings()
{
    if(settings.value("ffmpegPath").toString() != nullptr)
    {
        ui->pathFfmpeg->setText(settings.value("ffmpegPath").toString());

    }
    else
    {
        return;
    }
}

void DSAMainWindow::on_browseFfmpeg_clicked()
{
    QString fileName = nullptr;

    fileName = QFileDialog::getOpenFileName(this,
        tr("Locate FFmpeg Binary Build"), QDir::homePath());
    ui->pathFfmpeg->setText(fileName);
    settings.setValue("ffmpegPath", fileName);
    settings.sync();
}

void DSAMainWindow::on_actionffmpeg_start_triggered()
{
    QString file = ui->pathFfmpeg->text();

    QStringList params;
    QProcess ffmpeg;

    ffmpeg.setProcessChannelMode(QProcess::ForwardedChannels);
    ffmpeg.startDetached(file,params);
    ffmpeg.waitForFinished();
    QString output = ffmpeg.readAll();
    ui->label_debug->setText(output);
}

void DSAMainWindow::on_pathFfmpeg_textChanged(const QString &arg1)
{
    settings.setValue("ffmpegPath", arg1);
    settings.sync();
    qInfo() << "Updated path to: " << settings.value("ffmpegPath").toString();
}

void DSAMainWindow::on_actionQSettings_status_triggered()
{
    qInfo() << settings.status();
}
