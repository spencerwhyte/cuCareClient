#ifndef ADDPATIENTRECORDFORM_H
#define ADDPATIENTRECORDFORM_H

/*
  By Aaron Crozman (Student #100817740)
  Currently, this is just the GUI skeleton of the form.

  The default constructor uses a QString with default parameters set so that classes that inherit from this may pass in their own titles.
  Please note that the parameter should /only/ be declared otherwise when being called from a subclass!

  An expected change is that the constructor here will take in one of two things:
  - A pointer to a PatientRecord, such that the data may be filled out by the class.
  - A double pointer to a PatientRecord, such that the data may be created by the class.
  Whichever it would be, the form would have to store it as a member for its lifecycle, however, it won't be accessed from outside.

  I'm also none too sure of how to hook up the buttons through this way of creating a layout.
  */

#include <QObject>
#include "CUPage.h"
#include "CUFormElement.h"
#include "CUServerRequestButton.h"

class AddPatientRecordForm : public CUPage, public ClientObjectResponseDelegate
{
    Q_OBJECT

public:
    AddPatientRecordForm(CUNavigationProvisioningInterface *pNavigator); //Note - this should /only/ be given an input from a subclass!
  //AddPatientRecordForm(PatientRecord *patient, QString title = "Add Patient Record"); //This is simply what I'd be expecting to change!
    ~AddPatientRecordForm();

    void didSuccessfullyReceiveResponse(QList<StorableInterface *> * results);

    void didReceiveError(QString & errorMessage);

public slots:
        void sendPatientRecordToServer();

signals:
        void goBack(StorableInterface* object);



protected:
    CUFormElement *nameField;
    CUFormElement *phoneField;
    CUFormElement *ohipField;
    CUFormElement *physicianField;
    CUServerRequestButton *confirmButton;
    PatientRecord *patient;
};

#endif // ADDPATIENTRECORDFORM_H
