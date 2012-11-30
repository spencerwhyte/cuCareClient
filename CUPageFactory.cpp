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
    IPAddressConfigurationForm *returnPage = new IPAddressConfigurationForm(navigator);
    return returnPage;
}

QWidget* CUPageFactory::navigateFromPatientRecordPage(int choice)
{
    PatientRecordPage *returnPage = new PatientRecordPage(navigator);
    return returnPage;
}

QWidget* CUPageFactory::navigateFromQueryDatabaseForm(int choice)
{
    QueryDatabaseForm *returnPage = new QueryDatabaseForm(navigator);
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
