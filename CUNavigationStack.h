/*
Hashem Shawqi
Carleton University

This class inherits QStackedWidget and is meant to simplify the operations of the widget
The stack is initialized with the login page already in there
  */

#ifndef CUNAVIGATIONSTACK
#define CUNAVIGATIONSTACK

#include<QStackedWidget>
#include<QWidget>

class CUNavigationStack : public QStackedWidget
{
    Q_OBJECT

public:
    CUNavigationStack();
    ~CUNavigationStack();

    void push(QWidget *widget);
    void pop();
    QWidget* lastQWidget();
};

#endif
