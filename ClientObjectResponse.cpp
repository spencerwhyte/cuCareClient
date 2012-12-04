#include "ClientObjectResponse.h"

/*
  Creates a ClientObjectResponse that will be used
  to transcribe the response from the server from
  the data recieved over the given tcp socket.
  */
ClientObjectResponse::ClientObjectResponse(ClientObjectResponseDelegate * d): delegate(d){

}

/*
  Reads the response from the server and transcribes it
  into a list of objects. This list ob objects is then
  relayed back to the ClientObjectResponseDelegate.
  */
int ClientObjectResponse::fillObjectResponse(){
    fillXMLResponse();
}

/*
  Overiding method from ClientXMLResponse to receive the parsed
  XML data that was sent by the server.
  */
void ClientObjectResponse::XMLResponseReceived(QList<QMap<QString, QVariant> > &data, QString & className){
    QList<StorableInterface*> * objects  = new QList<StorableInterface*>();
    for(int i =0 ; i < data.length(); i++){
        StorableInterface * current = StorableFactory::GetFactory().getInstance(className);
        current->setAttributesAndValues(data.at(i));

        objects->append(current);
    }

    delegate->didSuccessfullyReceiveResponse(objects);



}

void ClientObjectResponse::responseFailed(QString error){
    delegate->didReceiveError(error);
}

  void ClientObjectResponse::TCPResponseFailed(QString errorMessage){
      responseFailed(errorMessage);
  }
