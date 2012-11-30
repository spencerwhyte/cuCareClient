/*
Hashem Shawqi
Carleton University

This class contains information concerning a consultation record and a table of all followups attached to that consultation record
  */

#ifndef CONSULTATIONRECORDPAGE
#define CONSULTATIONRECORDPAGE

#include"CUPage.h"
#include"CUFormElement.h"
#include"CUNavigationButton.h"
#include"CUFormTable.h"

class ConsultationRecordPage : public CUPage
{
    Q_OBJECT

public:
    ConsultationRecordPage(CUNavigationProvisioningInterface *pNavigator);
    ~ConsultationRecordPage();

public slots:
    void addFollowupButtonClicked();

private:
    CUFormElement *dateAndTime, *reason, *ohipNumber, *diagnosis;
    CUNavigationButton *addFollowupButton;
    CUFormTable *followupTable;
};

#endif
