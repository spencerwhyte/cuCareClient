/*
Hashem Shawqi
Carleton University

This page would already contain previously set networking configurations
These may be changed, affecting the network settings on the current system
  */

#ifndef IPADDRESSCONFIGURATIONFORM
#define IPADDRESSCONFIGURATIONFORM

#include"CUPage.h"
#include"CUFormElement.h"
#include"CUServerRequestButton.h"
#include "ClientSettings.h"
#include <QMessageBox>



class IPAddressConfigurationForm : public CUPage
{
    Q_OBJECT

public:
    IPAddressConfigurationForm(CUNavigationProvisioningInterface *pNavigator);
    ~IPAddressConfigurationForm();

public slots:
    void submitButtonClicked();

signals:
    void goBack();

private:
    QLabel *instructionLabel; //informs user what to input
    CUFormElement *ipAddressEntry;
    CUFormElement *portNumberEntry;
    CUServerRequestButton *submitButton;
};

#endif
