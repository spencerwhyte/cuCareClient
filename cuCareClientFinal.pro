# Add more folders to ship with the application, here
folder_01.source = qml/cuCareClientFinal
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xE032D2C6

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
# CONFIG += qdeclarative-boostable

# Add dependency to Symbian components
# CONFIG += qt-components

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    ClientTCPRequest.cpp \
    ClientHTTPRequest.cpp \
    ClientXMLRequest.cpp \
    ClientObjectRequest.cpp \
    ClientTCPResponse.cpp \
    ClientHTTPResponse.cpp \
    ClientXMLResponse.cpp \
    ClientObjectResponse.cpp \
    User.cpp \
    StorableFactory.cpp \
    Record.cpp \
    PatientRecord.cpp \
    FollowUpRecord.cpp \
    ConsultationRecord.cpp \
    ClientSettings.cpp \
    CUNavigationProvisioning.cpp \
    QueryDatabaseForm.cpp \
    ConsultationRecordPage.cpp \
    CUPageFactory.cpp \
    LoginForm.cpp \
    CUPage.cpp \
    HomePage.cpp \
    PatientRecordPage.cpp \
    IPAddressConfigurationForm.cpp \
    AdministrativeAssistantPageFactory.cpp \
    PhysicianPageFactory.cpp \
    CUNavigationStack.cpp \
    CUFormElement.cpp \
    CUFormTable.cpp \
    CUContentPane.cpp \
    CUNavigationButton.cpp \
    CUServerRequestButton.cpp \
    LoadingSpinner.cpp \
    EditConsultationRecordForm.cpp \
    AddConsultationRecordForm.cpp \
    AddFollowupForm.cpp \
    UpdateFollowupForm.cpp \
    addpatientrecordform.cpp \
    EditPatientRecordForm.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()


HEADERS += \
    ClientTCPRequest.h \
    ClientHTTPRequest.h \
    ClientXMLRequest.h \
    ClientObjectRequest.h \
    ClientTCPResponse.h \
    ClientHTTPResponse.h \
    ClientXMLResponse.h \
    ClientObjectResponse.h \
    User.h \
    StorableInterface.h \
    StorableFactory.h \
    Record.h \
    PatientRecord.h \
    FollowUpRecord.h \
    ConsultationRecord.h \
    ClientObjectResponseDelegate.h \
    ClientSettings.h \
    QueryDatabaseForm.h \
    ConsultationRecordPage.h \
    HomePage.h \
    CUPage.h \
    PatientRecordPage.h \
    LoginForm.h \
    IPAddressConfigurationForm.h \
    CUPageFactory.h \
    CUNavigationProvisioning.h \
    CUNavigationProvisioningInterface.h \
    AdministrativeAssistantPageFactory.h \
    PhysicianPageFactory.h \
    CUNavigationStack.h \
    LoadingSpinner.h \
    CUServerRequestButton.h \
    CUNavigationButton.h \
    CUFormTable.h \
    CUFormElement.h \
    CUContentPane.h \
    EditConsultationRecordForm.h \
    AddConsultationRecordForm.h \
    addpatientrecordform.h \
    AddFollowupForm.h \
    UpdateFollowupForm.h \
    EditPatientRecordForm.h


QT += network


QT += xml

OTHER_FILES += \
    loader.gif \
    configuration.png

RESOURCES += \
    ImageResources.qrc
