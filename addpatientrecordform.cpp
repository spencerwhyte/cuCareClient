#include"addpatientrecordform.h"

AddPatientRecordForm::AddPatientRecordForm(CUNavigationProvisioningInterface *pNavigator) : CUPage("Add Patient Record", true, pNavigator)
{
    // decide the name and the type of the inputField and the type of input
    nameField = new CUFormElement("Name:", CUFormElement::LINE, this);
    phoneField= new CUFormElement("Phone Number:", CUFormElement::LINE, this);
    ohipField = new CUFormElement("OHIP Number:", CUFormElement::LINE, this);
    physicianField = new CUFormElement("Primary Physician:", CUFormElement::LINE, this);

    // create the login button
    confirmButton = new CUServerRequestButton("OK", this);

    // add the two elements to the page's content pane
    addElement(nameField, 0, 0, 3);
    addElement(phoneField, 0, 1, 3);
    addElement(ohipField, 0, 2, 3);
    addElement(physicianField, 0, 3, 3);
    addElement(confirmButton, 2, 4);

    QObject::connect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendPatientRecordToServer()));
    QObject::connect(this, SIGNAL(goBack(StorableInterface*)), pNavigator, SLOT(back(StorableInterface*)));

}

// since all QT elements will be garbage-collected and the elements in this page have no extra non-QT pointers, there is no content in most destructor bodies for now
AddPatientRecordForm::~AddPatientRecordForm()
{

}

void AddPatientRecordForm::didSuccessfullyReceiveResponse(QList<StorableInterface *> * results){
    StorableInterface* record = results->at(0);

    emit goBack(record);
}

void AddPatientRecordForm::didReceiveError(QString & errorMessage){

}

void AddPatientRecordForm::sendPatientRecordToServer()
{
    PatientRecord recordToBeAdded;

    recordToBeAdded.setName(nameField->getInput());
    recordToBeAdded.setOHIPNumber(ohipField->getInput());
    recordToBeAdded.setPhoneNumber(phoneField->getInput());
    recordToBeAdded.setPrimaryPhysician(physicianField->getInput());

    ClientObjectRequest * r = new ClientObjectRequest(this, recordToBeAdded, ClientObjectRequest::Add);
    setRequest(r);
}
