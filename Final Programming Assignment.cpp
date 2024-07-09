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
    void printGarden(std::vector<std::vector<std::string>>& locGarden, int locRows, int locColumns) {
        for (int i = 0; i < locRows; i++) {
            for (int j = 0; j < locColumns; j++) {
                std::cout << locGarden[i][j]; // print each element in the predefined garden.
            }
            std::cout << std::endl; // create a new row after each row is complete.
        }
    }

    /* TEMPORARY -----> set the location of the robot. <----- TEMPORARY */
    void location(std::vector<std::vector<std::string>>& shakey, int x, int y) {
        shakey[x][y] = "S ";
    }
    
    void setStartingElements(std::vector<std::vector<std::string>>& shakey, int x, int y) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                shakey[i][j] = "* "; // set each element in the 2D array to this element.
            }
        }
    }

    
    

    // run if user rotates shakey left by 90 degrees.
    char rotateLeft(char direction) {
        switch (direction) {
        case 'N':
            return direction = 'E'; break;
        case 'E':
            return direction = 'S';  break;
        case 'S':
            return direction = 'W'; break;
        default:
            return direction = 'N'; break;
        }
        return direction;
    }

    // run if user rotates shakey right by 90 degrees.
    char rotateRight(char direction) {
        switch (direction) {
        case 'N':
            return direction = 'W'; break;
        case 'E':
            return direction = 'N'; break;
        case 'S':
            return direction = 'E'; break;
        default:
            return direction = 'S'; break;
        }
    }

    int step(char direction, int x, int y, int rows, int columns) {
        if (direction == 'N') {
            if (y < rows) {
                y++; return y;
            }
           
        }
        else if (direction == 'E') {
            x++; return x;
        }
        else if (direction == 'S') {
            y--; return y;
        }
        else if (direction == 'W') {
            x--; return x;
        }
    }

    vector<std::string> inventory;
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
    // used to store user array size.
    int rows;
    int columns;

    // shakeys coordinates.
    int x = 1;
    int y = 1;

    // control shakey direction.
    char direction = 'N';
    

    std::cout << "Enter rows: ";
    std::cin >> rows;
    std::cout << "Enter columns: ";
    std::cin >> columns;
    
    // create a 2D array named garden, with the user defined size.
    std::vector<std::vector<std::string>> garden(rows, std::vector<std::string>(columns));
    Garden shakey; // create object shakey the robot.

    // allocate the user defined array with the element below.
    shakey.setStartingElements(garden, rows, columns); // start the game, with the default map.

    
    shakey.location(garden, shakeyX, shakeyY); // set [1, 1] to S for shakey?
    //shakey.printGarden(garden, rows, columns); // flush console and print garden.
    

    char userInput; // grab command from user.

    string item;
    
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
       

        switch (userInput) {
            userInput = toupper(userInput);
        case 'L':
        
            direction = shakey.rotateLeft(direction); 
            std::system("cls");
            std::cout << "Facing: " << direction << std::endl;
            break;
        case 'R':
        
            direction = shakey.rotateRight(direction);
            std::system("cls");
            std::cout << "Facing: " << direction << std::endl;
            break;
        case 'S':
            x = shakey.step(direction, x, y, rows, columns);
            y = shakey.step(direction, x, y, rows, columns);
            break;
        case 'P':
        
            cout << "Enter item to pick up: ";
            cin >> item;
            shakey.pickUpItem(item);
            break;
        case 'I':
        case 'i':
            shakey.showInventory();
            break;
        case 'Q':
        case 'q':
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
            break;
        }
        
    } while (userInput != 'Q' && userInput != 'q');



    return 0;
}
