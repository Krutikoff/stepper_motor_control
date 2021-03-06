#pragma once
#include <string>
#include <QString>
#include <array>
#include <QPushButton>
#include <QSpinBox>
#include <QLineEdit>
#include <QRadioButton>
#include "view/mainwindow.h"
#include <iostream>

namespace view {

using namespace std;


class View
{
public:
    enum class PushButtonNames{
        ForwardMovePushButton = 0,
        BackMovePushButton,
        LeftMovePushButton,
        RightMovePushButton,
        UpMovePushButton,
        DownMovePushButton,
        StartPushButton,
        StopPushButton,
        GoToPushButton,
        MovePushButton,
        END,
    };

    enum class SpinBoxNames{
        XCoordinateSpinBox = 0,
        YCoordinateSpinBox,
        ZCoordinateSpinBox,
        XDistanceSpinBox,
        YDistanceSpinBox,
        ZDistanceSpinBox,
        Engine1SpeedSpinBox,
        Engine2SpeedSpinBox,
        Engine3SpeedSpinBox,
        Engine4SpeedSpinBox,
        Engine1BoostSpinBox,
        Engine2BoostSpinBox,
        Engine3BoostSpinBox,
        Engine4BoostSpinBox,
        END,
    };

    enum class RadioButtonNames{
        MildStopEngine1RadioButton = 0,
        MildStopEngine2RadioButton,
        MildStopEngine3RadioButton,
        MildStopEngine4RadioButton,
        InstantStopEngine1RadioButton,
        InstantStopEngine2RadioButton,
        InstantStopEngine3RadioButton,
        InstantStopEngine4RadioButton,
        END,
    };

    View();

    void show(){
        _main_window.show();
    }

    QPushButton* get_push_button(PushButtonNames name);
    QSpinBox* get_spinbox(SpinBoxNames name);
    QRadioButton* get_radio_button(RadioButtonNames name);

signals:
    void valueChanged(int newValue);

private:



    static constexpr auto PUSH_BUTTON_COUNT =  static_cast<unsigned int>(PushButtonNames::END);
    static constexpr auto SPINBOX_COUNT = static_cast<unsigned int>(SpinBoxNames::END);
    static constexpr auto RADIO_BUTTON_COUNT = static_cast<unsigned int>(RadioButtonNames::END);

    array<QString, PUSH_BUTTON_COUNT> push_button_names = {{
        "ForwardMovePushButton",
        "BackMovePushButton",
        "LeftMovePushButton",
        "RightMovePushButton",
        "UpMovePushButton",
        "DownMovePushButton",
        "StartPushButton",
        "StopPushButton",
        "GoToPushButton",
        "MovePushButton",
    }};

    array<QString, SPINBOX_COUNT> spinbox_names = {{
        "XCoordinateSpinBox",
        "YCoordinateSpinBox",
        "ZCoordinateSpinBox",
        "XDistanceSpinBox",
        "YDistanceSpinBox",
        "ZDistanceSpinBox",
        "Engine1SpeedSpinBox",
        "Engine2SpeedSpinBox",
        "Engine3SpeedSpinBox",
        "Engine4SpeedSpinBox",
        "Engine1BoostSpinBox",
        "Engine2BoostSpinBox",
        "Engine3BoostSpinBox",
        "Engine4BoostSpinBox",
    }};

    array<QString, RADIO_BUTTON_COUNT> radio_button_names = {{
        "MildStopEngine1RadioButton",
        "MildStopEngine2RadioButton",
        "MildStopEngine3RadioButton",
        "MildStopEngine4RadioButton",
        "InstantStopEngine1RadioButton",
        "InstantStopEngine2RadioButton",
        "InstantStopEngine3RadioButton",
        "InstantStopEngine4RadioButton",
    }};


    MainWindow _main_window;

    vector<QPushButton*> _push_button;
    vector<QSpinBox*> _spinbox;
    vector<QRadioButton*> _radio_button;
};


}
