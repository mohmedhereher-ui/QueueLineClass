#pragma once
#include<iostream>
#include"clsMyDynamicArray.h"
using namespace std;
template<class T>
class clsMyQueueArr
{
protected:
	clsMyDynamicArray <T>_MyList;
public:
	void push(T data) {
		_MyList.InsertAtEnd(data);
	}
	void pop() {
		_MyList.DeletFirstItem();
	}
	void Print(string text= "Queue Elements : \n") {
		cout << text;
		for (int i = 0; _MyList.Size() > i; i++) {
			cout << _MyList.OriginalArray[i] << " ";
		}
		cout << endl;
	}
	int Size() {
		return _MyList.Size();
	}
	bool IsImpty() {
		return _MyList.IsEmpty();
	}
	T GetItem(int index) {
		return _MyList.GetItem(index);
	}
	T front() {
		return _MyList.GetItem(0);
	}
	T back() {
		return _MyList.GetItem(_MyList.Size() - 1);
	}
	void Reverse() {
		_MyList.Reverse();
	}
	bool UpdateItem(int index, T data) {
		return _MyList.UpdateItem(index, data);
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
	bool DeleteFirstItem() {
		_MyList.DeletFirstItem();
	}
	bool DeleteLastItem() {
		_MyList.DeletLastItem();
	}
};

