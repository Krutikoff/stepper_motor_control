
#include <QApplication>
#include <view/view.h>
#include <controller/controller.h>
#include <QSpinBox>


using namespace view;
using namespace controller;



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Controller controller;

    return a.exec();
}




