#include "communicator.h"

using namespace ledcubesimulator::network;

Communicator::Communicator(int port) {
    state = new types::LEDCubeState();
    server = new QTcpServer();
    connect(server, SIGNAL(newConnection()), this, SLOT(handleNewConnection()));
    server->listen(QHostAddress::Any, port); // TODO: check return value
}

Communicator::~Communicator() {
    server->close();
    delete state;
    delete server;
}

void Communicator::handleNewConnection() {
    while(server->hasPendingConnections()) {
        QTcpSocket *sock = server->nextPendingConnection();
        connect(sock, SIGNAL(readyRead()), this, SLOT(handleNewData()));
    }
}

void Communicator::handleNewData() {
    QTcpSocket *sock = qobject_cast<QTcpSocket *>(sender());
    if(sock) {
        while(sock->bytesAvailable() >= 16) {
            if(sock->read((char *)state->data, 16) == 16) {
                emit receivedLEDCubeState(state->data);
            }
        }
    }
}
