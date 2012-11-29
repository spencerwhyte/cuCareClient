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
ClientTCPResponse::ClientTCPResponse() : socket(NULL) , allData(new QString()){

}

/*
  Starts reading the tcp data received from
  the server into this internal buffer.
  */
int ClientTCPResponse::fillTCPResponse(){
   connect(socket, SIGNAL(readyRead()), this, SLOT(readyToReceive()));
   readyToReceive();
}

/*
  This method gets called when more TCPData has
  been received. Override this method to receive
  all of the latest data.

        totalData - Input parameter containing
        all of the data that has been received
        thus far.
  */
virtual void ClientTCPResponse::TCPResponseReceived(QString& totalData){

}

void ClientTCPResponse::readyToReceive(){
    socket->waitForReadyRead(10);
    QByteArray newData = socket->readAll();
    allData->append(newData);
    TCPResponseReceived(*allData);
}


