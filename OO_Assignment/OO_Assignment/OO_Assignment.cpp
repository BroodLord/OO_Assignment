// OO_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MapArrayClass.h"
#include "MapArrayClass.cpp"


class MyObject
{

	int ma;
public:
	MyObject()
	{

	}
	MyObject(int a) : ma(a)
	{

	}
	bool operator < (MyObject const& obj)
	{
		return ma < obj.ma;
	}
};


int main()
{
	MapArray<MyObject, int>* Map = new MapArray<MyObject, int>(DEFAULT_SIZE);
	for (int i = 0; i < 10; i++)
	{
		MyObject o1(i);
		Map->AddKVP(o1, i);
	}
	Map->RemoveKVP(5);
	return 0;
}
