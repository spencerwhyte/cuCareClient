#include "ClientObjectRequest.h"
ClientObjectRequest::ClientObjectRequest(ClientObjectResponseDelegate * delegate, StorableInterface& object, ObjectRequestType t) : response(new ClientObjectResponse(delegate)), type(t){
    fillObjectRequest(object,t);
}

/*
  Sends the given object to the server over http
  along with the given operation and the delegate
  who is responsible for handling the response.
  */
int ClientObjectRequest::fillObjectRequest(StorableInterface& object, ObjectRequestType t){
    QMap<QString, QVariant> mapping;
    object.getAttributesAndValues(mapping);
    QString name = object.className();
    fillXMLRequest(mapping, name, stringForObjectRequestType(t));

}

ClientObjectRequest::ObjectRequestType ClientObjectRequest::getType(){
    return type;
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
QString& ClientObjectRequest::stringForObjectRequestType(ObjectRequestType t){
    if(t == Add){
        static QString add("Add");
        return add;
    }else if(t == Edit){
        static QString edit("Edit");
        return edit;
    }else if(t == Remove){
        static QString remove ("Remove");
        return remove;
    }else if(t == Query){
        static QString query("Query");
        return query;
    }else{
        static QString query("EqualityQuery");
        return query;
    }
}
