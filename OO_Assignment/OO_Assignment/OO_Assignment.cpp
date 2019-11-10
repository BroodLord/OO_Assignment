// OO_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MapArrayClass.h"
#include "MapArrayClass.cpp"
#include <string>


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
	MapArray<int, std::string>* Map = new MapArray<int, std::string>(DEFAULT_SIZE);
	for (int i = 0; i < 10; i++)
	{
		Map->AddKVP(i, "Danny");
	}
	Map->RemoveKVP(5);
	MapArray<int, std::string>::Iterator It;
	int count = 0;
	for(It = Map->Begin(); It != Map->End(); ++It)
	{
		std::cout <<"[" << count << "]" << " Key: " << It->Key  << std::endl;
		std::cout << "[" << count << "]" << " Value: " << It->Value << std::endl;
		count++;
	}

	return 0;
}
