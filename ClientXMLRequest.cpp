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
int ClientXMLRequest::fillXMLRequest(QMap<QString, QVariant> &data, QString &objectName, QString & operation){
    QString xmlText;

    QXmlStreamWriter writer(&xmlText);

    writer.writeStartDocument();

    writer.writeStartElement(objectName);

    QList<QString> keys = data.keys();
    QList<QVariant> values = data.values();

    for(int i = 0; i < keys.length(); i++){
        writer.writeTextElement(keys.at(i), values.at(i).toString());
    }

    writer.writeEndElement();

    fillHTTPRequest(xmlText, url);

}
