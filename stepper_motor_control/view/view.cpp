#include "view.h"

using namespace view;

View::View() {
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

QPushButton* View::get_push_button(PushButtonNames name){
    auto index = static_cast<uint32_t>(name);
    QPushButton* button = _push_button[index];
    return button;
}

QSpinBox& View::get_spinbox(SpinBoxNames name){
    auto index = static_cast<uint32_t>(name);
    QSpinBox* spinbox = _spinbox[index];
    return *spinbox;
}

QRadioButton& View::get_radio_button(RadioButtonNames name){
    auto index = static_cast<uint32_t>(name);
    QRadioButton* radio_button = _radio_button[index];
    return *radio_button;
}

