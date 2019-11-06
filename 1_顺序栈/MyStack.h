#ifndef _MYSTACK_H
#define _MYSTACK_H
#include<algorithm>

#include "MyUtil.h"

template<class T>
class MyStack
{
public:
	MyStack(int stackCapacity=10);
	~MyStack();

	bool IsEmpty() const;
	T& Top() const;					//top是要显示出来最上面的数据的,所以它有返回值,而返回什么跟它的数据类型(T)有关,所以是 T
	void Push(const T& item);
	void Pop();						//pop只弹出最上面的数据,但是不需要返回呀,所以void
private:
	T *stack;
	int top;
	int capacity;
};

template<class T>
void MyStack<T>::Pop()
{
	if(IsEmpty()) throw "Stack is empty. Cannot delete.";
	stack[top--].~T();
}

template<class T>
inline bool MyStack<T>::IsEmpty() const  //inline -- 内联函数.一个非常简单的函数(所含的代码很少),但是要调用很多次,
										 //为了减少每次调用所消耗的时间(调用过程很复杂的,就很费时间),使用内联函数(就是调用函数时),
										 //相当于把这个内联函数内部的函数体重写到该调用位置直接使用,通过增加代码体积来减少消耗时间
										 //不过, 有时候也是不能用的,何时不能用嘞?  那何时应该用呢?
{
	return top == -1;
}

template<class T>
inline T& MyStack<T>::Top() const
{
	if(IsEmpty()) throw "Stack is empty";
	return stack[top]; //返回栈最上面的元素(数据)
}

//创建栈-----构造函数 ? ? ?
template<class T>
MyStack<T>::MyStack(int stackCapacity):capacity(stackCapacity)
{
	if(capacity < 1) throw "stack capacity must be > 0";
	stack = new T[capacity]; //利用new开辟(创建)一个新数组
	top = -1; //并且它的top指向-1的位置(初始没有数据的时候,top指向-1)
}

template<class T>
MyStack<T>::~MyStack()
{
	delete[] stack; //删除了上面new的stack
}

template<class T>
void MyStack<T>::Push(const T& item)
{
	if(top == capacity-1)   //满了
	{
		ChangeSize1D(stack, capacity, 2*capacity);
		capacity *= 2;
	}
	stack[++top] = item;
}

#endif