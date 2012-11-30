#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"


#include "User.h"
#include "ClientObjectRequest.h"
#include "ClientObjectResponseDelegate.h"
#include  <QList>
#include "PatientRecord.h"
#include "FollowUpRecord.h"
#include <QDateTime>







#include<QApplication>
#include<QMainWindow>
#include<QString>
#include"CUNavigationStack.h"
#include"CUNavigationProvisioning.h"

void testUser(){
    User u;
    QString username("Spencer Whyte");
    u.setUsername(username);
    u.setUserType(User::Physician);
    u.setId(100);

    if(QString::compare(u.getUsername(), QString("Spencer Whyte")) != 0){
        qDebug() << "User/getUsername test failed";
    }

    if(u.getId() != 100){
         qDebug() << "User/getId test failed";
    }

    if(u.getUserType() != User::Physician){
         qDebug() << "User/getUserType test failed";
    }

}


void testPatient(){
    PatientRecord p;

    QString name("John Doe");
    p.setName(name);

    QString phoneNumber("613-599-1209");
    p.setPhoneNumber(phoneNumber);

    QString ohip("QWERTYUIOP123456789");
    p.setOHIPNumber(ohip);

    QString physician("Spencer Whyte");
    p.setPrimaryPhysician(physician);

    if(QString::compare(p.getName(), QString("John Doe")) != 0){
        qDebug() << "User/name test failed";
    }

    if(QString::compare(p.getPhoneNumber(), QString("613-599-1209")) != 0){
        qDebug() << "User/phone test failed";
    }

    if(QString::compare(p.getOHIPNumber(), QString("QWERTYUIOP123456789")) != 0){
        qDebug() << "User/ohip test failed";
    }

    if(QString::compare(p.getPrimaryPhysician(), QString("Spencer Whyte")) != 0){
        qDebug() << "User/physician test failed";
    }
}

void testAddUser(){
    User * u = new User();
    QString username("Spencer Whyte");
    u->setUsername(username);
    u->setUserType(User::Physician);


    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             for(int i = 0 ; i < results.length(); i++){
                 qDebug() << ((User*)results.at(i))->getUsername();
                 qDebug() << ((User*)results.at(i))->stringForUserType();
             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, *u, ClientObjectRequest::Add);

}

void testAddPatient(){
    PatientRecord * p = new PatientRecord();

    QString name("John Doe");
    p->setName(name);

    QString phoneNumber("613-599-1209");
    p->setPhoneNumber(phoneNumber);

    QString ohip("QWERTYUIOP123456789");
    p->setOHIPNumber(ohip);

    QString physician("Spencer Whyte");
    p->setPrimaryPhysician(physician);


    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){
                 qDebug() << ((PatientRecord*)results.at(i))->getName();
                 qDebug() << ((PatientRecord*)results.at(i))->getPhoneNumber();
                 qDebug() << ((PatientRecord*)results.at(i))->getOHIPNumber();
                 qDebug() << ((PatientRecord*)results.at(i))->getPrimaryPhysician();
                 qDebug() << ((PatientRecord*)results.at(i))->getId();
             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, *p, ClientObjectRequest::Add);
}


void testQueryUser(){
    User * u = new User();
    QString username("Spencer Whyte");
    u->setUsername(username);
    u->setUserType(User::Physician);


    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){
                 qDebug() << ((User*)results.at(i))->getUsername();
                 qDebug() << ((User*)results.at(i))->stringForUserType();
             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, *u, ClientObjectRequest::Query);

}

void testQueryPatient(){
    PatientRecord * p = new PatientRecord();

   // QString name("John Doe");
   // p->setName(name);

    //QString phoneNumber("613-599-1209");
   // p->setPhoneNumber(phoneNumber);

    //QString ohip("QWERTYUIOP123456789");
    //p->setOHIPNumber(ohip);

    QString physician("Spencer Whyte");
    p->setPrimaryPhysician(physician);

   // int id=1;
   // p->setId(1);

    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){
                 qDebug() << ((PatientRecord*)results.at(i))->getName();
                 qDebug() << ((PatientRecord*)results.at(i))->getPhoneNumber();
                 qDebug() << ((PatientRecord*)results.at(i))->getOHIPNumber();
                 qDebug() << ((PatientRecord*)results.at(i))->getPrimaryPhysician();
                 qDebug() << ((PatientRecord*)results.at(i))->getId();
             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, *p, ClientObjectRequest::Query);
}

