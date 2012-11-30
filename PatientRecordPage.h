/*
Hashem Shawqi
Carleton University

This page displays all patient information and a list of all consultations attached to this patient
A consultation may be clicked to access that consultation
  */

#ifndef PATIENTRECORDPAGE
#define PATIENTRECORDPAGE

#include"CUPage.h"
#include"CUFormElement.h"
#include"CUNavigationButton.h"
#include"CUFormTable.h"

class PatientRecordPage : public CUPage
{
    Q_OBJECT

public:
    PatientRecordPage(CUNavigationProvisioningInterface *pNavigator);
    ~PatientRecordPage();

private:
    CUFormElement *phoneNumberElement, *ohipNumberElement, *primaryPhysicianElement; //patient data
    CUNavigationButton *addConsultationButton;
    CUFormTable *consultationRecordsTable;
};

#endif
