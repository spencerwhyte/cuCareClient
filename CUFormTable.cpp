#include"CUFormTable.h"

CUFormTable::CUFormTable(int pColumns, int pRows) : QTableWidget(pRows, pColumns)
{
    setSelectionBehavior(QAbstractItemView::SelectRows);

	columns = pColumns;
	rows = pRows;

    //remove the grid
    setGridStyle(Qt::NoPen);

    //change the style of the headers
    QPalette headerPalette;
    headerPalette.setColor(QPalette::Base, Qt::red);
    //headerPalette.setColor(QPalette::Button, Qt::red);

    verticalHeader()->hide();

    setContextMenuPolicy(Qt::CustomContextMenu);
}

CUFormTable::~CUFormTable()
{

}

void CUFormTable::addAllRows(QList<QList<QTableWidgetItem*> * > dataEntries)
{
    setRowCount(dataEntries.length());
    for(int j = 0 ; j < dataEntries.length();j++){
        QList<QTableWidgetItem*> *currentRow =  dataEntries.at(j);
        //the QList holds a table entry for each column, loop thorugh each of those entries
        for (int i = 0; i < currentRow->length(); i++)
        {
            QTableWidgetItem* currentItem = currentRow->at(i);
            currentItem->setFlags(currentItem->flags() ^ Qt::ItemIsEditable);

            setItem(j, i , currentItem);

        }
    }
}


void CUFormTable::setHeaderLabels(QStringList columnHeaders)
{
    setColumnCount(columnHeaders.count());

	//set the column titles to those provided
	setHorizontalHeaderLabels(columnHeaders);
    int calculatedWidth = (int)((width() -20)/((double)columnHeaders.length()));
    for(int i = 0; i < columnHeaders.length(); i++){
        setColumnWidth(i,calculatedWidth);
    }



}
