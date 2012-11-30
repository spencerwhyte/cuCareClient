#include"QueryDatabaseForm.h"

QueryDatabaseForm::QueryDatabaseForm(CUNavigationProvisioningInterface *pNavigator) : CUPage("Query Database", true, pNavigator)
{
    subjectPane = new CUContentPane(0);
    patientLimitSearchPane = new CUContentPane(0);

	subjectLabel = new QLabel("Select subject...");
	subjectComboBox = new QComboBox();
	subjectComboBox->addItem("<select subject>");
	subjectComboBox->addItem("Patient");

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
    hider->addWidget(blankWidget);
    hider->addWidget(patientLimitSearchPane);
    hider->setCurrentWidget(blankWidget);

    //add the new content pane into this page's content pane
    addElement(hider, 1, 0, 1, 1, Qt::AlignRight);

    searchButton = new CUServerRequestButton("Search", 0);
    resultsTable = new CUFormTable(1, 1);

	// add the last two elements now
    addElement(searchButton, 1, 1, 1, 1, Qt::AlignRight);
    addElement(resultsTable, 0, 2, 2, 1);

    //handle the event in which a subject is selected and the parameter are to be displayed
    QObject::connect(subjectComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(previewLimits(int)));
}

QueryDatabaseForm::~QueryDatabaseForm()
{

}

void QueryDatabaseForm::previewLimits(int choice)
{
    switch(choice)
    {
        case 0:
            hider->setCurrentIndex(0);
            break;
        case 1:
            hider->setCurrentIndex(1);
            break;
    }
}
