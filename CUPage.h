/*
Hashem Shawqi
Carleton University

This class is the super class for all pages in cuCare. The template involves a title at the top-left corner and a content pane in the center
  */

#ifndef CUPAGE
#define CUPAGE

#include<QApplication>
#include<QWidget>
#include<QLabel>
#include<QGridLayout>
#include<QString>
#include<QPalette>
#include<QColor>
#include<QGridLayout>
#include<QIcon>
#include<QStyle>
#include"CUContentPane.h"
#include"CUNavigationButton.h"
#include"CUNavigationProvisioningInterface.h"

#include "ClientObjectRequest.h"

class CUPage : public QWidget
{
    Q_OBJECT
    ClientObjectRequest * request;
public:
    CUPage(QString title, bool containsBackButton, CUNavigationProvisioningInterface *pNavigator);
	~CUPage();

    void setRequest(ClientObjectRequest * request);
    void setTitle(QString newtitle);

    ClientObjectRequest * getRequest();

    QGridLayout* getLayout();
    CUNavigationProvisioningInterface* getNavigator();
    // set the title of the page
    void setPageTitle(QString title);
    // insert an element at the bottom of the contentpane
    void addElement(QWidget *element, int xPosition = 0);
    // specify where you want to insert the element in the contentpane and its span on the grid layout
    void addElement(QWidget *element, int xPosition, int yPosition, int xSpan = 1, int ySpan = 1);
    // add an element, and specify its alignment
    void addElement(QWidget *element, int xPosition, int yPosition, int xSpan, int ySpan, Qt::AlignmentFlag alignment);
    // add an element to the table in the page, if it exists
    virtual void addToTable(StorableInterface* object);
    virtual void updateTable(StorableInterface* object);

signals:
    void navigateAwayFromPage(int choice);
    void navigateAwayFromPage(int choice, StorableInterface* object);

private:
	QLabel *titleLabel;
    CUNavigationButton *backButton; // this is the button that will navigate back in the page stack
    CUContentPane *contentPane; // this panel contains all objects that are required for the page to behave uniquely
    QGridLayout *layout;
};

#endif
