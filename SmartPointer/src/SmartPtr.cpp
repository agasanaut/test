//============================================================================
// Name        : SmartPtr.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<class T>
class SmartPtr
{
	T* ptr;
public:
	SmartPtr(T* p):ptr(p){}
	~SmartPtr(){}

	T& operator*(){return *ptr;};
	T* operator->(){return ptr;};

};
int main() {

SmartPtr<int>ptr(new int(4));

cout<<*ptr;

	return 0;
}
