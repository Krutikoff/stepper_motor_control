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

    std::array<QPushButton, 5> _button;
    std::array<QCheckBox, 5> _checkbox;
    std::array<QLineEdit, 5> _lineedit;
    std::array<QRadioButton, 5> _radio_button;
    MainWindow _main_window;
};


}
