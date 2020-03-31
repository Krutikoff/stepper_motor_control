#include "view.h"

using namespace view;

View::View() {
    QPushButton* start_button = _main_window.findChild<QPushButton*>("StartPushButton");
    QPushButton* close_button = _main_window.findChild<QPushButton*>("ClosePushButton");
    std::cout << close_button;

    for(const auto& name : push_button_names){
        QPushButton* ui_element_ptr = _main_window.findChild<QPushButton*>(name);
        _push_button.push_back(ui_element_ptr);
    }

    for(const auto& name : spinbox_names){
        QSpinBox* ui_element_ptr = _main_window.findChild<QSpinBox*>(name);
        _spinbox.push_back(ui_element_ptr);
    }

    for(const auto& name : radio_button_names){
        QRadioButton* ui_element_ptr = _main_window.findChild<QRadioButton*>(name);
        _radio_button.push_back(ui_element_ptr);
    }
}

QPushButton& View::get_push_button(PushButtonNames name){
    auto index = static_cast<uint32_t>(name);
    QPushButton* button = _push_button[index];
    return *button;
}

QSpinBox& View::get_spinbox(SpinBoxNames name){
    auto index = static_cast<uint32_t>(name);
    QSpinBox* spinbox = _spinbox[index];
    return *spinbox;
}