void testEditUser(){
    User * u = new User();
    QString username("Spencer Whyte");
    u->setUsername(username);
    u->setUserType(User::Physician);


    class TestObject2 : public ClientObjectResponseDelegate{

         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() << ((User*)results.at(0))->getUsername();
             qDebug() << ((User*)results.at(0))->stringForUserType();
             qDebug() << ((User*)results.at(0))->getId();
             qDebug() << "EDIT FINISHED";
         }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }

    };




    class TestObject : public ClientObjectResponseDelegate{
        QList<StorableInterface*> * rj;


         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             rj = new QList<StorableInterface*>(results);
             TestObject2 * t2 = new TestObject2();
             User * u = (User*)results.at(0);
             u->setUserType(User::MedicalPersonnel);
             ClientObjectRequest * r2 = new ClientObjectRequest(t2 , *u, ClientObjectRequest::Edit);


        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, *u, ClientObjectRequest::Query);
}

void testEditPatient(){
    PatientRecord * p = new PatientRecord();

    QString name("Jack Doe");
    p->setName(name);

    QString phoneNumber("613-599-1209");
    p->setPhoneNumber(phoneNumber);

    QString ohip("QWERTYUIOP123456789");
    p->setOHIPNumber(ohip);

    QString physician("Spencer Whyte");
    p->setPrimaryPhysician(physician);

    p->setId(1);

    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){
                 qDebug() << ((PatientRecord*)results.at(i))->getName();
                 qDebug() << ((PatientRecord*)results.at(i))->getPhoneNumber();
                 qDebug() << ((PatientRecord*)results.at(i))->getOHIPNumber();
                 qDebug() << ((PatientRecord*)results.at(i))->getPrimaryPhysician();
                 qDebug() << ((PatientRecord*)results.at(i))->getId();
             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, *p, ClientObjectRequest::Edit);
}



void testRemoveUser(){
    User * u = new User();
    QString username("Spencer Whyte");
    u->setUsername(username);
    u->setUserType(User::Physician);
    u->setId(1);


    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() << "REMOVED USER SUCCESSFULLY";
             for(int i = 0 ; i < results.length(); i++){
                 qDebug() << ((User*)results.at(i))->getUsername();
                 qDebug() << ((User*)results.at(i))->stringForUserType();
             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, *u, ClientObjectRequest::Remove);
}

void testRemovePatient(){
    PatientRecord * u = new PatientRecord();
    u->setId(1);

    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() << "REMOVED USER SUCCESSFULLY";
             for(int i = 0 ; i < results.length(); i++){

             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, *u, ClientObjectRequest::Remove);
}

void testConsulationRecord(){

    ConsultationRecord c;
    QDateTime d;
    QDate qd;
    QTime qt;

    qd.setYMD(2000,1,1);

    qt.setHMS(12,12,12);



    d.setDate(qd);
    d.setTime(qt);

    c.setDateAndTime(d);

    c.setDiagnosis(QString("Cancer"));

    c.setOHIPNumber(QString("QWERTYUIOP123456789"));

    c.setReason(QString("It's just part of life"));



    if(c.getDateAndTime().date().day() != 1){
        qDebug() << "ERROR IN consultation/date/day TEST CASE";
    }

    if(c.getDateAndTime().date().month() != 1){
        qDebug() << "ERROR IN consultation/date/month TEST CASE";
    }

    if(c.getDateAndTime().date().year() != 2000){
        qDebug() << "ERROR IN consultation/date/year TEST CASE";
    }

    if(c.getDateAndTime().time().hour() != 12){
        qDebug() << "ERROR IN consultation/time/hour TEST CASE";
    }

    if(c.getDateAndTime().time().minute() != 12){
        qDebug() << "ERROR IN consultation/time/minute TEST CASE";
    }

    if(c.getDateAndTime().time().second() != 12){
        qDebug() << "ERROR IN consultation/time/second TEST CASE";
    }

    if(QString::compare(c.getDiagnosis(), "Cancer") !=0){
        qDebug() << "ERROR IN consultation/diagnosis TEST CASE";
    }

    if(QString::compare(c.getOHIPNumber(), "QWERTYUIOP123456789") !=0){
        qDebug() << "ERROR IN consultation/ohip TEST CASE";
    }

    if(QString::compare(c.getReason(), "It's just part of life") !=0){
        qDebug() << "ERROR IN consultation/reason TEST CASE";
    }


}



