#include "EditPatientRecordForm.h"

EditPatientRecordForm::EditPatientRecordForm(CUNavigationProvisioningInterface* pNavigator, StorableInterface* object) : AddPatientRecordForm(pNavigator)
{
    patient = (PatientRecord*)object;
    //Just call the superclass constructor with the new parameter.
    //TODO: Populate the form with the data from a passed-in record!

    setPageTitle("Edit Patient");

    //enter all patient details
    nameField->setInput(patient->getName());
    phoneField->setInput(patient->getPhoneNumber());
    ohipField->setInput(patient->getOHIPNumber());
    physicianField->setInput(patient->getPrimaryPhysician());

    QObject::disconnect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendPatientRecordToServer()));
    QObject::connect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendPatientRecordToServer()));
    QObject::disconnect(this, SIGNAL(goBack(StorableInterface*)), pNavigator, SLOT(back(StorableInterface*)));
    QObject::connect(this, SIGNAL(goBack(StorableInterface*)), pNavigator, SLOT(updateThenBack(StorableInterface*)));
}

EditPatientRecordForm::~EditPatientRecordForm()
{
    //Do nothing!
}

void EditPatientRecordForm::sendPatientRecordToServer()
{
    patient->setName(nameField->getInput());
    patient->setOHIPNumber(ohipField->getInput());
    patient->setPhoneNumber(phoneField->getInput());
    patient->setPrimaryPhysician(physicianField->getInput());

    ClientObjectRequest * r = new ClientObjectRequest(this, *(StorableInterface*)patient, ClientObjectRequest::Edit);
    setRequest(r);
}

void EditPatientRecordForm::didSuccessfullyReceiveResponse(QList<StorableInterface *> * results){
    StorableInterface* record = results->at(0);

    emit goBack(record);
}

void EditPatientRecordForm::didReceiveError(QString & errorMessage){

}
