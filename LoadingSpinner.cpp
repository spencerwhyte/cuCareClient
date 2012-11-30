#include "LoadingSpinner.h"

LoadingSpinner::LoadingSpinner(QWidget *parent) : QLabel(parent)
{
	setFixedSize(16, 16);
    spinnyMovie = new QMovie(":/new/spinner/loader.gif");

	this->setMovie(spinnyMovie);
}

LoadingSpinner::~LoadingSpinner() 
{
	delete spinnyMovie;
}

void LoadingSpinner::start() 
{
	spinnyMovie->start();
}

void LoadingSpinner::stop() 
{
	spinnyMovie->stop();
}
