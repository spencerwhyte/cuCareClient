#include "AdministrativeAssisstantAddConsultationRecordForm.h"

AdministrativeAssisstantAddConsultationRecordForm::AdministrativeAssisstantAddConsultationRecordForm(CUNavigationProvisioningInterface *pNavigator, StorableInterface* object) : AddConsultationRecordForm(pNavigator, object)
{
    getReasonField()->setEditable(false);
}

AdministrativeAssisstantAddConsultationRecordForm::~AdministrativeAssisstantAddConsultationRecordForm()
{

}
