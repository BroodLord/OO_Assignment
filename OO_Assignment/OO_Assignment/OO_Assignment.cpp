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
	friend ostream& operator<<(ostream& os, const MyObject& obj)
	{
		os << obj.ma;
		return os;
	}
};


void TestCaseInt()
{
	int Test = 420;
	string Test2 = "Alex";
	std::cout << "Test Case: Int, String" << std::endl;
	MapArray<int, std::string>* Map = new MapArray<int, std::string>(DEFAULT_SIZE);
	std::cout << "Adding " << Test << " and " << Test2 << " to Map" << std::endl;
	Map->AddKVP(Test, Test2);
	for (MapArray<int, std::string>::Iterator It = Map->Begin(); It != Map->End(); ++It)
	{
		std::cout << "Key: " << It->Key << std::endl;
		std::cout << "Value: " << It->Value << std::endl;
	}
	if (Map->FindKey(Test))
	{
		std::cout << "KEY FOUND: " << Test << std::endl;
	}
	std::cout << "Getting Value At Key " << Test << " : " << Map->GetValue(Test) << std::endl;
	std::cout << "Removing element with Key: " << Test << std::endl;
	Map->RemoveKVP(Test);
	Map->IsEmpty();
	std::cout << "Adding Generic Data" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Map->AddKVP(i, "Da");
	}
	std::cout << "Displaying Sorted Map with Iterator" << std::endl;
	int count = 0;
	for (MapArray<int, std::string>::Iterator It = Map->Begin(); It != Map->End(); ++It)
	{
		std::cout << "[" << count << "]" << " Key: " << It->Key << std::endl;
		std::cout << "[" << count << "]" << " Value: " << It->Value << std::endl;
		count++;
	}
	Map->~MapArray();
	std::cout << "///////////////////////////////////////////" << std::endl;
	//float TestF2 = 32.43536f;
	//std::cout << "Test Case: Int, Float" << std::endl;
	//MapArray<int, float>* Map2 = new MapArray<int, float>(DEFAULT_SIZE);
	//std::cout << "Adding " << Test << " and " << TestF2 << " to Map" << std::endl;
	//Map2->AddKVP(Test, TestF2);
	//for (MapArray<int, float>::Iterator It = Map2->Begin(); It != Map2->End(); ++It)
	//{
	//	std::cout << "Key: " << It->Key << std::endl;
	//	std::cout << "Value: " << It->Value << std::endl;
	//}
	//if (Map->FindKey(Test))
	//{
	//	std::cout << "KEY FOUND: " << Test << std::endl;
	//}
	//std::cout << "Getting Value At Key " << Test << " : " << Map2->GetValue(Test) << std::endl;
	//std::cout << "Removing element with Key: " << Test << std::endl;
	//Map2->RemoveKVP(Test);
	//Map2->IsEmpty();
	//std::cout << "Adding Generic Data" << std::endl;
	//for (int i = 0; i < 10; i++)
	//{
	//	Map2->AddKVP(i, 43.4356f);
	//}
	//std::cout << "Displaying Sorted Map with Iterator" << std::endl;
	//count = 0;
	//for (MapArray<int, float>::Iterator It = Map2->Begin(); It != Map2->End(); ++It)
	//{
	//	std::cout << "[" << count << "]" << " Key: " << It->Key << std::endl;
	//	std::cout << "[" << count << "]" << " Value: " << It->Value << std::endl;
	//	count++;
	//}
	//std::cout << "///////////////////////////////////////////" << std::endl;
}
void TestCaseString()
{

}
void TestCaseChar()
{

}
void TestCaseFloat()
{

}
void TestCaseDouble()
{

}
void TestCaseUDC()
{

}

int main()
{
	//MapArray<MyObject, std::string>* Map = new MapArray<MyObject, std::string>(DEFAULT_SIZE);
	//for (int i = 0; i < 11; i++)
	//{
	//	MyObject o1(i);
	//	Map->AddKVP(o1, "Danny");
	//}
	//int count = 0;
	//for(MapArray<MyObject, std::string>::Iterator It = Map->Begin(); It != Map->End(); ++It)
	//{
	//	std::cout << "[" << count << "]" << " Key: " << It->Key << std::endl;
	//	std::cout << "[" << count << "]" << " Value: " << It->Value << std::endl;
	//	count++;
	//}
	TestCaseInt();

	return 0;
}
