/*****************************************************************************
Author: Cesar Roncancio
Date:   08/15/2021

Description:
You have been tasked by the IT department of Acme Electronics to write a program to generate a report about last year’s sales. The report created by the program will be the table shown below. It will also display the division and quarter with the highest sales and the division and quarter with the lowest sales for the year.

The program will need to use a 2-Dimensional array. This array that will hold the sales totals for 4 divisions and for 4 quarters. The array must be created to also hold the total for each division and for each quarter (in other words the total for each column and each row, when thinking about the array as a table or spreadsheet). These totals will be calculated by the program once the values have been inputted by the user. This array will have the quarters as the columns and the divisions as the rows. The last column will hold the totals for the rows (division totals) and the last row will hold the totals for the columns (quarter totals). Note: the very last element in the array will not be used.

Another array should be used to store the division names of North, South, East, and West. This array will be used when getting the inputs from the user and for the outputs.

The program should use two global constants called ROWS and COLS.

The program must provide the following functions:

double CalculateTotal(double [][COLS]);
Calculates the total of the complete array except for the totals in the last column and last row.
Returns the total.
double CalculateAverage(double [][COLS]);
Calculates the average of all the values in the array except for the column and row with the totals in them.
Returns the average.
double CalculateRowTotal(double [][COLS], int);
Calculates the total for row that is specified by the second parameter.
Returns the total for the specified row.
double CalculateColumnTotal(double [][COLS], int);
Calculates the total for a column that is specified by the second parameter.
Returns the total for the specified column.
double FindHighest(double [][COLS], int&, int&);
Finds the highest sales in the array.
Provides the index values (row, column) of where the highest value is located in the array.
Returns the highest amount.
double FindLowest(double [][COLS], int&, int&);
Finds the lowest sales in the array.
Provides the index values of where the lowest value is located in the array.
Returns the lowest amount.
The program should output a table in the same format as below which will then be followed by the division and quarter with the highest value and the division and quarter with the lowest value.

Pseudo code:
   Start
	-Declare variables and Functions
	-Display "Enter the sales info:"
	-For every position in the divisions array enter a value for the sales
	-Input columns and rows
	-Do a For to call the CalculateRowTotal Function
	-Do a For to call the CalculateColumnTotal
	-Display the inputs and results in a table form
	-total = return value of Function CalculateTotal
	-Display "Company total sales: "
	-Display total
	-average = return value of Function CalculateAverage
	-Display average
	-highest = return value of Function FindHighest
	-Diplay the index for div[] array according to the value returned from the Function FindHighest 
	-Display " Division has the highest sales at "
	-Display " in "
	-Display the index for qtr[] array according to the value returned from the Function FindHighest
	-lowest = return value of Function FindLowest
	-Diplay the index for div[] array according to the value returned from the Function FindLowest
	-Display " Division has the lowest sales at "
	-Display " in "
	-Display the index for qtr[] array according to the value returned from the Function FindLowest
	-For for rows and For for columns
	-total = the sum of sales values on the array
	-return total
	-Function CalculateAverage
	-For for rows and For for columns
	-avgTot = the sum of sales values on the array
	-index = 0 + number of columns visited
	-average = avgTot / index
	-return average
	-Function CalculateRowTotal
	-For visiting the row array
	-rowTot = the sum of row values
	-return rowTot
	-Function CalculateColumnTotal
	-For visiting the column array
	-colTot = the sum of column values
	-return colTot
	-Function FindHighest
	-For for rows and For for columns
	-If the values on numbers[x][y] are higher than the previous set
	-high = numbers[x][y]
	-return high
	-Function FindLowest
	-For for rows and For for columns
	-If the values on numbers[x][y] are lower than the previous set
	-low = numbers[x][y]
	-return low
   End
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int COLS = 5;
const int ROWS = 5;

double total = 0;
double average;
double lowest;
double highest;

double sales[ROWS][COLS];

double CalculateTotal(double[][COLS]);
double CalculateAverage(double[][COLS]);
double CalculateRowTotal(double[][COLS], int);
double CalculateColumnTotal(double[][COLS], int);
double FindHighest(double[][COLS], int&, int&);
double FindLowest(double[][COLS], int&, int&);

int main()
{
	const int divNum = 5, qtrNum = 5;
	double rowTotal, columnTotal;

	string div[divNum] = { "North", "South", "East", "West", "Quarter Total" };
	string qtr[qtrNum] = { "Quarter 1", "Quarter 2", "Quarter 3", "Quarter 4", "Division Total" };

	// get the sales info
	cout << "Enter the sales info:" << endl << endl;
	for (int strDivIndex = 0; strDivIndex < COLS; strDivIndex++) {
		if (strDivIndex == (COLS - 1)) {
			for (int i = 0; i < COLS; i++) {
				rowTotal = CalculateRowTotal(sales, i);
				sales[i][strDivIndex] = rowTotal;
			}
			break;
		}
		for (int strQtrIndex = 0; strQtrIndex < ROWS; strQtrIndex++) {
			if (strQtrIndex == (ROWS - 1)) {
				for (int i = 0; i < COLS; i++) {
					columnTotal = CalculateColumnTotal(sales, i);
					sales[strQtrIndex][i] = columnTotal;
				}
				break;
			}
			cout << div[strDivIndex] << " - " << qtr[strQtrIndex] << ": ";
			cin >> sales[strDivIndex][strQtrIndex];
		}
		cout << endl;
	}

	cout << setprecision(2) << fixed << showpoint;

	// display table
	cout << "\t\t";
	for (int i = 0; i < divNum; i++) {
		if (i < (divNum - 1)) {
			cout << setw(12) << qtr[i];
		}
		else {
			cout << setw(15) << qtr[i];
		}

	}
	cout << endl;
	for (int row = 0; row < ROWS; row++) {
		cout << div[row];
		if (row < (ROWS - 1)) {
			cout << "\t\t";
		}
		else {
			cout << "\t";
		}
		for (int col = 0; col < COLS; col++) {
			if (col < (COLS - 1)) {
				cout << setw(12) << sales[row][col];
			}
			else {
				cout << setw(15) << sales[row][col];
			}
		}
		cout << endl;
	}

	// call functions and display total, average, lowest, and highest
	total = CalculateTotal(sales);
	cout << endl << "Company total sales: " << total << endl;

	average = CalculateAverage(sales);
	cout << "Company average sales: " << average << endl;

	int row, col;
	highest = FindHighest(sales, row, col);
	cout << div[row] << " Division has the highest sales at " << highest <<
		" in " << qtr[col] << endl;

	lowest = FindLowest(sales, row, col);
	cout << div[row] << " Division has the lowest sales at " << lowest <<
		" in " << qtr[col] << endl << endl;

	// end of program
	system("pause");
	return 0;
}



// functions

double CalculateTotal(double numbers[][COLS]) {
	for (int x = 0; x < (ROWS - 1); x++) {
		for (int y = 0; y < (COLS - 1); y++) {
			total += numbers[x][y];
		}
	}
	return total;
}

double CalculateAverage(double numbers[][COLS]) {
	double index = 0;
	double avgTot = 0;
	for (int x = 0; x < (ROWS - 1); x++) {
		for (int y = 0; y < (COLS - 1); y++) {
			avgTot += numbers[x][y];
			index++;
		}
	}
	average = avgTot / index;
	return average;
}

double CalculateRowTotal(double numbers[][COLS], int row) {
	double rowTot = 0;
	for (int col = 0; col < (COLS - 1); col++) {
		rowTot += numbers[row][col];
	}
	return rowTot;
}

double CalculateColumnTotal(double numbers[][COLS], int col) {
	double colTot = 0;
	for (int row = 0; row < (ROWS - 1); row++) {
		colTot += numbers[row][col];
	}
	return colTot;
}

double FindHighest(double numbers[][COLS], int& row, int& col) {
	double high = 0;
	for (int x = 0; x < (ROWS - 1); x++) {
		for (int y = 0; y < (COLS - 1); y++) {
			if ((numbers[x][y]) > high) {
				row = x;
				col = y;
				high = numbers[row][col];
			}
		}
	}
	return high;
}

double FindLowest(double numbers[][COLS], int& row, int& col) {
	double low = numbers[0][0];
	for (int x = 0; x < (ROWS - 1); x++) {
		for (int y = 0; y < (COLS - 1); y++) {
			if ((numbers[x][y]) <= low) {
				row = x;
				col = y;
				low = numbers[row][col];
			}
		}
	}
	return low;
}