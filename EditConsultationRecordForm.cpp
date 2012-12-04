#include "EditConsultationRecordForm.h"

EditConsultationRecordForm::EditConsultationRecordForm(CUNavigationProvisioningInterface* pNavigator, StorableInterface* object) : AddConsultationRecordForm(pNavigator, object)
{
    diagnosisField = new CUFormElement("Diagnosis:", CUFormElement::PARAGRAPH, this);

    addElement(diagnosisField, 0, 3, 3);
    //TODO: Populate the form with the data from a passed-in record!

    consultation = (ConsultationRecord*)object;

    diagnosisField->setInput(consultation->getDiagnosis());
    dateTimeField->setInput(consultation->getDateAndTime().toString());
    reasonField->setInput(consultation->getReason());

    setPageTitle("Edit Consultation");

    QObject::disconnect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendConsultationToServer()));
    QObject::connect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendUpdatedConsultationToServer()));
}

EditConsultationRecordForm::~EditConsultationRecordForm()
{
    //Do nothing!
}

void EditConsultationRecordForm::sendUpdatedConsultationToServer()
{
    consultation->setDateAndTime(dateTimeField->getDate());
    consultation->setReason(reasonField->getInput());


    ClientObjectRequest * r = new ClientObjectRequest(this, *(StorableInterface*)consultation, ClientObjectRequest::Edit);
    setRequest(r);
}
