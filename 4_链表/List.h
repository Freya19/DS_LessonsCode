#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class Type> class List;

template<class Type>
class ListNode
{
friend class List<Type>;

private:
	Type data;
	ListNode *link;
	ListNode(Type);
};


template<class Type>
class List
{
public:
	List() { first = 0; };
	void Insert(Type);
	void Delete(Type);
	void Invert();
	void Concatenate(List<Type>);
	void Show();//测试用的
private:
	ListNode<Type> *first;
};

template<class Type>
ListNode<Type>::ListNode(Type element)
{
	data = element;
	link = 0;
}

template<class Type>
void List<Type>::Insert(Type k)
{
	ListNode<Type> *newnode = new ListNode<Type>(k);
	newnode->link = first;
	first = newnode;
}

template<class Type>
void List<Type>::Delete(Type k)
{
	ListNode<Type> *previous = 0; //前一个
	ListNode<Type> *current;
	for(current = first; 
		current && current->data != k; 
		previous = current, current = current->link)
	{
		; //什么都不做，空循环，找到要被删除的节点
	}
	
	if(current)
	{
		if(previous) previous->link = current->link;
		else first = first->link;
		delete current;
	}
	
}

template<class Type>
void List<Type>::Invert()
{
	ListNode<Type> *p = first, *q = 0;
	while(p)
	{
		ListNode<Type> *r = q; q = p;
		p = p->link;
		q->link = r;
	}
	first = q;
}

template<class Type>
void List<Type>::Concatenate(List<Type> b)
{
	if(!first) { first = b.first; return; }
	if(b.first)
	{
		ListNode<Type> *p;
		for(p=first; p->link; p=p->link) ; //空循环
		p->link = b.first;
	}
}

template<class Type>
void List<Type>::Show()
{
	for(ListNode<Type> *current = first; current; current = current->link)
	{
		std::cout << current->data;
		if(current->link) std::cout << " -> ";
	}
	std::cout << std::endl;
}

#endif