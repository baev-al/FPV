#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStringList>

class SerialConnection
{
    QSerialPort port;
public:
    SerialConnection();
    QStringList listPort();
};

#endif // SERIALCONNECTION_H
