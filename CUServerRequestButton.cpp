#include"CUServerRequestButton.h"

CUServerRequestButton::CUServerRequestButton(QString buttonName, QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    button = new QPushButton(buttonName, this);
	spinner = new LoadingSpinner(this);

	layout->addWidget(button, 0, 0);
	layout->addWidget(spinner, 0, 1);
	
	setLayout(layout);
}

CUServerRequestButton::~CUServerRequestButton()
{

}

QPushButton* CUServerRequestButton::getButton()
{
    return button;
}

//this method starts the gif loading animation spinning
void CUServerRequestButton::startSpinner()
{
	spinner->start();
}

//this mehtod stops the gif loading animation from spinning and hides it
void CUServerRequestButton::stopSpinner()
{
	spinner->stop();
}
