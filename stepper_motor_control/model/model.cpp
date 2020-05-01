#include <model/model.h>
#include <QDebug>

namespace model{

void Model::set_move_direction(MoveDiractionNames direction){

    _move_diraction.forward = 0;
    _move_diraction.back = 0;
    _move_diraction.right = 0;
    _move_diraction.left = 0;
    _move_diraction.up = 0;
    _move_diraction.down= 0;
    if(direction == MoveDiractionNames::FORWARD){
        _move_diraction.forward = 1;
    }
    else if (direction == MoveDiractionNames::BACK) {
        _move_diraction.back = 1;
    }
    else if (direction == MoveDiractionNames::RIGHT) {
        _move_diraction.right = 1;
    }
    else if (direction == MoveDiractionNames::LEFT) {
        _move_diraction.left = 1;
    }
    else if (direction == MoveDiractionNames::UP) {
        _move_diraction.up = 1;
    }
    else if (direction == MoveDiractionNames::DOWN) {
        _move_diraction.down = 1;
    }

    _move_cmd.engine1_speed = _engine_speeds._1;
    _move_cmd.engine2_speed = _engine_speeds._2;
    _move_cmd.engine3_speed = _engine_speeds._3;
    _move_cmd.engine4_speed = _engine_speeds._4;

    _move_cmd.engine1_boost = _engine_boosts._1;
    _move_cmd.engine1_boost = _engine_boosts._2;
    _move_cmd.engine1_boost = _engine_boosts._3;
    _move_cmd.engine1_boost = _engine_boosts._4;
    _move_cmd.x_distance = _distance.x;
    _move_cmd.y_distance = _distance.y;
    _move_cmd.z_distance = _distance.z;

    _tcp_client.send_cmd(TcpClient::Cmd::MOVE);
}

void Model::set_engine_speed(EngineNumber engine_number, uint16_t value){
    auto engine_index = static_cast<uint8_t>(engine_number);
    auto *itr = reinterpret_cast<EngineSpeeds::SpeedType*>(&_engine_speeds);
    auto current_speed = itr + engine_index;
    *current_speed = value;

    qDebug() << "[Model]::engine1 speed value: " << _engine_speeds._1;
    qDebug() << "[Model]::engine2 speed value: " << _engine_speeds._2;
    qDebug() << "[Model]::engine3 speed value: " << _engine_speeds._3;
    qDebug() << "[Model]::engine4 speed value: " << _engine_speeds._4;
}

void Model::set_engine_boost(EngineNumber engine_number, uint16_t value){
    auto engine_index = static_cast<uint8_t>(engine_number);
    auto *itr = reinterpret_cast<uint16_t*>(&_engine_boosts);
    auto current_boost = itr + engine_index;
    *current_boost = value;

    qDebug() << "[Model]::boost1 speed value: " << _engine_boosts._1;
    qDebug() << "[Model]::boost2 speed value: " << _engine_boosts._2;
    qDebug() << "[Model]::boost3 speed value: " << _engine_boosts._3;
    qDebug() << "[Model]::boost4 speed value: " << _engine_boosts._4;
}

void Model::set_x_coortdinate(uint32_t coordinate){
    _coordinate.x = coordinate;
    qDebug() << "[Model]:: coordinate x : " << _coordinate.x;
}

void Model::set_y_coortdinate(uint32_t coordinate){
    _coordinate.y = coordinate;
    qDebug() << "[Model]:: coordinate y : " << _coordinate.y;
}

void Model::set_z_coortdinate(uint32_t coordinate){
    _coordinate.z = coordinate;
    qDebug() << "[Model]:: coordinate z : " << _coordinate.z;
}

void Model::set_x_distance(uint32_t distance){
    _distance.x = distance;
    qDebug() << "[Model]:: coordinate x : " << _coordinate.x;
}

void Model::set_y_distance(uint32_t distance){
    _distance.y = distance;
    qDebug() << "[Model]:: coordinate y : " << _coordinate.y;
}

void Model::set_z_distance(uint32_t distance){
    _distance.z = distance;
    qDebug() << "[Model]:: coordinate z : " << _coordinate.z;
}

void Model::start(){
//     uint8_t cmd_buffer
//    _tcp_client.send_cmd(Cmd::Start);

    _start_cmd.forward_move = _move_diraction.forward;
    _start_cmd.back_move = _move_diraction.back;
    _start_cmd.right_move = _move_diraction.right;
    _start_cmd.left_move = _move_diraction.left;

    _start_cmd.engine1_speed = _engine_speeds._1;
    _start_cmd.engine2_speed = _engine_speeds._2;
    _start_cmd.engine3_speed = _engine_speeds._3;
    _start_cmd.engine4_speed = _engine_speeds._4;

    _start_cmd.engine1_boost = _engine_boosts._1;
    _start_cmd.engine2_boost = _engine_boosts._2;
    _start_cmd.engine3_boost = _engine_boosts._3;
    _start_cmd.engine4_boost = _engine_boosts._4;


    _tcp_client.send_cmd(TcpClient::Cmd::START);

}

void Model::set_stop_mode(StopMode mode){
    _stop_mode = mode;
}

void Model::stop(){
    auto mode = static_cast<uint8_t>(_stop_mode);


    _tcp_client.send_stop_cmd(mode);
}
}
