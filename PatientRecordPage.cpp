#include"PatientRecordPage.h"

PatientRecordPage::PatientRecordPage(CUNavigationProvisioningInterface *pNavigator, StorableInterface* object) : CUPage(((PatientRecord*)object)->getName(), true, pNavigator), dataEntries(NULL),currentObjectRequest(NULL)
{
    patient = (PatientRecord*)object;

    //note the lack of a title. The title should be the patient's name. Make sure you setup the name after the patient data is received
    phoneNumberElement = new CUFormElement("Phone Number:", CUFormElement::LINE, 0);
    ohipNumberElement = new CUFormElement("OHIP Number:", CUFormElement::LINE, 0);
    primaryPhysicianElement = new CUFormElement("Primary Physician:", CUFormElement::LINE, 0);
    addConsultationButton = new CUNavigationButton("Add Consultation", 0);
    consultationRecordsTable = new CUFormTable(0, 0);

    //add the elements to the page
    addElement(phoneNumberElement);
    addElement(ohipNumberElement);
    addElement(primaryPhysicianElement);
    addElement(addConsultationButton, 0, 5, 1, 1, Qt::AlignRight);
    addElement(consultationRecordsTable);

    //populate the form
    PatientRecord* patientRecord = (PatientRecord*) object;
    phoneNumberElement->setInput(patientRecord->getPhoneNumber());
    ohipNumberElement->setInput(patientRecord->getOHIPNumber());
    primaryPhysicianElement->setInput(patientRecord->getPrimaryPhysician());

    //prevent the user from editing the elements with patient information
    phoneNumberElement->setEditable(false);
    ohipNumberElement->setEditable(false);
    primaryPhysicianElement->setEditable(false);

    //connect all navigation handlers
    QObject::connect(addConsultationButton, SIGNAL(clicked()), this, SLOT(navigateToAddConsultationRecordForm()));
    QObject::connect(consultationRecordsTable, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(launchPatientContextMenu(const QPoint &)));
    QObject::connect(consultationRecordsTable, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(navigateToConsultationRecordPage(int, int)));
    QObject::connect(this, SIGNAL(navigateAwayFromPage(int,StorableInterface*)), pNavigator, SLOT(navigateFromPatientRecordPage(int, StorableInterface*)));

    QString ohipNumber = patientRecord->getOHIPNumber();

    ConsultationRecord record;
    record.setOHIPNumber(ohipNumber);


    ClientObjectRequest * request = new ClientObjectRequest((ClientObjectResponseDelegate*)this,record,ClientObjectRequest::EqualityQuery);


}

PatientRecordPage::~PatientRecordPage()
{
    delete dataEntries;
    delete currentObjectRequest;
}

void PatientRecordPage::setCurrentObjectRequest(ClientObjectRequest * newRequest){
    delete currentObjectRequest;
    currentObjectRequest = newRequest;
}

void PatientRecordPage::didSuccessfullyReceiveResponse(QList<StorableInterface *> * results){
    addConsultationTableData(results);
}

void PatientRecordPage::didReceiveError(QString & errorMessage){

}

/*
  This method receives a list of consultation records and traverses them,
  for each consultation record, the consultation's information is collected and
  cast into a QTableWidgetItem.
  */
void PatientRecordPage::addConsultationTableData(QList<StorableInterface*> * da)
{
    setDataEntries((QList<ConsultationRecord*> *) da);

    addConsultationTableDataAgain(da);
}

void PatientRecordPage::addConsultationTableDataAgain(QList<StorableInterface*> * da)
{
    consultationRecordsTable->setColumnCount(1);
    QStringList headerList;
    headerList << "Date and Time of Consultation";
    consultationRecordsTable->setHeaderLabels(headerList);


    QList<QList<QTableWidgetItem *> *> allRows;

    for (int row = 0; row < dataEntries->size(); row++)
    {
        ConsultationRecord * currentConsultation = (ConsultationRecord*)dataEntries->at(row);
        QTableWidgetItem * dateAndTime = new QTableWidgetItem();

        dateAndTime->setData(Qt::DisplayRole, currentConsultation->getDateAndTime().toString());

        QList<QTableWidgetItem *> * currentRow = new  QList<QTableWidgetItem *>();

        currentRow->append(dateAndTime);

        allRows.append(currentRow);
    }
    consultationRecordsTable->addAllRows(allRows);

    qDeleteAll(allRows);
}


void PatientRecordPage::setDataEntries(QList<ConsultationRecord *> *da)
{
    delete dataEntries;
    dataEntries = da;
}

void PatientRecordPage::launchPatientContextMenu(const QPoint &)
{
    QMenu* contextMenu = new QMenu ( this );
    Q_CHECK_PTR ( contextMenu );

    contextMenu->addAction ( "Edit" , this , SLOT (editConsultationRecord()) );
    contextMenu->popup( QCursor::pos() );
    contextMenu->exec();
    delete contextMenu;
    contextMenu = 0;
}

void PatientRecordPage::editConsultationRecord()
{
    if(consultationRecordsTable->currentItem()!=NULL)
    {
        StorableInterface* consultation = dataEntries->at(consultationRecordsTable->currentRow());
        emit navigateAwayFromPage(0, consultation);
    }
}

void PatientRecordPage::navigateToConsultationRecordPage(int row, int col)
{
    StorableInterface* consultation = dataEntries->at(row);
    emit navigateAwayFromPage(1, consultation);
}

void PatientRecordPage::navigateToAddConsultationRecordForm()
{
    emit navigateAwayFromPage(2, patient);
}

void PatientRecordPage::addToTable(StorableInterface* object)
{
    dataEntries->append((ConsultationRecord*)object);

    QList<StorableInterface*> * newModel = (QList<StorableInterface*>*)dataEntries;

    addConsultationTableDataAgain(newModel);
}

void PatientRecordPage::updateTable(StorableInterface* object)
{
    for(int i =0; i< dataEntries->length(); i++)
    {
        if(dataEntries->at(i)->getId() == ((ConsultationRecord*)object)->getId())
        {
            dataEntries->replace(i, ((ConsultationRecord*)object));
            break;
        }
    }

    QList<StorableInterface*> * newModel = (QList<StorableInterface*>*)dataEntries;

    addConsultationTableDataAgain(newModel);
}
