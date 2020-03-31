
#include <QApplication>
#include <view/view.h>
#include <QSpinBox>

using namespace view;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    view::View view;
    QSpinBox& engine1_boost = view.get_spinbox(View::SpinBoxNames::Engine1BoostSpinBox);
    engine1_boost.setValue(7);
    view.show();

    return a.exec();
}
