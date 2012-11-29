#include "ClientXMLResponse.h"

/*
  Creates a new ClientXMLResponse with the
  TCP Socket over which the data will be sent
  */
ClientXMLResponse::ClientXMLResponse(){

}

/*
   Call this method to initiate receiving
   XML data from the server
  */
int ClientXMLResponse::fillXMLResponse(){
    fillHTTPResponse();
}

/*
  Gets called when the XML data has been
  received from the server.

        data - The XML data that was received
  */
void ClientXMLResponse::XMLReponseReceived(QMap<QString, QVariant> &data, QString & className){

}

/*
  Overrides base class method to receive the
  body of the HTTP response.

        body - The body of the HTTP response
  */
void ClientXMLResponse::HTTPResponseReceived(QString &body){
    QMap<QString, QVariant> data;

    QString className;

    QDomDocument document("XMLDocument");
    document.setContent(body);

    QDomNode root = document.firstChild();
    className = root.nodeName();
    QDomNodeList keyValues = root.childNodes();
    for(int i =0 ; i < root.childNodes().length(); i++){
        QDomNode node = keyValues.at(i);
        data.insert(node.nodeName(), node.nodeValue());
    }

    XMLReponseReceived(data, className);
}
