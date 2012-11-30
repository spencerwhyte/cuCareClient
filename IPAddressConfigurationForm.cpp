#include"IPAddressConfigurationForm.h"

IPAddressConfigurationForm::IPAddressConfigurationForm(CUNavigationProvisioningInterface *pNavigator) : CUPage("Networking Configuration", true, pNavigator)
{
    instructionLabel = new QLabel("Please enter the server machine's ip address and port number:");
    ipAddressEntry = new CUFormElement("IP Address:", CUFormElement::LINE, 0);
    portNumberEntry = new CUFormElement("Port Number:", CUFormElement::LINE, 0);
    submitButton = new CUServerRequestButton("Submit", 0);

    addElement(instructionLabel);
    addElement(ipAddressEntry);
    addElement(portNumberEntry);
    addElement(submitButton, 0, 3, 1, 1, Qt::AlignRight);

    QObject::connect(submitButton->getButton(), SIGNAL(clicked()), this, SLOT(submitButtonClicked()));
    QObject::connect(this, SIGNAL(goBack()), pNavigator, SLOT(back()));
}

IPAddressConfigurationForm::~IPAddressConfigurationForm()
{

}

void IPAddressConfigurationForm::submitButtonClicked()
{

    ClientSettings& clientSettings = ClientSettings::GetClientSettings();
    QString addressInput = ipAddressEntry->getInput();
    if(clientSettings.setDefaultAddressString(addressInput)){
            QString portInput = portNumberEntry->getInput();
            if(clientSettings.setDefaultPortString(portInput)){
                emit goBack();

            }else{
                QMessageBox messageBox;
                messageBox.setText("The port number you entered was incorrect, please try again");
                messageBox.exec();
            }
    }else{
        QMessageBox messageBox;
        messageBox.setText("The IP address you entered was incorrect, please input the address in the format XXX.XXX.XXX.XXX");
        messageBox.exec();
    }




}
