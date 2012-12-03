#include"addpatientrecordform.h"

AddPatientRecordForm::AddPatientRecordForm(QString title) : CUPage(title)
{
    // decide the name and the type of the inputField and the type of input
//    usernameField = new CUFormElement("Username:", CUFormElement::LINE, this);
    nameField = new CUFormElement("Name:", CUFormElement::LINE, this);
    phoneField= new CUFormElement("Phone Number:", CUFormElement::LINE, this);
    ohipField = new CUFormElement("OHIP Number:", CUFormElement::LINE, this);
    physicianField = new CUFormElement("Primary Physician:", CUFormElement::LINE, this);

    // create the login button
//    loginButton = new CUServerRequestButton("Login", this);
    cancelButton = new QPushButton("Cancel", this);
    confirmButton = new CUServerRequestButton("OK", this);

    // add the two elements to the page's content pane
//    addElement(usernameField, 0); // the x-span is 2 so that the login button would be at the bottom-right
//    addElement(loginButton, 1);
    addElement(nameField, 0, 0, 3);
    addElement(phoneField, 0, 1, 3);
    addElement(ohipField, 0, 2, 3);
    addElement(physicianField, 0, 3, 3);
    addElement(cancelButton, 1, 4);
    addElement(confirmButton, 2, 4);
}

// since all QT elements will be garbage-collected and the elements in this page have no extra non-QT pointers, there is no content in most destructor bodies for now
AddPatientRecordForm::~AddPatientRecordForm()
{

}
