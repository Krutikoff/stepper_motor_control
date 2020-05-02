#include <controller/controller.h>
#include <QCoreApplication>
#include <QDebug>
#include <QPushButton>
#include <QSpinBox>
#include <QRadioButton>


using namespace controller;


Controller::Controller(QObject *parent) : QObject(parent){
    _bind_signal_to_slot();
    _view.show();
}

void Controller::_bind_signal_to_slot(){


    // Buttons
    QPushButton* forward_move_pb = _view.get_push_button(View::PushButtonNames::ForwardMovePushButton);
    QPushButton* back_move_pb = _view.get_push_button(View::PushButtonNames::BackMovePushButton);
    QPushButton* right_move_pb = _view.get_push_button(View::PushButtonNames::RightMovePushButton);
    QPushButton* left_move_pb = _view.get_push_button(View::PushButtonNames::LeftMovePushButton);
    QPushButton* up_move_pb = _view.get_push_button(View::PushButtonNames::UpMovePushButton);
    QPushButton* down_move_pb = _view.get_push_button(View::PushButtonNames::DownMovePushButton);
    QPushButton* start_pb = _view.get_push_button(View::PushButtonNames::StartPushButton);
    QPushButton* stop_pb = _view.get_push_button(View::PushButtonNames::StopPushButton);
    QPushButton* go_to_pb = _view.get_push_button(View::PushButtonNames::GoToPushButton);
    QPushButton* move_pb = _view.get_push_button(View::PushButtonNames::MovePushButton);

    connect(forward_move_pb, &QPushButton::pressed, this, &Controller::forward_move_pb_handler);
    connect(back_move_pb, &QPushButton::pressed, this, &Controller::back_move_pb_handler);
    connect(right_move_pb, &QPushButton::pressed, this, &Controller::right_move_pb_handler);
    connect(left_move_pb, &QPushButton::pressed, this, &Controller::left_move_pb_handler);
    connect(up_move_pb, &QPushButton::pressed, this, &Controller::up_move_pb_handler);
    connect(down_move_pb, &QPushButton::pressed, this, &Controller::down_move_pb_handler);
    connect(start_pb, &QPushButton::pressed, this, &Controller::start_pb_handler);
    connect(stop_pb, &QPushButton::pressed, this, &Controller::stop_pb_handler);
    connect(go_to_pb, &QPushButton::pressed, this, &Controller::go_to_pb_handler);
    connect(move_pb, &QPushButton::pressed, this, &Controller::move_pb_handler);

    // Spinbox
    QSpinBox* engine1_speed_sp = _view.get_spinbox(View::SpinBoxNames::Engine1SpeedSpinBox);
    QSpinBox* engine2_speed_sp = _view.get_spinbox(View::SpinBoxNames::Engine2SpeedSpinBox);
    QSpinBox* engine3_speed_sp = _view.get_spinbox(View::SpinBoxNames::Engine3SpeedSpinBox);
    QSpinBox* engine4_speed_sp = _view.get_spinbox(View::SpinBoxNames::Engine4SpeedSpinBox);

    connect(
        engine1_speed_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::engine1_speed_sp_handler
    );

    connect(
        engine2_speed_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::engine2_speed_sp_handler
    );

    connect(
        engine3_speed_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::engine3_speed_sp_handler
    );

    connect(
        engine4_speed_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::engine4_speed_sp_handler
    );

    QSpinBox* engine1_boost_sp = _view.get_spinbox(View::SpinBoxNames::Engine1BoostSpinBox);
    QSpinBox* engine2_boost_sp = _view.get_spinbox(View::SpinBoxNames::Engine2BoostSpinBox);
    QSpinBox* engine3_boost_sp = _view.get_spinbox(View::SpinBoxNames::Engine3BoostSpinBox);
    QSpinBox* engine4_boost_sp = _view.get_spinbox(View::SpinBoxNames::Engine4BoostSpinBox);

    connect(
        engine1_boost_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::engine1_boost_sp_handler
    );

    connect(
        engine2_boost_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::engine2_boost_sp_handler
    );

    connect(
        engine3_boost_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::engine3_boost_sp_handler
    );

    connect(
        engine4_boost_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::engine4_boost_sp_handler
    );

    QSpinBox* x_coordinate_sp = _view.get_spinbox(View::SpinBoxNames::XCoordinateSpinBox);
    QSpinBox* y_coordinate_sp = _view.get_spinbox(View::SpinBoxNames::YCoordinateSpinBox);
    QSpinBox* z_coordinate_sp = _view.get_spinbox(View::SpinBoxNames::ZCoordinateSpinBox);

    connect(
        x_coordinate_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::x_coordinate_sp_handler
    );

    connect(
        y_coordinate_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::y_coordinate_sp_handler
    );

    connect(
        z_coordinate_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::z_coordinate_sp_handler
    );

    QSpinBox* x_distance_sp = _view.get_spinbox(View::SpinBoxNames::XDistanceSpinBox);
    QSpinBox* y_distance_sp = _view.get_spinbox(View::SpinBoxNames::YDistanceSpinBox);
    QSpinBox* z_distance_sp = _view.get_spinbox(View::SpinBoxNames::ZDistanceSpinBox);

    connect(
        x_distance_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::x_distance_sp_handler
    );

    connect(
        y_distance_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::y_distance_sp_handler
    );

    connect(
        z_distance_sp,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &Controller::z_distance_sp_handler
    );


    QRadioButton* engine1_instante_mode_rb = _view.get_radio_button(View::RadioButtonNames::InstantStopEngine1RadioButton);
    QRadioButton* engine2_instante_mode_rb = _view.get_radio_button(View::RadioButtonNames::InstantStopEngine2RadioButton);
    QRadioButton* engine3_instante_mode_rb = _view.get_radio_button(View::RadioButtonNames::InstantStopEngine3RadioButton);
    QRadioButton* engine4_instante_mode_rb = _view.get_radio_button(View::RadioButtonNames::InstantStopEngine4RadioButton);
    QRadioButton* engine1_mild_mode_rb = _view.get_radio_button(View::RadioButtonNames::MildStopEngine1RadioButton);
    QRadioButton* engine2_mild_mode_rb = _view.get_radio_button(View::RadioButtonNames::MildStopEngine2RadioButton);
    QRadioButton* engine3_mild_mode_rb = _view.get_radio_button(View::RadioButtonNames::MildStopEngine3RadioButton);
    QRadioButton* engine4_mild_mode_rb = _view.get_radio_button(View::RadioButtonNames::MildStopEngine4RadioButton);

    connect(engine1_instante_mode_rb ,&QRadioButton::clicked, this, &Controller::engine1_instant_stop_mode);
    connect(engine2_instante_mode_rb ,&QRadioButton::clicked, this, &Controller::engine2_instant_stop_mode);
    connect(engine3_instante_mode_rb ,&QRadioButton::clicked, this, &Controller::engine3_instant_stop_mode);
    connect(engine4_instante_mode_rb ,&QRadioButton::clicked, this, &Controller::engine4_instant_stop_mode);
    connect(engine1_mild_mode_rb ,&QRadioButton::clicked, this, &Controller::engine1_mild_stop_mode);
    connect(engine2_mild_mode_rb ,&QRadioButton::clicked, this, &Controller::engine2_mild_stop_mode);
    connect(engine3_mild_mode_rb ,&QRadioButton::clicked, this, &Controller::engine3_mild_stop_mode);
    connect(engine4_mild_mode_rb ,&QRadioButton::clicked, this, &Controller::engine4_mild_stop_mode);
}


