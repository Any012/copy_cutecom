#include <QApplication>

#include "mainwindow.h"
#include "controlpanel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow win(nullptr);
//    ControlPanel win(nullptr);
    win.show();

    return app.exec();
}
