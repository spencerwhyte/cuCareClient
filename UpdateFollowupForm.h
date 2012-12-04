#ifndef UPDATEFOLLOWUPFORM_H
#define UPDATEFOLLOWUPFORM_H

/*
  By Aaron Crozman (Student #100817740)
  One last form for today.
  */

#include "AddFollowupForm.h"

class UpdateFollowupForm : public AddFollowupForm
{
    Q_OBJECT

public:
    UpdateFollowupForm(CUNavigationProvisioningInterface* pNavigator, StorableInterface* followup);
  //UpdateFollowupForm(FollowUpRecord *followup);
    ~UpdateFollowupForm();
};

#endif // UPDATEFOLLOWUPFORM_H
