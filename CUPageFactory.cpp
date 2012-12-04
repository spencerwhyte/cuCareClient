#include"CUPageFactory.h"

CUPageFactory::CUPageFactory(CUNavigationProvisioningInterface *pNavigator)
{
    navigator = pNavigator;
}

CUPageFactory::~CUPageFactory()
{

}

QWidget* CUPageFactory::navigateFromConsultationRecordPage(int choice, StorableInterface* object)
{
    QWidget *returnPage = 0;
    if(choice == 0)
    {
        returnPage = new UpdateFollowupForm(navigator, object);
    }
    else if (choice == 1) // he chose to go to the addFollowupPage
    {
        returnPage = new AddFollowupForm(navigator);
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

QWidget* CUPageFactory::navigateFromPatientRecordPage(int choice, StorableInterface* object)
{
    QWidget* returnPage = 0;
    if (choice == 0) //they chose to edit the consultation record
    {
        returnPage = new EditConsultationRecordForm(navigator, object);
    }
    else if (choice == 1) //they chose to navigate to a consultation record
    {
        returnPage = new ConsultationRecordPage(navigator, object);
    }
    else if (choice == 2) //they chose to navigate to the add consultation record form
    {
        returnPage = new AddConsultationRecordForm(navigator);
    }
    return returnPage;
}

QWidget* CUPageFactory::navigateFromQueryDatabaseForm(int choice, StorableInterface* object)
{
    QWidget *returnPage = 0;
    if (choice == 0) //this leads to edit a patient record
    {
        returnPage = new EditPatientRecordForm(navigator, object);
    }
    else if (choice == 1) //this leads to a patient record page
    {
        returnPage = new PatientRecordPage(navigator, object);
    }
    return returnPage;
}


QWidget* CUPageFactory::navigateFromHomePage(int choice)
{
    QWidget* returnWidget = 0;

    if(choice == 0) // go to the add patient record
    {
        returnWidget = new AddPatientRecordForm(navigator);
    }
    else if(choice == 1)
    {
        returnWidget = new QueryDatabaseForm(navigator);
    }
    return returnWidget;
}
