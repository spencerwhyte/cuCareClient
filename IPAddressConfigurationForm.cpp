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
}

IPAddressConfigurationForm::~IPAddressConfigurationForm()
{

}
