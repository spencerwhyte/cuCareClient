/*
Hashem Shawqi
Carleton University

This class is supposed to create a table and populate it with the appropriate model data
*/

#ifndef CUFORMTABLE
#define CUFORMTABLE

#include<QList>
#include<QWidget>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QHeaderView>

class CUFormTable : public QTableWidget 
{
    Q_OBJECT

public:
	// set the number of columns and rows in the table, and pass a QStringList for the column titles
    CUFormTable(int pColumns, int pRows);
	~CUFormTable();
	
	// this method takes a list of table entries and fills the current row's cells one-by-one, the list should contain one entry for each column
    void addAllRows(QList<QList<QTableWidgetItem*> * > dataEntries);
    void setHeaderLabels(QStringList columnHeaders);

private:
	int columns;
	int rows;
};

#endif
