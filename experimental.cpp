
#include <iostream>
#include <vector>
#include <string>
#include <random>

#define MOVEABLE true
#define NOTMOVEABLE false
#define BREAKABLE true
#define NOTBREAKABLE false
#define WALKABLE true
#define NOTWALKABLE false

using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

class Garden {
private:
	// object atributes for Shakey's Garden.
	string item;
	bool moveable;
	bool fragile;
	bool walkable;

public:
	Garden() { // default constructor.
		moveable = false; fragile = false; walkable = false;
	}
	Garden(string item, bool moveable, bool fragile, bool walkable) { // overload constructor.
		this->item = item; this->moveable = moveable; this->fragile = fragile; this->walkable = walkable;
	}
	// method calls.
	std::string getItem() const {
		return item;
	}
	bool getMoveable() const {
		return moveable;
	}
	void setItem(string item) {
		this->item = item;
	}
	void getLocation(int& x, int& y, vector<vector<Garden>>& garden, int row, int col, Garden& shakey) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (garden[i][j].getItem() == "S ") { // loop untill found.
					y = i; x = j; // set location values for x and y by reference.
				}
			}
		}
	}
	// move shakey the robot.
	void forward(int& x, int& y, int col, int row, vector<vector<Garden>>& garden, Garden& shakey, Garden& space) {
		if (y >= 2) {
			garden[y][x] = space;
			y--;
			garden[y][x] = shakey;
		}
		else cout << "Cannot move to spot!\n";
	}
	void down(int& x, int& y, int col, int row, vector<vector<Garden>>& garden, Garden& shakey, Garden& space) {
		if (y < (col - 2)) {
			garden[y][x] = space;
			y++;
			garden[y][x] = shakey;
		}
		else cout << "Cannot move to spot!\n";
	}
	void left(int& x, int& y, int col, int row, vector<vector<Garden>>& garden, Garden& shakey, Garden& space) {
		if (x >= 2) {
			garden[y][x] = space;
			x--;
			garden[y][x] = shakey;
		}
		else cout << "Cannot move to spot!\n";
	}
	void right(int& x, int& y, int col, int row, vector<vector<Garden>>& garden, Garden& shakey, Garden& space) {
		if (x < (row - 2)) {
			garden[y][x] = space;
			x++;
			garden[y][x] = shakey;
		}
		else cout << "Cannot move to spot!\n";
	}
};

// prototypes
void promptGardenSize(int&, int&);
void setGarden(vector<vector<Garden>>&, int, int, Garden&, Garden&, Garden&, Garden&, Garden&, Garden&, Garden&);
void printGarden(vector<vector<Garden>>&, int, int);
void printCoordinates(int, int);

int main() {
	// used for gathering information about garden size.
	int row = -1; int col = -1;
	promptGardenSize(row, col); // ask the user to define rows and columns of map size.
	vector<vector<Garden>> garden(row, vector<Garden>(col)); // generate new Garden Matrix based on user input size.
	int y = -1; int x = -1; // location data for shakey.

	// shakey.setItem("S "); // set the item for the object shakey.
	Garden shakey("S ", MOVEABLE, NOTBREAKABLE, WALKABLE);
	Garden flower("F ", MOVEABLE, BREAKABLE, WALKABLE);
	Garden tree("T ", NOTMOVEABLE, NOTBREAKABLE, NOTWALKABLE);
	Garden mountain("M ", NOTMOVEABLE, NOTBREAKABLE, NOTWALKABLE);
	Garden water("W ", NOTMOVEABLE, NOTBREAKABLE, NOTWALKABLE); 
	Garden space("* ", MOVEABLE, NOTBREAKABLE, WALKABLE); 
	Garden fence("# ", NOTMOVEABLE, NOTBREAKABLE, NOTWALKABLE);

	// set garden item and shakey starting location.
	setGarden(garden, row, col, shakey, flower, tree, mountain, water, space, fence);
	cout << "Garden Generated!\n";

	shakey.getLocation(x, y, garden, row, col, shakey); // set location.
	//cout << "Shakey Coordinates: (" << x << ", " << y << ")\n"; // print coordinates.

	
	char userInput;
	do {
		printGarden(garden, row, col);
		cout << "Enter a option: ";
		cin >> userInput;
		userInput = toupper(userInput);
		switch (userInput) {
		case 'W':
			system("cls");
			shakey.forward(x, y, col, row, garden, shakey, space);
			printCoordinates(x, y);
			break;
		case 'S':
			system("cls");
			shakey.down(x, y, col, row, garden, shakey, space);
			printCoordinates(x, y);
			break;
		case 'A':
			system("cls");
			shakey.left(x, y, col, row, garden, shakey, space);
			printCoordinates(x, y);
			break;
		case 'D':
			system("cls");
			shakey.right(x, y, col, row, garden, shakey, space);
			printCoordinates(x, y);
			break;
		default:
			system("cls");
			cout << "Invalid option.\n";
			break;
		}
	} while (userInput != ' ');
	

	return 0;
}

