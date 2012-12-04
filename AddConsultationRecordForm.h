#ifndef ADDCONSULTATIONRECORDFORM_H
#define ADDCONSULTATIONRECORDFORM_H

/*
  By Aaron Crozman (Student #100817740)

  Much like AddPatientRecordForm, this uses a default parameter in the default constructor.
  */

#include<QObject>
#include "CUPage.h"
#include "CUFormElement.h"
#include "CUServerRequestButton.h"

class AddConsultationRecordForm : public CUPage, public ClientObjectResponseDelegate
{
    Q_OBJECT

public:
    AddConsultationRecordForm(CUNavigationProvisioningInterface *pNavigator, StorableInterface* object); //Note - this should /only/ be given an input from a subclass!
    ~AddConsultationRecordForm();

    void didSuccessfullyReceiveResponse(QList<StorableInterface *> * results);
    void didReceiveError(QString & errorMessage);

    CUFormElement* getReasonField();

private:

    CUFormElement* getDateTimeField();
    CUServerRequestButton* getConfirmButton();
    PatientRecord* getPatientRecord();

    void setReasonField(CUFormElement* newReasonField);
    void setDateTimeField(CUFormElement* dateTime);
    void setPatientRecord(PatientRecord*);
    void setConfirmButton(CUServerRequestButton* newButton);


public slots:
    void sendConsultationToServer();

signals:
    void goBack(StorableInterface*);

protected:
    CUFormElement *dateTimeField;
    CUFormElement *reasonField;
    CUServerRequestButton *confirmButton;
    PatientRecord* patient;
};

#endif // ADDCONSULTATIONRECORDFORM_H
