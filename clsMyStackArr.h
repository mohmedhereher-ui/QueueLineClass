#pragma once
#include<iostream>
#include"clsMyQueueArr.h"
using namespace std;
template<class T>
class clsMyStackArr : public clsMyQueueArr<T>
{
public:
	void push(T data) {
		clsMyQueueArr<T>::_MyList.InsertAtBeginning(data);
	}
	T Top() {
		return clsMyQueueArr<T>::front();
	}
	T Bottom() {
		return clsMyQueueArr<T>::back();
	}
	void Print() {
		clsMyQueueArr<T>::Print("\nStack element :\n");
		cout << "Top  <---->  Buttom\n";
	}
};

