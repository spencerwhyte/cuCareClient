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

class ClientHTTPResponse : public ClientTCPResponse
{
public:
    /*
      Constructs a client http response with the
      the socket over which the HTTP data will be
      sent.
      */
    ClientHTTPResponse(int TCPSocket);
    /*
      Reads the body of the HTTP response from the
      server

            body - Output parameter used to store
            the body of the HTTP response sent by the server.
      */
    fillHTTPResponse(QString &body);
};

#endif // CLIENTHTTPRESPONSE_H
