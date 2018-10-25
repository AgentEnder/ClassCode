#include<iostream>
#include<string>

#include "ArrayList.h"
#include "OrderedListType.h"
#include "LinkedList.h"


using namespace std;
int main() {
	
	LinkedList<int> list = LinkedList<int>();
	ArrayList<int> array_list = ArrayList<int>();
	cout << "Enter 10 numbers!" << endl;
	for (int  i = 0; i < 10; i++)
	{
		int input;
		cin >> input;
		list.push_back(input);
		array_list.insert(input);
	}
	int * listarr = list.as_array(); //Testing as_array
	cout << "TESTING as_array on LinkedList<t>" << endl;
	for (int i = 0; i < list.get_length(); i++)
	{
		cout << listarr[i] << ",";
	}
	cout << endl;

	cout << "Print functions on ArrayList<t> and LinkedList<t>" << endl;
	cout << "LinkedList<t>:";
	list.print(); //Testing print
	cout << "ArrayList<t>:";
	array_list.print();

	cout << "PERFORM SORT NOW" << endl;

	list.insertion_sort();
	array_list.insertionSort();

	cout << "LinkedList<t>:";
	list.print(); //Testing print
	cout << "ArrayList<t>:";
	array_list.print();

	cin.ignore();
	string holder;
	getline(cin, holder);
}