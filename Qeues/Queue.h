#include<stddef.h>

#ifndef Queue_h
#define Queue_h

// The Node data structure
struct Node {
    long data;
    Node* next;
    
    Node(long d) {
        data = d;
        next = NULL;
    }
    
    ~Node(){
        
    }
};

struct Queue {
    // Implement the Queue data structure so that the code works...
	Node* head;
	Node* tail;
	long length = 0;

	Queue() {
		head = NULL;
		tail = NULL;
	}

	bool isEmpty() {
		if (head == NULL)
			return true;
		else
			return false;
	}

	void push(long value) {
		if (isEmpty()) {
			Node* curr = new Node(value);
			
			head = curr;
			tail = curr;
		}
		else {
			Node* curr = new Node(value);
			tail->next = curr;
			tail = curr;
			
		}
		length++;
	}

	long pop() {
		Node* temp;
		temp = head->next;

		long data = head->data;

		delete head;
		head = temp;

		return data;

	}

	~Queue() {
		Node* temp = head;

		while (head != NULL) {
			head = head->next;
			delete temp;
			temp = head;
		}
		
	}

};

#endif
