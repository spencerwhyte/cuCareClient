/*
  By: Spencer Whyte
  #100817664
  Carleton University
  */

#ifndef CLIENTTCPREQUEST_H
#define CLIENTTCPREQUEST_H

/*
  The purpose of the ClientTCPRequest class is
  to provide the ability to send data to the
  server over a given TCP socket
  */

class ClientTCPRequest
{
    int socket;
public:
    /*
      Creates an object where TCPSocket is the socket
      that will be used for data transfer
      */
    ClientTCPRequest(int TCPSocket);

    fillRequest();

};


#endif // CLIENTTCPREQUEST_H