void testAddConsulationRecord(){

    ConsultationRecord c;
    QDateTime d;
    QDate qd;
    QTime qt;

    qd.setYMD(2000,1,1);

    qt.setHMS(12,12,12);

    d.setDate(qd);
    d.setTime(qt);

    c.setDateAndTime(d);

    c.setDiagnosis(QString("Cancer"));

    c.setOHIPNumber(QString("QWERTYUIOP123456789"));

    c.setReason(QString("It's just part of life"));







    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){

             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, c, ClientObjectRequest::Add);





    if(c.getDateAndTime().date().day() != 1){
        qDebug() << "ERROR IN consultation/date/day TEST CASE";
    }

    if(c.getDateAndTime().date().month() != 1){
        qDebug() << "ERROR IN consultation/date/month TEST CASE";
    }

    if(c.getDateAndTime().date().year() != 2000){
        qDebug() << "ERROR IN consultation/date/year TEST CASE";
    }

    if(c.getDateAndTime().time().hour() != 12){
        qDebug() << "ERROR IN consultation/time/hour TEST CASE";
    }

    if(c.getDateAndTime().time().minute() != 12){
        qDebug() << "ERROR IN consultation/time/minute TEST CASE";
    }

    if(c.getDateAndTime().time().second() != 12){
        qDebug() << "ERROR IN consultation/time/second TEST CASE";
    }

    if(QString::compare(c.getDiagnosis(), "Cancer") !=0){
        qDebug() << "ERROR IN consultation/diagnosis TEST CASE";
    }

    if(QString::compare(c.getOHIPNumber(), "QWERTYUIOP123456789") !=0){
        qDebug() << "ERROR IN consultation/ohip TEST CASE";
    }

    if(QString::compare(c.getReason(), "It's just part of life") !=0){
        qDebug() << "ERROR IN consultation/reason TEST CASE";
    }


}


void testQueryConsultationRecord(){
    ConsultationRecord c;


    c.setOHIPNumber(QString("QWERTYUIOP123456789"));

    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){
                 ConsultationRecord * r;
                 r= (ConsultationRecord * )results.at(i);
                 qDebug()<< r->getOHIPNumber();
             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, c, ClientObjectRequest::Query);

}
void testEditConsultationRecord(){
    ConsultationRecord c;
    QDateTime d;
    QDate qd;
    QTime qt;

    qd.setYMD(2000,1,1);

    qt.setHMS(12,12,12);

    d.setDate(qd);
    d.setTime(qt);

    c.setDateAndTime(d);

    c.setDiagnosis(QString("Cancer"));

    c.setOHIPNumber(QString("QWERTYUIOP123456789"));

    c.setReason(QString("It's not just part of life"));

    c.setId(1);

    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){

             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, c, ClientObjectRequest::Edit);
}

void testRemoveConsultationRecord(){
    ConsultationRecord c;
    c.setId(1);

    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){

             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, c, ClientObjectRequest::Remove);
}


