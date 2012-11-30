#include"ConsultationRecordPage.h"

ConsultationRecordPage::ConsultationRecordPage(CUNavigationProvisioningInterface *pNavigator) : CUPage("", true, pNavigator)
{
    //note the lack of a title. The title should be the patient's name. Make sure you setup the name after the patient data is received
    dateAndTime = new CUFormElement("Date and Time:", CUFormElement::DATE, 0);
    reason = new CUFormElement("Reason for Visit:", CUFormElement::PARAGRAPH, 0);
    ohipNumber = new CUFormElement("OHIP Number:", CUFormElement::LINE, 0);
    diagnosis = new CUFormElement("Diagnosis:", CUFormElement::PARAGRAPH, 0);
    addFollowupButton = new CUNavigationButton("Add Followup", 0);
    followupTable = new CUFormTable(0,0);
    //diagnosis->setMinimumWidth(500);

    //add the elements to the page
    addElement(ohipNumber);
    addElement(dateAndTime);
    addElement(reason);
    addElement(diagnosis);
    addElement(addFollowupButton, 0, 5, 1, 1, Qt::AlignRight);
    addElement(followupTable);

    //disable all the consultation information
    ohipNumber->setEditable(false);
    dateAndTime->setEditable(false);
    reason->setEditable(false);
    diagnosis->setEditable(false);

    //connect the add followup button to the navigator
    connect(this, SIGNAL(navigateAwayFromPage(int)), pNavigator, SLOT(navigateFromConsultationRecordPage(int)));
}


ConsultationRecordPage::~ConsultationRecordPage()
{

}

void ConsultationRecordPage::addFollowupButtonClicked()
{
    emit navigateAwayFromPage(0);
}
