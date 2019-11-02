// OO_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MapArrayClass.h"
#include "MapArrayClass.cpp"

int main()
{
	MapArray<int, std::string>* Map = new MapArray<int, std::string>(DEFAULT_SIZE);
	for (int i = 0; i < 1000; i++)
	{
		Map->Push(i, "D");
	}
	Map->Pop();
	return 0;
}
