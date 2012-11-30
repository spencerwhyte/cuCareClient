/*
  By: Spencer Whyte
  #100817664
  Carleton University
  */

#ifndef CLIENTXMLRESPONSE_H
#define CLIENTXMLRESPONSE_H

#include "ClientHTTPResponse.h"
#include <QMap>
#include <QDomDocument>
#include <QList>

/*
  The purpose of the ClientXMLResponse is to handle
  parsing XML responses sent by the server over TCP
 */

class ClientXMLResponse : public ClientHTTPResponse
{
public:
    /*
      Creates a new ClientXMLResponse with the
      TCP Socket over which the data will be sent
      */
    ClientXMLResponse();

    /*
       Call this method to initiate receiving
       XML data from the server
      */
    int fillXMLResponse();
    /*
      Gets called when the XML data has been
      received from the server.

            data - The XML data that was received
      */
    virtual void XMLResponseReceived(QList< QMap<QString, QVariant> > &data , QString & className);

    /*
      Overrides base class method to receive the
      body of the HTTP response.

            body - The body of the HTTP response
      */
    virtual void HTTPResponseReceived(QString &body);
};

#endif // CLIENTXMLRESPONSE_H
