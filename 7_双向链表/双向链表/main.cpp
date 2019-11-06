#include <iostream>

using namespace std;

class DblList; //前置声明

class DblListNode 
{
	friend class DblList;
public:
	int data;
	DblListNode *llink, *rlink;
};

class DblList
{
public:
	DblList() 
	{
		first = new DblListNode();
		first->llink = first->rlink = first;
	}
	void Insert(DblListNode*, DblListNode*);
	void Delete(DblListNode*);
//private:
public:
	DblListNode *first;
};

void DblList::Insert(DblListNode *p, DblListNode *x)
{
	p->llink = x;
	p->rlink = x->rlink;
	x->rlink->llink = p;
	x->rlink = p;
}

void DblList::Delete(DblListNode *x)
{
	if(x == first) 
		cerr << "Deletion of head node not permitted." << endl;
	else
	{
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
		delete x;
	}
}

int main()
{
	cout << "Hello 双向链表!" << endl;

	DblList intList;
	DblListNode *node1, *node2, *node3, *node4, *node5;
	node1 = new DblListNode();
	node2 = new DblListNode();
	node3 = new DblListNode();
	node4 = new DblListNode();
	node5 = new DblListNode();
	node1->data = 10;
	node2->data = 20;
	node3->data = 30;
	node4->data = 40;
	node5->data = 50;

	intList.Insert(node1,intList.first);
	intList.Insert(node2,intList.first);
	intList.Insert(node3,intList.first);
	intList.Insert(node4,intList.first);
	intList.Insert(node5,intList.first);
	intList.Delete(node4);

	cout << intList.first->rlink->data << endl;
	cout << intList.first->rlink->rlink->data << endl;
	cout << intList.first->rlink->rlink->rlink->data << endl;
	cout << intList.first->rlink->rlink->rlink->rlink->data << endl;	
	cout << intList.first->rlink->rlink->rlink->rlink->llink->data << endl;	
	cout << intList.first->rlink->rlink->rlink->rlink->llink->llink->data << endl;	
	return 0;
}