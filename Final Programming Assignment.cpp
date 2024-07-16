// CIS142 Introduction to C++ Summer 2024
// Final Programming Assignment
// Luis, Mao Bergan
// 25 July 2024

// Final Programming Assignment.cpp

/* Shakey’s garden can contain other objects which may be movable or immovable based upon its
physical nature; e.g Flowers. Flowers can be stepped on and destroyed. Trees are immovable and
cannot be destroyed */

#include <iostream>
#include <vector>
#include <random>
#include <windows.h>
using namespace std;

// only works on windows terminal
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // control colors.

class Garden {
public:
    // set the location of the robot.
    void location(vector<vector<string>>& shakey, int& x, int& y) {
        shakey[y][x] = "S ";
    }

    void clearLocation(vector<vector<string>>& shakey, int x, int y) {
        shakey[y][x] = "* ";
    }
    // run if user rotates shakey left by 90 degrees.
    void rotateRight(char& direction) {
        if (direction == 'N') {
            direction = 'E';
        }
        else if (direction == 'E') {
            direction = 'S';
        }
        else if (direction == 'S') {
            direction = 'W';
        }
        else if (direction == 'W') {
            direction = 'N';
        }
    }

    // run if user rotates shakey right by 90 degrees.
    void rotateLeft(char& direction) {
        if (direction == 'N') {
            direction = 'W';
        }
        else if (direction == 'E') {
            direction = 'N';
        }
        else if (direction == 'S') {
            direction = 'E';
        }
        else if (direction == 'W') {
            direction = 'S';
        }
    }

    // control for shakey the robot to step forward based on which way they are facing.
    void step(vector<vector<string>>& garden, char direction, int& x, int& y, int rows, int columns) {
        int yMinus = y - 1; int yPlus = y + 1; int xMinus = x - 1; int xPlus = x + 1; // local variables to check if next step is valid.
        // check to make sure its facing the right way, there is no obstacle, it does not go out of bounds.
        if ((direction == 'N') && (garden[yMinus][x] == "* " || garden[yMinus][x] == "F " || garden[yMinus][x] == "B ") && (y > 1)) {
            clearLocation(garden, x, y); y--; 
        }
        else if ((direction == 'E') && (garden[y][xPlus] == "* " || garden[y][xPlus] == "F " || garden[y][xPlus] == "B ") && (x + 1 < columns - 1)) {
            clearLocation(garden, x, y); x++; 
        }
        else if ((direction == 'S') && (garden[yPlus][x] == "* " || garden[yPlus][x] == "F " || garden[yPlus][x] == "B ") && (y + 1 < rows - 1)) {
            clearLocation(garden, x, y); y++; 
        }
        else if ((direction == 'W') && (garden[y][xMinus] == "* " || garden[y][xMinus] == "F " || garden[y][xMinus] == "B ") && (x > 1)) {
            clearLocation(garden, x, y); x--; 
        }
        else {
            SetConsoleTextAttribute(hConsole, 12); // red for warning
            cout << "Shakey cannot move foward, there is an obstacle in the way.\n"; }
    }

    vector<string> inventory; // stores inventory items for shakey.
    void pickUpItem(const string& item) {
        inventory.push_back(item);
        cout << "Picked up " << item << endl;
    }

    void showInventory() const {
        cout << "Inventory: ";
        for (const auto& item : inventory) {
            cout << item << " ";
        }
        cout << endl;
    }
};

void startGame(); // prompt the user to create garden and give the user options.
void setStartingElements(vector<vector<string>>&, int, int); // set default values for given user parameters.
void createFence(vector<vector<string>>&, int, int); // create the fence that acts as a barrier around the garden.
void printGarden(vector<vector<string>>&, int, int); // print the garden with the values provided.

int main() {
    startGame();
    return 0;
}

