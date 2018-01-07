#include "stdafx.h"
#include <iostream>

using namespace std;

const int n = 5;
int a[n][n] = { 0 };

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[j][i] << " ";
		}
		cout << endl;
	}
}

bool checkEdge(int v1, int v2) {
	if (a[v1][v2] == 1) {
		return true;
	}
	return false;
}

void removeEdge(int v1, int v2) {
	a[v1 - 1][v2 - 1] = 0;
	a[v2 - 1][v1 - 1] = 0;
}

void addEdge(int v1, int v2) {
	a[v1-1][v2-1] = 1;
	a[v2-1][v1-1] = 1;
}

int main()
{	
	addEdge(1, 4);
	addEdge(2, 4);
	addEdge(4, 5);
	addEdge(2, 5);
	addEdge(3, 5);
	
	print();

    return 0;
}

