#include <model/model.h>
#include <QDebug>

namespace model{

void Model::set_engine_speed(uint8_t engine_number, uint16_t value){
    auto engine_index = engine_number - 1;
    auto itr = reinterpret_cast<EngineSpeeds::SpeedType*>(&_engine_speeds);
    auto current_speed = itr + engine_index;
    *current_speed = value;

    qDebug() << "[Model]::engine1 speed value: " << _engine_speeds._1;
}

void Model::set_engine_boost(uint8_t engine_number, uint16_t value){
    auto engine_index = engine_number - 1;
    auto itr = reinterpret_cast<EngineSpeeds::SpeedType*>(&_engine_boosts);
    auto current_boost = itr + engine_index;
    *current_boost = value;

    qDebug() << "[Model]::engine1 speed value: " << _engine_boosts._1;
}

void Model::set_x_coortdinate(uint32_t coordinate){
    _coordinate.x = value;
    qDebug() << "[Model]:: coordinate x : " << _coordinate.x;
}

void Model::set_y_coortdinate(uint32_t coordinate){
    _coordinate.y = value;
    qDebug() << "[Model]:: coordinate x : " << _coordinate.y;
}

void Model::set_z_coortdinate(uint32_t coordinate){
    _coordinate.z = value;
    qDebug() << "[Model]:: coordinate x : " << _coordinate.z;
}

void Model::set_x_distance(uint32_t distance){
    _distance.x = value;
    qDebug() << "[Model]:: coordinate x : " << _coordinate.x;
}

void Model::set_y_distance(uint32_t distance){
    _distance.y = value;
    qDebug() << "[Model]:: coordinate y : " << _coordinate.y;
}

void Model::set_z_distance(uint32_t distance){
    _distance.z = value;
    qDebug() << "[Model]:: coordinate z : " << _coordinate.z;
}


}