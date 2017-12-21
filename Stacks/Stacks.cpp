
#include <iostream>
#include "Stack.h"

using namespace std;

int main(int argc, const char * argv[]) {

	int total = 0;

	char command = 'a';

	Stack ops = Stack();

	//Data in operations stack will = an operation 1 = a, 2 = s, 3 = m, and 4 = d
	Stack Operations = Stack();
	

	while (command != 'q') {
		cin >> command;
		if (command == 'a') {
			int value;
			cin >> value;

			total += value;

			ops.push(value);
			Operations.push(1);

			cout << "Total is: " << total << endl;
		}

		else if (command == 's') {
			int value;
			cin >> value;

			total -= value;

			ops.push(value);
			Operations.push(2);

			cout << "Total is: " << total << endl;
		}

		else if (command == 'm') {
			int value;
			cin >> value;

			total = total * value;

			ops.push(value);
			Operations.push(3);

			cout << "Total is: " << total << endl;
		}

		else if (command == 'd') {
			int value;
			cin >> value;

			if (value == 0) {
				cout << " Can't divide by 0" << endl;
			}
			else {
				total = total / value;

				ops.push(value);
				Operations.push(4);

				cout << "Total is: " << total << endl;
			}
		}
		
		else if (command == 'z') {
			if (ops.isEmpty()) {
				cout << "Can't undo anymore..." << endl;
			}
			else {
				int value = ops.pop();

				int op = Operations.pop();

				if (op == 1) {
					total = total - value;
					cout << "Total is: " << total << endl;
				}
				else if (op == 2) {
					total = total + value;
					cout << "Total is: " << total << endl;
				}
				else if (op == 3) {
					total = total / value;
					cout << "Total is: " << total << endl;
				}
				else {
					total = total * value;
					cout << "Total is: " << total << endl;
				}
			}
		}
	}

	cout << "Bye!" << endl;

	return 0;
}