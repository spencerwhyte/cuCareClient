#ifndef HOMEPAGE
#define HOMEPAGE

#include"CUPage.h"

class HomePage : public CUPage
{
    Q_OBJECT

public:
    HomePage(CUNavigationProvisioningInterface *pNavigator);
    ~HomePage();

public slots:
    void addPatientButtonClicked();
    void queryDatabaseButtonClicked();

signals:
    void navigateAwayFromPage(int);

private:
    //enter all buttons included in the page
    CUNavigationButton *addPatientRecordButton;
    CUNavigationButton *queryDatabaseButton;
    CUNavigationButton *reportsButton;
};

#endif
