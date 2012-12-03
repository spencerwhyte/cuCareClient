#ifndef ADDFOLLOWUPFORM_H
#define ADDFOLLOWUPFORM_H

/*
  By Aaron Crozman (Student #100817740)
  Another day, another GUI skeleton.
  */

#include <QComboBox>

#include "CUPage.h"
#include "CUFormElement.h"
#include "CUServerRequestButton.h"

class AddFollowupForm : public CUPage
{
public:
    AddFollowupForm(CUNavigationProvisioningInterface *pNavigator);
  //AddFollowupForm(FollowUpRecord *followup, QString title = "Add Followup");
    ~AddFollowupForm();

protected:
    QComboBox *statusBox;
    CUFormElement *dueDateField;
    CUFormElement *detailsField;
    CUServerRequestButton *confirmButton;

private:
    CUContentPane *statusPane;
    QLabel *statusLabel;
};

#endif // ADDFOLLOWUPFORM_H
