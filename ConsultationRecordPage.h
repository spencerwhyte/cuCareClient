/*
Hashem Shawqi
Carleton University

This class contains information concerning a consultation record and a table of all followups attached to that consultation record
  */

#ifndef CONSULTATIONRECORDPAGE
#define CONSULTATIONRECORDPAGE

#include<QMenu>
#include"CUPage.h"
#include"CUFormElement.h"
#include"CUNavigationButton.h"
#include"CUFormTable.h"
#include"ConsultationRecord.h"

class ConsultationRecordPage : public CUPage, ClientObjectResponseDelegate
{
    Q_OBJECT

public:
    ConsultationRecordPage(CUNavigationProvisioningInterface *pNavigator, StorableInterface* consultation);
    ~ConsultationRecordPage();

    void addFollowupTableData(QList<StorableInterface*> * da);
    void addFollowupTableDataAgain(QList<StorableInterface*> * da);
    void setDataEntries(QList<FollowUpRecord *> *da);

    void didSuccessfullyReceiveResponse(QList<StorableInterface *> * results);
    void didReceiveError(QString & errorMessage);

    void setCurrentObjectRequest(ClientObjectRequest * newRequest);
    void addToTable(StorableInterface* object);
    void updateTable(StorableInterface* object);

public slots:
    void addFollowupButtonClicked();
    void launchPatientContextMenu(const QPoint &);
    void navigateToUpdateFollowups(int row, int col);
    void navigateToUpdateFollowups();
    void navigateToAddFollowupForm();

private:
    CUFormElement *dateAndTime, *reason, *ohipNumber, *diagnosis;
    CUNavigationButton *addFollowupButton;
    CUFormTable *followupTable;
    ConsultationRecord* consultation;
    QList<FollowUpRecord*> * dataEntries;
    ClientObjectRequest * currentObjectRequest;
};

#endif
