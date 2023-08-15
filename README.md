# Assignment14P1
Assignment14 Programming 1
------------------------------------------------------------------------------------------------------
Author: Cesar Roncancio
Date:   08/15/2021

Description:
You have been tasked by the IT department of Acme Electronics to write a program to generate a report about last year’s sales. The report created by the program will be in the table shown below. It will also display the division and quarter with the highest sales and the division and quarter with the lowest sales for the year. <br>

The program will need to use a 2-Dimensional array. This array will hold the sales totals for 4 divisions and for 4 quarters. The array must be created to also hold the total for each division and for each quarter (in other words the total for each column and each row, when thinking about the array as a table or spreadsheet). These totals will be calculated by the program once the values have been inputted by the user. This array will have the quarters as the columns and the divisions as the rows. The last column will hold the totals for the rows (division totals) and the last row will hold the totals for the columns (quarter totals). Note: the very last element in the array will not be used. <br>
<br>
Another array should be used to store the division names of North, South, East, and West. This array will be used when getting the inputs from the user and for the outputs.
<br>
The program should use two global constants called ROWS and COLS.
<br>
The program must provide the following functions:
<br>
double CalculateTotal(double [][COLS]); <br>
Calculates the total of the complete array except for the totals in the last column and last row. <br>
Returns the total. <br>
double CalculateAverage(double [][COLS]); <br>
Calculates the average of all the values in the array except for the column and row with the totals in them. <br>
Returns the average. <br>
double CalculateRowTotal(double [][COLS], int); <br>
Calculates the total for row that is specified by the second parameter. <br>
Returns the total for the specified row. <br>
double CalculateColumnTotal(double [][COLS], int); <br>
Calculates the total for a column that is specified by the second parameter. <br>
Returns the total for the specified column. <br>
double FindHighest(double [][COLS], int&, int&); <br>
Finds the highest sales in the array. <br>
Provides the index values (row, column) of where the highest value is located in the array. <br>
Returns the highest amount. <br>
double FindLowest(double [][COLS], int&, int&); <br>
Finds the lowest sales in the array. <br>
Provides the index values of where the lowest value is located in the array. <br>
Returns the lowest amount. <br>
The program should output a table in the same format as below which will then be followed by the division and quarter with the highest value and the division and quarter with the lowest value. <br>
<br>
Pseudo code: <br>
   Start <br>
	-Declare variables and Functions <br>
	-Display "Enter the sales info:" <br>
	-For every position in the divisions array enter a value for the sales <br>
	-Input columns and rows <br>
	-Do a For to call the CalculateRowTotal Function <br>
	-Do a For to call the CalculateColumnTotal <br>
	-Display the inputs and results in a table form <br>
	-total = return value of Function CalculateTotal <br>
	-Display "Company total sales: " <br>
	-Display total <br>
	-average = return value of Function CalculateAverage <br>
	-Display average <br>
	-highest = return value of Function FindHighest <br>
	-Diplay the index for div[] array according to the value returned from the Function FindHighest <br>
	-Display " Division has the highest sales at " <br>
	-Display " in " <br>
	-Display the index for qtr[] array according to the value returned from the Function FindHighest <br>
	-lowest = return value of Function FindLowest <br>
	-Diplay the index for div[] array according to the value returned from the Function FindLowest <br>
	-Display " Division has the lowest sales at " <br>
	-Display " in " <br>
	-Display the index for qtr[] array according to the value returned from the Function FindLowest <br>
	-For for rows and For for columns <br>
	-total = the sum of sales values on the array <br>
	-return total <br>
	-Function CalculateAverage <br>
	-For for rows and For for columns <br>
	-avgTot = the sum of sales values on the array <br>
	-index = 0 + number of columns visited <br>
	-average = avgTot / index <br>
	-return average <br>
	-Function CalculateRowTotal <br>
	-For visiting the row array <br>
	-rowTot = the sum of row values <br>
	-return rowTot <br>
	-Function CalculateColumnTotal <br>
	-For visiting the column array <br>
	-colTot = the sum of column values <br>
	-return colTot <br>
	-Function FindHighest <br>
	-For for rows and For for columns <br>
	-If the values on numbers[x][y] are higher than the previous set <br>
	-high = numbers[x][y] <br>
	-return high <br>
	-Function FindLowest <br>
	-For for rows and For for columns <br>
	-If the values on numbers[x][y] are lower than the previous set <br>
	-low = numbers[x][y] <br>
	-return low <br>
   End
