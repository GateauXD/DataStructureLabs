// LinkedList.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;

	Node() {
		data = NULL;
		next = NULL;
	}

	Node(int value) {
		data = value;
		next = NULL;
	}

	void insert(Node* list,int value) {
		Node* newN = new Node(value);
		
		while (list->next != NULL) {
			list = list->next;
		}
		list->next = newN;
	}

	void print(Node* list) {
		while (list != NULL) {
			cout << list->data << " ";
			list = list->next;
		}
	}
};

int main(int argc, const char * argv[]) {

	int limit;

	cin >> limit;

	Node* list = new Node();
	list->data = 0;
	list->next = NULL;
	
	for (int i = 1; i <= limit; i++) {
		list->insert(list, i);
	}
	list->print(list);

	return 0;
}

