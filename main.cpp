#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"


#include "User.h"
#include "ClientObjectRequest.h"
#include "ClientObjectResponseDelegate.h"



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
             qDebug() << "SUCCESS";
        }

         virtual void didReceiveError(QString & errorMessage){
             qDebug() << errorMessage;
        }
    };

    TestObject* test = new TestObject();

    ClientObjectRequest *r = new ClientObjectRequest(test);
    r->fillObjectRequest(*u, ClientObjectRequest::Add);


}


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    testUser();
    testAddUser();


   return app->exec();
}
