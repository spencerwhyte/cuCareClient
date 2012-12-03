#include"CUPageFactory.h"

CUPageFactory::CUPageFactory(CUNavigationProvisioningInterface *pNavigator)
{
    navigator = pNavigator;
}

CUPageFactory::~CUPageFactory()
{

}

QWidget* CUPageFactory::navigateFromConsultationRecordPage(int choice)
{
    QWidget *returnPage = 0;
    if(choice == 0)
    {
        //AddFollowupPage *returnPage = new AddFollowupPage(navigator);
    }
    return returnPage;
}

QWidget* CUPageFactory::navigateFromLoginForm(int choice)
{
    QWidget *returnPage;
    if(choice == 0)
    {
        returnPage = new HomePage(navigator);
    }
    else if(choice == 1)
    {
        returnPage = new IPAddressConfigurationForm(navigator);
    }
    return returnPage;
}

QWidget* CUPageFactory::navigateFromPatientRecordPage(int choice)
{
    PatientRecordPage *returnPage = new PatientRecordPage(navigator);
    return returnPage;
}

QWidget* CUPageFactory::navigateFromQueryDatabaseForm(int choice)
{
    CUPage *returnPage = 0;
    if (choice == 0) //this leads to edit a patient record
    {
        returnPage = new EditPatientForm();
    }
    return returnPage;
}


QWidget* CUPageFactory::navigateFromHomePage(int choice)
{
    QWidget* returnWidget = 0;

    if(choice == 0) // go to the add patient record
    {
        //returnWidget = new AddPatientRecordForm(navigator);
    }
    else if(choice == 1)
    {
        returnWidget = new QueryDatabaseForm(navigator);
    }
    return returnWidget;
}
