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
