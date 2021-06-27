#include <iostream>
using namespace std;


struct Node {
	char val;
	struct Node *left, *right;
	Node (char v):val(v), left(nullptr), right(nullptr) {}
};


void printInorder(struct Node *root) {
	if (root) {
		printInorder(root->left);
		cout<<root->val<<" ";
		printInorder(root->right);
	}
}


void InvertBinaryTree(Node *root) {
	if (root == nullptr) 
		return;

	if (root) {
		InvertBinaryTree(root->left);
		InvertBinaryTree(root->right);
		Node *tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		
	}
}

int main() {
	cout<<"Algorithm to invert a binary tree"<<endl;

	Node *root = new Node('a');
	root->left = new Node('b');
	root->left->left = new Node('d');
	root->left->right = new Node('e');

	root->right = new Node('c');
	root->right->left = new Node('f');

	printInorder(root);
	cout<<endl;

	InvertBinaryTree(root);

	printInorder(root);
	cout<<endl;


	return 0;
}



