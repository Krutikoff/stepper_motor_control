#include <model/model.h>
#include <QDebug>
#include <cstring>

namespace model{

Model::Model() : _tcp_client(_start_cmd,
                     _stop_cmd,
                     _move_cmd,
                     _go_to_cmd,
                     _status_cmd,
                     _set_position_cmd)
{
    // Fill all structures with a value of 0
    //except for the command number field.
    memset(&_start_cmd, 0, sizeof(_start_cmd));
    memset(&_stop_cmd, 0, sizeof(_stop_cmd));
    memset(&_move_cmd, 0, sizeof(_move_cmd ));
    memset(&_go_to_cmd , 0, sizeof(_go_to_cmd));
    memset(&_set_position_cmd, 0, sizeof(_set_position_cmd));
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

    _start_cmd.forward_move = _move_diraction.forward;
    _start_cmd.forward_move = _move_diraction.back;
    _start_cmd.forward_move = _move_diraction.right;
    _start_cmd.forward_move = _move_diraction.left;

    _start_cmd.cmd_number = static_cast<uint8_t>(TcpClient::Cmd::START);
    _tcp_client.send_cmd(TcpClient::Cmd::START);
}

void Model::start(){
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

    _start_cmd.cmd_number = static_cast<uint8_t>(TcpClient::Cmd::START);
    _tcp_client.send_cmd(TcpClient::Cmd::START);

}

void Model::set_stop_mode(EngineNumber engine_number, StopMode mode){
    auto index = static_cast<uint8_t>(engine_number);
    _engines_stop_mode[index] = mode;
}

void Model::stop(){
    _stop_cmd.stop_mode_1 =  static_cast<uint8_t>(EngineNumber::_1);
    _stop_cmd.stop_mode_2 =  static_cast<uint8_t>(EngineNumber::_2);
    _stop_cmd.stop_mode_3 =  static_cast<uint8_t>(EngineNumber::_3);
    _stop_cmd.stop_mode_4 =  static_cast<uint8_t>(EngineNumber::_4);

    _stop_cmd.cmd_number = static_cast<uint8_t>(TcpClient::Cmd::STOP);
    _tcp_client.send_cmd(TcpClient::Cmd::STOP);
}

void Model::go_to(){
    _go_to_cmd.engine1_speed = _engine_speeds._1;
    _go_to_cmd.engine2_speed = _engine_speeds._2;
    _go_to_cmd.engine3_speed = _engine_speeds._3;
    _go_to_cmd.engine4_speed = _engine_speeds._4;

    _go_to_cmd.engine1_boost = _engine_boosts._1;
    _go_to_cmd.engine2_boost = _engine_boosts._2;
    _go_to_cmd.engine3_boost = _engine_boosts._3;
    _go_to_cmd.engine4_boost = _engine_boosts._4;
    _go_to_cmd.x_coordinate = _coordinate.x;
    _go_to_cmd.y_coordinate = _coordinate.y;
    _go_to_cmd.z_coordinate = _coordinate.z;

    _go_to_cmd.cmd_number = static_cast<uint8_t>(TcpClient::Cmd::GOTO);
    _tcp_client.send_cmd(TcpClient::Cmd::GOTO);
}

void Model::move(){
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

    _move_cmd.cmd_number = static_cast<uint8_t>(TcpClient::Cmd::MOVE);
    _tcp_client.send_cmd(TcpClient::Cmd::MOVE);
}
}
