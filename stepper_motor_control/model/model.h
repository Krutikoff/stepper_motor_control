#pragma once
#include <stdint.h>


namespace model {


class Model
{
public:

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
        uint32_t x = 0;
        uint32_t y = 0;
        uint32_t z = 0;
    };

    struct Distance{
        uint32_t x = 0;
        uint32_t y = 0;
        uint32_t z = 0;
    };

    Model() {}

    void set_engine_speed(uint8_t engine_number, uint16_t value);
    void set_engine_boost(uint8_t engine_number, uint16_t value);

    void set_x_coortdinate(uint32_t value);
    void set_y_coortdinate(uint32_t value);
    void set_z_coortdinate(uint32_t value);

    void set_x_distance(uint32_t value);
    void set_x_distance(uint32_t value);
    void set_z_distance(uint32_t value);

private:
    EngineSpeeds _engine_speeds;
    EngineBoost _engine_boosts;
    Coordinate _coordinate;
    Distance _distance;
};

}
