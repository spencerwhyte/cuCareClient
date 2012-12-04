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
  //EditPatientRecordForm(PatientRecord *patient);
    ~EditPatientRecordForm();

public slots:
        void sendEditedPatientRecordToServer();

};

#endif // EDITPATIENTRECORDFORM_H
