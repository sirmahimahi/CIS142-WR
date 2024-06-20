// CIS142 Introduction to C++ Summer 2024
// Programming Assignment #6
// Mao Bergan
// -TBA- -TBA- 2024

// CIS 142 Programming Assignment #6.cpp

/* Write an application that builds a multiplication table. 
This application should prompt the
user for the size of the table and build the appropriate size table with answers. */

#include <iostream>
#include <vector> // to make arrays accept user input

int main() {
	int rows; // user define array rows
	int columns; // user define array columns
	char keepPlaying;

	std::cout << "Welcome to Mao's Multiplication Table Creator!\n";
	std::cout << "Below you will be able to assign a table size.\n";
	do {
		// ask the user to define a range for the array.
		std::cout << "Enter number of rows: ";
		std::cin >> rows;
		rows = rows + 1; // increase value by one to have correct number of rows when outputting
		std::cout << "Enter number of columns: ";
		std::cin >> columns;
		columns = columns + 1; // increase value by one to have correct number of columns

		// using <vector> to create a 2D array. vector < vector < variavble > > variable name (rows , vector < variable > (columns , default value for each value)
		std::vector<std::vector<int>> grid(rows, std::vector<int>(columns)); // see line 49 for details

		for (int i = 1; i < rows; i++) {
			for (int j = 1; j < columns; j++) {
				grid[i][j] = i * j; // set each element in the 2D vector to this equation
				std::cout << grid[i][j] << '\t'; // print out the elements of every array 
			}
			std::cout << std::endl << std::endl; // new line each time the program has finished assigning and printing an element for each row
		}
		// ask the user if they want to make another table
		std::cout << "Would you like to make another multiplication table? (y/n): ";
		std::cin >> keepPlaying;
		keepPlaying = tolower(keepPlaying);
	} while (keepPlaying == 'y');
	return 0;
}
/* sources: 
* https://stackoverflow.com/questions/9694838/how-to-implement-2d-vector-array
* https://stackoverflow.com/questions/4807709/how-can-i-change-the-value-of-the-elements-in-a-vector
*/