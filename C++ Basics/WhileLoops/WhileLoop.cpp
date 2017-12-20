// WhileLoop.cpp : Defines the entry point for the console application.
//
#include <iostream>

using namespace std;

int main()
{
	int x = 0;

	//Determines if x is positive and computes if x is odd or even
	while (x != -1) {
		cout << "Please enter a positve integer" << endl;
		cin >> x;

		if (x > 0) {
			if (x % 2 == 0) {
				cout << "Even" << endl;
			}
			else
				cout << "Odd" << endl;
		}
		else if (x == -1) {
		}

		else {
			cout << "Please enter a positive number!" << endl;
		}
	}
	//Found this fix on learncpp.com to stop the command prompt from closing instantly
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
    return 0;
}

