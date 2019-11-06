#ifndef _MYUTIL_H
#define _MYUTIL_H

//构造一个能够放大数组的函数 ======> C++中为什么要使用模板: 建立通用的模板, 大大提高复用性
template<class T>
void ChangeSize1D(T* &a, const int oldSize, const int newSize);

template<class T>
void ChangeSize1D(T* &a, const int oldSize, const int newSize)
{
	if(newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize]; //开辟新的数组,大小为newsize大小,类型为T,temp这个指针指向这个数组
	int number = min(oldSize, newSize);   //个数,可以放大可以缩小
	std::copy(a,a+number, temp);  //利用C++自带的copy函数将原数组数据一个个拷贝过来
	delete[] a;
	a=temp;
}

#endif