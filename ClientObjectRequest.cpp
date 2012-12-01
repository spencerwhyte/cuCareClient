#include "ClientObjectRequest.h"
ClientObjectRequest::ClientObjectRequest(ClientObjectResponseDelegate * delegate, StorableInterface& object, ObjectRequestType type) : response(new ClientObjectResponse(delegate)){
    fillObjectRequest(object,type);
}

/*
  Sends the given object to the server over http
  along with the given operation and the delegate
  who is responsible for handling the response.
  */
int ClientObjectRequest::fillObjectRequest(StorableInterface& object, ObjectRequestType type){
    QMap<QString, QVariant> mapping;
    object.getAttributesAndValues(mapping);
    QString name = object.className();
    fillXMLRequest(mapping, name, stringForObjectRequestType(type));

}


// Destructor
ClientObjectRequest::~ClientObjectRequest(){
    delete response;
}

/*
  Overriding base method from TCP to know when the
  data has actually been sent to the server.
  */
void ClientObjectRequest::TCPRequestFilled(){
    response->setSocket(getSocket());
    response->fillObjectResponse();
}


void ClientObjectRequest::TCPRequestFailed(){
    response->responseFailed(QString("Error: Unable to connect to the cuCare central server."));
}

// Helper method to help with constructing xml urls from the type of request
QString& ClientObjectRequest::stringForObjectRequestType(ObjectRequestType type){
    if(type == Add){
        static QString add("Add");
        return add;
    }else if(type == Edit){
        static QString edit("Edit");
        return edit;
    }else if(type == Remove){
        static QString remove ("Remove");
        return remove;
    }else if(type == Query){
        static QString query("Query");
        return query;
    }else{
        static QString query("EqualityQuery");
        return query;
    }
}
