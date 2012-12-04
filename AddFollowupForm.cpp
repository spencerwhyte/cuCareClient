#include "AddFollowupForm.h"

AddFollowupForm::AddFollowupForm(CUNavigationProvisioningInterface *pNavigator) : CUPage("Add Follow-up", true, pNavigator)
{
    // decide the name and the type of the fields and the corresponding types of input
    { //Status pane - I have it in its own block to separate it.
        statusPane = new CUContentPane(0);
        statusLabel = new QLabel("Status:");
        statusBox = new QComboBox();
        statusBox->addItem("Pending");
        statusBox->addItem("Overdue");
        statusBox->addItem("Complete");
        statusBox->setDisabled(true);

        statusPane->addElement(statusLabel, 0, 0, 1, 1, Qt::AlignTop);
        statusPane->addElement(statusBox, 1, 0, 1, 1, Qt::AlignTop);
    }
    dueDateField = new CUFormElement("Due Date:", CUFormElement::DATE, this);
    detailsField = new CUFormElement("Details:", CUFormElement::PARAGRAPH, this);

    // create the buttons
    confirmButton = new CUServerRequestButton("OK", this);

    // add the elements to the page's content pane
    addElement(statusPane, 0, 0, 3);
    addElement(dueDateField, 0, 1, 3);
    addElement(detailsField, 0, 2, 3);
    addElement(confirmButton, 2, 3);
}

// since all QT elements will be garbage-collected and the elements in this page have no extra non-QT pointers, there is no content in most destructor bodies for now
AddFollowupForm::~AddFollowupForm()
{

}
