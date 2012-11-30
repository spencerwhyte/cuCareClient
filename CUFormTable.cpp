#include"CUFormTable.h"

CUFormTable::CUFormTable(int pColumns, int pRows) : QTableWidget(pRows, pColumns)
{
	columns = pColumns;
	rows = pRows;
	currentRow = 0; //if any data is to be added, this will point to which row is to be edited

    //remove the grid
    setGridStyle(Qt::NoPen);

    //change the style of the headers
    QPalette headerPalette;
    headerPalette.setColor(QPalette::Base, Qt::red);
    //headerPalette.setColor(QPalette::Button, Qt::red);
    verticalHeader()->setPalette(headerPalette);
    setMinimumHeight(350);
}

CUFormTable::~CUFormTable()
{

}

void CUFormTable::addRow(QList<QTableWidgetItem*> dataEntries)
{
	//the QList holds a table entry for each column, loop thorugh each of those entries
	for (int i = 0; i < columns; i++)
	{
		setItem(currentRow, i, dataEntries.at(i));
	}
	
	//increment the currentRow such that the next addition will be at the next row
	currentRow++;
}


void CUFormTable::setHeaderLabels(QStringList columnHeaders)
{
	//set the column titles to those provided
	setHorizontalHeaderLabels(columnHeaders);
}
