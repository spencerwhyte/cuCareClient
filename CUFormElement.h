/*
Hashem Shawqi
Carleton University

This class contains a pair of a label (QLabel) and an input element (QLineEdit, QTextEdit, and QDateTimeEdit)
   */

#ifndef CUFORMELEMENT
#define CUFORMELEMENT

#include<QWidget>
#include<QLabel>
#include<QGridLayout>
#include<QLineEdit>
#include<QTextEdit>
#include<QDateTime>
#include<QDateTimeEdit>
#include"CUNavigationProvisioningInterface.h"


class CUFormElement : public QWidget
{
    Q_OBJECT

public:
    typedef enum cuFormVariant {LINE, PARAGRAPH, DATE} cuFormElement;

    CUFormElement(QString labelName, cuFormVariant pFormVariant, QWidget *parent);
	~CUFormElement();

    //get user input
    QString getInput();
    QDateTime getDate();
    void setInput(QString newInput);
    //set whether the input field ought to be edited or not
    void setEditable(bool editable);

signals:
    void setLineText(QString);

private:
	QLabel *label;
	QWidget *formInput;
	QGridLayout *layout;
    cuFormVariant formVariant;
};

#endif
