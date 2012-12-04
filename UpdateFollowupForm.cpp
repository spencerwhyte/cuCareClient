#include "UpdateFollowupForm.h"

UpdateFollowupForm::UpdateFollowupForm(CUNavigationProvisioningInterface* pNavigator, StorableInterface* object) : AddFollowupForm(pNavigator, object)
{
    followup = (FollowUpRecord*)object;
    //Just call the superclass constructor with the new parameter. Also enable one little thing.
    statusBox->setEnabled(true);

    //populate the fields
    if(followup->getStatus() == FollowUpRecord::PENDING){
         statusBox->setCurrentIndex(0);
    }else if(followup->getStatus() == FollowUpRecord::COMPLETE){
         statusBox->setCurrentIndex(2);
    }else if(followup->getStatus() == FollowUpRecord::OVERDUE){
         statusBox->setCurrentIndex(1);
    }

    setPageTitle("Update Followup");

    dueDateField->setInput(followup->getDueDateTime().toString());
    detailsField->setInput(followup->getDetails());

    QObject::disconnect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendFollowupToServer()));
    QObject::connect(confirmButton->getButton(), SIGNAL(clicked()), this, SLOT(sendFollowupToServer()));
    QObject::disconnect(this, SIGNAL(goBack(StorableInterface*)), pNavigator, SLOT(back(StorableInterface*)));
    QObject::connect(this, SIGNAL(goBack(StorableInterface*)), pNavigator, SLOT(updateThenBack(StorableInterface*)));
}

UpdateFollowupForm::~UpdateFollowupForm()
{
    //Do nothing!
}

void UpdateFollowupForm::didSuccessfullyReceiveResponse(QList<StorableInterface *> * results){
    StorableInterface* record = results->at(0);
    emit goBack(record);
}

void UpdateFollowupForm::didReceiveError(QString & errorMessage){

}

void UpdateFollowupForm::sendFollowupToServer()
{
    followup->setStatusForString(statusBox->currentText());
    followup->setDueDateTime(dueDateField->getDate());
    followup->setDetails(detailsField->getInput());


    ClientObjectRequest * r = new ClientObjectRequest(this, *(StorableInterface*)followup, ClientObjectRequest::Edit);
    setRequest(r);
}
