#include "EditConsultationRecordForm.h"

EditConsultationRecordForm::EditConsultationRecordForm() : AddConsultationRecordForm("Edit Consultation Record")
{
    diagnosisField = new CUFormElement("Diagnosis:", CUFormElement::PARAGRAPH, this);

    addElement(diagnosisField, 0, 3, 3);
    //TODO: Populate the form with the data from a passed-in record!
}

EditConsultationRecordForm::~EditConsultationRecordForm()
{
    //Do nothing!
}
