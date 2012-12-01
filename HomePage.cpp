#include "HomePage.h"

HomePage::HomePage(CUNavigationProvisioningInterface *pNavigator) : CUPage("Homepage", true, pNavigator)
{
    addPatientRecordButton = new CUNavigationButton("Add Patient Record", 0);
    addPatientRecordButton->setFlat(true);
    addPatientRecordButton->setFont(QFont("Sans Serif", 18, 1));
    addPatientRecordButton->setStyleSheet("QPushButton{border:1px solid #000000;} QPushButton:pressed {border:1px solid #ff0000;}");
    addPatientRecordButton->setMinimumWidth(275);

    queryDatabaseButton = new CUNavigationButton("Query Database", 0);
    queryDatabaseButton->setFlat(true);
    queryDatabaseButton->setFont(QFont("Sans Serif", 18, 1));
    queryDatabaseButton->setStyleSheet("QPushButton{border:1px solid #000000;} QPushButton:pressed {border:1px solid #ff0000;}");
    queryDatabaseButton->setMinimumWidth(275);

    reportsButton = new CUNavigationButton("Reports", 0);
    reportsButton->setFlat(true);
    reportsButton->setFont(QFont("Sans Serif", 18, 1));
    reportsButton->setStyleSheet("QPushButton{border:1px solid #000000;} QPushButton:pressed {border:1px solid #ff0000;}");
    reportsButton->setMinimumWidth(275);
    reportsButton->setEnabled(false);

    addElement(addPatientRecordButton);
    addElement(queryDatabaseButton);
    addElement(reportsButton);

    connect(addPatientRecordButton, SIGNAL(clicked()), this, SLOT(addPatientButtonClicked()));
    connect(queryDatabaseButton, SIGNAL(clicked()), this, SLOT(queryDatabaseButtonClicked()));

    connect(this, SIGNAL(navigateAwayFromPage(int)), pNavigator, SLOT(navigateFromHomePage(int)));
}

HomePage::~HomePage()
{

}

void HomePage::addPatientButtonClicked()
{
    emit navigateAwayFromPage(0);
}

void HomePage::queryDatabaseButtonClicked()
{
    emit navigateAwayFromPage(1);
}
