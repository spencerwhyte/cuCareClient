/*
  By: Spencer Whyte
  #100817664
  Carleton University
  */

#ifndef CLIENTOBJECTREQUEST_H
#define CLIENTOBJECTREQUEST_H

#include "ClientXMLRequest.h"
#include "ClientObjectResponseDelegate.h"
#include "ClientObjectResponse.h"
#include "StorableFactory.h"



/*
  The purpose of the client object request is to
  provide the service of transfering object over
  the network via the given TCP socket
  */

class ClientObjectRequest : public ClientXMLRequest
{
    // Internal
    // We dont retain delegates
    ClientObjectResponse * response;
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
    ClientObjectRequest(ClientObjectResponseDelegate * delegate,StorableInterface& object, ObjectRequestType type);


    // Destructor
    ~ClientObjectRequest();

private:
    /*
      Sends the given object to the server over http
      along with the given operation and the delegate
      who is responsible for handling the response.
      */

    int fillObjectRequest(StorableInterface& object, ObjectRequestType type);
    /*
      Overriding base method from TCP to know when the
      data has actually been sent to the server.
      */
    virtual void TCPRequestFilled();
    /*
      Overriding base method from TCP to know when
      the TCP request fails
      */
    virtual void TCPRequestFailed();

    // Helper method to help with constructing xml urls from the type of request
    QString& stringForObjectRequestType(ObjectRequestType type);
};

#endif // CLIENTOBJECTREQUEST_H
