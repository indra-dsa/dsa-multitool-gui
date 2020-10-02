#include "fworker.h"
#include <QProcess>

fWorker::fWorker(QObject *parent) : QObject(parent)
{
    QString filePath = ui->pathFfmpeg->text();

    QStringList params;
    QProcess p;

    p.setProcessChannelMode(QProcess::MergedChannels);

#ifdef Q_OS_OSX
    //params << "-i";
    //params << ui->lineEdit_testFile->text();
#endif

#ifdef Q_OS_WIN
    //p.setNativeArguments(ui->lineEdit_params->text()); // VERY IMPORTANT FOR WINDOWS!!!!!
#endif

    //p.start(file,params);

    QString output;
    if (p.waitForStarted(-1))
    {
        while(p.waitForReadyRead(-1))
        {
            output += p.readAll();
      //      ui->label_debug->setText(output);
        }
    }

    p.waitForFinished();

}