// ASK THE USER TO GENERATE GARDEN SIZE
void promptGardenSize(int& row, int& col) {
	cout << "Enter rows (min 2): ";
	cin >> row;
	row = row + 2; // added for fence wall.

	system("cls");
	cout << "Enter columns (min 2): ";
	cin >> col;
	col = col + 2; // added for fence wall.
	system("cls");
}
// SET RANDOM ITEMS IN GARDEN
void setGarden(vector<vector<Garden>>& garden, int row, int col, Garden& shakey, Garden& flower, Garden& tree, Garden& mountain, Garden& water, Garden& space, Garden& fence) {
	std::random_device rd; // create variable.
	std::mt19937 rng(rd()); // generator seed for variable.
	std::uniform_int_distribution<std::mt19937::result_type> randNum(1, 12); // set value.

	int fenceRow = col - 1; int fenceCol = col - 1; // used to define total elements in array. array elements start at 0.
	for (int y = 0; y < row; y++) { // y = rows.
		for (int x = 0; x < col; x++) { // x = columns.
			// set random item to each array value defined by the user.
			switch (randNum(rng)) { 
			case 1: garden[y][x] = water; break;
			case 2: garden[y][x] = mountain; break;
			case 3: garden[y][x] = tree; break;
			case 4: garden[y][x] = flower; break;
			case 5: garden[y][x] = flower; break;
			case 6: garden[y][x] = flower; break;
			case 7: garden[y][x] = flower; break;
			default: garden[y][x] = space; break;
			}
			// set fence wall.
			garden[y][0] = fence; // top row.
			garden[0][x] = fence; // bottom row.
			garden[y][fenceCol] = fence; // left column.
			garden[fenceRow][x] = fence; // right column.
		}
	}
	// empty starting space override.
	garden[1][1] = shakey; // set starting location for shakey.
	garden[1][2] = space;
	garden[2][1] = space;
	garden[2][2] = space;
}
// PRINT GARDEN ITEMS
void printGarden(vector<vector<Garden>>& garden, int row, int col) {
	for (int y = 0; y < row; y++) { // y = rows.
		for (int x = 0; x < col; x++) { // x = columns.
			if (garden[y][x].getItem() == "W ") 
				cout << "\x1B[34m" << garden[y][x].getItem() << "\033[0m"; // blue water
			if (garden[y][x].getItem() == "M ") 
				cout << "\x1B[97m" << garden[y][x].getItem() << "\033[0m"; // white mountain
			if (garden[y][x].getItem() == "T ") 
				cout << "\x1B[92m" << garden[y][x].getItem() << "\033[0m"; // green tree
			if (garden[y][x].getItem() == "F ") 
				cout << "\x1B[33m" << garden[y][x].getItem() << "\033[0m"; // yellow flower
			if (garden[y][x].getItem() == "* ") 
				cout << "\x1B[30m" << garden[y][x].getItem() << "\033[0m"; // black empty space
			if (garden[y][x].getItem() == "# ") 
				cout << "\x1B[37m" << garden[y][x].getItem() << "\033[0m"; // grey fence wall
			if (garden[y][x].getItem() == "S ") 
				cout << "\x1B[31m" << garden[y][x].getItem() << "\033[0m"; // red shakey the robot
		}
		cout << endl; // new line after each item has been displayed in a row.
	}
}

void printCoordinates(int x, int y) {
	//system("cls");
	cout << "Shakey Coordinates: (" << x << ", " << y << ")\n";
}
