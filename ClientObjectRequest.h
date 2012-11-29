/*
  By: Spencer Whyte
  #100817664
  Carleton University
  */

#ifndef CLIENTOBJECTREQUEST_H
#define CLIENTOBJECTREQUEST_H

#include "ClientXMLRequest.h"
#include "ClientObjectResponseDelegate.h"

#include "StorableFactory.h"



/*
  The purpose of the client object request is to
  provide the service of transfering object over
  the network via the given TCP socket
  */

class ClientObjectRequest : public ClientXMLRequest
{
public:
    typedef enum ObjectRequestType{
        Add,
        Edit,
        Remove,
        Query
    } ObjectRequestType;
    /*
      Constructs a client object request which is
      used to send an object to the server over the
      given tcp socket.
      */
    ClientObjectRequest(int TCPSocket);
    /*
      Sends the given object to the server over http
      along with the given operation and the delegate
      who is responsible for handling the response.
      */
    int fillObjectRequest(StorableInterface& object, ClientObjectResponseDelegate * delegate, ObjectRequestType type);
    // Destructor
    ~ClientObjectRequest();
};

#endif // CLIENTOBJECTREQUEST_H
