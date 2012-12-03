#include"PatientRecordPage.h"

PatientRecordPage::PatientRecordPage(CUNavigationProvisioningInterface *pNavigator, StorableInterface* object) : CUPage(((PatientRecord*)object)->getName(), true, pNavigator), dataEntries(NULL)
{
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
}

PatientRecordPage::~PatientRecordPage()
{
    delete dataEntries;
}

/*
  This method receives a list of consultation records and traverses them,
  for each consultation record, the consultation's information is collected and
  cast into a QTableWidgetItem.
  */
void PatientRecordPage::addConsultationTableData(QList<StorableInterface*> * da)
{
    setDataEntries((QList<ConsultationRecord*> *) da);
    consultationRecordsTable->setColumnCount(1);
    QStringList headerList;
    headerList << "Date and Time of Consultation";
    consultationRecordsTable->setHeaderLabels(headerList);

    qDebug() << "SETTING HEADERS TO: " << headerList;

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
