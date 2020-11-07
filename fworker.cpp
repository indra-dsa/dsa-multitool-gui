#include "fworker.h"
#include <QProcess>
#include <QSettings>

fWorker::fWorker()
{
    QStringList params;

}

fWorker::~fWorker()
{

}

void fWorker::process()
{
    QSettings settings;
    QString filePath = settings.value("ffmpegPath").toString();
    QProcess p;

    p.setProcessChannelMode(QProcess::MergedChannels);

#ifdef Q_OS_WIN
    p.setNativeArguments("-i \"C:\\Users\\info\\Desktop\\ffmpeg test\\200828 BCL Video V1.mp4\" -bf 0 -g 1 \"C:\\Users\\info\\Desktop\\ffmpeg test\\200828 BCL Video V1-N.mp4\""); // VERY IMPORTANT FOR WINDOWS!!!!!
#endif

    p.start(filePath,params);

    if (p.waitForStarted(-1))
    {
        while(p.waitForReadyRead(-1))
        {
            output += p.readAll();
            emit outputAvailable(output);
        }
    }

    p.waitForFinished();

}

void fWorker::getFfmpeg()
{

}
