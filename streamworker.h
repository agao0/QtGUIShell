#ifndef STREAMWORKER_H
#define STREAMWORKER_H

#include <QObject>
#include <QDebug>
#include <QRunnable>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>

class StreamWorker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit StreamWorker(QObject *parent = nullptr);
    ~StreamWorker();

signals:
    void started();
    void finished();

public slots:
    void doCommand();
    // TODO: could make a generic Worker interface class that all Workers inherits to guarantee a "doCommand()" function

private:
    QMutex *m_mutex;
    bool *m_continue_streaming;


    // QRunnable interface
public:
    void run();
};

#endif // STREAMWORKER_H
