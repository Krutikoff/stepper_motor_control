#include <controller/controller.h>
#include <QCoreApplication>

using namespace controller;


Controller::Controller(QObject *parent) : QObject(parent){

    QPushButton* forward_move_pb = _view.get_push_button(View::PushButtonNames::ForwardMovePushButton);
    connect(forward_move_pb, &QPushButton::pressed, this, &Controller::handleButton);


    QSpinBox& engine1_boost = _view.get_spinbox(View::SpinBoxNames::Engine1BoostSpinBox);
    engine1_boost.setValue(7);
    _view.show();
}


void Controller::handleButton(){
    int a = 5;
    a = 10;
}
