// 用来测试
#include <iostream>
#include <string>
#include "MyStack.h"

using namespace std;

class Dog
{
};

int main()
{
	MyStack<string> myStringStack;
	MyStack<Dog> dogStack;
	MyStack<int> st;

	st.Push(99);
	st.Push(22);
	st.Push(18);
	st.Push(67);
	cout << st.Top() << endl;
	st.Pop();
	cout << st.Top() << endl;
	st.Pop();
	cout << st.Top() << endl;
	st.Pop();
	cout << st.Top() << endl;


	cout << "TEST!" << endl;
	return 0;
}