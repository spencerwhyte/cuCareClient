#include"ConsultationRecordPage.h"

ConsultationRecordPage::ConsultationRecordPage(CUNavigationProvisioningInterface *pNavigator, StorableInterface* object) : CUPage(((ConsultationRecord*)object)->getDateAndTime().toString(), true, pNavigator), dataEntries(NULL), currentObjectRequest(NULL)
{
    //note the lack of a title. The title should be the patient's name. Make sure you setup the name after the patient data is received
    dateAndTime = new CUFormElement("Date and Time:", CUFormElement::DATE, 0);
    reason = new CUFormElement("Reason for Visit:", CUFormElement::PARAGRAPH, 0);
    ohipNumber = new CUFormElement("OHIP Number:", CUFormElement::LINE, 0);
    diagnosis = new CUFormElement("Diagnosis:", CUFormElement::PARAGRAPH, 0);
    addFollowupButton = new CUNavigationButton("Add Followup", 0);
    followupTable = new CUFormTable(0,0);
    //diagnosis->setMinimumWidth(500);

    //populate the fields
    ConsultationRecord* consultation = (ConsultationRecord*)object;
    dateAndTime->setInput(consultation->getDateAndTime().toString());
    reason->setInput(consultation->getReason());
    ohipNumber->setInput(consultation->getOHIPNumber());
    diagnosis->setInput(consultation->getDiagnosis());

    //add the elements to the page
    addElement(ohipNumber);
    addElement(dateAndTime);
    addElement(reason);
    addElement(diagnosis);
    addElement(addFollowupButton, 0, 5, 1, 1, Qt::AlignRight);
    addElement(followupTable);

    //disable all the consultation information
    ohipNumber->setEditable(false);
    dateAndTime->setEditable(false);
    reason->setEditable(false);
    diagnosis->setEditable(false);

    //connect the add followup button to the navigator
    QObject::connect(addFollowupButton, SIGNAL(clicked()), this, SLOT(navigateToAddFollowupForm()));
    //QObject::connect(this, SIGNAL(navigateAwayFromPage(int)), pNavigator, SLOT(navigateFromConsultationRecordPage(int)));
    QObject::connect(followupTable, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(launchPatientContextMenu(const QPoint &)));
    QObject::connect(this, SIGNAL(navigateAwayFromPage(int, StorableInterface*)), pNavigator, SLOT(navigateFromConsultationRecordPage(int, StorableInterface*)));
    QObject::connect(followupTable, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(navigateToUpdateFollowups(int, int)));


    ClientObjectRequest * request = new ClientObjectRequest(this, *object, ClientObjectRequest::EqualityQuery);
    setCurrentObjectRequest(request);
}


ConsultationRecordPage::~ConsultationRecordPage()
{
    delete dataEntries;
    delete currentObjectRequest;
}

void ConsultationRecordPage::addFollowupButtonClicked()
{
    emit navigateAwayFromPage(0);
}

void ConsultationRecordPage::setCurrentObjectRequest(ClientObjectRequest * newRequest){
    delete currentObjectRequest;
    currentObjectRequest = newRequest;
}

/*
  This method receives a list of followups and traverses them,
  for each followup, that followup's information is collected and
  cast into a QTableWidgetItem.
  */
void ConsultationRecordPage::addFollowupTableData(QList<StorableInterface*> * da)
{
    setDataEntries((QList<FollowUpRecord*> *) da);

    addFollowupTableDataAgain(da);
}

void ConsultationRecordPage::addFollowupTableDataAgain(QList<StorableInterface*> * da)
{
    followupTable->setColumnCount(1);
    QStringList headerList;
    headerList << "Status" << "Due Date" << "Details";
    followupTable->setHeaderLabels(headerList);

    qDebug() << "SETTING HEADERS TO: " << headerList;

    QList<QList<QTableWidgetItem *> *> allRows;

    for (int row = 0; row < dataEntries->size(); row++)
    {
        FollowUpRecord * currentFollowup = (FollowUpRecord*)dataEntries->at(row);

        QTableWidgetItem *statusString = 0;
        if(currentFollowup->getStatus() == FollowUpRecord::PENDING)
        {
            statusString =  new QTableWidgetItem(QString("Pending"));
        }
        else if (currentFollowup->getStatus() == FollowUpRecord::OVERDUE)
        {
            statusString = new QTableWidgetItem(QString("Overdue"));
        }
        else if (currentFollowup->getStatus() == FollowUpRecord::COMPLETE)
        {
            statusString = new QTableWidgetItem(QString("Complete"));
        }
        else
        {
            statusString = new QTableWidgetItem(QString("Invalid"));
        }

        QTableWidgetItem* dueDateTime = new QTableWidgetItem();
        QTableWidgetItem* details = new QTableWidgetItem(currentFollowup->getDetails());

        dueDateTime->setData(Qt::DisplayRole, currentFollowup->getDueDateTime().toString());

        QList<QTableWidgetItem *> * currentRow = new  QList<QTableWidgetItem *>();

        currentRow->append(statusString);
        currentRow->append(dueDateTime);
        currentRow->append(details);

        allRows.append(currentRow);
    }
    followupTable->addAllRows(allRows);

    qDeleteAll(allRows);
}

void ConsultationRecordPage::setDataEntries(QList<FollowUpRecord *> *da)
{
    delete dataEntries;
    dataEntries = da;
}

void ConsultationRecordPage::didSuccessfullyReceiveResponse(QList<StorableInterface *> * results){

    qDebug() << "SDHFJKJBSDBFJKSBDJKSDJKFSDFJKSHDKJFHSDJKf";

    if(currentObjectRequest->getType() == ClientObjectRequest::EqualityQuery){
         addFollowupTableData(results);
    }else if(currentObjectRequest->getType() == ClientObjectRequest::Add){

    }


}

void ConsultationRecordPage::didReceiveError(QString & errorMessage){

}

void ConsultationRecordPage::launchPatientContextMenu(const QPoint &)
{
    QMenu* contextMenu = new QMenu ( this );
    Q_CHECK_PTR ( contextMenu );

    contextMenu->addAction ( "View/Update" , this , SLOT (navigateToUpdateFollowups()) );
    contextMenu->popup( QCursor::pos() );
    contextMenu->exec();
    delete contextMenu;
    contextMenu = 0;
}

void ConsultationRecordPage::navigateToUpdateFollowups()
{
    StorableInterface* followup = (StorableInterface*)dataEntries->at(followupTable->currentRow());
    emit navigateAwayFromPage(0, followup);
}

void ConsultationRecordPage::navigateToUpdateFollowups(int row, int col)
{
    StorableInterface* followup = (StorableInterface*)dataEntries->at(followupTable->currentRow());
    emit navigateAwayFromPage(0, followup);
}

void ConsultationRecordPage::navigateToAddFollowupForm()
{
    emit navigateAwayFromPage(1, 0);
}

void ConsultationRecordPage::addToTable(StorableInterface* object)
{
    qDebug() << "BE HAPPY EVERYTHING GOOD";
    dataEntries->append((FollowUpRecord*)object);

    QList<StorableInterface*> * newModel = (QList<StorableInterface*>*)dataEntries;

    addFollowupTableDataAgain(newModel);
}
