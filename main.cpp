#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"


#include "User.h"
#include "ClientObjectRequest.h"
#include "ClientObjectResponseDelegate.h"
#include  <QList>

void testUser(){
    User u;
    QString username("spencerwhyte");
    u.setUsername(username);
    u.setUserType(User::Physician);
    u.setId(100);

    if(QString::compare(u.getUsername(), QString("spencerwhyte")) != 0){
        qDebug() << "User/getUsername test failed";
    }

    if(u.getId() != 100){
         qDebug() << "User/getId test failed";
    }

    if(u.getUserType() != User::Physician){
         qDebug() << "User/getUserType test failed";
    }

}


void testAddUser(){
    User * u = new User();
    QString username("spencerwhyte");
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


void testQueryUser(){
    User * u = new User();
    QString username("spencerwhyte");
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

void testEditUser(){
    User * u = new User();
    QString username("spencerwhyte");
    u->setUsername(username);
    u->setUserType(User::Physician);


    class TestObject2 : public ClientObjectResponseDelegate{

         void didSuccessfullyReceiveResponse(QList<StorableInterface *> &results) {
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
             ClientObjectRequest * r2 = new ClientObjectRequest(t2 , *u, ClientObjectRequest::Edit);


        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test, *u, ClientObjectRequest::Query);
}



Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    //testUser();
    //testAddUser();
    //testQueryUser();
    testEditUser();


   return app->exec();
}
