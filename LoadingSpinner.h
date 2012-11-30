/*
Hashem Shawqi
Carleton University

This is the spinny gif that is activated when calling the start() function
Resizing is to the detriment of the quality, just move it to the location you want it to occupy
   */

#ifndef LOADING_SPINNER
#define LOADING_SPINNER

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QImageReader>

class LoadingSpinner : public QLabel
{
    Q_OBJECT

public:
	LoadingSpinner(QWidget *parent);
	~LoadingSpinner();
	void start();
        void stop();

private:
	QMovie *spinnyMovie;
};

#endif
