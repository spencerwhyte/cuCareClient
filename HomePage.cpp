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

    addElement(addPatientRecordButton);
    addElement(queryDatabaseButton);
}

HomePage::~HomePage()
{

}
