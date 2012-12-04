#ifndef EDITCONSULTATIONRECORDFORM_H
#define EDITCONSULTATIONRECORDFORM_H

/*
  By Aaron Crozman (Student #100817740)
  Yay, GUI skeletons!
  */

#include "AddConsultationRecordForm.h"


class EditConsultationRecordForm : public AddConsultationRecordForm
{
    Q_OBJECT

public:
    EditConsultationRecordForm(CUNavigationProvisioningInterface* pNavigator, StorableInterface* consultation);
    //EditConsultationRecordForm(ConsultationRecord *consultation);
    ~EditConsultationRecordForm();

    void didSuccessfullyReceiveResponse(QList<StorableInterface *> * results);

    void didReceiveError(QString & errorMessage);

public slots:
    void sendConsultationToServer();
private:
    CUFormElement *diagnosisField;
    ConsultationRecord* consultation;
};

#endif // EDITCONSULTATIONRECORDFORM_H
