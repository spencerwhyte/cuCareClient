#include "ClientSettings.h"

ClientSettings::ClientSettings() : port(60007), address(new QHostAddress("134.117.28.146")){


}

ClientSettings::~ClientSettings(){
    delete address;
}

QHostAddress& ClientSettings::getDefaultAddress(){
    return *address;
}

qint16 ClientSettings::getDefaultPort(){
    return port;
}

void  ClientSettings::setDefaultAddress(QString &newAddress){
    delete address;
    address = new QHostAddress(newAddress);
}

void ClientSettings::setDefaultPort(int newPort){
    port = newPort;
}

