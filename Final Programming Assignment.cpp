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
#include <cctype>
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

class Garden {
public:
    // control the console view of all elements in 2D array.
    void printGarden(vector<vector<string>>& locGarden, int locRows, int locColumns) {
        for (int i = 0; i < locRows; i++) {
            for (int j = 0; j < locColumns; j++) {
                cout << locGarden[i][j]; // print each element in the predefined garden.
            }
            cout << endl; // create a new row after each row is complete.
        }
    }

    /* TEMPORARY -----> set the location of the robot. <----- TEMPORARY */
    void location(std::vector<vector<string>>& shakey, int& x, int& y) {
        shakey[y][x] = "S ";
    }

    // sets every value in the user defined array to the default value '*'.
    void setStartingElements(vector<vector<string>>& shakey, int x, int y) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                SetConsoleTextAttribute(hConsole, 10);
                shakey[i][j] = "* "; // set each element in the 2D array to this element.
                
            }
        }
    }

    // run if user rotates shakey left by 90 degrees.
    void rotateRight(char& direction) {
        if (direction == 'N')
            direction = 'E';
        else if (direction == 'E')
            direction = 'S';
        else if (direction == 'S')
            direction = 'W';
        else if (direction == 'W')
            direction = 'N';
    }

    // run if user rotates shakey right by 90 degrees.
    void rotateLeft(char& direction) {
        if (direction == 'N')
            direction = 'W';
        else if (direction == 'E')
            direction = 'N';
        else if (direction == 'S')
            direction = 'E';
        else if (direction == 'W')
            direction = 'S';
    }

    // control for shakey the robot to step forward based on which way they are facing.
    void step(char direction, int& x, int& y, int rows, int columns) {

        if (direction == 'N') {
            if (y > 0) y--;
        }
        else if (direction == 'E') {
            if (x + 1 < columns) x++;
        }
        else if (direction == 'S') {
            if (y + 1 < rows) y++;
        }
        else if (direction == 'W') {
            if (x > 0) x--;
        }
        else std::cout << "Out of bounds!\n";
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

int main() {

    char userInput; // store users options to execute commands.

    // shakeys coordinates, starts at (x, y) = (1, 1).
    int x = 0;
    int y = 0;

    // control shakey direction.
    char direction = 'E';

    
    // ask for user input to create garden size.
    int rows;
    std::cout << "Enter rows: ";
    std::cin >> rows;
    system("cls"); // reset the console.
    int columns;
    std::cout << "Enter columns: ";
    std::cin >> columns;
    system("cls"); // reset the console.

    // create a 2D array named garden, with the user defined size.
    vector<vector<string>> garden(rows, vector<string>(columns));

    Garden shakey; // create object shakey the robot.

    // allocate the user defined array with the element below.
    shakey.setStartingElements(garden, rows, columns); // start the game, with the default map.

    /* TEMPORARY -----> set the location of the robot. <----- TEMPORARY */
    shakey.location(garden, x, y); // set [1, 1] to S for shakey?
    //shakey.printGarden(garden, rows, columns); // flush console and print garden.

    do {
        shakey.printGarden(garden, rows, columns); // flush console and print garden.

        // options menu.
        SetConsoleTextAttribute(hConsole, 7);
        cout << "Facing: " << direction << endl;
        // show coordinates of the robots location.
        std::cout << "Shakey coordinates: " << "(" << x + 1 << ", " << y + 1 << ")" << endl;
        cout << "Options:\n";
        cout << "L - Move Left\n";
        cout << "R - Move Right\n";
        cout << "P - Pick Up Item\n";
        cout << "I - Show Inventory\n";
        cout << "S - Step\n";
        cout << "Q - Quit\n";
        cout << "Enter your choice: ";
        cin >> userInput;
        userInput = toupper(userInput);
        string item; // inventory items?
        switch (userInput) {
        case 'L':
            SetConsoleTextAttribute(hConsole, 10);
            shakey.rotateLeft(direction);
            system("cls"); // reset the console.
            break;
        case 'R':
            SetConsoleTextAttribute(hConsole, 10);
            shakey.rotateRight(direction);
            system("cls"); // reset the consol.
            break;
        case 'S':
            SetConsoleTextAttribute(hConsole, 10);
            system("cls");
            garden[y][x] = "* ";
            shakey.step(direction, x, y, rows, columns);
            shakey.location(garden, x, y);
            break;
        case 'P':
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
    return 0;
}
