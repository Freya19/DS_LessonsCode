#include <iostream>
#include "LinkedStack.h"

using namespace std;

int main()
{
	cout << "测试链式栈" << endl;

	LinkedStack<int> s;

	s.Push(10);
	cout << s.Top() << endl;
	s.Push(20);
	cout << s.Top() << endl;
	s.Push(30);
	cout << s.Top() << endl;

	s.Pop();
	cout << s.Top() << endl;
	return 0;
}