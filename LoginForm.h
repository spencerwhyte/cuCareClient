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

#include "ClientObjectRequest.h"
#include "ClientObjectResponseDelegate.h"

#include <QMessageBox>

class LoginForm : public CUPage, public ClientObjectResponseDelegate
{
    Q_OBJECT

public:
    LoginForm(CUNavigationProvisioningInterface *pNavigator);
	~LoginForm();


   /*
     Gets called when the request to login has completed
     */
  virtual void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results);

  /*
    Gets called when request to the server fails
  */
  virtual void didReceiveError(QString & errorMessage);


public slots:
    void configurationButtonClicked();
    void communicateUsernameToServer();

private:
	CUFormElement *usernameField; //this will contain the label and the line input
	CUServerRequestButton *loginButton; // login to cuCare
    CUNavigationButton *configurationButton;
};

#endif
