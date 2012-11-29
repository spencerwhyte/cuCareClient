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

    QString url;
    url.append("/");
    if(type ){
        url.append();
    }else{
        url.append();
    }
    fillXMLRequest(mapping, url);
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
