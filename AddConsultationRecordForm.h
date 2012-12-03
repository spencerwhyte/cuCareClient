#ifndef ADDCONSULTATIONRECORDFORM_H
#define ADDCONSULTATIONRECORDFORM_H

/*
  By Aaron Crozman (Student #100817740)

  Much like AddPatientRecordForm, this uses a default parameter in the default constructor.
  */

#include "CUPage.h"
#include "CUFormElement.h"
#include "CUServerRequestButton.h"

class AddConsultationRecordForm : public CUPage
{
public:
    AddConsultationRecordForm(QString title = "Add Consultation Record"); //Note - this should /only/ be given an input from a subclass!
  //AddConsultationRecordForm(ConsultationRecord *consultation, QString title = "Add Consultation Record"); //This is simply what I'd be expecting to change!
    ~AddConsultationRecordForm();

protected:
    CUFormElement *dateTimeField;
    CUFormElement *reasonField;
    CUFormElement *ohipField;
    QPushButton *cancelButton;
    CUServerRequestButton *confirmButton;
  //ConsultationRecord *consultation; //Again, expected change.
};

#endif // ADDCONSULTATIONRECORDFORM_H
