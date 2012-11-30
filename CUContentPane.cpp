#include"CUContentPane.h"

CUContentPane::CUContentPane(QWidget *parent) : QWidget(parent)
{
	// set the layout for the pane, it will modify accordingly when changes take place later on
    layout = new QGridLayout(this);
    setLayout(layout);

    columns = 0; //you start with a single column
    rows = 0; //you start with a single row
}

CUContentPane::~CUContentPane()
{

}

//adds an elmenet to the bottom of the content pane and updates the grid size
void CUContentPane::addElement(QWidget *element, int xPosition)
{
    //set this as the parent; vital for it to show up on the screen
    element->setParent(this);

    //by default the new element is inserted at the bottom-left of the grid
    layout->addWidget(element, rows, xPosition, 1, 1);

    //if someone expanded the layout, then modify the x and y accordingly
    columns = layout->columnCount();
    //expand the  grid
    rows = layout->rowCount();
}

// adds an element to the content pane and updates the grid size
void CUContentPane::addElement(QWidget *element, int xPosition, int yPosition, int xSpan, int ySpan)
{
    //set this as the parent; vital for it to show up on the screen
    element->setParent(this);

	//by default the new element is inserted at the bottom-left of the grid
    layout->addWidget(element, yPosition, xPosition, ySpan, xSpan);

	//if someone expanded the layout, then modify the x and y accordingly
    columns = layout->columnCount();
    rows = layout->rowCount();
}

// you can insert an element into the grid and set its alignment
void CUContentPane::addElement(QWidget *element, int xPosition, int yPosition, int xSpan, int ySpan, Qt::AlignmentFlag alignment)
{
	//set this as the parent; vital for it to show up on the screen
    element->setParent(this);

	//by default the new element is inserted at the bottom-left of the grid
    layout->addWidget(element, yPosition, xPosition, ySpan, xSpan);

    // set the alignment of that element in the layout
    layout->setAlignment(element, alignment);

    //if someone expanded the layout, then modify the x and y accordingly
    columns = layout->columnCount();
    rows = layout->rowCount();
}
