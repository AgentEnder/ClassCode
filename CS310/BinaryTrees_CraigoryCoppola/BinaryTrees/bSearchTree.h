#pragma once

#include<iostream>
#include<cassert>

#include "binaryTreeType.h"

template<class t>
class bSearchTreeType : public binaryTreeType<t> {
public:
	bool search(const t& item) const;
	void insert(const t& item);
	void deleteNode(const t& item);
private:
	void deleteFromTree(binaryTreeNode<t>* &p);
};

template<class t>
inline bool bSearchTreeType<t>::search(const t & item) const
{
	binaryTreeNode<t> * current = this->root;
	bool found = false;

	if (this->root == nullptr)
	{
		cerr << "You can not search an empty tree!";
	}

	while (!found && current != nullptr)
	{
		if (current->info == item)
		{
			found = true;
		}
		else if (current->info < item)
		{
			current = current->rlink;
		}
		else
		{
			current = current->llink;
		}
	}
	return !(current == nullptr);
}

template<class t>
inline void bSearchTreeType<t>::insert(const t & item)
{
	binaryTreeNode<t> * current = this->root;
	binaryTreeNode<t> * trailCurrent = nullptr;
	binaryTreeNode<t> * newNode = new binaryTreeNode<t>();
	newNode->info = item;
	newNode->llink = nullptr;
	newNode->rlink = nullptr;

	if (current == nullptr)
	{
		this->root = newNode;
	}
	else
	{
		while (current != nullptr)
		{
			trailCurrent = current;
			if (current->info == item)
			{
				cerr << "the insert item is already in the list, duplicates are not allowed @" << item << endl;
				return;
			}
			else if (current->info > item)
			{
				current = current->llink;
			}
			else {
				current = current->rlink;
			}
		}
		if (trailCurrent->info > item)
		{
			trailCurrent->llink = newNode;
		}
		else
		{
			trailCurrent->rlink = newNode;
		}
	}
}

template<class t>
inline void bSearchTreeType<t>::deleteNode(const t & item)
{
	binaryTreeNode<t> * current;
	binaryTreeNode<t> * trailCurrent;
	bool found = false;
	if (this->root == nullptr)
	{
		cerr << "You cannot delete from an empty tree!";
	}
	else
	{
		current = this->root;
		trailCurrent = this->root;

		while (current != nullptr && !found)
		{
			if (current->info == item)
			{
				found = true;
			}
			else
			{
				trailCurrent = current;
				if (current->info > item)
				{
					current = current->llink;
				}
				else
				{
					current = current->rlink;
				}
			}
		}
		if (current == nullptr)
		{
			cerr << "You cannot delete a nonexistant node!" << endl;
			return;
		}
		else
		{
			if (current == this->root)
			{
				deleteFromTree(this->root);
			}
			else if (trailCurrent->info > item)
			{
				deleteFromTree(trailCurrent->llink);
			}
			else
			{
				deleteFromTree(trailCurrent->rlink);
			}
		}
	}
}

template<class t>
inline void bSearchTreeType<t>::deleteFromTree(binaryTreeNode<t>*& p)
{
	binaryTreeNode<t> * current;
	binaryTreeNode<t> * trailCurrent;
	binaryTreeNode<t> * temp;
	if (p == nullptr)
	{
		cerr << "ERROR: the node to be deleted is nullptr!";
	}
	else if (p->llink == nullptr && p->rlink == nullptr)
	{
		temp = p;
		p = nullptr;
		delete temp;
	}
	else if (p->llink == nullptr)
	{
		temp = p;
		p = temp->rlink;
		delete temp;
	}
	else if (p->rlink == nullptr)
	{
		temp = p;
		p = temp->llink;
		delete temp;
	}
	else
	{
		current = p->llink;
		trailCurrent = current;
		while (current->rlink!=nullptr)
		{
			trailCurrent = current;
			current = current->rlink;
		}
		p->info = current->info;
		if (trailCurrent == nullptr)
		{
			p->llink = current->llink;
		}
		else
		{
			trailCurrent->rlink = current->llink;
		}
		delete current;
	}
}
