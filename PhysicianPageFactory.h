/*
Hashem Shawqi
Carleton University

This class is a subclass of the CUPageFactory, it essentially redirects a physician to the pages that match
his permissions
  */

#ifndef PHYSICIANPAGEFACTORY
#define PHYSICIANPAGEFACTORY

#include"CUPageFactory.h"


class PhysicianPageFactory : public CUPageFactory
{
public:
    PhysicianPageFactory(CUNavigationProvisioningInterface *pNavigator);
    ~PhysicianPageFactory();

};

#endif
