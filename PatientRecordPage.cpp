#include"PatientRecordPage.h"

PatientRecordPage::PatientRecordPage(CUNavigationProvisioningInterface *pNavigator) : CUPage("", true, pNavigator)
{
    //note the lack of a title. The title should be the patient's name. Make sure you setup the name after the patient data is received
    phoneNumberElement = new CUFormElement("Phone Number:", CUFormElement::LINE, 0);
    ohipNumberElement = new CUFormElement("OHIP Number:", CUFormElement::LINE, 0);
    primaryPhysicianElement = new CUFormElement("Primary Physician:", CUFormElement::LINE, 0);
    addConsultationButton = new CUNavigationButton("Add Consultation", 0);
    consultationRecordsTable = new CUFormTable(0, 0);

    //add the elements to the page
    addElement(phoneNumberElement);
    addElement(ohipNumberElement);
    addElement(primaryPhysicianElement);
    addElement(addConsultationButton, 0, 5, 1, 1, Qt::AlignRight);
    addElement(consultationRecordsTable);

    //prevent the user from editing the elements with patient information
    phoneNumberElement->setEditable(false);
    ohipNumberElement->setEditable(false);
    primaryPhysicianElement->setEditable(false);
}

PatientRecordPage::~PatientRecordPage()
{

}
