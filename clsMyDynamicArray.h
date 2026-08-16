#pragma once
#include <iostream>
using namespace std;
template<class T>
class clsMyDynamicArray
{
private:
	int _Size;
	T* _TempArray;
public:
	T* OriginalArray;
	clsMyDynamicArray(int size=0) {
		if (size < 0) {
			size = 0;
		}
		_Size = size;
		OriginalArray = new T[size];
	}
	~clsMyDynamicArray() {
		delete[] OriginalArray;
	}
	void PrintList() {
		cout << "\nArray Items :\n";
		for (int i = 0; _Size > i;i++) {
			cout << OriginalArray[i] << " ";
		}
		cout << endl;
	}
	bool SetItem(int index,T value) {
		if ((index >= _Size) || (index< 0)) {
			return false;
		}
		OriginalArray[index] = value;
		return true;
	}
	bool IsEmpty() {
		return (_Size == 0);
	}
	int Size() {
		return _Size;
	}
	void Resize(int new_size) {
		if (new_size < 0) {
			new_size = 0;
		}
		_TempArray = new T[new_size];
		if (new_size < _Size) {
			_Size = new_size;
		}
		for (int i = 0; _Size > i; i++) {
			_TempArray[i] = OriginalArray[i];
		}
		_Size = new_size;
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}
	T GetItem(int index) {
		if (index<0||index>=_Size) {
			index = 0;
		}
		return OriginalArray[index];
	}
	void Clear() {
		delete[] OriginalArray;
		OriginalArray = new T[0];
		_Size = 0;
	}
	void Reverse() {
		_TempArray = new T[_Size];
		for (int i = 0;_Size> i; i++) {
			_TempArray[i] = OriginalArray[_Size - 1 - i];
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}
	bool DeleteItemAtIndex(int index) {
		if (index<0||index>=_Size) {
			return false;
		}
		_TempArray = new T[_Size-1];
		int counter = 0;
		for (int i = 0; _Size > i; i++) {
			if (index==i) {
				continue;
			}
			_TempArray[counter] = OriginalArray[i];
			counter++;
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		_Size -= 1;
		return true;
	}
	bool DeletFirstItem() {
		return DeleteItemAtIndex(0);
	}
	bool DeletLastItem() {
		return DeleteItemAtIndex(_Size-1);
	}
	int Find(T data) {
		for (int i = 0; _Size > i; i++) {
			if (OriginalArray[i] == data) {
				return i;
			}
		}
		return -1;
	}
	bool DeleteItem(T data) {
		int index = Find(data);
		return DeleteItemAtIndex(index);
	}
	bool InsertItemAtIndex(int index,T data) {
		if (index < 0 || index > _Size) {
			return false;
		}
		_TempArray = new T[_Size + 1];
		int counter = 0;
		for (int i = 0; _Size >= i; i++) {
			if (index == i) {
				_TempArray[i] = data;
				continue;
			}
			_TempArray[i] = OriginalArray[counter];
			counter++;
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		_Size += 1;
		return true;
	}
	bool InsertAtBeginning(T data) {
		return InsertItemAtIndex(0, data);
	}
	bool InsertBefore(int index,T data) {
		if (index < 1)
			return InsertItemAtIndex(0, data);
		else
			return InsertItemAtIndex(index - 1, data);
	}
	bool InsertAfter(int index,T data) {
		return InsertItemAtIndex(index+1, data);
	}
	bool InsertAtEnd(T data) {
		return InsertItemAtIndex(_Size, data);
	}
	bool UpdateItem(int index,T new_data) {
		if (index < 0 || index >= _Size) {
			return false;
		}
		OriginalArray[index] = new_data;
		return true;
	}
};

