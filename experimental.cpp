
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
};

// prototypes
void setMatrix(vector<vector<Garden>>&, int, int, Garden&);
void printMatrix(vector<vector<Garden>>&, int, int);

int main() {
	int row = -1; int col = -1;
	cout << "Enter rows (min 2): ";
	cin >> row;
	row = row + 2; // added for fence wall.

	system("cls");
	cout << "Enter columns (min 2): ";
	cin >> col;
	col = col + 2; // added for fence wall.
	system("cls");
	// generate new Garden Matrix based on user input size.
	vector<vector<Garden>> matrix(row, vector<Garden>(col));
	Garden shakey;
	shakey.setItem( "S ");
	setMatrix(matrix, row, col, shakey);
	printMatrix(matrix, row, col);

	return 0;
}

void setMatrix(vector<vector<Garden>>& matrix, int row, int col, Garden& shakey) {
	std::random_device rd; // create variable.
	std::mt19937 rng(rd()); // generator seed for variable.
	std::uniform_int_distribution<std::mt19937::result_type> randNum(1, 8); // set value.

	int fenceRow = col - 1; int fenceCol = col - 1;
	for (int y = 0; y < row; y++) { // y = rows.
		for (int x = 0; x < col; x++) { // x = columns.
			// cout << randNum(rng); // debug (print random number).
			switch (randNum(rng)) { // generate a random number to assign a random item to each tile.
			case 1:
				matrix[y][x] = Garden( "W ", NOTMOVEABLE, NOTBREAKABLE, NOTWALKABLE); // water.
				break;
			case 2:
				matrix[y][x] = Garden( "M ", NOTMOVEABLE, NOTBREAKABLE, NOTWALKABLE); // mountain.
				break;
			case 3:
				matrix[y][x] = Garden( "T ", NOTMOVEABLE, NOTBREAKABLE, NOTWALKABLE); // tree.
				break;
			case 4:
				matrix[y][x] = Garden( "F ", MOVEABLE, BREAKABLE, WALKABLE); // flower.
				break;
			case 5:
				matrix[y][x] = Garden( "B ", MOVEABLE, NOTBREAKABLE, WALKABLE); // bush.
				break;
			default:
				matrix[y][x] = Garden("* ", NOTMOVEABLE, NOTBREAKABLE, WALKABLE); // empty space.
				break;
			}
			// set fence wall.
			matrix[y][0] = Garden("# ", NOTMOVEABLE, NOTBREAKABLE, NOTWALKABLE);
			matrix[0][x] = Garden("# ", NOTMOVEABLE, NOTBREAKABLE, NOTWALKABLE);
			matrix[y][fenceCol] = Garden("# ", NOTMOVEABLE, NOTBREAKABLE, NOTWALKABLE);
			matrix[fenceRow][x] = Garden("# ", NOTMOVEABLE, NOTBREAKABLE, NOTWALKABLE);
		}
	}
	// empty starting space override..
	matrix[1][1] = Garden(shakey.getItem(), NOTMOVEABLE, NOTBREAKABLE, WALKABLE); // set starting location for shakey.
	matrix[1][2] = Garden("* ", NOTMOVEABLE, NOTBREAKABLE, WALKABLE);
	matrix[2][1] = Garden("* ", NOTMOVEABLE, NOTBREAKABLE, WALKABLE);
	matrix[2][2] = Garden("* ", NOTMOVEABLE, NOTBREAKABLE, WALKABLE);
}

void printMatrix(vector<vector<Garden>>& matrix, int row, int col) {
	for (int y = 0; y < row; y++) { // y = rows.
		for (int x = 0; x < col; x++) { // x = columns.
			cout << matrix[y][x].getItem();
		}
		cout << endl;
	}
}
