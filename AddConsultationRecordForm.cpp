#include "AddConsultationRecordForm.h"

AddConsultationRecordForm::AddConsultationRecordForm(CUNavigationProvisioningInterface *pNavigator, StorableInterface* object) : CUPage("Add Consultation", true, pNavigator)
{
    setPatientRecord((PatientRecord*)object);

    // decide the name and the type of the inputField and the type of input
    setDateTimeField(new CUFormElement("Date and Time:", CUFormElement::DATE, this));
    setReasonField(new CUFormElement("Reason for Visit:", CUFormElement::PARAGRAPH, this));

    // create the buttons
    setConfirmButton(new CUServerRequestButton("OK", this));

    // add the two elements to the page's content pane
    addElement(dateTimeField, 0, 0, 3);
    addElement(reasonField, 0, 1, 3);
    addElement(confirmButton, 2, 4, 1, 1, Qt::AlignRight);

    QObject::connect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendConsultationToServer()));
    QObject::connect(this, SIGNAL(goBack(StorableInterface*)), pNavigator, SLOT(back(StorableInterface*)));
}

// since all QT elements will be garbage-collected and the elements in this page have no extra non-QT pointers, there is no content in most destructor bodies for now
AddConsultationRecordForm::~AddConsultationRecordForm()
{

}

CUFormElement* AddConsultationRecordForm::getReasonField()
{
    return reasonField;
}

CUFormElement* AddConsultationRecordForm::getDateTimeField()
{
    return dateTimeField;
}

CUServerRequestButton* AddConsultationRecordForm::getConfirmButton()
{
    return confirmButton;
}

void AddConsultationRecordForm::setConfirmButton(CUServerRequestButton* newButton)
{
    confirmButton = newButton;
}

void AddConsultationRecordForm::setReasonField(CUFormElement* newReasonField)
{
    reasonField = newReasonField;
}

void AddConsultationRecordForm::setDateTimeField(CUFormElement* newDateTimeField)
{
    dateTimeField = newDateTimeField;
}

void AddConsultationRecordForm::setPatientRecord(PatientRecord* newPatientRecord)
{
    patient = newPatientRecord;
}

PatientRecord* AddConsultationRecordForm::getPatientRecord()
{
    return patient;
}

void AddConsultationRecordForm::sendConsultationToServer()
{

    ConsultationRecord recordToBeAdded;
    recordToBeAdded.setDateAndTime(dateTimeField->getDate());
    recordToBeAdded.setOHIPNumber(patient->getOHIPNumber());
    recordToBeAdded.setReason(reasonField->getInput());

    ClientObjectRequest * r = new ClientObjectRequest(this, recordToBeAdded, ClientObjectRequest::Add);
    setRequest(r);
}

void AddConsultationRecordForm::didSuccessfullyReceiveResponse(QList<StorableInterface *> * results){
    StorableInterface* record = results->at(0);
    emit goBack(record);
}

void AddConsultationRecordForm::didReceiveError(QString & errorMessage){

}
