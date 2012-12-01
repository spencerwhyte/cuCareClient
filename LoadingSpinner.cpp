#include "LoadingSpinner.h"

LoadingSpinner::LoadingSpinner(QWidget *parent) : QLabel(parent)
{
	setFixedSize(16, 16);
    spinnyMovie = new QMovie(":/new/spinner/loader.gif");


}

LoadingSpinner::~LoadingSpinner() 
{
	delete spinnyMovie;
}

void LoadingSpinner::start() 
{
    this->setMovie(spinnyMovie);
	spinnyMovie->start();
}

void LoadingSpinner::stop() 
{
	spinnyMovie->stop();
    this->setMovie(NULL);
}
