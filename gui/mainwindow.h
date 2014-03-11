#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <network/communicator.h>

namespace Ui {
    class MainWindow;
}

namespace ledcubesimulator {
namespace gui {

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void onLEDSizeChange(double s);

private:
    Ui::MainWindow *ui;
    network::Communicator *communicator;

};

} // end of namespace gui
} // end of namespace ledcubesimulator

#endif // MAINWINDOW_H
