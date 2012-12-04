#include "UpdateFollowupForm.h"

UpdateFollowupForm::UpdateFollowupForm(CUNavigationProvisioningInterface* pNavigator, StorableInterface* object) : AddFollowupForm(pNavigator)
{
    //Just call the superclass constructor with the new parameter. Also enable one little thing.
    statusBox->setEnabled(true);
    //TODO: Populate the form with the data from a passed-in record!

    FollowUpRecord* followup = (FollowUpRecord*)object;
    //populate the fields

    if(followup->getStatus() == FollowUpRecord::PENDING){
         statusBox->setCurrentIndex(0);
    }else if(followup->getStatus() == FollowUpRecord::COMPLETE){
         statusBox->setCurrentIndex(2);
    }else if(followup->getStatus() == FollowUpRecord::OVERDUE){
         statusBox->setCurrentIndex(1);
    }

    dueDateField->setInput(followup->getDueDateTime().toString());
    detailsField->setInput(followup->getDetails());
}

UpdateFollowupForm::~UpdateFollowupForm()
{
    //Do nothing!
}
