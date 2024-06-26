// CIS142 Introduction to C++ Summer 2024
// Program #3: Programming Assignment #4
// Author: Mao Bergan
// Date Due: 19 June 2024

// CIS 142 Program Assignment #4.cpp

/* Write an application guessing game. Your application with pick a number
randomly and ask the user to guess the number. Your feedback to the user
is whether the number is low or high. Keep track of the amount of guesses
the user has used. */

#include <iostream>
#include <cstdlib> // include cstdlib to use srand() function.
#include <ctime> // include ctime to use time() function.

int main()
{
	srand(unsigned(time(0))); // creates somewhat random seed based off time and make sure its always positive.

	// modify range of numbers to guess from (default 1-20) <--- <--- <--- <---
	int max = 20; 
	int randomNumber = rand() % max + 1;
	
	// ask the user to guess number.
	std::cout << "Guess what number I am thinking of from 1-" << max << "\n";
	// std::cout << randomNumber; // TESTING PURPOSE ONLY!!!  <--- <--- <--- <---

	int guess; // user guess
	int attempt = 1; // set user attempt tracker to 1

	do
	{
		std::cout << "Guess: ";
		std::cin >> guess; // ask the user to enter first guess
		if (guess < randomNumber) // execute if guess is too low
		{
			std::cout << "Your number is too low!\n";
			std::cout << "Guess again: ";
			attempt++;
		}
		else if (guess > randomNumber) // execute if guess is too high
		{
			std::cout << "Your number is too high!\n";
			std::cout << "Guess again: ";
			attempt++;
		}
		else if (guess == randomNumber) // execute if guess is correct
		{
			if (attempt == 1) // execute if guess is correct on first try
			{
				std::cout << "\nYou have guessed the number in " << attempt << " attempt.\nDid you read my mind?\n";
			}
			else // execute if guess is correct after multiple attempts
			{
				std::cout << "\nYou have guessed the number in " << attempt << " attempts.\nGood Job!\n";
			}
		}
		else // default return if entry is not valid
		{
			std::cout << "Invalid entry.\n";
			std::cout << "Guess again: ";
			attempt++;
		}
	} while (guess != randomNumber);

	return 0;
}
