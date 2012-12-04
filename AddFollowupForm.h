#ifndef ADDFOLLOWUPFORM_H
#define ADDFOLLOWUPFORM_H

/*
  By Aaron Crozman (Student #100817740)
  Another day, another GUI skeleton.
  */

#include<QObject>
#include <QComboBox>

#include "CUPage.h"
#include "CUFormElement.h"
#include "CUServerRequestButton.h"

class AddFollowupForm : public CUPage, public ClientObjectResponseDelegate
{
    Q_OBJECT

public:
    AddFollowupForm(CUNavigationProvisioningInterface *pNavigator, StorableInterface* consultation);
    ~AddFollowupForm();


protected:
    QComboBox *statusBox;
    CUFormElement *dueDateField;
    CUFormElement *detailsField;
    CUServerRequestButton *confirmButton;
    void didSuccessfullyReceiveResponse(QList<StorableInterface *> * results);

    void didReceiveError(QString & errorMessage);

public slots:
    void sendFollowupToServer();

signals:
    void goBack(StorableInterface*);

private:
    CUContentPane *statusPane;
    QLabel *statusLabel;
    ConsultationRecord* consultation;
};

#endif // ADDFOLLOWUPFORM_H
