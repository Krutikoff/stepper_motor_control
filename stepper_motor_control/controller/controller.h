#pragma once
#include <view/view.h>
#include <QObject>

namespace controller {

using namespace view;

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = 0);


public slots:
    void handleButton();

    // Button handlers
    void forward_move_pb_handler();
    void back_move_pb_handler();
    void right_move_pb_handler();
    void left_move_pb_handler();
    void up_move_pb_handler();
    void down_move_pb_handler();
    void start_pb_handler();
    void stop_pb_handler();

    // Spinbox handlers
    void engine1_speed_sp_handler(int value);
    void engine2_speed_sp_handler(int value);
    void engine3_speed_sp_handler(int value);
    void engine4_speed_sp_handler(int value);

    void engine1_boost_sp_handler(int value);
    void engine2_boost_sp_handler(int value);
    void engine3_boost_sp_handler(int value);
    void engine4_boost_sp_handler(int value);

    void x_coordinate_sp_handler(int value);
    void y_coordinate_sp_handler(int value);
    void z_coordinate_sp_handler(int value);

    void x_distance_sp_handler(int value);
    void y_distance_sp_handler(int value);
    void z_distance_sp_handler(int value);

private:
    View _view;

    void _bind_signal_to_slot();
};
}
