// CIS142 Introduction to C++ Summer 2024
// Final Programming Assignment
// Mao Bergan
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
    // control the console view of all elements in 2D array.
    void printGarden(vector<vector<string>>& locGarden, int locRows, int locColumns) {
        for (int i = 0; i < locRows; i++) {
            for (int j = 0; j < locColumns; j++) {
                if (locGarden[i][j] == "# ") { 
                    SetConsoleTextAttribute(hConsole, 8); } // gray color for fence
                else if (locGarden[i][j] == "S ") { 
                    SetConsoleTextAttribute(hConsole, 12); } // red color for Shakey
                else if (locGarden[i][j] == "B ") { 
                    SetConsoleTextAttribute(hConsole, 5); } // purple color for bush
                else if (locGarden[i][j] == "F ") { 
                    SetConsoleTextAttribute(hConsole, 6); } // yellow color for flower
                else if (locGarden[i][j] == "M ") { 
                    SetConsoleTextAttribute(hConsole, 7); } // white color for mountain
                else if (locGarden[i][j] == "T ") { 
                    SetConsoleTextAttribute(hConsole, 10); } // bright green color for tree
                else if (locGarden[i][j] == "W ") { 
                    SetConsoleTextAttribute(hConsole, 9); } // blue color for water
                else { 
                    SetConsoleTextAttribute(hConsole, 8); } // green color for garden}
                cout << locGarden[i][j]; // print each element in the predefined garden.
            }
            // cout << endl; // create a new row after each row is complete.
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

    // set the location of the robot.
    void location(std::vector<vector<string>>& shakey, int& x, int& y) {
        shakey[y][x] = "S ";
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
        // generate random location for other items in shakey's world.
        for (int i = 0; i < (x + y)/2; i++) {
            randomX = randX(rng); randomY = randX(rng);
            shakey[randomX][randomY] = "B ";
            randomX = randX(rng); randomY = randX(rng);
            shakey[randomX][randomY] = "F ";
            randomX = randX(rng); randomY = randX(rng);
            shakey[randomX][randomY] = "T ";
            randomX = randX(rng); randomY = randX(rng);
            shakey[randomX][randomY] = "M ";
            randomX = randX(rng); randomY = randX(rng);
            shakey[randomX][randomY] = "W ";
        }
        for (int i = 0; i < x + y; i++) {
            randomX = randX(rng); randomY = randX(rng);
            shakey[randomX][randomY] = "B ";
            randomX = randX(rng); randomY = randX(rng);
            shakey[randomX][randomY] = "F ";
        }

    }

    
    



    // creating/offseting fence
    void createFence(vector<vector<string>>& shakey, int rows, int columns) {
        for (int i = 0; i < rows; ++i) {
            shakey[i][0] = "# ";
            shakey[i][columns - 1] = "# ";
        }
        for (int j = 0; j < columns; ++j) {
            shakey[0][j] = "# ";
            shakey[rows - 1][j] = "# ";
        }
    }

    // run if user rotates shakey left by 90 degrees.
    void rotateRight(char& direction) {
        if (direction == 'N') { direction = 'E'; }
        else if (direction == 'E') { 
            direction = 'S'; }
        else if (direction == 'S') { 
            direction = 'W'; }
        else if (direction == 'W') { 
            direction = 'N'; }
    }

    // run if user rotates shakey right by 90 degrees.
    void rotateLeft(char& direction) {
        if (direction == 'N') { direction = 'W'; }
        else if (direction == 'E') { 
            direction = 'N'; }
        else if (direction == 'S') { 
            direction = 'E'; }
        else if (direction == 'W') { 
            direction = 'S'; }
    }

    // control for shakey the robot to step forward based on which way they are facing.
    void step(vector<vector<string>>& garden, char direction, int& x, int& y, int rows, int columns) {
        /*if (garden[y][x] == "F ") { garden[y][x] = "F "; }
        else if (garden[y][x] == "B ") { garden[y][x] = "B "; }
        else if (garden[y][x] == "F ") { garden[y][x] = "F "; }
        else if (garden[y][x] == "M ") { garden[y][x] = "M "; }*/
        
        if (direction == 'N') { if (y > 1) y--; }
        else if (direction == 'E') { 
            if (x + 1 < columns - 1) x++; }
        else if (direction == 'S') { 
            if (y + 1 < rows - 1) y++; }
        else if (direction == 'W') { 
            if (x > 1) x--; }
    }

    vector<std::string> inventory; // stores inventory items for shakey.
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

void startGame();

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

    Garden shakey; // create object shakey the robot.

    // allocate the user defined array with the element below.
    shakey.setStartingElements(garden, rows, columns); // start the game, with the default map.
    shakey.createFence(garden, rows, columns); // create the fence around the garden.

    /* TEMPORARY -----> set the location of the robot. <----- TEMPORARY */
    shakey.location(garden, x, y); // set [1, 1] to S for shakey?

    char userInput; // store users options to execute commands
    do {
        shakey.printGarden(garden, rows, columns); // flush console and print garden.

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
