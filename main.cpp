#include <QApplication>
#include <QDesktopWidget>

#include "gui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ledcubesimulator::gui::MainWindow widget;
    widget.show();

    /*
    GLWindow window;
    window.resize(window.sizeHint());
    int desktopArea = QApplication::desktop()->width() *
                      QApplication::desktop()->height();
    int widgetArea = window.width() * window.height();
    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        window.show();
    else
        window.showMaximized();
    */
    return app.exec();
}
