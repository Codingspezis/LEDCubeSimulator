#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QTcpServer>
#include <QTcpSocket>

#include <types/ledcubestate.h>

namespace ledcubesimulator {
namespace network {

class Communicator : public QObject
{
    Q_OBJECT

public:
    Communicator(int port);
    ~Communicator();

signals:
    void receivedLEDCubeState(quint8 *data);

protected slots:
    void handleNewConnection();
    void handleNewData();

private:
    QTcpServer *server;
    types::LEDCubeState *state;

};

} // end of namespace network
} // end of namespace ledcubesimulator

#endif // COMMUNICATOR_H
