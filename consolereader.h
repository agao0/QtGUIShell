#ifndef CONSOLEREADER_H
#define CONSOLEREADER_H

#include <QObject>
#include <QTextStream>
#include <QDebug>
#include <QThread>

class ConsoleReader : public QObject
{
    Q_OBJECT
public:
    explicit ConsoleReader(QObject *parent = nullptr);
    ~ConsoleReader();

signals:
    void sendInput(QString textInput);

public slots:
    void readInput();

private:
};

#endif // CONSOLEREADER_H
