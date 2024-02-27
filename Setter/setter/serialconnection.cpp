#include "serialconnection.h"

SerialConnection::SerialConnection()
{
}

QStringList SerialConnection::listPort()
{
    QStringList availablePorts;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
    {
        availablePorts.append(info.portName());
    }
    return availablePorts;
}
