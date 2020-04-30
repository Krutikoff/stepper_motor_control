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
        MOVE,
        GOTO,
        STATUS,
        SET_POS,
        EMERGENCY,
    };


    struct __attribute__((packed, aligned(1))) StartCmd{
        uint8_t number;
        uint8_t activate_engine_mask;
        uint8_t empty_byte;
        uint8_t forward_move;
        uint8_t back_move;
        uint8_t right_move;
        uint8_t left_move;
        uint16_t engine1_speed;
        uint16_t engine2_speed;
        uint16_t engine3_speed;
        uint16_t engine4_speed;
        uint16_t engine1_boost;
        uint16_t engine2_boost;
        uint16_t engine3_boost;
        uint16_t engine4_boost;
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
        uint32_t x_distance;
        uint32_t y_distance;
        uint32_t z_distance;
        uint32_t none_distance;

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
