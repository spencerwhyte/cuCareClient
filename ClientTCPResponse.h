/*
  By: Spencer Whyte
  #100817664
  Carleton University
  */

#ifndef CLIENTTCPRESPONSE_H
#define CLIENTTCPRESPONSE_H
#include <QObject>
#include <QTcpSocket>
/*
  The purpose of the ClientTCPResponse is to
  transcribe a response that has been sent by
  the server over TCP.
  */
class ClientTCPResponse : public QObject
{
    Q_OBJECT
    QTcpSocket * socket;

    QString * allData;
public:
    // Getters
    QTcpSocket* getSocket();
    void setSocket(QTcpSocket* newSocket);

    /*
     Creates a ClientTCPResponse where the given
     TCP socket is the socket over which the data
     will be sent.
      */
    ClientTCPResponse();
    /*
      Starts reading the tcp data received from
      the server into this internal buffer.
      */
    int fillTCPResponse();
    /*
      This method gets called when more TCPData has
      been received. Override this method to receive
      all of the latest data.

            totalData - Input parameter containing
            all of the data that has been received
            thus far.
      */
    virtual void TCPResponseReceived(QString& totalData);

    void readyToReceive();
};

#endif // CLIENTTCPRESPONSE_H
