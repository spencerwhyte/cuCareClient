/*
Hashem Shawqi
Carleton University

This page displays all patient information and a list of all consultations attached to this patient
A consultation may be clicked to access that consultation
  */

#ifndef PATIENTRECORDPAGE
#define PATIENTRECORDPAGE

#include<QMenu>
#include"CUPage.h"
#include"CUFormElement.h"
#include"CUNavigationButton.h"
#include"CUFormTable.h"

class PatientRecordPage : public CUPage, ClientObjectResponseDelegate
{
    Q_OBJECT

public:
    PatientRecordPage(CUNavigationProvisioningInterface *pNavigator, StorableInterface* object);
    ~PatientRecordPage();

    void addConsultationTableData(QList<StorableInterface*> * da);
    void addConsultationTableDataAgain(QList<StorableInterface*> * da);
    void setDataEntries(QList<ConsultationRecord*> * da);
    void setCurrentObjectRequest(ClientObjectRequest * newRequest);

    void didSuccessfullyReceiveResponse(QList<StorableInterface *> * results);
    void didReceiveError(QString & errorMessage);
    void addToTable(StorableInterface* object);
    void updateTable(StorableInterface* object);

public slots:
    void editConsultationRecord();
    void navigateToConsultationRecordPage(int row, int col);
    void launchPatientContextMenu(const QPoint &);
    void navigateToAddConsultationRecordForm();

private:
    CUFormElement *phoneNumberElement, *ohipNumberElement, *primaryPhysicianElement; //patient data
    CUNavigationButton *addConsultationButton;
    CUFormTable *consultationRecordsTable;
    QList<ConsultationRecord*> * dataEntries;
    ClientObjectRequest * currentObjectRequest;
    PatientRecord* patient;
};

#endif
