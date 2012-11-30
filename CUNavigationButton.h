#ifndef CUNAVIGATIONBUTTON
#define CUNAVIGATIONBUTTON

#include<QPushButton>
#include<QString>

class CUNavigationButton : public QPushButton
{
    Q_OBJECT

public:
    CUNavigationButton(QString buttonName, QWidget *parent);
    ~CUNavigationButton();
};

#endif
