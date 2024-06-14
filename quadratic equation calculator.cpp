#include <iostream>
#include <cmath>

using namespace std;
int main() {

	double a, b, c;
	double root1;
	double root2;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	root1 = (-b + std::sqrt(b * b - 2 * a * c)) / (2 * a);
	// positive root
	root2 = (-b - std::sqrt(b * b - 2 * a * c)) / (2 * a);
	// negative root

	cout << "Positive root is: " << root1 << "\n";
	cout << "Negative root is: " << root2 << "\n";

}