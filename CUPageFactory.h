/*
Hashem Shawqi
Carleton University

This class contains functions for navigating from each page in the system
The navigation is essentially like asking the class "I am class A and I want to navigate away from here"
and this class will tell you where to go. The actual implementation is meant to utilize the subclasses,
since each of them is meant to be used for a specific kind of user.

The reason some of the pages in cuCare aren't here is because they only navigate back, such as the AddPatientRecordForm
  */

#ifndef CUPAGEFACTORY
#define CUPAGEFACTORY

#include<QWidget>
#include"CUNavigationProvisioningInterface.h"
#include"ConsultationRecordPage.h"
#include"IPAddressConfigurationForm.h"
#include"LoginForm.h"
#include"HomePage.h"
#include"PatientRecordPage.h"
#include"QueryDatabaseForm.h"
#include"EditPatientRecordForm.h"
#include"EditConsultationRecordForm.h"
#include"AddFollowupForm.h"
#include"UpdateFollowupForm.h"
#include"addpatientrecordform.h"

class CUPageFactory
{
public:
    CUPageFactory(CUNavigationProvisioningInterface* pNavigator);
    ~CUPageFactory();

    // the choice at the end allows us to determine which nvaigation button on the page was pressed
    // for occasions where there are two navigation buttons beside a back button
    virtual QWidget* navigateFromConsultationRecordPage(int choice, StorableInterface* object);
    virtual QWidget* navigateFromLoginForm(int choice);
    virtual QWidget* navigateFromPatientRecordPage(int choice, StorableInterface* object);
    virtual QWidget* navigateFromQueryDatabaseForm(int choice, StorableInterface* object);
    virtual QWidget* navigateFromHomePage(int choice);

    CUNavigationProvisioningInterface* getNavigator();
private:
    CUNavigationProvisioningInterface *navigator;
};

#endif
