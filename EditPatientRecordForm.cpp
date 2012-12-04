#include "EditPatientRecordForm.h"

EditPatientRecordForm::EditPatientRecordForm(CUNavigationProvisioningInterface* pNavigator, StorableInterface* object) : AddPatientRecordForm(pNavigator)
{
    //Just call the superclass constructor with the new parameter.
    //TODO: Populate the form with the data from a passed-in record!

    setPageTitle("Edit Patient");

    PatientRecord* patient = (PatientRecord*)object;
    //enter all patient details
    nameField->setInput(patient->getName());
    phoneField->setInput(patient->getPhoneNumber());
    ohipField->setInput(patient->getOHIPNumber());
    physicianField->setInput(patient->getPrimaryPhysician());

    QObject::disconnect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendPatientRecordToServer()));
    QObject::connect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendEditedPatientRecordToServer()));
}

EditPatientRecordForm::~EditPatientRecordForm()
{
    //Do nothing!
}

void EditPatientRecordForm::sendEditedPatientRecordToServer()
{
    PatientRecord recordToBeAdded;

    recordToBeAdded.setName(nameField->getInput());
    recordToBeAdded.setOHIPNumber(ohipField->getInput());
    recordToBeAdded.setPhoneNumber(phoneField->getInput());
    recordToBeAdded.setPrimaryPhysician(physicianField->getInput());

    ClientObjectRequest * r = new ClientObjectRequest(this, recordToBeAdded, ClientObjectRequest::Edit);
    setRequest(r);
}
