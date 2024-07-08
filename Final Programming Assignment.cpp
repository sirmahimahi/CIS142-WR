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
    void location(std::vector<std::vector<std::string>>& locGarden, int x, int y) {
        locGarden[x][y] = "S ";
        std::system("cls");
    }
};

int main() {
    int rows;
    int columns;
    std::cout << "Enter rows: ";
    std::cin >> rows;
    std::cout << "Enter columns: ";
    std::cin >> columns;
    // create a 2D array named garden, with the user defined size.
    std::vector<std::vector<std::string>> garden(rows, std::vector<std::string>(columns));

    // allocate the user defined array with the element below.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            garden[i][j] = "* "; // set each element in the 2D array to this element.
        }
    }

    Garden shakey; // create object shakey the robot.
    shakey.printGarden(garden, rows, columns);
    shakey.location(garden, 0, 0); // set [1, 1] to S for shakey?
    shakey.printGarden(garden, rows, columns);
    return 0;
}
