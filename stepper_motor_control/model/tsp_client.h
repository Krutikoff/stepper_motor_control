#pragma once
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <vector>

namespace tcp {

using namespace std;

class TcpClient : public QObject
{
    Q_OBJECT
public:


    enum class Cmd{
        START,
        STOP,
        MOVE,
        GOTO,
        STATUS,
        SET_POS,
        EMERGENCY,
    };


    struct StartCmd{
        const uint8_t number = 0;
        uint8_t activate_engine_mask = 0 ;
        uint8_t empty_byte = 0;
        uint8_t forward_move = 0;
        uint8_t back_move = 0;
        uint8_t right_move = 0;
        uint8_t left_move = 0;
        uint16_t engine1_speed = 0;
        uint16_t engine2_speed = 0;
        uint16_t engine3_speed = 0;
        uint16_t engine4_speed = 0;
        uint16_t engine1_boost = 0;
        uint16_t engine2_boost = 0;
        uint16_t engine3_boost = 0;
        uint16_t engine4_boost = 0;
    };

    struct __attribute__((packed, aligned(1))) StopCmd{
      uint16_t number;
      uint8_t active_engine_mask;
      uint8_t empty_byte;
      uint8_t stop_mode_1;
      uint8_t stop_mode_2;
      uint8_t stop_mode_3;
      uint8_t stop_mode_4;

    };

    struct __attribute__((packed, aligned(1))) MoveCmd{
        uint8_t number = 4;
        uint8_t activate_engine_mask;
        uint8_t empty_byte;
        uint16_t engine1_speed;
        uint16_t engine2_speed;
        uint16_t engine3_speed;
        uint16_t engine4_speed;
        uint16_t engine1_boost;
        uint16_t engine2_boost;
        uint16_t engine3_boost;
        uint16_t engine4_boost;
        uint32_t x_distance;
        uint32_t y_distance;
        uint32_t z_distance;
        uint32_t none_distance = 0;

    };

    struct __attribute__((packed, aligned(1))) GoToCmd{
        uint8_t number;
        uint8_t activate_engine_mask;
        uint8_t empty_byte;
        uint16_t engine1_speed;
        uint16_t engine2_speed;
        uint16_t engine3_speed;
        uint16_t engine4_speed;
        uint16_t engine1_boost;
        uint16_t engine2_boost;
        uint16_t engine3_boost;
        uint16_t engine4_boost;
        int32_t x_coordinate;
        int32_t y_coordinate;
        int32_t z_coordinate;
        int32_t none_coordinate;

    };

    struct __attribute__((packed, aligned(1))) StatusCmd{
        uint8_t number;
    };

    struct __attribute__((packed, aligned(1))) SetPositionCmd{
        uint8_t number;
        uint8_t activate_engine_mask;
        uint8_t empty_byte;
        uint32_t position_1;
        uint32_t position_2;
        uint32_t position_3;
        uint32_t position_4;
    };

    TcpClient(StartCmd& start_cmd,
              StopCmd& stop_cmd,
              MoveCmd& move_cmd,
              GoToCmd& go_to_cmd,
              StatusCmd& status_cmd,
              SetPositionCmd& set_position_cmd,
              QObject *parent = 0);


public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

    void send_stop_cmd(uint8_t stop_mode);
    void send_cmd(Cmd cmd);

private:
    QTcpServer* mTcpServer;
    QTcpSocket* mTcpSocket;

    using Packet = vector<uint8_t>;
    Packet _packet;
    void _build_packet(Cmd cmd);

    StartCmd& _start_cmd;
    StopCmd& _stop_cmd;
    MoveCmd& _move_cmd;
    GoToCmd& _go_to_cmd;
    StatusCmd& _status_cmd;
    SetPositionCmd& _set_position_cmd;
};

}
