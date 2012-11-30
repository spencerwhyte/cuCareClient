/*
Hashem Shawqi
Carleton University

The content pane is the capital widget where the elements that serve the purpose behind that window are present
  */

#ifndef CUCONTENTPANE
#define CUCONTENTPANE

#include<QObject>
#include<QWidget>
#include<QGridLayout>

class CUContentPane : public QWidget
{
    Q_OBJECT

public:
    CUContentPane(QWidget *parent);
    ~CUContentPane();

    // insert an element at the bottom of the contentpane
    void addElement(QWidget *element, int xPosition = 0);
    // specify where you want to insert the element in the contentpane and its span on the grid layout
    void addElement(QWidget *element, int xPosition, int yPosition, int xSpan = 1, int ySpan = 1);
    // add an element, and specify its alignment
    void addElement(QWidget *element, int xPosition, int yPosition, int xSpan, int ySpan, Qt::AlignmentFlag alignment);

private:
    int columns; //current number of columns in layout
    int rows; //current number of rows in layout
	QGridLayout *layout;
};

#endif
