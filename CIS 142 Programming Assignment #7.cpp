// CIS142 Introduction to C++ Summer 2024
// Programming Assignment #7
// Mao Bergan
// 13 July 2024

// CIS 142 Programming Assignment #7.cpp

/* The scenario is this: you are on Noah's ark with a set of animals. As the months pass, the
animals begin to breed. You need to keep track of your animal inventory down below.
The ark has 3 types of animals: mammals, birds, and fish. Your program should have at least 2
kinds of mammals (cat, dog), 2 kinds of fish (goldfish, shark), and 2 kinds of birds (eagle,
parakeet). You should start the program with 2 animals of each species on the ark, one male
and one female, for a total of 12 animals. */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
    
class animals {
public:
    std::string gender;
    std::string name;
    int age = 0;

    animals(std::string locGender, std::string locName, int locAge) {
        gender = locGender;
        name = locName;
        age = locAge;
    }
    void display() const {
        std::cout << gender << " " << name << " " << age << '\n';
    }
};

int main()
{
    int userSelection = 1;
    int months = 0;
    int mammalBreed = 12;
    int fishBreed = 6;
    int birdBreed = 9;
    srand(unsigned(time(NULL))); // random generator call
    std::vector<animals> allAnimals; // creates a vector out of our class animals with the first 12 animals preinitialized.
    allAnimals.push_back(animals("Female", "Cat", 0));
    allAnimals.push_back(animals("Male", "Cat", 0));
    allAnimals.push_back(animals("Female", "Dog", 0));
    allAnimals.push_back(animals("Male", "Dog", 0));
    allAnimals.push_back(animals("Female", "Goldfish", 0));
    allAnimals.push_back(animals("Male", "Goldfish", 0));
    allAnimals.push_back(animals("Female", "Shark", 0));
    allAnimals.push_back(animals("Male", "Shark", 0));
    allAnimals.push_back(animals("Female", "Eagle", 0));
    allAnimals.push_back(animals("Male", "Eagle", 0));
    allAnimals.push_back(animals("Female", "Parakeet", 0));
    allAnimals.push_back(animals("Male", "Parakeet", 0));
    for (int i = 0; i < allAnimals.size(); i++) allAnimals[i].display(); // display all animals.
    
    do { // display how many months have passed since program started.
	if (months == 1) std::cout << "You have been on the ark for " << months << " month.\n";
	else std::cout << "You have been on the ark for " << months << " months.\n";

	// determine the size of the allAnimals vector before spawning new animals.
    size_t animalVectorSize; 
    animalVectorSize = allAnimals.size(); 

    if (months == mammalBreed) { 
        for (int i = 0; i < animalVectorSize; i++) { // breed a new cat if it is 12 months old and female.
            if (allAnimals[i].name == "Cat") {
                if (allAnimals[i].gender == "Female") {
                    int gender = rand() % 2; // assign the new mammal a random gender.
                    std::string genderName = "Male";
                    if (gender == 1) genderName = "Male";
                    else genderName = "Female";
                    allAnimals.push_back(animals(genderName, "Cat", 0));
                }
            }
            if (allAnimals[i].name == "Dog") { // breed a new dog if it is 12 months old and female.
                if (allAnimals[i].gender == "Female") {
                    int gender = rand() % 2; // assign the new mammal a random gender.
                    std::string genderName = "Male";
                    if (gender == 1) genderName = "Male";
                    else genderName = "Female";
                    allAnimals.push_back(animals(genderName, "Dog", 0));
                    // mammalBreed = mammalBreed + 12;
                }
            }
        }
        system("color 6");
        std::cout << "A new animal has been born!\n";
        mammalBreed = mammalBreed + 12;
    }

    if (months == fishBreed) {
        for (int i = 0; i < animalVectorSize; i++) { // breed a new goldfish if it is 12 months old and female.
            if (allAnimals[i].name == "Goldfish") {
                if (allAnimals[i].gender == "Female") {
                    int gender = rand() % 2; // assign the new mammal a random gender.
                    std::string genderName = "Male";
                    if (gender == 1) genderName = "Male";
                    else genderName = "Female";
                    allAnimals.push_back(animals(genderName, "Goldfish", 0));
                }
            }
            if (allAnimals[i].name == "Shark") { // breed a new shark if it is 12 months old and female.
                if (allAnimals[i].gender == "Female") {
                    int gender = rand() % 2; // assign the new mammal a random gender.
                    std::string genderName = "Male";
                    if (gender == 1) genderName = "Male";
                    else genderName = "Female";
                    allAnimals.push_back(animals(genderName, "Shark", 0));
                }
            }
        }
        system("color 6");
        std::cout << "A new animal has been born!\n";
        fishBreed = fishBreed + 6;
    }

    if (months == birdBreed) {
        for (int i = 0; i < animalVectorSize; i++) { // breed a new eagle if it is 12 months old and female.
            if (allAnimals[i].name == "Eagle") {
                if (allAnimals[i].gender == "Female") {
                    int gender = rand() % 2; // assign the new mammal a random gender.
                    std::string genderName = "Male";
                    if (gender == 1) genderName = "Male";
                    else genderName = "Female";
                    allAnimals.push_back(animals(genderName, "Eagle", 0));
                }
            }
            if (allAnimals[i].name == "Parakeet") { // breed a new parakeet if it is 12 months old and female.
                if (allAnimals[i].gender == "Female") {
                    int gender = rand() % 2; // assign the new mammal a random gender.
                    std::string genderName = "Male";
                    if (gender == 1) genderName = "Male";
                    else genderName = "Female";
                    std::cout << "Hello World!";
                    allAnimals.push_back(animals(genderName, "Parakeet", 0));
                }
            }
        }
        system("color 6");
        std::cout << "A new animal has been born!\n";
        birdBreed = birdBreed + 9;
    }

	std::cout << "What would you like to do?\n";
	std::cout << "[1] Let another month pass.\n";
	std::cout << "[2] Check inventory.\n";
	std::cout << "[3] Quit.\n";
	std::cin >> userSelection;
    std::system("cls"); // clear terminal each time a user action is performed.

    if (userSelection == 1) { // let a month pass and age each animal in the vector by 1 month.
        for (int i = 0; i < allAnimals.size(); i++) allAnimals[i].age++; months++;
    }
    else if (userSelection == 2) { // refresh inventory with all existing and new animals.
        for (int i = 0; i < allAnimals.size(); i++) {
            system("color 7"); allAnimals[i].display();
        }
    }
    } while (userSelection != 3); // end program is user selects 3 to exit.
    return 0;
}
