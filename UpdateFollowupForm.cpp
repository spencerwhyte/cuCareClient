#include "UpdateFollowupForm.h"

UpdateFollowupForm::UpdateFollowupForm() : AddFollowupForm("Edit Followup")
{
    //Just call the superclass constructor with the new parameter. Also enable one little thing.
    statusBox->setEnabled(true);
    //TODO: Populate the form with the data from a passed-in record!
}

UpdateFollowupForm::~UpdateFollowupForm()
{
    //Do nothing!
}
