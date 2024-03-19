#include "streamworker.h"

StreamWorker::StreamWorker(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Created:" << this << QThread::currentThread();
}

StreamWorker::~StreamWorker()
{
    qInfo() << "Destroyed:" << this << QThread::currentThread();

}

void StreamWorker::doCommand()
{

}

void StreamWorker::run()
{

}