void Controller::forward_move_pb_handler(){
    _model.set_move_direction(Model::MoveDiractionNames::FORWARD);
    qDebug() << "forward_move_pb_handler";
}

void Controller::back_move_pb_handler(){
    _model.set_move_direction(Model::MoveDiractionNames::BACK);
    qDebug() << "back_move_pb_handler";
}

void Controller::right_move_pb_handler(){
    _model.set_move_direction(Model::MoveDiractionNames::RIGHT);
    qDebug() << "right_move_pb_handler";
}

void Controller::left_move_pb_handler(){
    _model.set_move_direction(Model::MoveDiractionNames::LEFT);
    qDebug() << "left_move_pb_handler";
}

void Controller::up_move_pb_handler(){
    _model.set_move_direction(Model::MoveDiractionNames::UP);
    qDebug() << "up_move_pb_handler";
}

void Controller::down_move_pb_handler(){
    _model.set_move_direction(Model::MoveDiractionNames::DOWN);
    qDebug() << "down_move_pb_handler";
}

void Controller::start_pb_handler(){
    _model.start();
    qDebug() << "start_pb_handler";

}
void Controller::stop_pb_handler(){
    _model.stop();
    qDebug() << "stop_pb_handler";
}

void Controller::go_to_pb_handler(){
    _model.go_to();
    qDebug() << "stop_pb_handler";
}

