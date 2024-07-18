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
    // run if user rotates Shakey left by 90 degrees.
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
        cout << "Shakey rotated right!\n";
    }

    // run if user rotates Shakey right by 90 degrees.
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
        cout << "Shakey rotated left!\n";
    }

    // control for Shakey the robot to step forward based on which way they are facing.
    void step(vector<vector<string>>& garden, char direction, int& x, int& y, int rows, int columns) {
        int yMinus = y - 1, yPlus = y + 1, xMinus = x - 1, xPlus = x + 1; // Local variables to check if next step is valid.
        // check to make sure it's facing the right way, there is no obstacle, it does not go out of bounds.
        if ((direction == 'N') && (garden[yMinus][x] == "* " || garden[yMinus][x] == "F " || garden[yMinus][x] == "B ") && (y > 1)) {
            clearLocation(garden, x, y); y--;
            if (garden[yMinus][x] == "F ") {
                SetConsoleTextAttribute(hConsole, 12); // red for warning
                cout << "A flower has been destroyed!\n";
            }
            else if (garden[yMinus][x] == "B ") {
                SetConsoleTextAttribute(hConsole, 12); // red for warning
                cout << "A bush has been destroyed!\n";
            }
            else if (garden[yMinus][x] == "* ") {
                cout << "Shakey stepped forward!\n";
            }
        }
        else if ((direction == 'E') && (garden[y][xPlus] == "* " || garden[y][xPlus] == "F " || garden[y][xPlus] == "B ") && (x + 1 < columns - 1)) {
            clearLocation(garden, x, y); x++;
            if (garden[y][xPlus] == "F ") {
                SetConsoleTextAttribute(hConsole, 12); // red for warning
                cout << "A flower has been destroyed!\n";
            }
            else if (garden[y][xPlus] == "B ") {
                SetConsoleTextAttribute(hConsole, 12); // red for warning
                cout << "A bush has been destroyed!\n";
            }
            else if (garden[y][xPlus] == "* ") {
                cout << "Shakey stepped forward!\n";
            }
        }
        else if ((direction == 'S') && (garden[yPlus][x] == "* " || garden[yPlus][x] == "F " || garden[yPlus][x] == "B ") && (y + 1 < rows - 1)) {
            clearLocation(garden, x, y); y++;
            if (garden[yPlus][x] == "F ") {
                SetConsoleTextAttribute(hConsole, 12); // red for warning
                cout << "A flower has been destroyed!\n";
            }
            else if (garden[yPlus][x] == "B ") {
                SetConsoleTextAttribute(hConsole, 12); // red for warning
                cout << "A bush has been destroyed!\n";
            }
            else if (garden[yPlus][x] == "* ") {
                cout << "Shakey stepped forward!\n";
            }
        }
        else if ((direction == 'W') && (garden[y][xMinus] == "* " || garden[y][xMinus] == "F " || garden[y][xMinus] == "B ") && (x > 1)) {
            clearLocation(garden, x, y); x--;
            if (garden[y][xMinus] == "F ") {
                SetConsoleTextAttribute(hConsole, 12); // red for warning
                cout << "A flower has been destroyed!\n";
            }
            else if (garden[y][xMinus] == "B ") {
                SetConsoleTextAttribute(hConsole, 12); // red for warning
                cout << "A bush has been destroyed!\n";
            }
            else if (garden[y][xMinus] == "* ") {
                cout << "Shakey stepped forward!\n";
            }
        }
        else {
            SetConsoleTextAttribute(hConsole, 12); // red for warning
            cout << "Shakey cannot move forward, there is an obstacle in the way!\n";
        }
    }

    // stores inventory items for shakey.
    void pickUpItem(vector<string>& inventory, vector<vector<string>>& garden, char direction, int& x, int& y, int rows, int columns) {
        int yMinus = y - 1, yPlus = y + 1, xMinus = x - 1, xPlus = x + 1;
        string item; // store the array value from garden[y][x].
        // check to make sure it's facing the right way, there is no obstacle, it does not go out of bounds.
        if ((direction == 'N') && (garden[yMinus][x] == "F " || garden[yMinus][x] == "B ") && (y > 1)) {
            item = garden[yMinus][x]; // set item to the value in front of the robot.
            clearLocation(garden, x, yMinus); // clear item in front of the robot.
            inventory.push_back(item); // add item in front of the robot to inventory.
            cout << "Shakey picked up an item!\n";
        }
        else if ((direction == 'E') && (garden[y][xPlus] == "F " || garden[y][xPlus] == "B ") && (x + 1 < columns - 1)) {
            item = garden[y][xPlus];
            clearLocation(garden, xPlus, y);
            inventory.push_back(item);
            cout << "Shakey picked up an item!\n";
        }
        else if ((direction == 'S') && (garden[yPlus][x] == "F " || garden[yPlus][x] == "B ") && (y + 1 < rows - 1)) {
            item = garden[yPlus][x];
            clearLocation(garden, x, yPlus);
            inventory.push_back(item);
            cout << "Shakey picked up an item!\n";
        }
        else if ((direction == 'W') && (garden[y][xMinus] == "F " || garden[y][xMinus] == "B ") && (x > 1)) {
            item = garden[y][xMinus];
            clearLocation(garden, xMinus, y);
            inventory.push_back(item);
            cout << "Shakey picked up an item!\n";
        }
        else {
            SetConsoleTextAttribute(hConsole, 12); // red for warning
            cout << "There is no item to pick up!\n";
        }
    }

    // drops an item from the inventory in front of Shakey.
    void dropItem(vector<string>& inventory, vector<vector<string>>& garden, char direction, int x, int y, int rows, int columns) {
        if (inventory.empty()) {
            SetConsoleTextAttribute(hConsole, 12); // red for warning
            cout << "Inventory is empty, cannot drop item!\n";
            return;
        }
        int yMinus = y - 1, yPlus = y + 1, xMinus = x - 1, xPlus = x + 1;
        string item = inventory.back(); // get the last item from inventory.
        // check to make sure it's facing the right way, there is no obstacle, it does not go out of bounds.
        if ((direction == 'N') && garden[yMinus][x] == "* " && y > 1) {
            garden[yMinus][x] = item; // place item in front of the robot.
            inventory.pop_back(); // remove item from inventory.
            cout << "Shakey dropped an item!\n";
        }
        else if ((direction == 'E') && garden[y][xPlus] == "* " && x + 1 < columns - 1) {
            garden[y][xPlus] = item; // place item in front of the robot.
            inventory.pop_back(); // remove item from inventory.
            cout << "Shakey dropped an item!\n";
        }
        else if ((direction == 'S') && garden[yPlus][x] == "* " && y + 1 < rows - 1) {
            garden[yPlus][x] = item; // place item in front of the robot.
            inventory.pop_back(); // remove item from inventory.
            cout << "Shakey dropped an item!\n";
        }
        else if ((direction == 'W') && garden[y][xMinus] == "* " && x > 1) {
            garden[y][xMinus] = item; // place item in front of the robot.
            inventory.pop_back(); // remove item from inventory.
            cout << "Shakey dropped an item!\n";
        }
        else {
            SetConsoleTextAttribute(hConsole, 12); // red for warning
            cout << "Cannot drop item here!\n";
        }
    }

    void showInventory(const vector<string>& inventory) const {
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
    // shakey's coordinates
    int x = 1, y = 1;

    // control Shakey facing direction.
    char direction = 'E';

    // ask for user input to create garden size.
    int rows;
    cout << "Enter rows: ";
    cin >> rows;
    rows += 2;
    system("cls");
    int columns;
    cout << "Enter columns: ";
    cin >> columns;
    columns += 2;
    system("cls");

    // create a 2D array named garden, with the user-defined size.
    vector<vector<string>> garden(rows, vector<string>(columns));
    vector<string> inventory; // Create an inventory array to store items.
    // create object Shakey the robot.
    Garden shakey;

    // allocate the user-defined array with the element below.
    setStartingElements(garden, rows, columns); // start the game, with the default map.
    createFence(garden, rows, columns); // create the fence around the garden.

    // set the location of the robot.
    shakey.location(garden, x, y); // set [1, 1] to S for Shakey.

    char userInput; // store users options to execute commands
    do {
        printGarden(garden, rows, columns); // flush console and print garden.

        // options menu.
        SetConsoleTextAttribute(hConsole, 7);
        cout << "Facing: " << direction << endl;
        // show coordinates of the robot's location.
        cout << "Shakey coordinates: " << "(" << x << ", " << y << ")" << endl;
        cout << "Options:\n";
        cout << "L - Rotate Left\n";
        cout << "R - Rotate Right\n";
        cout << "P - Pick Up Item\n";
        cout << "D - Drop Item\n";
        cout << "I - Show Inventory\n";
        cout << "S - Step Forward\n";
        cout << "H - Teleport Home (1, 1)\n";
        cout << "X - Soft Locked? Generate new Garden\n";
        cout << "Q - Quit\n";
        cout << "Enter your choice: ";
        cin >> userInput;
        userInput = toupper(userInput);

        switch (userInput) {
        case 'L': // rotate Shakey to the left based on its current direction.
            SetConsoleTextAttribute(hConsole, 10);
            system("cls");
            shakey.rotateLeft(direction);
            break;
        case 'R': // rotate Shakey to the right based on its current direction.
            SetConsoleTextAttribute(hConsole, 10);
            system("cls");
            shakey.rotateRight(direction);
            break;
        case 'S': // have Shakey the robot move forward in the direction they are facing.
            SetConsoleTextAttribute(hConsole, 10);
            system("cls");
            shakey.step(garden, direction, x, y, rows, columns);
            shakey.location(garden, x, y);
            break;
        case 'P': // pick up the item that Shakey is standing on.
            SetConsoleTextAttribute(hConsole, 10);
            system("cls");
            shakey.pickUpItem(inventory, garden, direction, x, y, rows, columns); // pick up item in front of Shakey.
            shakey.location(garden, x, y); // update the location of Shakey in the array.
            break;
        case 'D': // drop an item from the inventory in front of Shakey.
            SetConsoleTextAttribute(hConsole, 10);
            system("cls");
            shakey.dropItem(inventory, garden, direction, x, y, rows, columns);
            shakey.location(garden, x, y); // update the location of Shakey in the array.
            break;
        case 'I': // show inventory.
            SetConsoleTextAttribute(hConsole, 10);
            system("cls");
            shakey.showInventory(inventory);
            break;
        case 'H': // teleport Shakey to (1,1).
            SetConsoleTextAttribute(hConsole, 10);
            system("cls");
            shakey.clearLocation(garden, x, y);
            x = 1; y = 1;
            shakey.location(garden, x, y);
            direction = 'E';
            cout << "Shakey teleported to (1,1)!\n";
            break;
        case 'Q':
            system("cls");
            cout << "Exiting...\n";
            break;
        case 'X': // prompt the user to create a new garden if they are soft locked.
            system("cls");
            garden.clear(); // clear garden array.
            inventory.clear(); // clear inventory.
            direction = 'E'; // set default direction.
            x = 1; y = 1; // set default location.
            cout << "Enter rows: ";
            cin >> rows;
            rows += 2;
            system("cls");
            cout << "Enter columns: ";
            cin >> columns;
            columns += 2;
            garden.resize(rows, vector<string>(columns));
            system("cls");
            setStartingElements(garden, rows, columns); // start the game, with the default map.
            createFence(garden, rows, columns); // create the fence around the garden.
            shakey.location(garden, x, y); // set [1, 1] to S for Shakey.
            break;
        default:
            system("cls");
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Invalid choice, please try again.\n";
            break;
        }
    } while (userInput != 'Q');
}