void startGame() {
    // shakeys coordinates
    int x = 1; int y = 1;

    // control shakey facing direction.
    char direction = 'E';

    // ask for user input to create garden size.
    int rows;
    cout << "Enter rows: ";
    cin >> rows;
    rows = rows + 2;
    system("cls");
    int columns;
    cout << "Enter columns: ";
    cin >> columns;
    columns = columns + 2;
    system("cls");

    // create a 2D array named garden, with the user defined size.
    vector<vector<string>> garden(rows, vector<string>(columns));
    // create object shakey the robot.
    Garden shakey;

    // allocate the user defined array with the element below.
    setStartingElements(garden, rows, columns); // start the game, with the default map.
    createFence(garden, rows, columns); // create the fence around the garden.

    // set the location of the robot.
    shakey.location(garden, x, y); // set [1, 1] to S for shakey.

    char userInput; // store users options to execute commands
    do {
        printGarden(garden, rows, columns); // flush console and print garden.

        // options menu.
        SetConsoleTextAttribute(hConsole, 7);
        cout << "Facing: " << direction << endl;
        // show coordinates of the robots location.
        cout << "Shakey coordinates: " << "(" << x << ", " << y << ")" << endl;
        cout << "Options:\n";
        cout << "L - Rotate Left\n";
        cout << "R - Rotate Right\n";
        cout << "P - Pick Up Item\n";
        cout << "I - Show Inventory\n";
        cout << "S - Step Forward\n";
        cout << "Q - Quit\n";
        cout << "Enter your choice: ";
        cin >> userInput;
        userInput = toupper(userInput);
        string item; // inventory items?
        switch (userInput) {
        case 'L': // rotate shakey to the left based on its current direction.
            SetConsoleTextAttribute(hConsole, 10);
            shakey.rotateLeft(direction);
            system("cls");
            break;
        case 'R': // rotate shakey to the right based on its current direction.
            SetConsoleTextAttribute(hConsole, 10);
            shakey.rotateRight(direction);
            system("cls");
            break;
        case 'S': // have shakey the robot move forward in the direction they are facing.
            SetConsoleTextAttribute(hConsole, 10);
            system("cls");
            //garden[y][x] = "* ";
            shakey.step(garden, direction, x, y, rows, columns);
            shakey.location(garden, x, y);
            break;
        case 'P': // pick up the item that shakey is standing on.
            SetConsoleTextAttribute(hConsole, 10);
            system("cls");
            cout << "Enter item to pick up: ";
            cin >> item;
            shakey.pickUpItem(item);
            break;
        case 'I':
            SetConsoleTextAttribute(hConsole, 10);
            system("cls");
            shakey.showInventory();
            break;
        case 'Q':
            system("cls");
            cout << "Exiting...\n";
            break;
        default:
            system("cls");
            cout << "Invalid choice, please try again.\n";
            break;
        }
    } while (userInput != 'Q');
}

// sets every value in the user defined array to the default value '*'.
void setStartingElements(vector<vector<string>>& shakey, int x, int y) {
    random_device rd; // create random number generator.
    mt19937 rng(rd()); // generator seed.
    uniform_int_distribution<mt19937::result_type> randX(1, x - 2); // set value.
    uniform_int_distribution<mt19937::result_type> randY(1, y - 2);
    int randomX = randX(rng);
    int randomY = randX(rng);
    // set each element in the 2D array to this element.
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            shakey[i][j] = "* ";
        }
    }

    for (int i = 0; i < (x + y) / 2; i++) { // generate random location for other items in shakey's world.
        randomX = randX(rng); randomY = randY(rng);
        shakey[randomX][randomY] = "T ";
        randomX = randX(rng); randomY = randY(rng);
        shakey[randomX][randomY] = "M ";
        randomX = randX(rng); randomY = randY(rng);
        shakey[randomX][randomY] = "W ";
    }

    for (int i = 0; i < x + y; i++) { // generate bushes and flowers more often.
        randomX = randX(rng); randomY = randY(rng);
        shakey[randomX][randomY] = "B ";
        randomX = randX(rng); randomY = randY(rng);
        shakey[randomX][randomY] = "F ";
    }
}

// creating/offseting fence
void createFence(vector<vector<string>>& shakey, int rows, int columns) {
    int col = columns - 1; int row = rows - 1; // local values to prevent overflow.
    for (int i = 0; i < rows; ++i) {
        shakey[i][0] = "# ";
        shakey[i][col] = "# ";
    }
    for (int j = 0; j < columns; ++j) {
        shakey[0][j] = "# ";
        shakey[row][j] = "# ";
    }
}

// control the console view of all elements in 2D array.
void printGarden(vector<vector<string>>& locGarden, int locRows, int locColumns) {
    for (int i = 0; i < locRows; i++) {
        for (int j = 0; j < locColumns; j++) {
            if (locGarden[i][j] == "# ") {
                SetConsoleTextAttribute(hConsole, 8);
            } // gray color for fence
            else if (locGarden[i][j] == "* ") {
                SetConsoleTextAttribute(hConsole, 8);
            } // grey color for Shakey
            else if (locGarden[i][j] == "S ") {
                SetConsoleTextAttribute(hConsole, 12);
            } // red color for Shakey
            else if (locGarden[i][j] == "B ") {
                SetConsoleTextAttribute(hConsole, 5);
            } // purple color for bush
            else if (locGarden[i][j] == "F ") {
                SetConsoleTextAttribute(hConsole, 6);
            } // yellow color for flower
            else if (locGarden[i][j] == "M ") {
                SetConsoleTextAttribute(hConsole, 7);
            } // white color for mountain
            else if (locGarden[i][j] == "T ") {
                SetConsoleTextAttribute(hConsole, 10);
            } // bright green color for tree
            else if (locGarden[i][j] == "W ") {
                SetConsoleTextAttribute(hConsole, 9);
            } // blue color for water
            else {
                SetConsoleTextAttribute(hConsole, 8);
            } // grey color for garden}
            cout << locGarden[i][j]; // print each element in the predefined garden.
        }
        // print legend on right side of garden map.
        switch (i) {
        case 0:
            cout << "\tLegend:\n";
            break;
        case 1:
            cout << "\tS - Shakey\t B - Bush\n";
            break;
        case 2:
            cout << "\tF - Flower\t M - Mountain\n";
            break;
        case 3:
            cout << "\tT - Tree\t W - Water\n";
            break;
        default:
            cout << endl;
            break;
        }
    }
}
