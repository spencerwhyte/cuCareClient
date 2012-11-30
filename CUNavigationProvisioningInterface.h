#ifndef CUNAVIGATIONPROVISIONINGINTERFACE
#define CUNAVIGATIONPROVISIONINGINTERFACE

#include<QObject>
#include"User.h"

class CUNavigationProvisioningInterface : public QObject
{
    Q_OBJECT

    virtual void setUserType(User *user) = 0; //called by the login page when the user type may first be determined

public slots:
    virtual void back() = 0; //move back in the stack
    virtual void navigateFromLoginForm(int choice) = 0;
    virtual void navigateFromQueryDatabaseForm(int choice) = 0;
    virtual void navigateFromPatientRecordPage(int choice) = 0;
    virtual void navigateFromConsultationRecordPage(int choice) = 0;
    virtual void navigateFromHomePage(int choice) = 0;

};

#endif
