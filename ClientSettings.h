/*
  By: Spencer Whyte
  #100817664
  Carleton University
*/

#ifndef CLIENTSETTINGS_H
#define CLIENTSETTINGS_H

#include <QHostAddress>

/*
  The purpose of the client settings class
  is to manage all of the settings that
  are relevant to the client in particular

  */

class ClientSettings
{
public:
    static ClientSettings & GetClientSettings(){
        static ClientSettings currentSettings;
        return currentSettings;
    }
    // Getters
    QHostAddress& getDefaultAddress();
    qint16 getDefaultPort();
    // Setters
    void setDefaultPort(int newPort);
    void setDefaultAddress(QString & address);

private:
    QHostAddress * address;
    qint16 port;
    ClientSettings();
    ClientSettings(ClientSettings  const &);
      void operator=(ClientSettings const &);
};

#endif // CLIENTSETTINGS_H
