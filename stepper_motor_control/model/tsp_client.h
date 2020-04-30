#pragma once
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

namespace tcp {


class TcpClient : public QObject
{
    Q_OBJECT
public:
    TcpClient(QObject *parent = 0);

    enum class Cmd{
        START,
        STOP,
    };

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

    void send_stop_cmd(uint8_t stop_mode);

private:
    QTcpServer* mTcpServer;
    QTcpSocket* mTcpSocket;
};

}
