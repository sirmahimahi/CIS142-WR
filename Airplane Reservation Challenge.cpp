// CIS142 Introduction to C++ Summer 2024
// Airplane Seating Assignment
// Mao Bergan
// 16 July 2024

// Airplane Seating Assignment.cpp

/* Airplane Seating Assignment) Write a program that can be used to
assign seats for a commercial airplane.The airplane has 13 rows, with six
seats in each row.Rows 1 and 2 are first class, rows 3 through 7 are
business class, and rows 8 through 13 are economy class. */

#include <iostream>
#include <vector>
#include <string>
#include <random>

class Seat {
	int seatNum;
	char seatLetter;
	std::string seatPos;
	std::string display;

public:
	Seat() { // default constructor.
		seatLetter = 'A';
		seatNum = 1;
	} // overload constructor.
	Seat(int seatNum, char seatLetter, std::string seatPos, std::string display) {
		this->seatNum = seatNum;
		this->seatLetter = seatLetter;
		//seatPos = seatLetter + std::to_string(seatNum); // combine num and letter.
		this->seatPos = seatPos; // set seat position num and letter.
		this->display = display;
	}

	std::string getDisplay() {
		return display;
	}
	std::string getSeatPos() {
		return seatPos;
	}
	void setDisplay(std::string display) {
		this->display = display;
	}

};
// prototypes
void game(std::vector<std::vector<Seat>>&);
void checkAvailability(std::vector<std::vector<Seat>>&, std::string);
void setMap(std::vector<std::vector<Seat>>&);
void printMap(std::vector<std::vector<Seat>>&);
void printFirstClass(std::vector<std::vector<Seat>>&);
void printBusinessClass(std::vector<std::vector<Seat>>&);
void printEconomyClass(std::vector<std::vector<Seat>>&);
void printMap(std::vector<std::vector<Seat>>&, int);

int main() {
	int row = 14; int col = 7; int mapSize = row * col;
	std::vector<std::vector<Seat>> seatMap(row, std::vector<Seat>(col));
	setMap(seatMap);
	char answer = 'Y';
	do {
		game(seatMap);
		std::cout << "Would you like to make another selection? (y/n): ";
		std::cin >> answer;
		answer = std::toupper(answer);
		system("cls");
	} while (answer != 'N');
	system("cls");
	return 0;
}

void game(std::vector<std::vector<Seat>>& seatMap) {
	//std::cout << "X - Not Available\n* - Available\n";
	printMap(seatMap);

	// ask the user to select the seat they want.
	std::cout << "\n1 - First Class\n";
	std::cout << "2 - Business Class\n";
	std::cout << "3 - Economy Class\n";
	std::cout << "Select ticket type: ";
	int ticketType;
	std::cin >> ticketType;
	std::string ticketName;
	printMap(seatMap, ticketType);

	std::cout << "Select row: ";
	int seatRow = 0;
	std::cin >> seatRow;

	std::cout << "Select a seat letter: ";
	char seatLetter = 'A';
	std::cin >> seatLetter;
	seatLetter = toupper(seatLetter);

	// combine seat number and letter.
	std::string rowToStr = std::to_string(seatRow);
	std::string seatPos = rowToStr + seatLetter;
	std::cout << "You selected " << ticketName << seatPos;

	checkAvailability(seatMap, seatPos);
}

// ask the user to select a seat row and seat position.
void checkAvailability(std::vector<std::vector<Seat>>& seatMap, std::string seatPos) {
	bool found = false;
	for (int j = 1; j < 7; j++) {
		for (int i = 1; i < 14; i++) {
			if (seatMap[i][j].getSeatPos() == seatPos && seatMap[i][j].getDisplay() == "* ") {
				seatMap[i][j].setDisplay("O ");
				std::cout << "\nThis seat is available.\n";
				found = true;
				break;
			}
		} if (found) break;
	} 
	if (found != true) std::cout << "\nThis seat is not available.\n";
}

// set avaiable seats.
void setMap(std::vector<std::vector<Seat>>& seatMap) {
	std::random_device rd; // create random number generator.
	std::mt19937 rng(rd()); // generator seed.
	std::uniform_int_distribution<std::mt19937::result_type> randNum(1, 2); // set value.
	int seatRand = randNum(rng);

	char c = 'A'; // display a-f at top of seats.
	for (int j = 1; j < 7; j++) {
		std::string str;
		str += c;
		str += " ";
		seatMap[0][j] = Seat(j, c, str, str);
		for (int i = 1; i < 14; i++) {
			// combine seat number and letter.
			std::string numToStr = std::to_string(i);
			std::string seatPos = numToStr + c;
			
			// default values for the seat rows from 1 - 13.
			int num = i;
			std::string str = "Row ";
			std::string merge = str + std::to_string(num) + "\t";
			seatMap[i][0] = Seat(i, c, str, merge); // set row numbers.

			// random seat availability generator.
			seatRand = randNum(rng);
			if (seatRand == 1) {
				std::string available = "* ";
				seatMap[i][j] = Seat(i, c, seatPos, available);
			}
			else if (seatRand == 2) {
				std::string available = "X ";
				seatMap[i][j] = Seat(i, c, seatPos, available);
			}
			
		}
		c++;
	}
	// default values for seat position from A to F.
	
	std::string blank = " \t";
	seatMap[0][0] = Seat(0, 'Z', "0Z", blank); // set empty value for top left array element.
}

// print all seats.
void printMap(std::vector<std::vector<Seat>>& seatMap) {
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 7; j++) {
			std::cout << seatMap[i][j].getDisplay();
		}
		std::cout << std::endl;
	}
	std::cout << "X - Not available\n";
	std::cout << "* - Available\n";
	std::cout << "O - User selected\n";
}

void printFirstClass(std::vector<std::vector<Seat>>& seatMap) {
	for (int j = 0; j < 7; j++) {
		std::cout << seatMap[0][j].getDisplay();
	}
	std::cout << std::endl;
	for (int i = 1; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			std::cout << seatMap[i][j].getDisplay();
		}
		std::cout << std::endl;
	}
	std::cout << "X - Not available\n";
	std::cout << "* - Available\n";
	std::cout << "O - User selected\n";
}

void printBusinessClass(std::vector<std::vector<Seat>>& seatMap) {
	for (int j = 0; j < 7; j++) {
		std::cout << seatMap[0][j].getDisplay();
	}
	std::cout << std::endl;
	for (int i = 3; i < 8; i++) {
		for (int j = 0; j < 7; j++) {
			std::cout << seatMap[i][j].getDisplay();
		}
		std::cout << std::endl;
	}
	std::cout << "X - Not available\n";
	std::cout << "* - Available\n";
	std::cout << "O - User selected\n";
}

void printEconomyClass(std::vector<std::vector<Seat>>& seatMap) {
	for (int j = 0; j < 7; j++) {
		std::cout << seatMap[0][j].getDisplay();
	}
	std::cout << std::endl;
	for (int i = 8; i < 14; i++) {
		for (int j = 0; j < 7; j++) {
			std::cout << seatMap[i][j].getDisplay();
		}
		std::cout << std::endl;
	}
	std::cout << "X - Not available\n";
	std::cout << "* - Available\n";
	std::cout << "O - User selected\n";
}

void printMap(std::vector<std::vector<Seat>>& seatMap, int ticketType) {
	switch (ticketType) {
	case 1:
		system("cls");
		printFirstClass(seatMap);
		break;
	case 2:
		system("cls");
		printBusinessClass(seatMap);
		break;
	case 3:
		system("cls");
		printEconomyClass(seatMap);
		break;
	default:
		std::cout << "Invalid ticket type.";
	}
}