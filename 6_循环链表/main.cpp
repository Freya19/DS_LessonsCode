#include <iostream>
#include <list> //C++ STL中的链表
#include "List.h" //我做的链表

using namespace std;

int main()
{
	cout << "测试: " << endl;

	cout << "这是我的链表和迭代器: " << endl;
	List<int> intList;

	intList.Insert(5);
	intList.Insert(15);
	intList.Insert(25);
	intList.Insert(35);
	
	ListIterator<int> li(intList);
	if(li.NotNull())
	{
		cout << *li.First();
		while(li.NextNotNull())
			cout << " -> " << *li.Next();
		cout << endl;
	}

	cout << "测试一下循环：" << endl;
	ListIterator<int> iter(intList);
	cout << *iter.First() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;

	return 0;
}