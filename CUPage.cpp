#include"CUPage.h"

CUPage::CUPage(QString title, bool containsBackButton, CUNavigationProvisioningInterface *pNavigator) : QWidget(), backButton(NULL), request(NULL)
{

    qDebug() << "CUPAGE CRASH TRACE";
    setMinimumSize(800, 600); // a smaller window would be unusable, a bigger window would be ugly

    layout = new QGridLayout(this);

    titleLabel = new QLabel(title, this);
    contentPane = new CUContentPane(this);

    titleLabel->setGeometry(10,10,300,30);
    titleLabel->setFont(QFont("Sans Serif", 20, 1));

    //change the color of the title
    QPalette titlePalette;
    titlePalette.setColor(QPalette::WindowText, Qt::darkGray);
    titleLabel->setPalette(titlePalette);
    qDebug() << "1";
    //if there is a back button, then assign the layout accordingly
    if(containsBackButton)
    {
        // set the button to have a default back arrow on it
        backButton = new CUNavigationButton("",this);
        backButton->setIcon(backButton->style()->standardIcon(QStyle::SP_ArrowBack));
        backButton->setMaximumWidth(60);

        //add the elements to the lay out and align the content pane in the middle
        layout->addWidget(titleLabel, 0, 1);
        layout->addWidget(backButton, 0, 0);
        layout->addWidget(contentPane, 1, 0, 1, 2);

        //connect back button to navigator
        QObject::connect(backButton, SIGNAL(clicked()), pNavigator, SLOT(back()));
    }

    else
    {
        layout->addWidget(titleLabel, 0, 0);
        layout->addWidget(contentPane, 1, 0);
    }

    layout->setAlignment(contentPane, Qt::AlignCenter);
    layout->setRowStretch(0, 0); // the title should be stuck up no matter how the screen is resized
    layout->setRowStretch(1, 1); // the contents should always be in the center
    qDebug() << "2";
    setLayout(layout);
}

// Never know what you might want to fill into a destructor
CUPage::~CUPage()
{
    if(request){
       delete request;
    }
}

void CUPage::setPageTitle(QString newTitle)
{
    titleLabel->setText(newTitle);
}

CUNavigationProvisioningInterface* CUPage::getNavigator()
{

}

void CUPage::setRequest(ClientObjectRequest * r){
    if(request){
        delete request;
    }
    request = r;
}

ClientObjectRequest * CUPage::getRequest(){
    return request;
}

QGridLayout* CUPage::getLayout()
{
    return layout;
}

// setup the title of the page
void CUPage::setTitle(QString title)
{
    titleLabel->setText(title);
}

// insert an element at the bottom of the contentpane
void CUPage::addElement(QWidget *element, int xPosition)
{
    contentPane->addElement(element, xPosition);
}

// calls the addElement of the content pane of that page, adding an element to the pane itself
void CUPage::addElement(QWidget *element, int xPosition, int yPosition, int xSpan, int ySpan)
{
    contentPane->addElement(element, xPosition, yPosition, xSpan, ySpan);
}


// add an element, and specify its alignment
void CUPage::addElement(QWidget *element, int xPosition, int yPosition, int xSpan, int ySpan, Qt::AlignmentFlag alignment)
{
    contentPane->addElement(element, xPosition, yPosition, xSpan, ySpan, alignment);
}

void CUPage::addToTable(StorableInterface* object)
{
    qDebug() << "ATTENTION I'M BEING CALLED FROM THE WRONG PLACE!";
}

