#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include "window_cjj.h"

int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    MainWindow w;
    w.show();

    return app.exec();
}