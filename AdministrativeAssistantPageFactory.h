/*
Hashem Shawqi
Carleton University

This class is a subclass of the CUPageFactory, it essentially redirects an administrative assistant
to the pages that match his permissions
  */

#ifndef ADMINISTRATIVEASSISTANTPAGEFACTORY
#define ADMINISTRATIVEASSISTANTPAGEFACTORY

#include"CUPageFactory.h"
#include"AdministrativeAssisstantAddConsultationRecordForm.h"
#include"AdministrativeAssisstantEditConsultationRecordForm.h"

class AdministrativeAssistantPageFactory : public CUPageFactory
{
public:
    AdministrativeAssistantPageFactory(CUNavigationProvisioningInterface *pNavigator);
    ~AdministrativeAssistantPageFactory();

    QWidget* navigateFromPatientRecordPage(int choice, StorableInterface* object);
};

#endif
