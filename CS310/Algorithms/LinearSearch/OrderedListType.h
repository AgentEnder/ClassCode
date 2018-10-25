#ifndef H_OrderedListType
#define H_OrderedListType

#include <iostream>
#include "ArrayList.h"

using namespace std;

template<class t>
class OrderedArrayList : public ArrayList<t> {
public:
	void insert(const t& item);
	int binarySearch(const t& item) const;
	int seqOrderedSearch(const t& item) const;

	OrderedArrayList(int size = 100);
};

template<class t>
void OrderedArrayList<t>::insert(const t & item)
{
	int first = 0;
	int last = ArrayList<t>::length - 1;
	int mid;

	bool found = false;

	if (this->length == 0)
	{
		this->list[0] = item;
		this->length++;
	}
	else if (this->length == this->maxSize)
	{
		cerr << "Cannot insert into a full list!";
	}
	else
	{
		while (first <= last && !found)
		{
			mid = (first + last) / 2;
			if (this->list[mid] == item)
			{
				found = true;
			}
			else if (this->list[mid] > item)
			{
				last = mid - 1;
			}
			else
			{
				first = mid + 1;
			}
		}
		if (found)
		{
			cerr << "You cannot insert duplicate items!";
		}
		else
		{
			if (ArrayList<t>::list[mid] < item)
			{
				mid++;
			}
			this->insertAt(mid, item);
		}
	}
}

template<class t>
int OrderedArrayList<t>::binarySearch(const t & item) const
{
	int first = 0;
	int last = this->length - 1;
	int mid;

	bool found = false;

	while (first <= last && !found)
	{
		mid = (first + last) / 2;

		if (this->list[mid] == item)
		{
			found = true;
		}
		else if (this->list[mid] > item)
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;
		}
	}
	if (found)
	{
		return mid;
	}
	else
	{
		return -1;
	}
	return 0;
}




template<class t>
int OrderedArrayList<t>::seqOrderedSearch(const t & item) const
{
	int loc;
	bool found = false;
	
	for (loc = 0; loc < this->length; loc++)
	{
		if (this->list[loc] >= item)
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		if (this->list[loc] == item)
		{
			return loc;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}

	return 0;
}

template<class t>
inline OrderedArrayList<t>::OrderedArrayList(int size) : ArrayList<t>(size)
{
}

#endif