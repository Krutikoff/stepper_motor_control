#include <model/tsp_client.h>
#include <QDebug>
#include <QCoreApplication>
#include <vector>
#include <QByteArray>

namespace tcp{

using namespace std;


TcpClient::TcpClient(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &TcpClient::slotNewConnection);



    if(!mTcpServer->listen(QHostAddress::Any, 6000)){
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

    for(uint8_t i = 0; i < size; ++i){
        auto byte = *(data_start + i);
        _packet.push_back(byte);
    }
}
void TcpClient::send_stop_cmd(uint8_t stop_mode){

    struct __attribute__((packed, aligned(1))) Packet{
      uint16_t cmd_number = 3;
      uint8_t active_engine_mask = 0x0F; // 0000 1111
      uint8_t empty_byte = 0;
      uint8_t stop_mode_1 = 0;
      uint8_t stop_mode_2 = 0;
      uint8_t stop_mode_3 = 0;
      uint8_t stop_mode_4 = 0;

    } packet;
    static_assert(sizeof(Packet) == 8,
                      "Error: Packet size is not correct");

    packet.stop_mode_1 = stop_mode;
    packet.stop_mode_2 = stop_mode;
    packet.stop_mode_3 = stop_mode;
    packet.stop_mode_4 = stop_mode;

    uint8_t size_data = sizeof(Packet);
    uint8_t cmd_buffer[size_data];
    const uint8_t* byte = reinterpret_cast<const uint8_t*>(&packet);


    for (uint8_t i = 0; i < size_data; ++i) {
        cmd_buffer[i] = *(byte + i);
    }

    auto res = mTcpSocket->write((char *)cmd_buffer, size_data);
    qDebug() << res;



}

void TcpClient::slotClientDisconnected(){
    mTcpSocket->close();
}

}
