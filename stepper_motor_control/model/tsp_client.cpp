#include <model/tsp_client.h>
#include <QDebug>
#include <QCoreApplication>
#include <QByteArray>

namespace tcp{

TcpClient::TcpClient(StartCmd& start_cmd,
                     StopCmd& stop_cmd,
                     MoveCmd& move_cmd,
                     GoToCmd& go_to_cmd,
                     StatusCmd& status_cmd,
                     SetPositionCmd& set_position_cmd,
                     QObject *parent)
    : QObject(parent), _start_cmd(start_cmd),
      _stop_cmd(stop_cmd), _move_cmd(move_cmd),
      _go_to_cmd(go_to_cmd), _status_cmd(status_cmd),
      _set_position_cmd(set_position_cmd)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &TcpClient::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 5000)){
        qDebug() << "server is not started";
    } else {
        qDebug() << "server is started";
    }
}


void TcpClient::slotNewConnection(){
    mTcpSocket = mTcpServer->nextPendingConnection();


    connect(mTcpSocket, &QTcpSocket::readyRead, this, &TcpClient::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &TcpClient::slotClientDisconnected);
}

void TcpClient::slotServerRead(){
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array = mTcpSocket->readAll();

        mTcpSocket->write(array);
    }
}

void TcpClient::_build_packet(Cmd cmd){
    uint8_t *data_start;
    uint8_t size = 0;

    if(cmd == Cmd::START){
        data_start = reinterpret_cast<uint8_t*>(&_start_cmd);
        size = sizeof(_start_cmd);
    }
    else if(cmd == Cmd::STOP){
        data_start = reinterpret_cast<uint8_t*>(&_stop_cmd);
        size = sizeof(_stop_cmd);
    }
    else if(cmd == Cmd::MOVE){
        data_start = reinterpret_cast<uint8_t*>(&_move_cmd);
        size = sizeof(_move_cmd);
    }
    else if(cmd == Cmd::GOTO){
        data_start = reinterpret_cast<uint8_t*>(&_go_to_cmd);
        size = sizeof(_go_to_cmd);
    }
    else if(cmd == Cmd::SET_POS){
        data_start = reinterpret_cast<uint8_t*>(&_set_position_cmd);
        size = sizeof(_set_position_cmd);
    }

    for(uint8_t i = 0; i < size; ++i){
        auto byte = *(data_start + i);
        _packet.push_back(byte);
    }
}

void TcpClient::send_cmd(Cmd cmd){
    _build_packet(cmd);

    for(uint8_t byte : _packet){
        auto res = mTcpSocket->write((char*)(&byte), sizeof(byte));
        qDebug() << res;
    }
}


void TcpClient::slotClientDisconnected(){
    mTcpSocket->close();
}

}
