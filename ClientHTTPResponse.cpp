#include "ClientHTTPResponse.h"

/*
  Constructs a client http response with the
  the socket over which the HTTP data will be
  sent.
  */
ClientHTTPResponse::ClientHTTPResponse(){

}

/*
  Reads the body of the HTTP response from the
  server
  */
int ClientHTTPResponse::fillHTTPResponse(){
    fillTCPResponse();
}

/*
  This method gets called when an HTTP response has been
  received. Override this method in the subclass to
  receive the data.

        body - The body of the HTTP request received

        */

void ClientHTTPResponse::HTTPResponseReceived(QString &body){

}


/*
  Overriding base method to receive data that was sent
  by the server
  */
void ClientHTTPResponse::TCPResponseReceived(QString &totalData){

    QStringList responseList = totalData.split("\r\n");
    if(responseList.length() < 2){ // We need to at least have a header and a body
        return;
    }
    QString header = responseList.at(0);

    QStringList headerList = header.split("\n");
    if(headerList.length() < 2){ // We need to at least have the protocol header and content length
        return;
    }

    QString protocolHeader = headerList.at(0);

    QStringList protocolList = header.split(" ");
    if(protocolList.length() < 3){ // The protocol header has to have it's three parts
        return;
    }

    QString protocol = protocolList.at(0);

    QString code = protocolList.at(1);

    QString other = protocolList.at(2);

    QString contentLength = headerList.at(1);

    int contentLengthInteger = contentLength.toInt();

    if(totalData.length() != header.length() + 2 + contentLengthInteger){ // We need to have all of the content
        return;
    }

    QString responseData = totalData.right(contentLengthInteger);

    HTTPResponseReceived(responseData);

}
