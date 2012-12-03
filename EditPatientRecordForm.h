#ifndef EDITPATIENTRECORDFORM_H
#define EDITPATIENTRECORDFORM_H

/*
  By Aaron Crozman (Student #100817740)
  Again, GUI skeleton only. Expected change is to take a pointer to a PatientRecord.
  */

#include "addpatientrecordform.h"

class EditPatientRecordForm : public AddPatientRecordForm
{
public:
    EditPatientRecordForm();
  //EditPatientRecordForm(PatientRecord *patient);
    ~EditPatientRecordForm();
};

#endif // EDITPATIENTRECORDFORM_H
