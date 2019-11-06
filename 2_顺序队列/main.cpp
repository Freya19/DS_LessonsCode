#include <iostream>
#include "顺序队列.h"

using namespace std;

int main()
{
	cout << "测试顺序队列" << endl;

	Queue<char> q(5);

	q.Push('A');
	q.Push('B');
	q.Push('C');
	cout << q.Front() << ", " << q.Rear() << endl;
	q.Push('D');
	q.Push('E');
	cout << q.Front() << ", " << q.Rear() << endl;
	//q.Pop();
	//cout << q.Front() << ", " << q.Rear() << endl;
	q.Push('F');
	cout << q.Front() << ", " << q.Rear() << endl;
	q.Push('G');
	cout << q.Front() << ", " << q.Rear() << endl;


	return 0;
}