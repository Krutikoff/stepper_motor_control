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
//        strint

        QPushButton* start_button = w.findChild<QPushButton*>("StartPushButton");
        QPushButton* close_button = w.findChild<QPushButton*>("ClosePushButton");
        std::cout << close_button;
    }

    void show(){
        w.show();
    }

    QPushButton& get_button(string& name);
    QCheckBox& get_checkbox(string& name);
    QLineEdit& get_lineedit(string& name);
    QRadioButton& get_radio_button(string& name);

private:
    MainWindow w;

    std::array<QPushButton, 5> _button;
    std::array<QCheckBox, 5> _checkbox;
    std::array<QLineEdit, 5> _lineedit;
    std::array<QRadioButton, 5> _radio_button;
};


}
