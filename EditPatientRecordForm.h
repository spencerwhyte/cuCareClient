#ifndef EDITPATIENTRECORDFORM_H
#define EDITPATIENTRECORDFORM_H

/*
  By Aaron Crozman (Student #100817740)
  Again, GUI skeleton only. Expected change is to take a pointer to a PatientRecord.
  */

#include "addpatientrecordform.h"

class EditPatientRecordForm : public AddPatientRecordForm
{
    Q_OBJECT

public:
    EditPatientRecordForm(CUNavigationProvisioningInterface* pNavigator, StorableInterface* patient);
    ~EditPatientRecordForm();

    void didSuccessfullyReceiveResponse(QList<StorableInterface *> * results);

    void didReceiveError(QString & errorMessage);

public slots:
        void sendPatientRecordToServer();

private:
        PatientRecord *patient;
};

#endif // EDITPATIENTRECORDFORM_H
