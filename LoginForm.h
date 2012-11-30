/*
Hashem Shawqi
Carleton University

This class represents the login page for cuCare
*/

#ifndef LOGINFORM
#define LOGINFORM

#include"CUPage.h"
#include"CUFormElement.h"
#include"CUServerRequestButton.h"

class LoginForm : public CUPage
{
    Q_OBJECT

public:
    LoginForm(CUNavigationProvisioningInterface *pNavigator);
	~LoginForm();

public slots:
    void configurationButtonClicked();

private:
	CUFormElement *usernameField; //this will contain the label and the line input
	CUServerRequestButton *loginButton; // login to cuCare
    CUNavigationButton *configurationButton;
};

#endif
