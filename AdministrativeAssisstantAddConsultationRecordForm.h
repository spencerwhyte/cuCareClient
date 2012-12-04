#ifndef ADMINISTRATIVEASSISSTANTADDCONSULTATIONRECORDFORM_H
#define ADMINISTRATIVEASSISSTANTADDCONSULTATIONRECORDFORM_H

#include<QObject>
#include"AddConsultationRecordForm.h"

class AdministrativeAssisstantAddConsultationRecordForm : public AddConsultationRecordForm
{
    Q_OBJECT

public:
    AdministrativeAssisstantAddConsultationRecordForm(CUNavigationProvisioningInterface *pNavigator, StorableInterface* object);
    ~AdministrativeAssisstantAddConsultationRecordForm();
};

#endif // ADMINISTRATIVEASSISSTANTADDCONSULTATIONRECORDFORM_H
