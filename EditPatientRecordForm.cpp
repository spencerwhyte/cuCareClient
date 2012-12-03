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
}

EditPatientRecordForm::~EditPatientRecordForm()
{
    //Do nothing!
}
