/*
  By: Spencer Whyte
  #100817664
  Carleton University
*/

#ifndef CLIENTSETTINGS_H
#define CLIENTSETTINGS_H
#include <QFile>
#include <QHostAddress>
#include <QByteArray>
#include <QStringList>
#include <QSettings>

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
    qint64 getDefaultPort();
    QString getDefaultAddressString();
    QString getDefaultPortString();

    // Setters
    bool setDefaultPortString(QString & port);
    bool setDefaultAddressString(QString & address);

    void saveSettings();
    bool loadSettings();

    ~ClientSettings();
private:
    QHostAddress * address;
    qint64 port;

    QSettings * settings;

    ClientSettings();

    ClientSettings(ClientSettings  const &);
    void operator=(ClientSettings  const &);
};

#endif // CLIENTSETTINGS_H
