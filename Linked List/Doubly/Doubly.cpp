// Doubly.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;

	Node() {
		data = NULL;
		next = NULL;
		prev = NULL;
	}

	Node(int value) {
		data = value;
		next = NULL;
		prev = NULL;
	}

	Node* insert(Node* start, int value) {
		Node* newN = new Node(value);

		while (start->next != NULL) {
			start = start->next;
		}
		start->next = newN;
		newN->prev = start;

		return newN;
	}

	void print(Node* start) {
		while (start != NULL) {
			cout << start->data << " ";
			start = start->next;
		}
	}

	void printReverse(Node* last) {
		while (last != NULL) {
			cout << last->data << " ";
			last = last->prev;
		}
	}
};

int main()
{

	int limit;
	cin >> limit;

	Node* A = new Node();
	A->data = 0;
	A->prev = NULL;
	A->next = NULL;

	Node* last = A;

	for (int i = 1; i < limit; i = i + i) {
		last = A->insert(A, i);
	}
	A->print(A);
	cout << endl;
	A->printReverse(last);

	return 0;

}

