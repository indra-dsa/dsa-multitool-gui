#ifndef FWORKER_H
#define FWORKER_H

#include "fitem.h"
#include <QObject>

class fWorker : public QObject
{
    Q_OBJECT
public:
    explicit fWorker(QObject *parent = nullptr);
    void getFfmpeg();

signals:
    void finished();
    void error(QString err);

public slots:
    void process();

private:
    fItem item;

};

#endif // FWORKER_H
