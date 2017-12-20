#include <iostream>


bool primeCalc(int i) {
	
	if (i == 1){
		return false;
	}
	
	for (int j = 2; j <= i - 1; j++) {
		if (i % j == 0)
			return false;
	}
	return true;
}

using namespace std;

int main()
{

	int n;
	bool prime;

	cout << "Enter an integer that you want to find prime numbers up to" << endl;
	cin >> n;

	for (int i = 1; i < n; i++) {
		if (primeCalc(i) == true) {
			cout << i << endl;
		}
	}


	//Found this fix on learncpp.com to stop the command prompt from closing instantly
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();

    return 0;

}

