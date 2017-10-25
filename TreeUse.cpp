#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;

void printPreOrder(TreeNode<int>* root) {
	cout << root->getData() << endl;
	for (int i = 0; i < root->numChildren(); i++) {
		printPreOrder(root->getChild(i));
	}
}

void printPostOrder(TreeNode<int>* root) {
	for (int i = 0; i < root->numChildren(); i++) {
		printPostOrder(root->getChild(i));
	}
	cout << root->getData() << endl;
}

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root Data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty()) {
		TreeNode<int>* firstNode = pendingNodes.front();
		pendingNodes.pop();

		cout << "Enter num children of " << firstNode->getData() << endl;
		int numChildren;
		cin >> numChildren;

		for (int i = 0; i < numChildren; i++) {
			cout << "Enter " << i << "th child of ";
			cout << firstNode->getData() << endl;
			int childData;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			pendingNodes.push(child);
			firstNode->addChild(child);
		}
	}
	return root;
}

int maxDegree(TreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}

	int maxDegree1 = root->numChildren();
	for (int i = 0; i < childCount; i++) {
		maxDegree1 = max(maxDegree1, maxDegree(root->getChild(i)));
	}
	return maxDegree1;
}

int height(TreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}

	int maxChildHeight = 0;
	for (int i = 0; i < childCount; i++) {
		maxChildHeight = max(maxChildHeight, height(root->getChild(i)));
	}
	return maxChildHeight + 1;
}

int sum(TreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int csum = root->getData();
	for (int i = 0; i < root->numChildren(); i++) {
		csum += sum(root->getChild(i));
	}
	return csum;
}

// 1 3 2 2 5 0 6 0 3 0 4 1 7 2 8 0 9 0
TreeNode<int>* takeTreeInput() {
	cout << "Enter Root Data" << endl;
	int rootData;
	cin >> rootData;

	TreeNode<int>* root = new TreeNode<int>(rootData);
	int childCount;
	cout << "Enter num children of " << rootData << endl;
	cin >> childCount;
	for (int i = 0; i < childCount; i++) {
		root->addChild(takeTreeInput());
	}
	return root;
}

void print(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}

	cout << root->getData() << ":";
	for (int i = 0; i < root->numChildren(); i++) {
		cout << root->getChild(i)->getData() << " ,";
	}
	cout << endl;

	for (int i = 0; i < root->numChildren(); i++) {
		print(root->getChild(i));
	}
}

int main() {
	TreeNode<int>* root	 = takeTreeInput();
	print(root);
	delete root;
}

