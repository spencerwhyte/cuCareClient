/*
  By: Spencer Whyte
  #100817664
  Carleton University
  */

#ifndef CLIENTOBJECTRESPONSE_H
#define CLIENTOBJECTRESPONSE_H

#include "ClientXMLResponse.h"
#include "StorableInterface.h"
#include "ClientObjectResponseDelegate.h"
#include <QList>
#include "StorableFactory.h"

/*

  The purpose of the ClientObjectResponse class is to provide
  the client with a uniform way of parsing object responses
  sent by the server.

*/

class ClientObjectResponse : public ClientXMLResponse
{
    ClientObjectResponseDelegate * delegate;
public:
    /*
      Creates a ClientObjectResponse that will be used
      to transcribe the response from the server from
      the data recieved over the given tcp socket.
      */
    ClientObjectResponse(ClientObjectResponseDelegate * delegate);
    /*
      Reads the response from the server and transcribes it
      into a list of objects. This list ob objects is then
      relayed back to the ClientObjectResponseDelegate.
      */
    int fillObjectResponse();
    /*
      Overiding method from ClientXMLResponse to receive the parsed
      XML data that was sent by the server.
      */
    virtual void XMLResponseReceived(QList<QMap<QString, QVariant> > & xmlData, QString & className);
    /*
      Gets called when the response fails to notify the delegate
      */
    void responseFailed(QString error);
    /*
      Gets called when the TCP response fails
      */
    void TCPResponseFailed(QString errorMessage);
};

#endif // CLIENTOBJECTRESPONSE_H
