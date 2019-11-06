#include <iostream>
#include "ThreeLetterList.h"

using namespace std;

class NodeB;

class NodeA
{
private:
	int data1; //三个数据域
	char data2;
	float data3;

	NodeA *linka;
	NodeB *linkb;
};

class NodeB
{
private:
	int data;
	NodeB *link;
};

class List;

class Node //节点
{
friend class List; //友元类
private:
	int data; //节点里的数据
	Node* link; //指向下一个节点的指针
};

class List //链表
{
public:
	void test();
	void show();
private:
	Node* first;//指向第一个节点的指针
};

void List::show()
{
	cout << first->data << " -> "
		<< first->link->data << " -> "
		<< first->link->link->data << endl;
}

void List::test()
{
	Node *f = new Node();
	f->data = 44;
	f->link = 0;

	first = f;

	f = new Node();
	f->data = 72;
	f->link = 0;

	first->link = f;

	f = new Node();
	f->data = 210;
	f->link = 0;

	first->link->link = f;
}

int main()
{
	List a;
	a.test(); //创建三个节点
	a.show();


	ThreeLetterList l;
	l.test();
	l.show();

	return 0;
}