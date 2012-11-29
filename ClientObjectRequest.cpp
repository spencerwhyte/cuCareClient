#include "ClientObjectRequest.h"
ClientObjectRequest::ClientObjectRequest(ClientObjectResponseDelegate * delegate) : response(new ClientObjectResponse(delegate)){

}

/*
  Sends the given object to the server over http
  along with the given operation and the delegate
  who is responsible for handling the response.
  */
int ClientObjectRequest::fillObjectRequest(StorableInterface& object, ObjectRequestType type){
    QMap<QString, QVariant> mapping;
    object.getAttributesAndValues(mapping);

    fillXMLRequest(mapping, object.className(), stringForObjectRequestType(type));

}


// Destructor
ClientObjectRequest::~ClientObjectRequest(){
    delete response;
}

/*
  Overriding base method from TCP to know when the
  data has actually been sent to the server.
  */
virtual void ClientObjectRequest::TCPRequestFilled(){
    response.fillObjectResponse();
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
    }else{
        static QString query("Query");
        return query;
    }
}
