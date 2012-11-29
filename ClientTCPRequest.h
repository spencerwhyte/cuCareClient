/*
  By: Spencer Whyte
  #100817664
  Carleton University
  */

#ifndef CLIENTTCPREQUEST_H
#define CLIENTTCPREQUEST_H
#include <QObject>
#include <QTcpSocket>
#include "ClientSettings.h"
/*
  The purpose of the ClientTCPRequest class is
  to provide the ability to send data to the
  server over a given TCP socket
  */

class ClientTCPRequest : public QObject
{
    Q_OBJECT
    QTcpSocket * socket;
    QString * data;

    QString * getData();
    QTcpSocket* getSocket();

    void setData(QString * newData);
    void setSocket(QTcpSocket * socket);

public:
    /*
      Creates an ClientTCPRequest object where TCPSocket is the socket
      that will be used for data transfer
      */
    ClientTCPRequest();
    //Destructor
    ~ClientTCPRequest();
    /*
      Fills a request by sending the given data over the network
      when the request has been filled, the TCPRequestFilled
      method is called. Override this method to implement additional
      functionality.
      */
    int fillTCPRequest(QString &data);
    /*
      This method gets called when all of the TCP data has been sent
      over to the server.
      */
    virtual void TCPRequestFilled();

public slots:

    void readyToSend();

};


#endif // CLIENTTCPREQUEST_H
