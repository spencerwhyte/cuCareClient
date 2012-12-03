/*
Hashem Shawqi
Carleton University

This class will be called whenever a GUI page sends a navigation request. The page is evaluated and the appropriate
navigation for that page's factory is called
  */

#ifndef CUNAVIGATIONPROVISIONING
#define CUNAVIGATIONPROVISIONING

#include<QObject>
#include"CUNavigationStack.h"
#include"CUPageFactory.h"
#include"PhysicianPageFactory.h"
#include"AdministrativeAssistantPageFactory.h"
#include"User.h"
#include"CUNavigationProvisioningInterface.h"

class CUNavigationProvisioning : public CUNavigationProvisioningInterface
{
    Q_OBJECT

public:
    CUNavigationProvisioning(CUNavigationStack *stack);
    ~CUNavigationProvisioning();

public slots:
    void setUserType(User *user); //called by the login page when the user type may first be determined
    void back(); //move back in the stack
    void navigateFromLoginForm(int choice);
    void navigateFromQueryDatabaseForm(int choice, StorableInterface* object);
    void navigateFromPatientRecordPage(int choice, StorableInterface* object);
    void navigateFromConsultationRecordPage(int choice);
    void navigateFromHomePage(int choice);

private:
    User *currentUser;
    CUNavigationStack *applicationStack;
    CUPageFactory *userFactory;
};

#endif
