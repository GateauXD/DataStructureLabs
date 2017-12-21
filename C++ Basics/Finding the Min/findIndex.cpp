// findIndex.cpp : Defines the entry point for the console application.
//

#include <iostream>	
#include "FindMin.h"

using namespace std;

int main(int argc, const char * argv[]) {

	int numbers[1000];

	for (int i = 0; i < 1000; i++) {
		numbers[i] = rand() % 10000;
	}

	int start;
	cin >> start;

	int end;
	cin >> end;

	int minIndex = findMin(numbers, start, end);

	cout << "Smallest number in range (" << start << " - " << end << "): " << numbers[minIndex] << endl;

	return 0;
}
