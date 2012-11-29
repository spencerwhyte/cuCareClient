/*
  By: Spencer Whyte
  #100817664
  Carleton University
  */

#ifndef CLIENTXMLREQUEST_H
#define CLIENTXMLREQUEST_H]

#include "ClientHTTPRequest.h"

/*
  The purpose of the ClientXMLRequest class is
  to handle sending XML data to the server over
  a given TCP connection
  */

class ClientXMLRequest : public ClientHTTPRequest
{
public:
    /*
      Constructs a new ClientXMLRequest with the
      TCP socket over which data will be sent.
      */
    ClientXMLRequest(int TCPSocket);
    /*
        Fills the XML request by sending the
        data to the server in xml format
      */
    int fillXMLRequest();
};

#endif // CLIENTXMLREQUEST_H
