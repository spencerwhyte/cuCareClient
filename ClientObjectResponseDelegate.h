/*
  By: Spencer Whyte
  #100817664
  Carleton University
*/


#ifndef CLIENTOBJECTRESPONSEDELEGATE_H
#define CLIENTOBJECTRESPONSEDELEGATE_H

#include "StorableInterface.h"
#include <QList>

/*
  The purpose of the ClientObjectResponseDelegate is
  to describe the protocol through which implementing
  objects are able to receive responses in the form of
  objects from the server.

*/

class ClientObjectResponseDelegate{
    /*
      Calls on the delegate when a successfull response has been
      received and passes in the results set which is a list
      of StorableInterface objects. If a database query has
      been performed, then the type of objects that you will
      find in the list is equal to the type of object you
      are querying for. If you are simply adding/editing/
      removing objects from the database then you will simply
      recieve an exact copy of the object that was passed
      in as a part of the add/edit/remove. It usually is just
      important that the process was completed successfully.

            resuls - The list of results that were received
            from the server
      */
    virtual void didSuccessfullyReceiveResponse(QList<StorableInterface> &results) = 0;

    /*
      Called on the delegate when the response received from
      the server is a failure response. Included is the
      relevant error message.]

            errrorMessage - The message explaining the error

      */
    virtual void didReceiveError(QString & errorMessage) = 0;


    // Destructor needs to be here to prevent memory issues
    virtual ~ClientObjectResponseDelegate() {};

};


#endif // CLIENTOBJECTRESPONSEDELEGATE_H
