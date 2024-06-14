// CIS142 Introduction to C++ Summer 2024
// Program #3: Programming Assignment #3
// Author: Mao Bergan
// Date Due: 17 June 2024

// Program Assignment #3.cpp

/* Write a program to generate and display a 
table of n^2 squared, for integer values of n
ranging from 1 to 10. Be sure to print 
appropriate column headings. */

#include <iostream>
// using namespace std; (will not be using but aware of its function)

int main()
{ // using the ASCII superscript value to have the power of 2 above a character.
	char superScript = 253; // line 32 for source.
	// display n with a space and n^2.
	std::cout << "n\tn" << superScript << std::endl;
	
	// variable to square values 1 through 10.
	int number; 
	
	// run untill program reaches 10.
	for (number = 1; number <= 100; number++)
	{ // first display number, second display that number to the power of 2.
		std::cout << number << "\t" << number * number << std::endl;
	}
}
/* sources
superscripts: https://stackoverflow.com/questions/4038377/superscript-in-c-console-output
*/
