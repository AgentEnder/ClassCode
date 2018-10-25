#ifndef H_ArrayListType
#define H_ArrayListType

#include<iostream>
#include<cassert>
#include<cstdlib>
#include<ctime>

template<class t>
class ArrayList {
public:
	const ArrayList<t>& operator=(const ArrayList<t>&);
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int getMaxSize() const;
	void print() const;
	bool isItemAtEqual(int location, const t & item);
	void insertAt(int location, const t& item);
	void insertEnd(const t& item);
	void removeAt(int location);
	void retrieveAt(int location, t& outItem);
	void replaceAt(int location, const t& item);
	void clearList();
	void insert(const t& item);
	void remove(const t& item);

	void shuffle();

	int seqSearch(const t& item) const;
	void selectionSort();
	void insertionSort();
	void insertionSort(int begin, int end);

	ArrayList(int size = 100);
	ArrayList(const ArrayList<t>& otherList);
	~ArrayList();

protected:
	int minLocation(int first, int last);
	void swap(int first, int second);


	t * list;
	int length;
	int maxSize;
};

template<class t>
const ArrayList<t>& ArrayList<t>::operator=(const ArrayList<t>& other)
{
	if (this != &other) {
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;
		list = new t[length];
		assert(list != null);

		for (int i = 0; i < length; i++)
		{
			list[i] = other.list[i]
		}
	}
	return *this;
	// TODO: insert return statement here
}

template<class t>
bool ArrayList<t>::isEmpty() const
{
	return length == 0;
}

template<class t>
bool ArrayList<t>::isFull() const
{
	return length == maxSize;
}

template<class t>
int ArrayList<t>::listSize() const
{
	return length;
}

template<class t>
int ArrayList<t>::getMaxSize() const
{
	return maxSize;
}

template<class t>
void ArrayList<t>::print() const
{
	cout << "[";
	for (int i = 0; i < length; i++)
	{
		std::cout << list[i] << ",";
	}
	cout << "]" << endl;
	return;
}

template<class t>
bool ArrayList<t>::isItemAtEqual(int location, const t & item)
{
	return list[location] == item;
}

template<class t>
void ArrayList<t>::insertAt(int location, const t & item)
{
	if (location < 0 || location >= maxSize) {
		cerr << "The position to insert the item is out of bounds." << endl;
	}
	else if (length >= maxSize) {
		cerr << "The ArrayList is full!" << endl;
	}
	else {
		for (int i = length; i > location; i--)
		{
			list[i] = list[i - 1];
		}
		list[location] = item;
		length++;
	}
}

template<class t>
void ArrayList<t>::insertEnd(const t & item)
{
	if (length >= maxSize) {
		cerr << "You cannot insert an item to a full list!";
	}
	else {
		list[length] = item;
		length++;
	}
}

template<class t>
void ArrayList<t>::removeAt(int location)
{
	if (location < 0 || location >= length) {
		cerr << "The item is out of range!";
	}
	else {
		for (int i = location; i < length; i++)
		{
			list[i] = list[i + 1];
		}
		length--;
	}
}

template<class t>
void ArrayList<t>::retrieveAt(int location, t & outItem)
{
	if (location < 0 || location >= length) {
		cerr << "The location is out of bounds!" << endl;
	}
	else {
		outItem = list[location]
	}
}

template<class t>
void ArrayList<t>::replaceAt(int location, const t & item)
{
	if (location < 0 || location >= length) {
		cerr << "Location out of bounds!";
	}
	else {
		list[location] = item;
	}
}

template<class t>
void ArrayList<t>::clearList()
{
	length = 0;
}

template<class t>
int ArrayList<t>::seqSearch(const t & item) const
{
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
			return i;
	}
	return -1;
}

template<class t>
void ArrayList<t>::selectionSort()
{
	for (int i = 0; i < length; i++)
	{
		int minIdx = minLocation(i, length - 1);
		swap(i, minIdx);
	}
}

template<class t>
void ArrayList<t>::insertionSort()
{
	for (int i = 1; i < length; i++)
	{
		if (list[i] < list[i - 1])
		{
			//OUT OF ORDER ELEMENT
			t temp = list[i];
			int location = i;

			do
			{
				list[location] = list[location - 1];
				location--;
			} while (location > 0 && list[location - 1] > temp);
			list[location] = temp;
		}
	}
}

template<class t>
void ArrayList<t>::insertionSort(int begin, int end)
{
	for (int i = begin + 1; i < end; i++)
	{
		if (list[i] < list[i - 1])
		{
			//OUT OF ORDER ELEMENT
			t temp = list[i];
			int location = i;

			do
			{
				list[location] = list[location - 1];
				location--;
			} while (location > 0 && list[location - 1] > temp);
			list[location] = temp;
		}
	}
}

template<class t>
void ArrayList<t>::insert(const t & item)
{
	if (length == 0) {
		list[length++] = item;
	}
	else if (length == maxSize) {
		cerr << "Cannot insert into a full list";
	}
	else {
		int loc = seqSearch(item);
		if (loc != -1) {
			cerr << "Cannot insert duplicates!";
		}
		else {
			list[length++] = item;
		}
	}
}

template<class t>
void ArrayList<t>::remove(const t & item)
{
	int loc;
	if (length == 0) {
		cerr << "Cannot remove from empty list" << endl;
	}
	else {
		loc = seqSearch(item)
			if (loc != -1) {
				removeAt(loc);
			}
			else {
				cout << "The item to be deleted is not in the list!";
			}
	}
}

template<class t>
void ArrayList<t>::shuffle()
{

	for (int i = 0; i < length; i++)
	{
		swap(rand() % length, rand() % length);
	}

}

template<class t>
ArrayList<t>::ArrayList(int size)
{
	if (size <= 0) {
		size = 100;
	}
	maxSize = size;
	length = 0;
	list = new t[maxSize];
	assert(list != NULL);
	srand((int)time(0));
}

template<class t>
ArrayList<t>::ArrayList(const ArrayList<t>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new t[maxSize];
	assert(list != NULL);
	for (int i = 0; i < length; i++)
	{
		list[i] = otherList[i];
	}
}

template<class t>
ArrayList<t>::~ArrayList()
{
	delete[] list;
}

template<class t>
int ArrayList<t>::minLocation(int first, int last)
{
	int minLocation = first;
	for (int i = first; i <= last; i++)
	{
		if (list[i] < list[minLocation]) {
			minLocation = i;
		}
	}
	return minLocation;
}

template<class t>
void ArrayList<t>::swap(int first, int second)
{
	t temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}

#endif