/*
Hashem Shawqi
Carleton University

This class groups a button and a loading spinner. This button must provoke communication with the server, since that's the only process expected to take any noticeable amount of time.
   */

#ifndef CUSERVERREQUESTBUTTON
#define CUSERVERREQUESTBUTTON

#include<QString>
#include<QWidget>
#include<QPushButton>
#include<QGridLayout>
#include"LoadingSpinner.h"

class CUServerRequestButton : public QWidget
{
    Q_OBJECT

public:
    CUServerRequestButton(QString buttonName, QWidget *parent);
	~CUServerRequestButton();

	void startSpinner(); // this sets the gif loading animation going
	void stopSpinner(); // this stops and hides the gif loading animation

private:
	QPushButton *button;
	LoadingSpinner *spinner;
	QGridLayout *layout;
};

#endif
