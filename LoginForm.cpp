#include"LoginForm.h"

LoginForm::LoginForm(CUNavigationProvisioningInterface *pNavigator) : CUPage("Login", false, pNavigator)
{
    // decide the name and the type of the inputField and the type of input
    usernameField = new CUFormElement("Username:", CUFormElement::LINE, this);

    // create the login button
    loginButton = new CUServerRequestButton("Login", this);

    // create the network configuration button
    configurationButton = new CUNavigationButton("", this);
    configurationButton->setIcon(QIcon(":/new/config/configuration.png"));
    configurationButton->setIconSize(QSize(30, 30));

    // add the two elements to the page's content pane
    addElement(usernameField, 0, 0); // the x-span is 2 so that the login button would be at the bottom-right
    addElement(loginButton, 1, 0);

    getLayout()->addWidget(configurationButton, 2, 0, 1, 1, Qt::AlignRight);

    //connect the event handlers
    // the configuration button will navigate away from the login for with index of 1
    connect(configurationButton, SIGNAL(clicked()), this, SLOT(configurationButtonClicked()));

    //connect this window' navigation signal to the navigator
    connect(loginButton->getButton(), SIGNAL(clicked()), this, SLOT(communicateUsernameToServer()));
    connect(this, SIGNAL(navigateAwayFromPage(int)), pNavigator, SLOT(navigateFromLoginForm(int)));
    connect(this, SIGNAL(   submitUser(User*)       ), pNavigator, SLOT(setUserType(User*)));
}

// since all QT elements will be garbage-collected and the elements in this page have no extra non-QT pointers, there is no content in most destructor bodies for now
LoginForm::~LoginForm() 
{

}

void LoginForm::configurationButtonClicked()
{
    emit navigateAwayFromPage(1);
}

void LoginForm::communicateUsernameToServer()
{
    User u;
    if(usernameField->getInput().length() != 0){
        u.setUsername(usernameField->getInput());
        ClientObjectRequest * request= new ClientObjectRequest(this, u, ClientObjectRequest::EqualityQuery);
        setRequest(request);
        loginButton->startSpinner();
    }else{
        QMessageBox errorMessageBox;
        errorMessageBox.setText(QString("You must input a username."));
        errorMessageBox.exec();
    }
}




/*
  Gets called when the request to login has completed
  */
void LoginForm::didSuccessfullyReceiveResponse(QList<StorableInterface *> &results){
    loginButton->stopSpinner();
    qDebug() << results.length();
    if(results.length()!= 0){
        User* u = (User*)results.at(0);
        qDebug() << u->stringForUserType();
        if(u->getUserType() != User::Invalid){
            emit submitUser(u);
            usernameField->setInput("");
            emit navigateAwayFromPage(0);
            return;
        }
    }

    QMessageBox errorMessageBox;
    errorMessageBox.setText(QString("The username you have entered is invalid. Please try again."));
    errorMessageBox.exec();


}

/*
 Gets called when request to the server fails
*/
void LoginForm::didReceiveError(QString & errorMessage){
    loginButton->stopSpinner();
    QMessageBox errorMessageBox;
    errorMessageBox.setText(errorMessage);
    errorMessageBox.exec();
}
