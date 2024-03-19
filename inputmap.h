#ifndef INPUTMAP_H
#define INPUTMAP_H

#include <QObject>
#include <QDebug>
#include <QThread>
// #include <QStringList>

class InputMap : public QObject
{
    Q_OBJECT
public:
    explicit InputMap(QObject *parent = nullptr);
    ~InputMap();

signals:
    void sendCommand();
    void badInput();
    void helpInput(QStringList* commands);
    void quitInput();

public slots:
    void processInput(QString input); // TODO: Make this generic, so that any form of input can be processed.
    // may need to implement own type of input class, like "GUI_INPUT class"
    // CAN THIS BE OVERLOADED? have another processInput(SOME OTHER ARG)??

private:
    QStringList m_commands = {
        "help                                     ",
        "stream       <SENSOR>     <DATA_TYPE>    ",
        "stream_angle <ARM>        <JOINT_NUMBER> ",
        "set          <VAR_NAME>   <VALUE>        ",
        "quit                                     "
    };
    QStringList commands;
};

#endif // INPUTMAP_H
