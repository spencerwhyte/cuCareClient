#include"AdministrativeAssistantPageFactory.h"

AdministrativeAssistantPageFactory::AdministrativeAssistantPageFactory(CUNavigationProvisioningInterface *pNavigator) : CUPageFactory(pNavigator)
{

}

AdministrativeAssistantPageFactory::~AdministrativeAssistantPageFactory()
{

}

QWidget* AdministrativeAssistantPageFactory::navigateFromPatientRecordPage(int choice, StorableInterface* object)
{
    QWidget* returnPage = 0;
    if (choice == 0) //they chose to edit the consultation record
    {
        returnPage = new  AdministrativeAssisstantEditConsultationRecordForm(getNavigator(), object);
    }
    else if (choice == 1) //they chose to navigate to a consultation record
    {
        returnPage = new ConsultationRecordPage(getNavigator(), object);
    }
    else if (choice == 2) //they chose to navigate to the add consultation record form
    {
        returnPage = new AdministrativeAssisstantAddConsultationRecordForm(getNavigator(), object);
    }
    return returnPage;
}
