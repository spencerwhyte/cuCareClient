#include"CUNavigationProvisioning.h"
#include<QDebug>

CUNavigationProvisioning::CUNavigationProvisioning(CUNavigationStack *stack)
{
    applicationStack = stack;
    currentUser = 0;
    userFactory = 0;
}

CUNavigationProvisioning::~CUNavigationProvisioning()
{

}

void CUNavigationProvisioning::back()
{
    applicationStack->pop();
}

// the user factory is initialized here
void CUNavigationProvisioning::setUserType(User *user)
{
    currentUser = user;
    // declare the user according to the appropriate factory
    switch(user->getUserType())
    {
        case User::Physician:
            userFactory = new PhysicianPageFactory(this);
            break;
        case User::MedicalPersonnel:
            userFactory = new AdministrativeAssistantPageFactory(this);
            break;
        case User::Administrator:
            break;
        case User::Invalid:
            break;
    }

    userFactory->navigateFromLoginForm(0);
}

void CUNavigationProvisioning::navigateFromLoginForm(int choice)
{
    //if the choice is 1, then the page requested is a networking configuration page
    //at this stage the page factory is not constructed yet. Therefore, we respond
    //with the appropriate page directly from here
    if(choice == 1)
    {
        IPAddressConfigurationForm *newPage = new IPAddressConfigurationForm(this);
        applicationStack->push(newPage);
        return;
    }
    userFactory->navigateFromLoginForm(choice);
}

void CUNavigationProvisioning::navigateFromQueryDatabaseForm(int choice)
{
    userFactory->navigateFromQueryDatabaseForm(choice);
}

void CUNavigationProvisioning::navigateFromPatientRecordPage(int choice)
{
    userFactory->navigateFromPatientRecordPage(choice);
}

void CUNavigationProvisioning::navigateFromConsultationRecordPage(int choice)
{
    QWidget* newPage = userFactory->navigateFromConsultationRecordPage(choice);
    applicationStack->push(newPage);
}

void CUNavigationProvisioning::navigateFromHomePage(int choice)
{
    QWidget* newPage = userFactory->navigateFromHomePage(choice);
    applicationStack->push(newPage);
}
