#ifndef HOMEPAGE
#define HOMEPAGE

#include"CUPage.h"

class HomePage : public CUPage
{
    Q_OBJECT

public:
    HomePage(CUNavigationProvisioningInterface *pNavigator);
    ~HomePage();

private:
    //enter all buttons included in the page
    CUNavigationButton *addPatientRecordButton;
    CUNavigationButton *queryDatabaseButton;
};

#endif
