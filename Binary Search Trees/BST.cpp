
#include <iostream>

using namespace std;

struct Node {
	long data;
	Node* left;
	Node* right;
};


void insert_test(Node* root,long value){

	Node* temp = root;

	while (true) {
		if (root == NULL) {
			temp->data = value;
			break;
		}
		else if (value <= temp->data) {
			if (temp->left == NULL) {
				Node* newNode = new Node();
				newNode->data = value;
				temp->left = newNode;
				break;
			}
			temp = temp->left;
		}
			
		else {
			if (temp->right == NULL) {
				Node* newNode = new Node();
				newNode->data = value;
				temp->right = newNode;
				break;
			}
			temp = temp->right;
		}

	}

}

Node* insert(Node* root, int value) {
	if (root == NULL) {
		root = new Node();
		root->data = value;
		root->left = NULL;
		root->right = NULL;
	}
	else {
		if (value < root->data) {
			root->left = insert(root->left, value);
		}
		else {
			root->right = insert(root->right, value);
		}
	}
	return root;
}

void displayTree(Node* root, int level, int direction) {
	if (root != NULL) {
		displayTree(root->right, level + 1, 1);

		for (int i = 0; i < level - 1; i++) {
			cout << "   ";
		}
		if (level > 0) {
			if (direction == 1) {
				cout << " /--";
			}
			else {
				cout << " \\--";
			}
		}
		cout << root->data;
		cout << endl;
		level++;

		displayTree(root->left, level, -1);
	}
}

void drawTree(Node* root) {
	displayTree(root, 0, 0);
	cout << endl << endl;
}

bool isBST(Node* root) {
	if (root == NULL) {
		return true;
	}
	else {
		bool levelOK = true;
		if (root->left != NULL && root->left->data > root->data) {
			levelOK = false;
		}
		if (root->right != NULL && root->right->data <= root->data) {
			levelOK = false;
		}
		return levelOK && isBST(root->left) && isBST(root->right);
	}
}

void print(Node* root) {
	if (root != NULL) {
		print(root->left);
		cout << root->data << " ";
		print(root->right);
	}

}

//Used to find if a number is in the tree if and if so returns a pointer to the location of the node
Node* findNode(Node*root, int value) {
	Node* temp;
	temp = root;

	if (temp == NULL) {
		return NULL;
	}
	
	else {
		if (value == temp->data) {
			return temp;
		}
		
		else if (value <= temp->data) {
			return findNode(temp->left, value);
		}
		
		else if (value > temp->data){
			return findNode(temp->right, value);
		}

	}
}

//Used to find the number of times a number is found a tree 
int occurrences(Node* root, int value) {
	Node* N = findNode(root, value);

	int count = 0;

	while (N) {

		if (N->data == value) 
			count++;	

		N = findNode(N->left, value);

	}

	return count;
}

void deletion(Node* root, int value) {
	Node* parent = root;

	//Left = -1 Right = 1
	int lastmove = 0;

	while (root->data != value) {
		parent = root;

		if (value < root->data) {
			root = root->left;
			lastmove = -1;
		}
		else if (value > root->data) {
			root = root->right;
			lastmove = 1;
		}
	}

	//If Node has no child nodes
	if (root->left == NULL && root->right == NULL) {
		if (lastmove = -1)
			parent->left = NULL;
		else if (lastmove = 1)
			parent->right = NULL;

		delete root;
	}

	//If Node has one child
	//Left has a child
	else if (root->left != NULL && root->right == NULL) {
		Node* successor = root->left;

		if (lastmove == -1)
			parent->left = successor;
		else if (lastmove = 1)
			parent->right = successor;

		delete root;
	}

	//Right has a child
	else if (root->right != NULL && root->left == NULL) {
		Node* successor = root->right;

		if (lastmove == -1)
			parent->left = successor;
		if (lastmove == 1)
			parent->right = successor;
		
		delete root;
	}

	//Node that is being deleted has two children
	else {
		Node* successor = root->right;

		while (successor->left != NULL) {
			successor = successor->left;
		}

		int temp = successor->data;
		delete successor;

		root->data = temp;
	}
		
}


int main(int argc, const char * argv[]) {

	Node* tree = NULL;

	tree = insert(tree, 5);
	tree = insert(tree, 2);
	tree = insert(tree, 7);
	tree = insert(tree, 1);
	tree = insert(tree, 3);
	tree = insert(tree, 6);
	tree = insert(tree, 8);
	tree = insert(tree, 5);
	tree = insert(tree, 5);
	tree = insert(tree, 5);

	drawTree(tree);

	deletion(tree, 7);

	//Look for the number 7 in the tree
	Node* N = findNode(tree, 7);

	if (N != NULL) {
		cout << "7 is Found" << endl;
	}
	else {
		cout << "7 is Found" << endl;
	}

	// For the values between 1 and 8, how many times does each one occur in the tree?
	for (int i = 0; i <= 8; i++) {
		cout << i << ": " << occurrences(tree, i) << endl;
	}

	return 0;
}

