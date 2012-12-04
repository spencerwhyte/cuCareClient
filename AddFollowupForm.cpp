#include "AddFollowupForm.h"

AddFollowupForm::AddFollowupForm(CUNavigationProvisioningInterface *pNavigator, StorableInterface* object) : CUPage("Add Follow-up", true, pNavigator)
{
    consultation = (ConsultationRecord*)object;
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

    QObject::connect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendFollowupToServer()));
    QObject::connect(this, SIGNAL(goBack(StorableInterface*)), pNavigator, SLOT(back(StorableInterface*)));
}

// since all QT elements will be garbage-collected and the elements in this page have no extra non-QT pointers, there is no content in most destructor bodies for now
AddFollowupForm::~AddFollowupForm()
{

}


void AddFollowupForm::didSuccessfullyReceiveResponse(QList<StorableInterface *> * results){
    StorableInterface* record = results->at(0);

    emit goBack(record);
}

void AddFollowupForm::didReceiveError(QString & errorMessage){

}

void AddFollowupForm::sendFollowupToServer()
{

    FollowUpRecord recordToBeAdded;

    recordToBeAdded.setConsultationRecordId(consultation->getId());
    recordToBeAdded.setStatusForString(statusBox->currentText());
    recordToBeAdded.setDueDateTime(dueDateField->getDate());
    recordToBeAdded.setDetails(detailsField->getInput());

    ClientObjectRequest * r = new ClientObjectRequest(this, recordToBeAdded, ClientObjectRequest::Add);
    setRequest(r);
}
