#pragma once
#include<iostream>
#include"clsMyStack.h"
class clsMyString
{
private:
	clsMyStack<string>_Undo;
	clsMyStack<string>_Redo;
	string _Value;
public:
	void SetValue(string value) {
		_Value = value;
		_Redo.push(_Value);
	}
	string GetValue() {
		return _Value;
	}
	__declspec(property(put= SetValue,get= GetValue))string Value;
	void Undo() {//ctrl z
		if (_Redo.Size()<=1) {
			cout << "Nothing to undo!\n";
			return;
		}
		_Undo.push(_Value);
		_Redo.pop();
		_Value = _Redo.Top();
	}
	void Redo() {//ctrl y
		if (_Undo.IsEmpty()) {
			cout << "Nothing to redo!\n";
			return;
		}
		_Redo.push(_Undo.Top());
		_Undo.pop();
		_Value = _Redo.Top();
	}
};

