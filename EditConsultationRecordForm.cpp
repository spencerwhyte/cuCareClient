#include "EditConsultationRecordForm.h"

EditConsultationRecordForm::EditConsultationRecordForm(CUNavigationProvisioningInterface* pNavigator, StorableInterface* object) : AddConsultationRecordForm(pNavigator, object)
{
    consultation = (ConsultationRecord*)object;

    diagnosisField = new CUFormElement("Diagnosis:", CUFormElement::PARAGRAPH, this);

    addElement(diagnosisField, 0, 3, 3);

    diagnosisField->setInput(consultation->getDiagnosis());
    dateTimeField->setInput(consultation->getDateAndTime().toString());
    reasonField->setInput(consultation->getReason());

    setPageTitle("Edit Consultation");

    QObject::disconnect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendConsultationToServer()));
    QObject::connect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendConsultationToServer()));
    QObject::disconnect(this, SIGNAL(goBack(StorableInterface*)), pNavigator, SLOT(back(StorableInterface*)));
    QObject::connect(this, SIGNAL(goBack(StorableInterface*)), pNavigator, SLOT(updateThenBack(StorableInterface*)));
}

EditConsultationRecordForm::~EditConsultationRecordForm()
{
    //Do nothing!
}

CUFormElement* EditConsultationRecordForm::getDiagnosisField()
{
    return diagnosisField;
}

void EditConsultationRecordForm::sendConsultationToServer()
{
    consultation->setDateAndTime(dateTimeField->getDate());
    consultation->setReason(reasonField->getInput());
    consultation->setDiagnosis(diagnosisField->getInput());


    ClientObjectRequest * r = new ClientObjectRequest(this, *(StorableInterface*)consultation, ClientObjectRequest::Edit);
    setRequest(r);
}

void EditConsultationRecordForm::didSuccessfullyReceiveResponse(QList<StorableInterface *> * results){
    StorableInterface* record = results->at(0);

    emit goBack(record);
}

void EditConsultationRecordForm::didReceiveError(QString & errorMessage){

}
