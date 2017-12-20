#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	char symbol;
	int amount = 0;

	while (amount != -2) {
		cin >> symbol >> amount;
		
		if (amount == -2) {
			return 0;
		}
			
		for (int i = 0; i < amount; i++) {
			if (amount == -1) {
				cout << endl;
				break;
			}
			else {
				cout << symbol;
			}

		}
	}

    return 0;

}

