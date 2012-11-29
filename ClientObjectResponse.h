/*
  By: Spencer Whyte
  #100817664
  Carleton University
  */

#ifndef CLIENTOBJECTRESPONSE_H
#define CLIENTOBJECTRESPONSE_H

#include "ClientXMLResponse.h"
#include "StorableInterface.h"
#includ "ClientObjectResponseDelegate.h"
#include <QList>
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
    ClientObjectResponse(int TCPSocket);
    /*
      Reads the response from the server and transcribes it
      into a list of objects. This list ob objects is then
      relayed back to the ClientObjectResponseDelegate.
      */
    fillRequest();

};

#endif // CLIENTOBJECTRESPONSE_H
