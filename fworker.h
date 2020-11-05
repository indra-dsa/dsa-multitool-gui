#ifndef FWORKER_H
#define FWORKER_H

#include "fitem.h"
#include <QObject>

class fWorker : public QObject
{
    Q_OBJECT

public:
    fWorker();
    ~fWorker();
    void getFfmpeg();
    QStringList params;
    QString output;

signals:
    void finished();
    void error(QString err);
    void outputAvailable(QString output);

public slots:
    void process();

private:
    fItem item;

};

#endif // FWORKER_H
