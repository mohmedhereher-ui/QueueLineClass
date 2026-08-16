#pragma once
#include<iostream>
#include"clsMyQueue.h"
using namespace std;
template<class T>
class clsMyStack :public clsMyQueue<T>
{
public:
	void push(T data) {
		clsMyQueue<T>::_MyList.InsertAtBeginning(data);
	}
	T Top() {
		return clsMyQueue<T>::front();
	}
	T Bottom() {
		return  clsMyQueue<T>::back();
	}
	void Print() {
		cout << "Stack element : \n";
		cout << "Top  <---->  Buttom\n";
		clsMyQueue<T>::_MyList.PrintList();
	}
};

