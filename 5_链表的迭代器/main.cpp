#include <iostream>
#include <list> //C++ STL中的链表
#include "List.h" //我做的链表

using namespace std;

int main()
{
	cout << "测试: " << endl;

	cout << "这是标准C++ STL中的链表和迭代器: " << endl;
	std::list<int> listIntegers;
	listIntegers.push_front(5);
	listIntegers.push_front(15);
	listIntegers.push_front(25);
	listIntegers.push_front(35);

	std::list<int>::iterator i = listIntegers.begin();
	while(i != listIntegers.end())
	{
		cout << *i * 10 << " -> ";
		++i;
	}
	cout <<endl << endl;

	cout << "这是我的链表和迭代器: " << endl;
	List<int> intList;

	intList.Insert(5);
	intList.Insert(15);
	intList.Insert(25);
	intList.Insert(35);
	
	ListIterator<int> li(intList);
	if(li.NotNull())
	{
		cout << *li.First() * 10;
		while(li.NextNotNull())
			cout << " -> " << *li.Next() * 10;
		cout << endl;
	}
	
	return 0;

	intList.Show();

	intList.Invert();
	intList.Show();


	intList.Delete(15);
	intList.Show();

	intList.Delete(20);
	intList.Show();


	List<char> charList;
	charList.Insert('a');
	charList.Insert('b');
	charList.Insert('c');
	charList.Insert('d');
	charList.Show();
	charList.Invert();
	charList.Show();

	List<char> char2List;
	char2List.Insert('e');
	char2List.Insert('f');
	char2List.Show();
	char2List.Invert();
	char2List.Show();

	charList.Concatenate(char2List);
	charList.Show();

	return 0;
}