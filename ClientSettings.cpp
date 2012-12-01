#include "ClientSettings.h"

ClientSettings::ClientSettings() : port(60007), address(new QHostAddress("134.117.28.146")){


}

ClientSettings::~ClientSettings(){
    delete address;
}

QHostAddress& ClientSettings::getDefaultAddress(){
    return *address;
}

qint64 ClientSettings::getDefaultPort(){
    return port;
}

QString ClientSettings::getDefaultAddressString(){
    return address->toString();
}

QString ClientSettings::getDefaultPortString(){
    return QString::number(port);
}

// Setters
bool ClientSettings::setDefaultPortString(QString & portString){
    int newPort = portString.toInt();
    if(newPort != 0){
        port = newPort;
        return true;
    }else{
        return false;
    }
}

bool ClientSettings::setDefaultAddressString(QString & addressString){
        QHostAddress * newAddress = new QHostAddress();
        if(newAddress->setAddress(addressString)){
            delete address;
            address = newAddress;
            return true;
        }else{
            return false;
        }
}


