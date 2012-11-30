#include "ClientHTTPRequest.h"

/*
  Creates a HTTP request obejct that will communicate with
  the server over the given tcp socket

  */
ClientHTTPRequest::ClientHTTPRequest(){

}

/*
  Destructor
  */
ClientHTTPRequest::~ClientHTTPRequest(){

}

/*
 Fills a HTTP request by sending the data over the TCP
 connection to the specified url

        data - Input parameter for the data that is
        being sent

        url - Input parameter for the url that the
        data is being sent to

  */
int ClientHTTPRequest::fillHTTPRequest(QString &data, QString &url){
    QString dataToBeSent;

    dataToBeSent.append("POST ");
    dataToBeSent.append(url);
    dataToBeSent.append(" HTTP/1.1\r\n");

    dataToBeSent.append("Content-Length: ");
    dataToBeSent.append(new QString(QString::number(data.length())));
    dataToBeSent.append("\r\n");
    dataToBeSent.append("\r\n");

    dataToBeSent.append(data);

    fillTCPRequest(dataToBeSent);
    return 0;
}
