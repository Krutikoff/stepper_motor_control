#pragma once
#include <string>
#include <QString>
#include <array>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QRadioButton>
#include "view/mainwindow.h"
#include <iostream>

namespace view {

using namespace std;


class View
{
    struct ButtonNames{
        string Start = "start";
    };

public:
    View() {
        QPushButton* start_button = _main_window.findChild<QPushButton*>("StartPushButton");
        QPushButton* close_button = _main_window.findChild<QPushButton*>("ClosePushButton");
        std::cout << close_button;
    }

    void show(){
        _main_window.show();
    }

    QPushButton& get_button(string& name);
    QCheckBox& get_checkbox(string& name);
    QLineEdit& get_lineedit(string& name);
    QRadioButton& get_radio_button(string& name);

private:

    enum class PushButtonNames{
        ForwardMovePushButton = 0,
        BackMovePushButton,
        LeftMovePushButton,
        RightMovePushButton,
        StartPushButton,
        StopPushButton,
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
        MildStopEngineRadioButton = 0,
        InstantStopEngineRadioButton,
        END,
    };

    MainWindow _main_window;

    array<QPushButton, 5> _button;
    array<QCheckBox, 5> _checkbox;
    array<QLineEdit, 5> _lineedit;
    array<QRadioButton, 5> _radio_button;
};


}
