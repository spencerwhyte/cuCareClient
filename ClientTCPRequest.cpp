#include "ClientTCPRequest.h"

/*
  Creates an ClientTCPRequest object where TCPSocket is the socket
  that will be used for data transfer
  */
ClientTCPRequest::ClientTCPRequest() : socket(new QTcpSocket(this)), data(new QString()), totalBytesSent(0), timer(NULL){
    QTimer * timeoutTimer = new QTimer();
    timeoutTimer->setInterval(8000);
    timeoutTimer->setSingleShot(true);
    timer = timeoutTimer;
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(connectionTimedOut()));
    connect(getSocket(), SIGNAL(connected()), this, SLOT(readyToSend()));
    connect(getSocket(), SIGNAL(bytesWritten(qint64)), this, SLOT(dataSent(qint64)));
}

ClientTCPRequest::~ClientTCPRequest(){
    delete data;
    delete timer;
}



void ClientTCPRequest::dataSent(qint64 bytesSent){
    totalBytesSent += bytesSent;
    if(totalBytesSent == data->length()){
        timer->stop();
        TCPRequestFilled();
    }
}

void ClientTCPRequest::connectionTimedOut(){

    TCPRequestFailed();
    socket->disconnect();
}

void ClientTCPRequest::readyToSend(){
    timer->stop();
    if(getSocket()->state()==QAbstractSocket::ConnectedState){
        QByteArray dataToSend;
        dataToSend.append(*data);
        getSocket()->write(dataToSend);
    }else{
        timer->stop();;
        TCPRequestFailed();
    }
}

// Setters

void ClientTCPRequest::setSocket(QTcpSocket * newSocket){
    socket = newSocket;
}

void ClientTCPRequest::setData(QString *newData){
    delete data;
    data = newData;
}

// Getters
QTcpSocket * ClientTCPRequest::getSocket(){
    return socket;
}

QString * ClientTCPRequest::getData(){
    return data;
}



/*
  Fills a request by sending the given data over the network
  when the request has been filled, the TCPRequestFilled
  method is called. Override this method to implement additional
  functionality.
  */
int ClientTCPRequest::fillTCPRequest(QString &data){

    setData(new QString(data));

    getSocket()->connectToHost(ClientSettings::GetClientSettings().getDefaultAddress(), ClientSettings::GetClientSettings().getDefaultPort());

}

/*
  This method gets called when all of the TCP data has been sent
  over to the server.
  */
void ClientTCPRequest::TCPRequestFilled(){

}

/*
  This method gets called when the TCP connection
  fails.
  */
void ClientTCPRequest::TCPRequestFailed(){

}
