/*
  By: Spencer Whyte
  #100817664
  Carleton University
  */

#ifndef CLIENTHTTPRESPONSE_H
#define CLIENTHTTPRESPONSE_H

/*
  The purpose of the ClientHTTPResponse is to handle
  transcribing responses sent by the server to the
  client over a TCP socket
  */

#include "ClientTCPResponse.h"
#include <QStringList>

class ClientHTTPResponse : public ClientTCPResponse
{
public:
    /*
      Constructs a client http response with the
      the socket over which the HTTP data will be
      sent.
      */
    ClientHTTPResponse();
    /*
      Reads the body of the HTTP response from the
      server
      */
    int fillHTTPResponse();

    /*
      This method gets called when an HTTP response has been
      received. Override this method in the subclass to
      receive the data.

            body - The body of the HTTP request received
      */
    virtual void HTTPResponseReceived(QString &body);

    /*
      Overriding base method to receive data that was sent
      by the server
      */
    virtual void TCPResponseReceived(QString &totalData);
};

#endif // CLIENTHTTPRESPONSE_H
