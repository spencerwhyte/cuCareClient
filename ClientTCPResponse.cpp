#include "ClientTCPResponse.h"

// Getters
QTcpSocket* ClientTCPResponse::getSocket(){
    return socket;
}

void ClientTCPResponse::setSocket(QTcpSocket* newSocket){
    if(socket){
        delete socket;
    }
    socket = newSocket;
}

/*
 Creates a ClientTCPResponse where the given
 TCP socket is the socket over which the data
 will be sent.
  */
ClientTCPResponse::ClientTCPResponse() : socket(NULL) , allData(new QString()), dataReceived(false){
    QTimer * timeoutTimer = new QTimer();
    timeoutTimer->setInterval(8000);
    timeoutTimer->setSingleShot(true);
    timer = timeoutTimer;
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(responseTimeOut()));
}
ClientTCPResponse::~ClientTCPResponse() {
    delete timer;
}

void ClientTCPResponse::responseTimeOut(){
    TCPResponseFailed(QString("Error: Unable to connect to the cuCare central database at this time."));
}


/*
  Starts reading the tcp data received from
  the server into this internal buffer.
  */
int ClientTCPResponse::fillTCPResponse(){

   connect(socket, SIGNAL(readyRead()), this, SLOT(readyToReceive()));
   connect(socket, SIGNAL(disconnected()), this, SLOT(cannotReceive()));
}

/*
  This method gets called when more TCPData has
  been received. Override this method to receive
  all of the latest data.

        totalData - Input parameter containing
        all of the data that has been received
        thus far.
  */
void ClientTCPResponse::TCPResponseReceived(QString& totalData){

}

void ClientTCPResponse::TCPResponseFailed(QString errorMessage){

}


void ClientTCPResponse::cannotReceive(){
    if(!dataReceived){
        timer->stop();
        TCPResponseFailed(QString("Error: Unable to connect to the cuCare central server."));
    }
}

void ClientTCPResponse::readyToReceive(){
    timer->stop();
    dataReceived = true;
    socket->waitForReadyRead(10);
    QByteArray newData = socket->readAll();
    allData->append(newData);
    TCPResponseReceived(*allData);
}