// sets every value in the user-defined array to the default value '*'.
void setStartingElements(vector<vector<string>>& garden, int x, int y) {
    random_device rd; // create random number generator.
    mt19937 rng(rd()); // generator seed.
    uniform_int_distribution<mt19937::result_type> randX(1, x - 2); // set value.
    uniform_int_distribution<mt19937::result_type> randY(1, y - 2);
    int randomX = randX(rng);
    int randomY = randX(rng);
    // set each element in the 2D array to this element.
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            garden[i][j] = "* ";
        }
    }

    for (int i = 0; i < (x + y) / 2; i++) { // generate random location for other items in Shakey's world.
        randomX = randX(rng); randomY = randY(rng);
        garden[randomX][randomY] = "T ";
        randomX = randX(rng); randomY = randY(rng);
        garden[randomX][randomY] = "M ";
        randomX = randX(rng); randomY = randY(rng);
        garden[randomX][randomY] = "W ";
    }

    for (int i = 0; i < x + y; i++) { // generate bushes and flowers more often.
        randomX = randX(rng); randomY = randY(rng);
        garden[randomX][randomY] = "B ";
        randomX = randX(rng); randomY = randY(rng);
        garden[randomX][randomY] = "F ";
    }
}

// creating/offsetting fence
void createFence(vector<vector<string>>& shakey, int rows, int columns) {
    int col = columns - 1, row = rows - 1; // local values to prevent overflow.
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
            } // gray color for empty space
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
            } // gray color for garden
            cout << locGarden[i][j]; // print each element in the predefined garden.
        }
        // print legend on right side of garden map.
        switch (i) {
        case 0:
            cout << "\tLegend:\n";
            break;
        case 1:
            cout << "\tS - Shakey\tB - Bush\n";
            break;
        case 2:
            cout << "\tF - Flower\tM - Mountain\n";
            break;
        case 3:
            cout << "\tT - Tree\tW - Water\n";
            break;
        case 4:
            cout << "\t# - Fence\t* - Empty space";
        default:
            cout << endl;
            break;
        }
    }
}