void Controller::move_pb_handler(){
    _model.move();
    qDebug() << "stop_pb_handler";
}


void Controller::engine1_speed_sp_handler(int value){
    _model.set_engine_speed(Model::EngineNumber::_1, value);
    qDebug() << "engine1 speed value: ";

}

void Controller::engine2_speed_sp_handler(int value){
    _model.set_engine_speed(Model::EngineNumber::_2, value);
    qDebug() << "engine2 speed value: ";
}

void Controller::engine3_speed_sp_handler(int value){
    _model.set_engine_speed(Model::EngineNumber::_3, value);
    qDebug() << "engine3 speed value: ";
}

void Controller::engine4_speed_sp_handler(int value){
    _model.set_engine_speed(Model::EngineNumber::_4, value);
    qDebug() << "engine4 speed value: ";
}


void Controller::engine1_boost_sp_handler(int value){
    _model.set_engine_boost(Model::EngineNumber::_1, value);
    qDebug() << "engine1 boost value: ";

}

void Controller::engine2_boost_sp_handler(int value){
    _model.set_engine_boost(Model::EngineNumber::_2, value);
    qDebug() << "engine2 boost value: ";
}

void Controller::engine3_boost_sp_handler(int value){
    _model.set_engine_boost(Model::EngineNumber::_3, value);
    qDebug() << "engine3 boost value: ";
}

void Controller::engine4_boost_sp_handler(int value){
    _model.set_engine_boost(Model::EngineNumber::_4, value);
    qDebug() << "engine4 boost value: ";
}

void Controller::x_coordinate_sp_handler(int value){
     _model.set_x_coortdinate(value);
    qDebug() << "x coordinate value: ";
}

void Controller::y_coordinate_sp_handler(int value){
   _model.set_y_coortdinate(value);
    qDebug() << "y coordinate value: ";
}

void Controller::z_coordinate_sp_handler(int value){
    _model.set_z_coortdinate(value);
    qDebug() << "z coordinate value: ";
}

void Controller::x_distance_sp_handler(int value){
    _model.set_x_distance(value);
    qDebug() << "x distance value: ";
}

void Controller::y_distance_sp_handler(int value){
    _model.set_y_distance(value);
    qDebug() << "y distance value: ";
}

void Controller::z_distance_sp_handler(int value){
    _model.set_z_distance(value);
    qDebug() << "z distance value: ";
}

void Controller::engine1_instant_stop_mode(){
    _model.set_stop_mode(Model::EngineNumber::_1, Model::StopMode::INSTANTE);
    qDebug() << "instant_stop_mode";
}

void Controller::engine2_instant_stop_mode(){
    _model.set_stop_mode(Model::EngineNumber::_2, Model::StopMode::INSTANTE);
    qDebug() << "instant_stop_mode";
}

void Controller::engine3_instant_stop_mode(){
    _model.set_stop_mode(Model::EngineNumber::_3, Model::StopMode::INSTANTE);
    qDebug() << "instant_stop_mode";
}

void Controller::engine4_instant_stop_mode(){
    _model.set_stop_mode(Model::EngineNumber::_4, Model::StopMode::INSTANTE);
    qDebug() << "instant_stop_mode";
}
void Controller::engine1_mild_stop_mode(){
    _model.set_stop_mode(Model::EngineNumber::_1, Model::StopMode::MILD);
    qDebug() << "mild_stop_mode";
}

void Controller::engine2_mild_stop_mode(){
    _model.set_stop_mode(Model::EngineNumber::_2, Model::StopMode::MILD);
    qDebug() << "mild_stop_mode";
}

void Controller::engine3_mild_stop_mode(){
    _model.set_stop_mode(Model::EngineNumber::_3, Model::StopMode::MILD);
    qDebug() << "mild_stop_mode";
}

void Controller::engine4_mild_stop_mode(){
    _model.set_stop_mode(Model::EngineNumber::_4, Model::StopMode::MILD);
    qDebug() << "mild_stop_mode";
}


void Controller::handleButton(){
    int a = 5;
    a = 10;
}
