// Ifelse.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

int main(){
	
	int x;

	//Asks the user to enter a number
	cout << "Please enter a positve integer" << endl;
	cin >> x;

	//Determines if x is positive and computes if x is odd or even
	if (x > 0) {
		if (x % 2 == 0) {
			cout << "Even" << endl;
		}
		else
			cout << "Odd" << endl;
	}
	else {
		cout << "Please enter a positive number!" << endl;
	}

	//Found this fix on learncpp.com to stop the command prompt from closing instantly
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();

    return 0;

}

