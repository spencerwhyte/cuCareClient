/*
Hashem Shawqi
Carleton University

This class is responsible for creating queries and displaying query reports
   */

#ifndef QUERYDATABASEFORM
#define QUERYDATABASEFORM

#include<QComboBox>
#include<QMenu>
#include"CUPage.h"
#include"ClientObjectResponseDelegate.h"
#include"CUFormElement.h"
#include"CUServerRequestButton.h"
#include"CUFormTable.h"
#include<QStackedWidget>

class PatientRecord;

class QueryDatabaseForm : public CUPage, public ClientObjectResponseDelegate
{
    Q_OBJECT
    QList<PatientRecord*> *dataEntries;
public:
    QueryDatabaseForm(CUNavigationProvisioningInterface *pNavigator);
	~QueryDatabaseForm();

    void addPatientTableData(QList<StorableInterface*> * dataEntries);
    virtual void didSuccessfullyReceiveResponse(QList<StorableInterface *>*results);


    void setDataEntries(QList<PatientRecord*> *dataEntries);


    /*
      Called on the delegate when the response received from
      the server is a failure response. Included is the
      relevant error message.

            errrorMessage - The message explaining the error

      */
    virtual void didReceiveError(QString & errorMessage);


public slots:
    void previewLimits(int choice);
    void searchButtonClicked();
    void launchPatientContextMenu(const QPoint &);
    void editPatientRecord();
    void deletePatientRecord();

signals:
    void clearResultsTable();

private:
	CUContentPane *subjectPane; // will hold the subject label and comboBox
	CUContentPane *patientLimitSearchPane; // will contain parameters to limit search
	QLabel *subjectLabel;
	QComboBox *subjectComboBox;
	QLabel *limitSearchLabel;
    QLabel *followupStatusLabel;
    QComboBox *followupStatusComboBox;
	CUFormElement *primaryPhysician;
	CUServerRequestButton *searchButton;
	CUFormTable *resultsTable;
    QStackedWidget* hider;
};

#endif
