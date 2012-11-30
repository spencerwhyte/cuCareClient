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

class QueryDatabaseForm : public CUPage
{
    Q_OBJECT

public:
    QueryDatabaseForm(CUNavigationProvisioningInterface *pNavigator);
	~QueryDatabaseForm();

public slots:
    void previewLimits(int choice);

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