void testFollowUp(){
    FollowUpRecord f;
    f.setConsultationRecordId(1);
    f.setDetails(QString("Details string"));
    QDate qd;
    QTime qt;
    QDateTime d;

    qd.setYMD(2000,1,1);

    qt.setHMS(12,12,12);

    d.setDate(qd);
    d.setTime(qt);

    f.setDueDateTime(d);

    f.setStatus(FollowUpRecord::PENDING);

    if(f.getConsultationRecordId() != 1){
        qDebug() << "ERROR WITH /followuprecord/consultationrecordid";
    }

    if(QString::compare(QString("Details string"),f.getDetails())!=0){
        qDebug() << "ERROR WITH /followuprecord/details TEST";
    }

    if(f.getDueDateTime().date().day() != 1){
        qDebug() << "ERROR WITH /followuprecord/datetime/day TEST";
    }

    if(f.getDueDateTime().date().month() != 1){
        qDebug() << "ERROR WITH /followuprecord/datetime/month TEST";
    }

    if(f.getDueDateTime().date().year() != 2000){
        qDebug() << "ERROR WITH /followuprecord/datetime/year TEST";
    }

    if(f.getDueDateTime().time().hour() != 12){
        qDebug() << "ERROR WITH /followuprecord/datetime/hour TEST";
    }

    if(f.getDueDateTime().time().minute() != 12){
        qDebug() << "ERROR WITH /followuprecord/datetime/minute TEST";
    }

    if(f.getDueDateTime().time().second() != 12){
        qDebug() << "ERROR WITH /followuprecord/datetime/second TEST";
    }

    if(f.getStatus() != FollowUpRecord::PENDING){
        qDebug() <<"ERROR WITH /followuprecord/status";
    }


}

void testAddFollowUp(){
    FollowUpRecord f;
    f.setConsultationRecordId(1);
    f.setDetails(QString("Details string"));
    QDate qd;
    QTime qt;
    QDateTime d;

    qd.setYMD(2000,1,1);

    qt.setHMS(12,12,12);

    d.setDate(qd);
    d.setTime(qt);

    f.setDueDateTime(d);

    f.setStatus(FollowUpRecord::PENDING);

    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){

             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, f, ClientObjectRequest::Add);
}

void testQueryFollowUp(){
    FollowUpRecord f;
    f.setStatus(FollowUpRecord::PENDING);

    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){
                 qDebug() << ((FollowUpRecord*)results.at(i))->getId();
             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, f, ClientObjectRequest::Query);

}

void testEditFollowUp(){
    FollowUpRecord f;
    f.setId(1);
    f.setConsultationRecordId(15);
    f.setDetails(QString("Details string"));
    QDate qd;
    QTime qt;
    QDateTime d;

    qd.setYMD(2000,1,1);

    qt.setHMS(12,12,12);

    d.setDate(qd);
    d.setTime(qt);

    f.setDueDateTime(d);

    f.setStatus(FollowUpRecord::OVERDUE);

    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){

             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, f, ClientObjectRequest::Edit);
}

void testRemoveFollowUp(){
    FollowUpRecord f;
    f.setId(1);

    class TestObject : public ClientObjectResponseDelegate{
         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
             qDebug() <<"SUCCESS";
             for(int i = 0 ; i < results.length(); i++){

             }
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, f, ClientObjectRequest::Remove);
}


/*
Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    //testUser();
    //testAddUser();
    //testQueryUser();
    //testEditUser();
    //testRemoveUser();

    //testPatient();
    //testAddPatient();
    ///testQueryPatient();
    //testEditPatient();
    //testRemovePatient();

    //testConsulationRecord();
    //testAddConsulationRecord();
    //testQueryConsultationRecord();
    //testEditConsultationRecord();
    //testRemoveConsultationRecord();

    //testFollowUp();
    //testAddFollowUp();
    //testQueryFollowUp();
    //testEditFollowUp();
    //testRemoveFollowUp();

   return app->exec();
}
*/

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //declare and initialize the stack that will hold the windows
    CUNavigationStack *stack = new CUNavigationStack();

    //declare the navigation element that will manage the control flow
    CUNavigationProvisioning *navigation = new CUNavigationProvisioning(stack);

    LoginForm *initialPage = new LoginForm(navigation);
    stack->addWidget(initialPage);
    stack->setCurrentWidget(initialPage);

    QMainWindow mainWindow;
    mainWindow.setCentralWidget(stack);

    mainWindow.show();
    return app.exec();
}


