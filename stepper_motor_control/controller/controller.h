#pragma once
#include <view/view.h>
#include <QPushButton>
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

private:
    View _view;
};
}
