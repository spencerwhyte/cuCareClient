#ifndef ADMINISTRATIVEASSISSTANTEDITCONSULTATIONRECORDFORM_H
#define ADMINISTRATIVEASSISSTANTEDITCONSULTATIONRECORDFORM_H

#include<QObject>
#include"EditConsultationRecordForm.h"

class AdministrativeAssisstantEditConsultationRecordForm : public EditConsultationRecordForm
{
    Q_OBJECT
public:
    AdministrativeAssisstantEditConsultationRecordForm(CUNavigationProvisioningInterface* pNavigator, StorableInterface* consultation);
    ~AdministrativeAssisstantEditConsultationRecordForm();
};

#endif // ADMINISTRATIVEASSISSTANTEDITCONSULTATIONRECORDFORM_H
