/*
  By: Spencer Whyte
  #100817664
  Carleton University
  */

#ifndef CLIENTHTTPREQUEST_H
#define CLIENTHTTPREQUEST_H

#include "ClientTCPRequest.h"

#include <QString>

/*
  The purpose of the ClientHTTPRequest object is to provide
  the ability for clients to send data to the server over
  HTTP

  */

class ClientHTTPRequest : public ClientTCPRequest
{
private:
    // Socket descriptor
    int socket;
public:
    /*
      Creates a HTTP request obejct that will communicate with
      the server over the given tcp socket

      */
    ClientHTTPRequest(int socket);
    /*
      Destructor
      */
    ~ClientHTTPRequest();
    /*
     Fills a HTTP request by sending the data over the TCP
     connection to the specified url

            data - Input parameter for the data that is
            being sent

            url - Input parameter for the url that the
            data is being sent to

      */
    int fillHTTPRequest(QString &data, QString &url);

};

#endif // CLIENTHTTPREQUEST_H
