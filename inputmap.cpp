#include "inputmap.h"

InputMap::InputMap(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Created:" << this << QThread::currentThread();
    foreach(QString item, m_commands) {
        QStringList temp = item.split(' ');
        commands.append(temp.at(0).toUpper());
    }
}

InputMap::~InputMap()
{
    qInfo() << "Destroyed:" << this << QThread::currentThread();

}

void InputMap::processInput(QString input)
{
    QStringList list = input.split(' ');
    if(list.size() <= 0)
    {
        emit badInput();
        return;
    }

    QString command = list.at(0).toUpper();
    if(!commands.contains(command))
    {
        emit badInput();
        return;
    }
    if(list.size() == 1)
    {
        if(command == "HELP")
        {
            // qInfo() << "HELP INPUTTED";
            emit helpInput(&m_commands);
            return;
        }
        if(command == "QUIT")
        {
            // qInfo() << "QUIT INPUTTED";
            emit quitInput();
            return;
        }
    }
}

