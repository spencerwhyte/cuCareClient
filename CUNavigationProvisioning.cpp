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

void CUNavigationProvisioning::back(StorableInterface* newObject)
{
    CUPage* widgetToModify = (CUPage*)applicationStack->lastQWidget();
    widgetToModify->addToTable(newObject);
    back();
}

void CUNavigationProvisioning::updateThenBack(StorableInterface* newObject)
{
    CUPage* widgetToModify = (CUPage*)applicationStack->lastQWidget();
    widgetToModify->updateTable(newObject);
    back();
}

// the user factory is initialized here
void CUNavigationProvisioning::setUserType(User *user)
{
    delete currentUser;
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
}

void CUNavigationProvisioning::navigateFromLoginForm(int choice)
{
    //if the choice is 1, then the page requested is a networking configuration page
    //at this stage the page factory is not constructed yet. Therefore, we respond
    //with the appropriate page directly from here
    QWidget *newPage;
    if(choice == 1)
    {
        newPage = new IPAddressConfigurationForm(this);
    }
    else if(choice == 0)
    {
        newPage = userFactory->navigateFromLoginForm(choice);
    }
    applicationStack->push(newPage);

}

void CUNavigationProvisioning::navigateFromQueryDatabaseForm(int choice, StorableInterface* object)
{
    QWidget* newPage = userFactory->navigateFromQueryDatabaseForm(choice, object);
    applicationStack->push(newPage);
}

void CUNavigationProvisioning::navigateFromPatientRecordPage(int choice, StorableInterface* object)
{
    QWidget* newPage = userFactory->navigateFromPatientRecordPage(choice, object);
    applicationStack->push(newPage);
}

void CUNavigationProvisioning::navigateFromConsultationRecordPage(int choice, StorableInterface* object)
{
    QWidget* newPage = userFactory->navigateFromConsultationRecordPage(choice, object);
    applicationStack->push(newPage);
}

void CUNavigationProvisioning::navigateFromHomePage(int choice)
{
    QWidget* newPage = userFactory->navigateFromHomePage(choice);
    applicationStack->push(newPage);
}
