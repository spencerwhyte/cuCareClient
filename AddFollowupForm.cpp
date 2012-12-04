#include "AddFollowupForm.h"

AddFollowupForm::AddFollowupForm(CUNavigationProvisioningInterface *pNavigator, StorableInterface* object) : CUPage("Add Follow-up", true, pNavigator)
{
    setConsultation((ConsultationRecord*)object);
    // decide the name and the type of the fields and the corresponding types of input
    { //Status pane - I have it in its own block to separate it.
        setStatusPane(new CUContentPane(0));
        setStatusLabel(new QLabel("Status:"));
        setStatusBox(new QComboBox());
        getStatusBox()->addItem("Pending");
        getStatusBox()->addItem("Overdue");
        getStatusBox()->addItem("Complete");
        getStatusBox()->setDisabled(true);

        getStatusPane()->addElement(statusLabel, 0, 0, 1, 1, Qt::AlignTop);
        getStatusPane()->addElement(statusBox, 1, 0, 1, 1, Qt::AlignTop);
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

QComboBox* AddFollowupForm::getStatusBox()
{
    return statusBox;
}

CUFormElement* AddFollowupForm::getDueDateField()
{
    return dueDateField;
}

CUFormElement* AddFollowupForm::getDetailsField()
{
    return detailsField;
}
CUServerRequestButton* AddFollowupForm::getConfirmButton()
{
    return confirmButton;
}

CUContentPane* AddFollowupForm::getStatusPane()
{
    return statusPane;
}

QLabel* AddFollowupForm::getStatusLabel()
{
    return statusLabel;
}

ConsultationRecord* AddFollowupForm::getConsulation()
{
    return consultation;
}

void AddFollowupForm::setStatusBox(QComboBox* newStatusBox)
{
    statusBox = newStatusBox;
}

void AddFollowupForm::setDueDateField(CUFormElement* newDueDateField)
{
    dueDateField = newDueDateField;
}

void AddFollowupForm::setDetailsField(CUFormElement* newDetailsField)
{
    detailsField = newDetailsField;
}

void AddFollowupForm::setConfirmButton(CUServerRequestButton* newConfirmButton)
{
    confirmButton = newConfirmButton;
}

void AddFollowupForm::setStatusPane(CUContentPane* newStatusPane)
{
    statusPane = newStatusPane;
}

void AddFollowupForm::setStatusLabel(QLabel* newStatusLabel)
{
    statusLabel = newStatusLabel;
}

void AddFollowupForm::setConsultation(ConsultationRecord* newConsultation)
{
    consultation = newConsultation;
}
