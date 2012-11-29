#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"


#include "User.h"



void testUser(){
    User u;
    QString username("spencerwhyte");
    u.setUsername(username);
    u.setUserType(User::Physician);
    u.setId(0);


}



Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    testUser();

    return app->exec();
}
