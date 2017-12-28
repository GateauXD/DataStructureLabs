#include <iostream>
#ifndef HashTable_h
#define HashTable_h

using namespace std;

// This is just the node that we have used for linked lists/stacks/queues
struct Node {
	int data;
	int size;
	Node* next;
	Node* head;
	Node* tail;

	Node() {
		data = NULL;
	}

	Node(int data) {
		this->data = data;
	}
};

struct HashTable {
	// Data will be stored in an array of queues
	// So a pointer to a pointer of Node
	Node** array;

	// The size is how many elements we wish to store
	int size;
	int indexFound;

	// Constructor, allocates enough memory for the table
	// and initializes it to NULL
	HashTable(int size) {

		array = (Node**)malloc(sizeof(Node*) * size);
		for (int i = 0; i < size; i++) {
			array[i] = NULL;
		}
		this->size = size;
	}

	// A hashing function
	int hash(int value) {
		int hash = value % size;
		return hash;
	}

	// Insert function
	void insert(int value) {
		//Insert a new node if the queue does not already exist
		if (array[hash(value)] == NULL) {
			Node* newN = new Node(value);
			array[hash(value)] = newN;
		}
		else {
			Node* newN = new Node(value);
			Node* temp = array[hash(value)];
			array[hash(value)] = newN;
			array[hash(value)]->next = temp;
		}
	}

	// A search function
	bool search(int value) {
		indexFound = 0;
		while (array[hash(value)]->next != NULL) {
			indexFound++;
			if (array[hash(value)]->data == value) {
				return true;
			}
			array[hash(value)] = array[hash(value)]->next;
		}
		return false;
	}

	// A function to display the contents of the table
	void print() {
		for (int i = 0; i < size; i++) {
			Node* curr = array[i];
			if (curr != NULL) {
				while (curr != NULL) {
					std::cout << curr->data << " ";
					curr = curr->next;
				}
				std::cout << std::endl;
			}
		}
	}

	void remove(int value) {
		if (search(value) == true) {
			if (indexFound = 0) {
				Node* temp = array[hash(value)];
				array[hash(value)] = array[hash(value)]->next;
				delete temp;
			}
			else {
				for (int i = 0; i < indexFound; i++) {
					array[hash(value)] = array[hash(value)]->next;
				}
				Node* temp = array[hash(value)]->next;
				array[hash(value)]->next = temp->next;
				delete temp;
			}
		}
	}

	// A destructor, which just releases the memory taken by the table
	~HashTable() {
		free(array);
	}

};

#endif /* HashTable_h */