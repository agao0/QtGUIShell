#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QString>
#include <QMap>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>
#include <QMutex>
#include <QMutexLocker>
#include <QObject>
#include <QList>
#include <QByteArray>
#include <QString>
#include <QMap>
#include <QStorageInfo>
#include <QDir>
#include <QFile>

#include "consolereader.h"
#include "commandexecutor.h"
#include "inputmap.h"
#include "gui_start.h"

// typedef QMap<QString, QSharedPointer<Test>> inputMap;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    gui_start::drawStartup();
    QThread::currentThread()->setObjectName("Main Thread");

    ConsoleReader reader;
    InputMap inputMap;
    CommandExecutor doer;
    QTextStream qout(stdout);

    // CONNECTING ALL SIGNALS AND SLOTS
    QObject::connect(&reader, &ConsoleReader::sendInput, &inputMap, &InputMap::processInput);
    QObject::connect(&doer, &CommandExecutor::nextInput, &reader, &ConsoleReader::readInput);
    // DOWNSTREAM InputMap -> CommandExecutor links
    QObject::connect(&inputMap, &InputMap::sendCommand, &doer, &CommandExecutor::processCommand);
    QObject::connect(&inputMap, &InputMap::badInput, &doer, &CommandExecutor::processBadInput);
    QObject::connect(&inputMap, &InputMap::helpInput, &doer, &CommandExecutor::processHelpInput);
    QObject::connect(&inputMap, &InputMap::quitInput, &doer, &CommandExecutor::processQuitInput);
    // CLEANUP CommandExecutor stop() links
    QObject::connect(&doer, &CommandExecutor::stop, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    reader.readInput();

    return a.exec();

}

// TODOS:
// Create QtMessageHandler to intercept QDebug and provide thorough GUI logging

// NOTE: Chose to use InputMap as a general filter that emits different signals based on input. It sends these
// signals (mostly for CommandExecutor BUT could connect to other things down the line) and doesn't care about
// whether they work or not. CommandExecutor will check the validity of the filtered input. IT WILL NEVER SEND
// SIGNALS UP THE CHAIN, i.e. all commands go down the chain, not back up the ConsoleReader or any other reader
// that will get created in the future
// - other approach was to do very light filtering here, and then pass QStringList to CommandExecutor and do
//   processing there. I chose this approach because I liked the idea of CommandExecutor very quickly being
//   able to figure out whether to store local instances of things without needing any parsing/filtering first
