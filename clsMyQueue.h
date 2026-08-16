#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
using namespace std;
template<class T>
class clsMyQueue 
{
protected:
	clsDblLinkedList <T>_MyList;
public:
	void push(T data) {
		_MyList.InsertAtEnd(data);
	}
	void pop() {
		_MyList.DeleteFirstNode();
	}
	void Print() {
		cout << "Queue Elements : \n";
		_MyList.PrintList();
	}
	int Size() {
		return _MyList.Size();
	}
	bool IsEmpty() {
		return _MyList.IsEmpty();
	}
	T GetItem(int index) {
		return _MyList.GetItem(index);
	}
	T front() {
		return GetItem(0);
	}
	T back() {
		return GetItem(_MyList.Size()-1);
	}
	void Reverse() {
		_MyList.Reverse();
	}
	bool UpdateItem(int index,T data) {
		return _MyList.UpdateItem(index,data);
	}
	bool InsertAfter(int index, T data) {
		return _MyList.InsertAfter(index, data);
	}
	void InsertAtFront(T data) {
		_MyList.InsertAtBeginning(data);
	}
	void InsertAtBack(T data) {
		_MyList.InsertAtEnd(data);
	}
	void Clear() {
		_MyList.Clear();
	}
};

