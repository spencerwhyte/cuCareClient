/*
Hashem Shawqi
Carleton University

This class is responsible for creating queries and displaying query reports
   */

#ifndef QUERYDATABASEFORM
#define QUERYDATABASEFORM

#include<QLabel>
#include<QComboBox>
#include"CUPage.h"
#include"CUFormElement.h"
#include"CUContentPane.h"
#include"CUServerRequestButton.h"
#include"CUFormTable.h"
#include<QStackedWidget>
#include"PatientRecord.h"
#include"StorableInterface.h"
#include"ClientObjectResponseDelegate.h"

class QueryDatabaseForm : public CUPage, public ClientObjectResponseDelegate
{
    Q_OBJECT

public:
    QueryDatabaseForm(CUNavigationProvisioningInterface *pNavigator);
	~QueryDatabaseForm();

    void addPatientTableData(QList<StorableInterface*> &dataEntries);
    virtual void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results);

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
