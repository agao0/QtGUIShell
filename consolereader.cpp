#include "consolereader.h"

ConsoleReader::ConsoleReader(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Created:" << this << QThread::currentThread();
}

ConsoleReader::~ConsoleReader()
{
    qInfo() << "Destroyed:" << this << QThread::currentThread();

}

void ConsoleReader::readInput()
{
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    qout<< "\n";
    qout << "Command> " << Qt::flush;
    QString line = qin.readLine();
    emit sendInput(line);
}
