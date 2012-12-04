#include "CUNavigationStack.h"

CUNavigationStack::CUNavigationStack() : QStackedWidget()
{

}

CUNavigationStack::~CUNavigationStack()
{

}


//push an element atop the stack, where the previous widget was sitting
void CUNavigationStack::push(QWidget *widget)
{
    addWidget(widget);
    setCurrentWidget(widget);
}

//pop an element from the stack and dispose of the widget on top of the stack
//the next widget is the one with the decremented index
void CUNavigationStack::pop()
{
    int disposableIndex = currentIndex();
    QWidget *disposableWidget = currentWidget();

    removeWidget(disposableWidget);
    setCurrentWidget(widget(disposableIndex - 1));
}

QWidget* CUNavigationStack::lastQWidget()
{
    int previousIndex = currentIndex();
    QWidget* previousWidget = widget(previousIndex - 1);
}
