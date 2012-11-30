#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"


#include "User.h"
#include "ClientObjectRequest.h"
#include "ClientObjectResponseDelegate.h"
#include  <QList>
#include "PatientRecord.h"

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
    //testQueryPatient();
    testEditPatient();

   return app->exec();
}
