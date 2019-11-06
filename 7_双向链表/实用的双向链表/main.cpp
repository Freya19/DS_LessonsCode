#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List<int> myList;

	myList.push_front(20);
	myList.push_front(30);
	myList.push_back(10);

	List<int>::const_iterator iter = myList.begin();
	cout << *iter << endl;
	++iter;
	cout << *iter << endl;
	++iter;
	cout << *iter << endl;

	return 0;
}