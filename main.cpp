#include <QApplication>

#include "gui/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ledcubesimulator::gui::MainWindow widget;
    widget.show();
    return app.exec();
}
