#include "AdministrativeAssisstantEditConsultationRecordForm.h"

AdministrativeAssisstantEditConsultationRecordForm::AdministrativeAssisstantEditConsultationRecordForm(CUNavigationProvisioningInterface* pNavigator, StorableInterface* consultation) : EditConsultationRecordForm(pNavigator, consultation)
{
    getReasonField()->setEditable(false);
    getDiagnosisField()->setEditable(false);
}

AdministrativeAssisstantEditConsultationRecordForm::~AdministrativeAssisstantEditConsultationRecordForm()
{

}
