#include"QueryDatabaseForm.h"

QueryDatabaseForm::QueryDatabaseForm(CUNavigationProvisioningInterface *pNavigator) : CUPage("Query Database", true, pNavigator)
{
    subjectPane = new CUContentPane(0);
    patientLimitSearchPane = new CUContentPane(0);

	subjectLabel = new QLabel("Select subject...");
	subjectComboBox = new QComboBox();
	subjectComboBox->addItem("<select subject>");
	subjectComboBox->addItem("Patient");
    subjectComboBox->addItem("Physician");
    subjectComboBox->addItem("Consultation");

    subjectPane->addElement(subjectLabel, 0, 0, 1, 1, Qt::AlignTop);
    subjectPane->addElement(subjectComboBox, 1, 0, 1, 1, Qt::AlignTop);
	//add the new content pane into this page's contentpane
	addElement(subjectPane);

	limitSearchLabel = new QLabel("Limit Search");
    followupStatusLabel = new QLabel("Followup Status:");
    followupStatusLabel->setMinimumWidth(80);
    followupStatusComboBox = new QComboBox();
    followupStatusComboBox->addItem("<any status>");
    followupStatusComboBox->addItem("Pending");
    followupStatusComboBox->addItem("Complete");
    followupStatusComboBox->addItem("Overdue");
    followupStatusComboBox->setMinimumWidth(180);
    QWidget* container = new QWidget(this);
    QGridLayout *tempLayout = new QGridLayout(this);
    container->setLayout(tempLayout);
    tempLayout->addWidget(followupStatusLabel, 0, 0);
    tempLayout->addWidget(followupStatusComboBox, 0, 1);
    primaryPhysician = new CUFormElement("Primary Physician:", CUFormElement::LINE, 0);

    patientLimitSearchPane->addElement(limitSearchLabel);
    patientLimitSearchPane->addElement(container);
    patientLimitSearchPane->addElement(primaryPhysician);

    hider = new QStackedWidget();
    QWidget *blankWidget = new QWidget();
    QLabel *notificationWidget = new QLabel("This functionality is not yet available");
    hider->addWidget(blankWidget);
    hider->addWidget(patientLimitSearchPane);
    hider->addWidget(notificationWidget);
    hider->setCurrentWidget(blankWidget);

    //add the new content pane into this page's content pane
    addElement(hider, 1, 0, 1, 1, Qt::AlignRight);

    searchButton = new CUServerRequestButton("Search", 0);
    searchButton->setVisible(false);

    resultsTable = new CUFormTable(0, 0);

	// add the last two elements now
    addElement(searchButton, 1, 1, 1, 1, Qt::AlignRight);
    addElement(resultsTable, 0, 2, 2, 1);

    //handle the event in which a subject is selected and the parameter are to be displayed
    QObject::connect(subjectComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(previewLimits(int)));
    QObject::connect(searchButton, SIGNAL(clicked()), this, SLOT(searchButtonClicked));
    QObject::connect(this, SIGNAL(clearResultsTable()), resultsTable, SLOT(clear()));
}

QueryDatabaseForm::~QueryDatabaseForm()
{

}

void QueryDatabaseForm::previewLimits(int choice)
{
    searchButton->setVisible(false);
    switch(choice)
    {
        case 0:
            hider->setCurrentIndex(0);
            break;
        case 1:
            hider->setCurrentIndex(1);
            searchButton->setVisible(true);
            break;
        case 2:
            hider->setCurrentIndex(2);
            break;
        case 3:
            hider->setCurrentIndex(2);
            break;
    }
}

/*
  This method receives a list of patient records and traverses them,
  for each patient record, the patient's information is collected and
  cast into a QTableWidgetItem.
  */
void QueryDatabaseForm::addPatientTableData(QList<StorableInterface*> &dataEntries)
{
    QStringList headerList;
    headerList << "Patient Name" << "OHIP Number" << "Phone Number" << "Primary Physician";
    resultsTable->setHorizontalHeaderLabels(headerList);

    for (int row = 0; row < dataEntries.size(); row++)
    {
        PatientRecord * currentPatient = (PatientRecord*)dataEntries.at(row);

        QTableWidgetItem *name = new QTableWidgetItem(QString(currentPatient->getName()));
        QTableWidgetItem *ohipNumber = new QTableWidgetItem(QString(currentPatient->getOHIPNumber()));
        QTableWidgetItem *phoneNumber = new QTableWidgetItem(QString(currentPatient->getPhoneNumber()));
        QTableWidgetItem *primaryPhysician = new QTableWidgetItem(QString(currentPatient->getPrimaryPhysician()));

        //insert the data into the table
        resultsTable->setItem(row, 0, name);
        resultsTable->setItem(row, 1, ohipNumber);
        resultsTable->setItem(row, 2, phoneNumber);
        resultsTable->setItem(row, 3, primaryPhysician);
    }
}

void QueryDatabaseForm::searchButtonClicked()
{

    PatientRecord p;
    QString physicianName = primaryPhysician->getInput();
    p.setHasCompletedFollowUps(true);
    p.setPrimaryPhysician(physicianName);

    switch(followupStatusComboBox->currentIndex())
    {
        case 1:
            p.setHasPendingFollowUps(true);
            break;
        case 2:
            p.setHasCompletedFollowUps(true);
            break;
        case 3:
            p.setHasOverDueFollowUps(true);
            break;
    }

    ClientObjectRequest* r = new ClientObjectRequest(this, p, ClientObjectRequest::Query);

}

void QueryDatabaseForm::didSuccessfullyReceiveResponse(QList<StorableInterface *> &results)
{
    emit clearResultsTable();

    addPatientTableData(results);
}

/*
  Called on the delegate when the response received from
  the server is a failure response. Included is the
  relevant error message.

        errrorMessage - The message explaining the error

  */
void QueryDatabaseForm::didReceiveError(QString & errorMessage)
{

}
