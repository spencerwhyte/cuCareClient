#include"CUFormElement.h"

// the form variant determines whether the 2nd pair item is a LineEdit, ParagraphEdit, or DateEdit
CUFormElement::CUFormElement(QString labelName, cuFormVariant pFormVariant,QWidget *parent) : QWidget(parent)
{
    formVariant = pFormVariant;

    layout = new QGridLayout(this);
    label = new QLabel(labelName, this);

	switch(formVariant)
	{
    case LINE: // LineEdit
        formInput = new QLineEdit(this);
        qDebug() << "BEFORE FAIL EMIT";
        connect(this, SIGNAL(setLineText(QString)), (QLineEdit*)formInput, SLOT(setText(QString)));
        qDebug() << "AFTER FAIL EMIT";
        break;
	case PARAGRAPH: // TextEdit
        qDebug() << "TTTTTTTT";
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

QString CUFormElement::getInput()
{
    switch(formVariant)
    {
    case LINE: // LineEdit
       return ((QLineEdit*)formInput)->text();
    case PARAGRAPH: // TextEdit
       return ((QTextEdit*)formInput)->document()->toPlainText();
    case DATE: // DateTime

        break;
    }
    return QString("");
}

void CUFormElement::setInput(QString newInput)
{
    switch(formVariant)
    {
    case LINE: // LineEdit
        qDebug() << "LINE";
        emit setLineText(newInput);
        break;
    case PARAGRAPH: // TextEdit
          qDebug() << "PARAGRAPH";
        ((QTextEdit*)formInput)->document()->setPlainText(newInput);
          break;
    case DATE: // DateTime
         qDebug() << "DateTime";
        break;
    }
}

void CUFormElement::setEditable(bool editable)
{
    formInput->setEnabled(editable);
}
