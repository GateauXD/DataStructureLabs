// ForLoop.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x;
	string sentence;

	cout << "Enter a sentence that you want to be repeated" << endl;
	cin >> sentence;

	cout << "Enter the amount of times you want the sentence to be repeated" << endl;
	cin >> x;

	for (int i = 0; i < x; i++) {
		cout << sentence << endl;
	}

	//Fixed command prompt from closing instantly found on learncpp.com
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();

    return 0;

}

