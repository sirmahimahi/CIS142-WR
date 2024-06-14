// CIS142 Introduction to C++ Summer 2024
// Program #3: Programming Assignment #5
// Author: Mao Bergan
// Date Due: 21 June 2024

// CIS 142 Program Assignment #5.cpp

/* Write a C++ game that allows a player to play Rock, Paper, Scissors against the
computer. The application should prompt the user for a choice and the
computer’s choice should be totally random. Your application must process the
results, if there is a winner, indicate so, if there is a tie then the game is not over
until there is a winner. Below is a sample run, the UI design is totally up to you,
the developer, it does not have to be exact as below. */

#include <iostream>
#include <cstdlib> // include cstdlib to use srand() function.
#include <ctime> // include ctime to use time() function.

// rock > scissors
// scissors > paper
// paper > rock

int main()
{
	// assign number to weapon
	int rock = 1;
	int paper = 2;
	int scissors = 3;

	// stores player and computer weapon
	int player;
	int computer;

	// continue playing if player chooses y
	char playAgain = 'Y';
	
	// used to store names to be used in console out
	std::string rockName = "Rock";
	std::string paperName = "Paper";
	std::string scissorsName = "Scissors";

	std::string playerWeaponName;
	std::string computerWeaponName;

	do // execute if player continues to  play
	{
		srand(unsigned(time(0))); // random generator
		computer = rand() % 3 + 1; // computer random number picker from 1-3
		// std::cout << computer << std::endl; // compuer random weapon picker // testing purpose only

		std::cout << "[1] Rock\n[2] Paper\n[3] Scissors\nChoose a weapon: ";
		std::cin >> player;

		// sets name of the player weapon name
		if (player == 1)
		{
			playerWeaponName = rockName;
		}
		else if (player == 2)
		{
			playerWeaponName = paperName;
		}
		else if (player == 3)
		{
			playerWeaponName = scissorsName;
		}

		// sets name of the computer weapon
		if (computer == 1)
		{
			computerWeaponName = rockName;
		}
		else if (computer == 2)
		{
			computerWeaponName = paperName;
		}
		else if (computer == 3)
		{
			computerWeaponName = scissorsName;
		}

		// if player and computer tie
		if (player == computer)
		{
			std::cout << "\nYou pick " << playerWeaponName << ", I pick " << computerWeaponName << "!\nIt's a tie!\n";
			//std::cout << "\nWould you like to play again? (y/n): "; // if player and computer tie
			//std::cin >> playAgain;
		}
		// if player wins
		else if ((player == 1 && computer == 3) || (player == 2 && computer == 1) || (player == 3 && computer == 2))
		{
			std::cout << "\nYou pick " << playerWeaponName << ", I pick " << computerWeaponName << "!\nYou win!\n";
			std::cout << "\nWould you like to play again? (y/n): "; // if player wins, execute to play again
			std::cin >> playAgain;
		}
		// if computer wins
		else if ((player == 3 && computer == 1) || (player == 1 && computer == 2) || (player == 2 && computer == 3))
		{
			std::cout << "\nYou pick " << playerWeaponName << ", I pick " << computerWeaponName << "!\nI win! Better luck next time!\n";
			std::cout << "\nLet's play again.\n"; // if player loses, execute to try again
			//std::cin >> playAgain;
		}
		else
		{
			std::cout << "\nInvalid weapon, try again (y/n): ";
			std::cin >> playAgain;
		}
	} while (playAgain == 'y' || playAgain == 'Y');

	return 0;
}