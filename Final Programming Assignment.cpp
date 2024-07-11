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
        shakey[x][y] = "S ";
    }

    // sets every value in the user defined array to the default value '*'.
    void setStartingElements(vector<vector<string>>& shakey, int x, int y) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                shakey[i][j] = "* "; // set each element in the 2D array to this element.
            }
        }
    }

    // run if user rotates shakey left by 90 degrees.
    char rotateLeft(char direction) {
        if (direction == 'N') return direction = 'E';
        else if (direction == 'E')
            return direction = 'S';
        else if (direction == 'S')
            return direction = 'W';
        else if (direction == 'W')
            return direction = 'N';
    }

    // run if user rotates shakey right by 90 degrees.
    char rotateRight(char direction) {
        if (direction == 'N')
            return direction = 'W';
        else if (direction == 'E')
            return direction = 'N';
        else if (direction == 'S')
            return direction = 'E';
        else if (direction == 'W')
            return direction = 'S';
    }

    // control for shakey the robot to step forward based on which way they are facing.
   void step(char direction, int &x, int &y, int rows, int columns) {
      
        if (direction == 'N') {
            if (y > 0) y--;
        }
        else if (direction == 'E') {
            if (x < columns) x++;
        }
        else if (direction == 'S') {
            if (y < rows) y++;
        }
        else if (direction == 'W') {
            if (x > 0) x--;
        }
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
    int x = 1;
    int y = 1;

    // control shakey direction.
    char direction = 'N';

    string item; // inventory items?

    int rows;
    std::cout << "Enter rows: ";
    std::cin >> rows;
    int columns;
    std::cout << "Enter columns: ";
    std::cin >> columns;

    // create a 2D array named garden, with the user defined size.
    vector<vector<string>> garden(rows, vector<string>(columns));

    vector<int> shakeyGrid;

    Garden shakey; // create object shakey the robot.

    // allocate the user defined array with the element below.
    shakey.setStartingElements(garden, rows, columns); // start the game, with the default map.

    /* TEMPORARY -----> set the location of the robot. <----- TEMPORARY */
    //shakey.location(garden, x, y); // set [1, 1] to S for shakey?
    //shakey.printGarden(garden, rows, columns); // flush console and print garden.

    do {
        shakey.printGarden(garden, rows, columns); // flush console and print garden.

        // options menu.
        cout << "Options:\n";
        cout << "L - Move Left\n";
        cout << "R - Move Right\n";
        cout << "P - Pick Up Item\n";
        cout << "I - Show Inventory\n";
        cout << "Q - Quit\n";
        cout << "Enter your choice: ";
        cin >> userInput;
        userInput = toupper(userInput);

        switch (userInput) {
        case 'L':
            direction = shakey.rotateLeft(direction);
            system("cls");
            cout << "Facing: " << direction << endl;
            break;
        case 'R':
            direction = shakey.rotateRight(direction);
            system("cls");
            cout << "Facing: " << direction << endl;
            break;
        case 'S':
            system("cls");
            garden[x][y] = "* ";
            shakey.step(direction, x, y, rows, columns);
            shakey.location(garden, x, y);

            std::cout << "Shakey coordinates: " << x << " " << y << endl;
            /*x = shakey.step(direction, x, y, rows, columns);
            y = shakey.step(direction, x, y, rows, columns);*/
            break;
        case 'P':
            system("cls");
            cout << "Enter item to pick up: ";
            cin >> item;
            shakey.pickUpItem(item);
            break;
        case 'I':
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
