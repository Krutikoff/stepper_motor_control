#include <controller/controller.h>
#include <QCoreApplication>
#include <QDebug>
#include <QPushButton>
#include <QSpinBox>
#include <QRadioButton>


using namespace controller;


Controller::Controller(QObject *parent) : QObject(parent){

//    QSpinBox& engine1_boost = _view.get_spinbox(View::SpinBoxNames::Engine1BoostSpinBox);
//    engine1_boost.setValue(7);

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
    QPushButton* start_move_pb = _view.get_push_button(View::PushButtonNames::StartPushButton);
    QPushButton* stop_move_pb = _view.get_push_button(View::PushButtonNames::StopPushButton);

    connect(forward_move_pb, &QPushButton::pressed, this, &Controller::forward_move_pb_handler);
    connect(back_move_pb, &QPushButton::pressed, this, &Controller::back_move_pb_handler);
    connect(right_move_pb, &QPushButton::pressed, this, &Controller::right_move_pb_handler);
    connect(left_move_pb, &QPushButton::pressed, this, &Controller::left_move_pb_handler);
    connect(up_move_pb, &QPushButton::pressed, this, &Controller::up_move_pb_handler);
    connect(down_move_pb, &QPushButton::pressed, this, &Controller::down_move_pb_handler);
    connect(start_move_pb, &QPushButton::pressed, this, &Controller::start_pb_handler);
    connect(stop_move_pb, &QPushButton::pressed, this, &Controller::stop_pb_handler);

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

}


void Controller::forward_move_pb_handler(){
    qDebug() << "forward_move_pb_handler";
}

void Controller::back_move_pb_handler(){
    qDebug() << "back_move_pb_handler";
}

void Controller::right_move_pb_handler(){
    qDebug() << "right_move_pb_handler";
}

void Controller::left_move_pb_handler(){
    qDebug() << "left_move_pb_handler";
}

void Controller::up_move_pb_handler(){
    qDebug() << "up_move_pb_handler";
}

void Controller::down_move_pb_handler(){
    qDebug() << "down_move_pb_handler";
}

void Controller::start_pb_handler(){
    qDebug() << "start_pb_handler";
}
void Controller::stop_pb_handler(){
    qDebug() << "stop_pb_handler";
}


void Controller::engine1_speed_sp_handler(int value){
    auto v = value;
    qDebug() << "engine1 speed value: " << v;

}

void Controller::engine2_speed_sp_handler(int value){
    auto v = value;
    qDebug() << "engine2 speed value: " << v;
}

void Controller::engine3_speed_sp_handler(int value){
    auto v = value;
    qDebug() << "engine3 speed value: " << v;
}

void Controller::engine4_speed_sp_handler(int value){
    auto v = value;
    qDebug() << "engine4 speed value: " << v;
}


void Controller::engine1_boost_sp_handler(int value){
    auto v = value;
    qDebug() << "engine1 boost value: " << v;

}

void Controller::engine2_boost_sp_handler(int value){
    auto v = value;
    qDebug() << "engine2 boost value: " << v;
}

void Controller::engine3_boost_sp_handler(int value){
    auto v = value;
    qDebug() << "engine3 boost value: " << v;
}

void Controller::engine4_boost_sp_handler(int value){
    auto v = value;
    qDebug() << "engine4 boost value: " << v;
}

void Controller::x_coordinate_sp_handler(int value){
    auto v = value;
    qDebug() << "x coordinate value: " << v;
}

void Controller::y_coordinate_sp_handler(int value){
    auto v = value;
    qDebug() << "y coordinate value: " << v;
}

void Controller::z_coordinate_sp_handler(int value){
    auto v = value;
    qDebug() << "z coordinate value: " << v;
}

void Controller::x_distance_sp_handler(int value){
    auto v = value;
    qDebug() << "x distance value: " << v;
}

void Controller::y_distance_sp_handler(int value){
    auto v = value;
    qDebug() << "y distance value: " << v;
}

void Controller::z_distance_sp_handler(int value){
    auto v = value;
    qDebug() << "z distance value: " << v;
}

void Controller::handleButton(){
    int a = 5;
    a = 10;
}
