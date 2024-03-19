#include "commandexecutor.h"

CommandExecutor::CommandExecutor(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Created:" << this << QThread::currentThread();
}

CommandExecutor::~CommandExecutor()
{
    qInfo() << "Destroyed: " << this << QThread::currentThread();
}

void CommandExecutor::processCommand()
{

}

void CommandExecutor::processBadInput()
{
    qInfo() << "BAD INPUT. Enter \"help\" for commands list.";
    emit nextInput();
}

void CommandExecutor::processHelpInput(QStringList *commands)
{
    qInfo() << "Available Commands:";
    QStringList list = *commands;
    foreach(QString command, list)
    {
        qInfo() << command;
    }
    emit nextInput();
}

void CommandExecutor::processQuitInput()
{
    qInfo() << "Quitting GUI";

    // PROBABLY HAVE TO ADD SOME STUFF WITH CLOSING THREADS AND CLEANING UP
    // OR WE CAN EMIT stop() AND HAVE THINGS SHUT DOWN IF THIS IS ACTIVATED!!!

    emit stop();

    // qInfo() << "THIS SHOULD NOT RUN"; JK, it still manages to run before everything shuts down

    // NOTE: we connect CommandExecutor's stop() signal to the QCoreApplication's quit() slot. This doesn't
    // work unless we put it as a QueuedConnection, i.e. this means that the QCoreApplication is actually
    // running on a different thread from the rest of the application. QueuedConnection means the quit() slot
    // invoked when control returns to the QCoreApplication's thread, and quit() is executed in that thread.
    // If we leave it as default, then a DirectConnection is used, which means that the quit() slot is invoked
    // immediately when the stop() signal is emitted. quit() is executed in CommandExecutor's thread, which is
    // the thread named "Main Thread", and since this didn't work, this must mean that QCoreApplication (the
    // receiver) is running on a different thread than CommandExecutor. Hence why the DirectConnection failed,
    // as the documentation shows that the quit() slot may fail to stop the program if there are some events still
    // going on.
}
