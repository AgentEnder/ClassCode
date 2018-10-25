#pragma once

#include <iostream>
#include "MyStack.h"

template<class t>
struct binaryTreeNode {
	t info;
	binaryTreeNode<t> * llink;
	binaryTreeNode<t> * rlink;
};

template<class t>
class binaryTreeType {
public:
	const binaryTreeType<t>& operator= (const binaryTreeType<t>& other);
	bool isEmpty() const;
	void inorderTraversal();
	void nonrecursivePreTraversal();
	void nonrecursiveInTraversal();
	void nonrecursivePostTraversal();
	void preorderTraversal();
	void postorderTraversal();
	int treeHeight() const;
	int treeNodeCount();
	int treeLeavesCount();
	void destroyTree();

	binaryTreeType(const binaryTreeType<t>& otherTree);
	binaryTreeType();
	~binaryTreeType();

protected:
	binaryTreeNode<t> * root;

private:
	void copyTree(binaryTreeNode<t> * &copiedTreeRoot, binaryTreeNode<t> * otherTreeRoot);
	void destroy(binaryTreeNode<t>* &p);
	void inorder(binaryTreeNode<t> *p) const;
	void preorder(binaryTreeNode<t> *p) const;
	void postorder(binaryTreeNode<t> *p) const;
	int height(binaryTreeNode<t> *p) const;
	int max(int x, int y) const;
	int nodeCount(binaryTreeNode<t> *p) const;
	int leavesCount(binaryTreeNode<t> *p) const;
};

template<class t>
int binaryTreeType<t>::max(int x, int y) const {
	return (x > y ? x : y);
}

template<class t>
inline int binaryTreeType<t>::nodeCount(binaryTreeNode<t>* p) const
{
	if (p == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
	}
}

template<class t>
inline int binaryTreeType<t>::leavesCount(binaryTreeNode<t>* p) const
{
	if (p == nullptr)
	{
		return 0;
	}
	else if (p->llink != nullptr || p->rlink != nullptr) //1+ subtrees exist
	{
		return leavesCount(p->llink) + leavesCount(p->rlink);
	}
	else
	{
		return 1;
	}
}

template<class t>
inline binaryTreeType<t>::binaryTreeType(const binaryTreeType<t>& otherTree)
{
	if (otherTree.root == nullptr)
	{
		root = nullptr;
	}
	else {
		copyTree(root, otherTree.root);
	}
}

template<class t>
inline binaryTreeType<t>::binaryTreeType()
{
	root = nullptr;
}

template<class t>
inline binaryTreeType<t>::~binaryTreeType()
{
	destroy(root);
}

template<class t>
inline const binaryTreeType<t>& binaryTreeType<t>::operator=(const binaryTreeType<t>& other)
{
	if (this != &other)
	{
		if (root != nullptr)
		{
			destroy(root);
		}
		else {
			if (otherTree.root == nullptr)
			{
				root = nullptr
			}
			else {
				copyTree(root, otherTree.root);
			}
		}
	}
	return *this;
}

template<class t>
inline bool binaryTreeType<t>::isEmpty() const
{
	return root == nullptr;
}

template<class t>
inline void binaryTreeType<t>::inorderTraversal()
{
	cout << "[";
	inorder(root);
	cout << "]" << endl;
}

template<class t>
inline void binaryTreeType<t>::nonrecursivePreTraversal()
{
	MyStack<binaryTreeNode<t>*> stack;
	binaryTreeNode<t> * current = root;
	cout << "[";
	while (current != nullptr || !stack.isEmptyStack())
	{
		if (current != nullptr)
		{
			stack.push(current);
			cout << current->info << ",";
			current = current->llink;
		}
		else
		{
			current = stack.top();
			stack.pop();
			current = current->rlink;
		}
	}
	cout << "]" << endl;

}


template<class t>
inline void binaryTreeType<t>::nonrecursiveInTraversal()
{
	MyStack<binaryTreeNode<t>*> stack;
	binaryTreeNode<t> * current = root;

	cout << "[";

	while (current != nullptr || !stack.isEmptyStack())
	{
		if (current != nullptr)
		{
			stack.push(current);
			current = current->llink;
		}
		else
		{
			current = stack.top();
			stack.pop();
			cout << current->info << ",";
			current = current->rlink;
		}
	}
	cout << "]" << endl;
}

template<class t>
inline void binaryTreeType<t>::nonrecursivePostTraversal()
{
	MyStack<binaryTreeNode<t>*> nodeStack;
	MyStack<int> intStack;
	int v = 0;
	binaryTreeNode<t> * current = root;

	cout << "[";

	if (current == nullptr)
	{
		cout << "Empty Tree";//Empty Tree
	}
	else
	{
		nodeStack.push(current);
		intStack.push(1);
		current = current->llink;
		while (!nodeStack.isEmptyStack())
		{
			if (current != nullptr and v == 0)
			{
				nodeStack.push(current);
				intStack.push(1);
				current = current->llink;
			}
			else
			{
				current = nodeStack.top();
				nodeStack.pop();
				v = intStack.top();
				intStack.pop();
				if (v == 1)
				{
					nodeStack.push(current);
					intStack.push(2);
					current = current->rlink;
					v = 0;
				}
				else
				{
					cout << current->info << ",";
				}
			}
		}
	}
	cout << "]" << endl;
}

template<class t>
inline void binaryTreeType<t>::preorderTraversal()
{
	cout << "[";
	preorder(root);
	cout << "]" << endl;
}

template<class t>
inline void binaryTreeType<t>::postorderTraversal()
{
	cout << "[";
	postorder(root);
	cout << "]" << endl;
}

template<class t>
inline int binaryTreeType<t>::treeHeight() const
{
	return height(root);
}

template<class t>
inline int binaryTreeType<t>::treeNodeCount()
{
	return nodeCount(root);
}

template<class t>
inline int binaryTreeType<t>::treeLeavesCount()
{
	return leavesCount(root);
}

template<class t>
inline void binaryTreeType<t>::destroyTree()
{
	destroy(root);
}

template<class t>
inline void binaryTreeType<t>::copyTree(binaryTreeNode<t>*& copiedTreeRoot, binaryTreeNode<t>* otherTreeRoot)
{
	if (otherTreeRoot == nullptr)
	{
		copiedTreeRoot = nullptr;
	}
	else
	{
		copiedTreeRoot = new binaryTreeNode<t>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
}

template<class t>
inline void binaryTreeType<t>::destroy(binaryTreeNode<t>*& p)
{
	if (p != nullptr)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = nullptr;
	}
}

template<class t>
inline void binaryTreeType<t>::inorder(binaryTreeNode<t>* p) const
{
	if (p != nullptr)
	{
		inorder(p->llink);
		cout << p->info << ",";
		inorder(p->rlink);
	}
}

template<class t>
inline void binaryTreeType<t>::preorder(binaryTreeNode<t>* p) const
{
	if (p != nullptr)
	{
		cout << p->info << ",";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template<class t>
inline void binaryTreeType<t>::postorder(binaryTreeNode<t>* p) const
{
	if (p != nullptr)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << ",";
	}
}

template<class t>
inline int binaryTreeType<t>::height(binaryTreeNode<t>* p) const
{
	if (p == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + max(height(p->llink), height(p->rlink));
	}
}
