#include "ClientSettings.h"

ClientSettings::ClientSettings() : port(60000), address(new QHostAddress(QHostAddress::LocalHost)){


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

void setDefaultAddress(QString &newAddress){
    delete address;
    address = new QHostAddress(newAddress);
}

void setDefaultPort(int newPort){
    port = newPort;
}

