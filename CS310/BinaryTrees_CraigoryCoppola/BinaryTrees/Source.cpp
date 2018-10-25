#include <iostream>

#include "bSearchTree.h"

using namespace std;

int main() {
	bSearchTreeType<int> tree;
	int length = 16;
	for (int i = 0; i < length; i++)
	{
		tree.insert((i * 7) % length);
	}
	cout << "Preorder Traversal: \t\t\t";
	tree.preorderTraversal();
	cout << "Nonrecursive Preorder Traversal: \t";
	tree.nonrecursivePreTraversal();
	cout << endl;
	cout << "Inorder Traversal: \t\t\t";
	tree.inorderTraversal();
	cout << "Nonrecursive Inorder Traversal: \t";
	tree.nonrecursiveInTraversal();
	cout << endl;
	cout << "Postorder Traversal: \t\t\t";
	tree.postorderTraversal();
	cout << "Nonrecursive Postorder Traversal: \t";
	tree.nonrecursivePostTraversal();
	cout << endl;
	int item = 0;
	cout << "What integer would you like to delete? ";
	cin >> item;
	tree.deleteNode(item);
	cout << "What integer would you like to search for? ";
	cin >> item;
	cout << "Item found: " << (tree.search(item)? "True" : "False") << endl;
	cout << "The trees height is: " << tree.treeHeight() << endl;
	cout << "The trees nodeCount is: " << tree.treeNodeCount() << endl;
	cout << "The trees leafCount is: " << tree.treeLeavesCount() << endl;
	getchar();
	getchar();

}