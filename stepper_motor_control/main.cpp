
#include <QApplication>
#include <view/view.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    view::View view;
    view.show();

    return a.exec();
}
