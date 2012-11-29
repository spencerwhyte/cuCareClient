#include "ClientXMLRequest.h"

/*
  Constructs a new ClientXMLRequest with the
  TCP socket over which data will be sent.
  */
ClientXMLRequest::ClientXMLRequest(){

}

/*
    Fills the XML request by sending the
    data to the server in xml format.
  */
int ClientXMLRequest::fillXMLRequest(QMap<QString, QVariant> &data, QString & url){

    QString xmlText;



    fillHTTPRequest(xmlText, url);

}
