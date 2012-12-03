#include "AddConsultationRecordForm.h"

AddConsultationRecordForm::AddConsultationRecordForm(CUNavigationProvisioningInterface *pNavigator) : CUPage("Add Consultation", true, pNavigator)
{
    // decide the name and the type of the inputField and the type of input
    dateTimeField = new CUFormElement("Date and Time:", CUFormElement::DATE, this);
    reasonField = new CUFormElement("Reason for Visit:", CUFormElement::PARAGRAPH, this);
    ohipField = new CUFormElement("OHIP Number:", CUFormElement::LINE, this);

    // create the buttons
    confirmButton = new CUServerRequestButton("OK", this);

    // add the two elements to the page's content pane
    addElement(dateTimeField, 0, 0, 3);
    addElement(reasonField, 0, 1, 3);
    addElement(ohipField, 0, 2, 3);
    addElement(confirmButton, 2, 4);
}

// since all QT elements will be garbage-collected and the elements in this page have no extra non-QT pointers, there is no content in most destructor bodies for now
AddConsultationRecordForm::~AddConsultationRecordForm()
{

}
