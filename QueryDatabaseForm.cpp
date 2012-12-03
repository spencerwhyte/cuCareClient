#include"QueryDatabaseForm.h"

QueryDatabaseForm::QueryDatabaseForm(CUNavigationProvisioningInterface *pNavigator) : CUPage("Query Database", true, pNavigator), dataEntries(NULL),currentObjectRequest(NULL)
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
    QObject::connect(searchButton->getButton(), SIGNAL(clicked()), this, SLOT(searchButtonClicked()));
    QObject::connect(this, SIGNAL(clearResultsTable()), resultsTable, SLOT(clearContents()));
    QObject::connect(resultsTable, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(launchPatientContextMenu(const QPoint &)));
    QObject::connect(resultsTable, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(navigateToPatientRecord(int, int)));
    QObject::connect(this, SIGNAL(navigateToPatientRecord(int, StorableInterface*)), pNavigator, SLOT(navigateFromQueryDatabaseForm(int,StorableInterface*)));
    QObject::connect(this, SIGNAL(navigateToEditConsultationRecordPage(int, StorableInterface*)), pNavigator, SLOT(navigateFromQueryDatabaseForm(int,StorableInterface*)));
}

QueryDatabaseForm::~QueryDatabaseForm()
{
    delete dataEntries;
    delete currentObjectRequest;
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

void QueryDatabaseForm::setDataEntries(QList<PatientRecord*> * da){
    if(dataEntries){
        delete dataEntries;
    }
    dataEntries = da;
}

void QueryDatabaseForm::setCurrentObjectRequest(ClientObjectRequest * newRequest){
    delete currentObjectRequest;
    currentObjectRequest = newRequest;
}

/*
  This method receives a list of patient records and traverses them,
  for each patient record, the patient's information is collected and
  cast into a QTableWidgetItem.
  */
void QueryDatabaseForm::addPatientTableData(QList<StorableInterface*> * da)
{
    setDataEntries((QList<PatientRecord*> *) da);
    resultsTable->setColumnCount(4);
    QStringList headerList;
    headerList << "Patient Name" << "OHIP Number" << "Phone Number" << "Primary Physician";
    resultsTable->setHeaderLabels(headerList);

    qDebug() << "SETTING HEADERS TO: " << headerList;

    QList<QList<QTableWidgetItem *> *> allRows;

    for (int row = 0; row < dataEntries->size(); row++)
    {
        PatientRecord * currentPatient = (PatientRecord*)dataEntries->at(row);

        QTableWidgetItem *name = new QTableWidgetItem();
        name->setData(Qt::DisplayRole, QString(currentPatient->getName()));
        QTableWidgetItem *ohipNumber = new QTableWidgetItem(QString(currentPatient->getOHIPNumber()));
        QTableWidgetItem *phoneNumber = new QTableWidgetItem(QString(currentPatient->getPhoneNumber()));
        QTableWidgetItem *primaryPhysician = new QTableWidgetItem(QString(currentPatient->getPrimaryPhysician()));

        QList<QTableWidgetItem *> * currentRow = new  QList<QTableWidgetItem *>();

        currentRow->append(name);
        currentRow->append(ohipNumber);
        currentRow->append(phoneNumber);
        currentRow->append(primaryPhysician);

        allRows.append(currentRow);
    }
    resultsTable->addAllRows(allRows);

    qDeleteAll(allRows);
}

void QueryDatabaseForm::searchButtonClicked()
{

    PatientRecord p;
    QString physicianName = primaryPhysician->getInput();
    p.setPrimaryPhysician(physicianName);

    switch(followupStatusComboBox->currentIndex())
    {
        case 1:
         qDebug() << "PENDING FOLLOW UPDSS";
            p.setHasPendingFollowUps(true);
            break;
        case 2:
        qDebug() << "COMPLETED FOLLOW UPDSS";
            p.setHasCompletedFollowUps(true);
            break;
        case 3:
         qDebug() << "OVERDUE FOLLOW UPDSS";
            p.setHasOverDueFollowUps(true);
            break;
    }

    ClientObjectRequest* r = new ClientObjectRequest(this, p, ClientObjectRequest::Query);
    this->setCurrentObjectRequest(r);
}

void QueryDatabaseForm::launchPatientContextMenu(const QPoint &)
{
    QMenu* contextMenu = new QMenu ( this );
    Q_CHECK_PTR ( contextMenu );

    contextMenu->addAction ( "Edit" , this , SLOT (editPatientRecord()) );
    contextMenu->addAction ( "Delete" , this , SLOT (deletePatientRecord()) );
    contextMenu->popup( QCursor::pos() );
    contextMenu->exec();
    delete contextMenu;
    contextMenu = 0;
}

void QueryDatabaseForm::navigateToPatientRecord(int row, int col)
{
    qDebug() << row;
    StorableInterface* patient = (StorableInterface*)dataEntries->at(row);
    emit navigateToPatientRecord(1, patient);
}

void QueryDatabaseForm::editPatientRecord()
{
    StorableInterface* patient = (StorableInterface*)dataEntries->at(resultsTable->currentRow());
    emit navigateToEditConsultationRecordPage(0, patient);
}

void QueryDatabaseForm::deletePatientRecord()
{
    qDebug() << "Inside launchPatientContextMenu ATTENTION!!";
    StorableInterface* patient = (StorableInterface*)dataEntries->at(resultsTable->currentRow());

    ClientObjectRequest * request = new ClientObjectRequest((ClientObjectResponseDelegate*)this, *patient, ClientObjectRequest::Remove);
    setCurrentObjectRequest(request);
    // Remove the data from the internal data array
    //dataEntries->removeAt(resultsTable->currentRow());
}

void QueryDatabaseForm::didSuccessfullyReceiveResponse(QList<StorableInterface *> *results)
{

    qDebug()<<"EMITING CLEAR RESULTS TABLE";
   // emit clearResultsTable();

    qDebug() << currentObjectRequest->stringForObjectRequestType(currentObjectRequest->getType());
    if(currentObjectRequest->getType()==ClientObjectRequest::Query){
        qDebug() << "ADDING PATIENT DATA";
        addPatientTableData(results);
    }else if(currentObjectRequest->getType()==ClientObjectRequest::Remove){
        PatientRecord * deletedPatientRecord = (PatientRecord*)results->at(0);
        for(int i = 0 ; i < dataEntries->length(); i++){
            PatientRecord * currentPatientRecord = (PatientRecord*)dataEntries->at(i);
            if(currentPatientRecord->getId() == deletedPatientRecord->getId()){
                resultsTable->removeRow(i);
                dataEntries->removeAt(i);
                delete currentPatientRecord;
                break;
            }
        }
    }


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
