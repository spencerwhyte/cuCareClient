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
void ClientXMLResponse::XMLResponseReceived(QList<QMap<QString, QVariant> > &data, QString & className){
}


/*
  Overrides base class method to receive the
  body of the HTTP response.

        body - The body of the HTTP response
  */
void ClientXMLResponse::HTTPResponseReceived(QString &body){
    QList<QMap<QString, QVariant> > data;

    QString className;

    QDomDocument document("XMLDocument");
    document.setContent(body);

    QDomNode root = document.firstChildElement();


    QDomNodeList keyValues = root.childNodes();

    for(int i =0 ; i < keyValues.length(); i++){
        QDomNodeList doubleChildren = keyValues.at(i).childNodes();
        className = keyValues.at(i).nodeName();
        QMap<QString, QVariant> currentMap;
        for(int j = 0 ; j < doubleChildren.length(); j++){
            QDomNode node = doubleChildren.at(j);
            QString attributeName = node.nodeName();
            QVariant attributeValue(node.firstChild().nodeValue());
            currentMap.insert(attributeName, attributeValue);
        }
        data.append(currentMap);
    }
    XMLResponseReceived(data, className);
}
