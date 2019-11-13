// OO_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MapArrayClass.h"
#include "MapArrayClass.cpp"
#include <string>
#include <typeinfo>


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
template<typename T, typename K>
void TestCase(T Key, K Value)
{
	int count = 0;
	std::cout << "Test Case: " << typeid(Key).name() << " " << typeid(Value).name() << std::endl;
	MapArray<T, K>* Map = new MapArray<T, K>(DEFAULT_SIZE);
	std::cout << "Adding " << Key << " and " << Value << " to Map" << std::endl;
	Map->AddKVP(Key, Value);
	std::cout << "Displaying Sorted Map with Iterator" << std::endl;
	typename MapArray<T, K>::Iterator It;
	for (It = Map->Begin(); It != Map->End(); ++It)
	{
		std::cout << "[" << count << "]" << "Key: " << It->Key << std::endl;
		std::cout << "[" << count << "]" << "Value: " << It->Value << std::endl;
		count++;
	}
	std::cout << "CurrentSize: " << Map->CurrentSize() << std::endl;
	if (Map->FindKey(Key))
	{
		std::cout << "KEY FOUND: " << Key << std::endl;
	}
	std::cout << "Getting Value At Key " << Key << " : " << Map->GetValue(Key) << std::endl;
	std::cout << "Removing element with Key: " << Key << std::endl;
	Map->RemoveKVP(Key);
	Map->IsEmpty();
	count = 0;
	Map->~MapArray();
	std::cout << "///////////////////////////////////////////" << std::endl;
}

int main()
{
	int TestI = 50;
	float TestF = 65.654f;
	std::string TestS = "Test";
	char TestC = 'T';
	bool TestB = 0;
	MyObject TestUDC = 20;

	std::cout << "ALL INT TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestCase<int, int>(TestI, TestI);
	TestCase<int, float>(TestI, TestF);
	TestCase<int, string>(TestI, TestS);
	TestCase<int, char>(TestI, TestC);
	TestCase<int, bool>(TestI, TestB);
	TestCase<int, MyObject>(TestI, TestUDC);
	std::cout << "ALL FLOAT TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestCase<float, int>(TestF, TestI);
	TestCase<float, float>(TestF, TestF);
	TestCase<float, string>(TestF, TestS);
	TestCase<float, char>(TestF, TestC);
	TestCase<float, bool>(TestF, TestB);
	TestCase<float, MyObject>(TestF, TestUDC);
	std::cout << "ALL STRING TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestCase<string, int>(TestS, TestI);
	TestCase<string, float>(TestS, TestF);
	TestCase<string, string>(TestS, TestS);
	TestCase<string, char>(TestS, TestC);
	TestCase<string, bool>(TestS, TestB);
	TestCase<string, MyObject>(TestS, TestUDC);
	std::cout << "ALL CHAR TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestCase<char, int>(TestC, TestI);
	TestCase<char, float>(TestC, TestF);
	TestCase<char, string>(TestC, TestS);
	TestCase<char, char>(TestC, TestC);
	TestCase<char, bool>(TestC, TestB);
	TestCase<char, MyObject>(TestC, TestUDC);
	std::cout << "ALL BOOL TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestCase<bool, int>(TestB, TestI);
	TestCase<bool, float>(TestB, TestF);
	TestCase<bool, string>(TestB, TestS);
	TestCase<bool, char>(TestB, TestC);
	TestCase<bool, bool>(TestB, TestB);
	TestCase<bool, MyObject>(TestB, TestUDC);
	std::cout << "ALL USER DEFINED CLASSES TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestCase<MyObject, int>(TestUDC, TestI);
	TestCase<MyObject, float>(TestUDC, TestF);
	TestCase<MyObject, string>(TestUDC, TestS);
	TestCase<MyObject, char>(TestUDC, TestC);
	TestCase<MyObject, bool>(TestUDC, TestB);
	TestCase<MyObject, MyObject>(TestUDC, TestUDC);
	return 0;
}
