#include "ClientSettings.h"

ClientSettings::ClientSettings() : port(60007), address(new QHostAddress("134.117.28.146")){
    settings = new QSettings(QString("./settings.txt"), QSettings::NativeFormat);
    loadSettings();

}

ClientSettings::~ClientSettings(){
    delete address;
    delete settings;
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
/*
  Saves the clients settings to the local file system
  */
void  ClientSettings::saveSettings(){
    settings->setValue(QString("port"), QVariant(port));
    settings->setValue(QString("address"), QVariant(QString(getDefaultAddressString())));
}

/*
  Loads the clients settings from the local file system
  */
bool ClientSettings::loadSettings(){
    QVariant portResult = settings->value(QString("port"), QVariant(60007));
    port = portResult.toInt();
    QVariant addressResult = settings->value(QString("address"),QVariant("134.117.28.146"));
    QString addressString = addressResult.toString();
    setDefaultAddressString(addressString);
}

// Setters
bool ClientSettings::setDefaultPortString(QString & portString){
    int newPort = portString.toInt();
    if(newPort != 0){
        if(port!=newPort){
            port = newPort;
            saveSettings();
        }else{
            port = newPort;
        }
        return true;
    }else{
        return false;
    }
}

bool ClientSettings::setDefaultAddressString(QString & addressString){
        QHostAddress * newAddress = new QHostAddress();
        if(newAddress->setAddress(addressString)){
            if(QString::compare(address->toString() , newAddress->toString()) != 0){
                delete address;
                address = newAddress;
                saveSettings();
            }else{
                delete newAddress;
            }
            return true;
        }else{
            return false;
        }
}


