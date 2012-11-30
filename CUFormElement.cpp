#include"CUFormElement.h"

// the form variant determines whether the 2nd pair item is a LineEdit, ParagraphEdit, or DateEdit
CUFormElement::CUFormElement(QString labelName, cuFormVariant formVariant, QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    label = new QLabel(labelName, this);

	switch(formVariant)
	{
	case LINE: // LineEdit
        formInput = new QLineEdit(this);
		break;
	case PARAGRAPH: // TextEdit
        formInput = new QTextEdit(this);
		//this element needs to have a bigger body than the other two
        setMinimumHeight(75);
        setMinimumWidth(600);
		break;
	case DATE: // DateTime
		//create a QDateTime object so that the default date and time match curent ones
		QDateTime current = QDateTime::currentDateTime();
        formInput = new QDateTimeEdit(current, this);
		break;
	}

	layout->addWidget(label, 0, 0);
	layout->addWidget(formInput, 0, 1);

	//set the default width for the input field
	label->setMinimumWidth(80);
    formInput->setMinimumWidth(180);

    setLayout(layout);
}

CUFormElement::~CUFormElement()
{

}

void CUFormElement::setEditable(bool editable)
{
    formInput->setEnabled(editable);
}
