#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include <QObject>
#include <QDebug>
#include <QThread>

class CommandExecutor : public QObject
{
    Q_OBJECT
public:
    explicit CommandExecutor(QObject *parent = nullptr);
    ~CommandExecutor();

signals:
    void nextInput();
    void stop();
    // I think this should emit more signals eventually, but for now keeping it simple

public slots:
    void processCommand();
    void processBadInput();
    void processHelpInput(QStringList* commands);
    void processQuitInput();
};

#endif // COMMANDEXECUTOR_H
