#ifndef EDITCONSULTATIONRECORDFORM_H
#define EDITCONSULTATIONRECORDFORM_H

/*
  By Aaron Crozman (Student #100817740)
  Yay, GUI skeletons!
  */

#include "AddConsultationRecordForm.h"

class EditConsultationRecordForm : public AddConsultationRecordForm
{
public:
    EditConsultationRecordForm();
    //EditConsultationRecordForm(ConsultationRecord *consultation);
    ~EditConsultationRecordForm();

protected:
    CUFormElement *diagnosisField;
};

#endif // EDITCONSULTATIONRECORDFORM_H
