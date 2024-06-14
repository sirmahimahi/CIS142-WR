#include <iostream>
// fizzbuzz for loop example
// print fizz if the input is multiple by 3
// print buzz if the input is multiple by 5
// print fizzbuzz if both 3 and 5 are multiples
int main() {
	int i; 
	for (i = 1; i <= 100; i++) { // print numbers 1 - 100

		if (i % 3 == 0 && i % 5 == 0) \ {
			std::cout << "fizzbuzz\n";
		}
		else if (i % 3 == 0) {
			std::cout << "fizz\n";
		}
		else if (i % 5 == 0) {
			std::cout << "buzz\n";
		}
		else {
			std::cout << i << "\n";
		}

	}

}
