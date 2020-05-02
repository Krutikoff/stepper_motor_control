#pragma once
#include <stdint.h>
#include <model/tsp_client.h>
#include <array>


namespace model {

using namespace tcp;
using namespace std;

class Model
{
public:

    struct MoveDiraction{
        uint8_t forward = 0;
        uint8_t back = 0;
        uint8_t right = 0;
        uint8_t left = 0;
        uint8_t up = 0;
        uint8_t down = 0;

        MoveDiraction& operator=(const MoveDiraction& diraction){
            forward = diraction.forward;
            forward = diraction.back;
            forward = diraction.right;
            forward = diraction.left;
            return *this;
        }
    };

    enum class MoveDiractionNames{
        FORWARD = 0,
        BACK,
        RIGHT,
        LEFT,
        UP,
        DOWN
    };

    enum class EngineNumber{
        _1 = 0,
        _2,
        _3,
        _4,
        END,
    };

    struct EngineSpeeds{
        using SpeedType = uint16_t;
        SpeedType _1 = 0;
        SpeedType _2 = 0;
        SpeedType _3 = 0;
        SpeedType _4 = 0;
    };

    struct EngineBoost{
        uint16_t _1 = 0;
        uint16_t _2 = 0;
        uint16_t _3 = 0;
        uint16_t _4 = 0;
    };

    struct Coordinate{
        int32_t x = 0;
        int32_t y = 0;
        int32_t z = 0;
    };

    struct Distance{
        int32_t x = 0;
        int32_t y = 0;
        int32_t z = 0;
    };

    enum class StopMode : uint8_t {
        MILD = 0,
        INSTANTE,
    };

    Model();

    void set_move_direction(MoveDiractionNames direction);
    void set_engine_speed(EngineNumber engine_number, uint16_t value);
    void set_engine_boost(EngineNumber engine_number, uint16_t value);

    void set_x_coortdinate(uint32_t value);
    void set_y_coortdinate(uint32_t value);
    void set_z_coortdinate(uint32_t value);

    void set_x_distance(uint32_t value);
    void set_y_distance(uint32_t value);
    void set_z_distance(uint32_t value);

    void start();
    void set_stop_mode(EngineNumber engine_number, StopMode mode);
    void stop();
    void go_to();
    void move();

private:
    MoveDiraction _move_diraction;
    EngineSpeeds _engine_speeds;
    EngineBoost _engine_boosts;
    Coordinate _coordinate;
    Distance _distance;

    static constexpr uint8_t _QUANTITY_OF_ENGINE = static_cast<uint8_t>(EngineNumber::END);
    array<StopMode, _QUANTITY_OF_ENGINE> _engines_stop_mode;

    TcpClient _tcp_client;
    TcpClient::StartCmd _start_cmd;
    TcpClient::StopCmd _stop_cmd;
    TcpClient::MoveCmd _move_cmd;
    TcpClient::GoToCmd _go_to_cmd;
    TcpClient::StatusCmd _status_cmd;
    TcpClient::SetPositionCmd _set_position_cmd;

};

}
