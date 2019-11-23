// OO_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "MapArrayClass.h"
#include "MapArrayClass.cpp"
#include <string>
#include <typeinfo>

/* This is class which is used for testing*/
class MyObject
{

	int TestInt;
public:
	MyObject(){}
	MyObject(int a) : TestInt(a){}

	/*The user has to provide these two function as this will allow them to compare and use the iterator*/
	bool operator < (MyObject const& obj)
	{
		/*Compares*/
		return TestInt < obj.TestInt;
	}
	friend std::ostream& operator<<(std::ostream& os, const MyObject& obj)
	{
		/*Allows for class output to console window*/
		os << obj.TestInt;
		return os;
	}
};

/*This function is a generic function, this will allow me to pass any two arrays of any data type and test them
  This runs through all my public test cases and it will even test my private functions
  This allows me to have it all in one function so multiple lines of code don't need to be copied*/
template<typename T, typename K>
void TestInterfaceMethods(T Key[], K Value[])
{
	int count = 0;
	std::cout << "Test Case: " << typeid(Key[0]).name() << " " << typeid(Value[0]).name() << std::endl;
	MapArray<T, K>* Map = new MapArray<T, K>();
	std::cout << "Adding elements to the Map" << std::endl;
	for (int i = 0; i < 26; i++)
	{
		Map->AddKVP(Key[i], Value[i]);
	}
	std::cout << "Is The Map Empty: " << Map->IsEmpty() << std::endl;
	std::cout << "Displaying Sorted Map with Iterator" << std::endl;
	typename MapArray<T, K>::Iterator It;
	for (It = Map->Begin(); It != Map->End(); ++It)
	{
		std::cout << "[" << count << "]" << "Key: " << It->Key << " ," <<  " Value: " << It->Value << std::endl;
		count++;
	}
	std::cout << "CurrentSize: " << Map->CurrentSize() << std::endl;
	std::cout << "Trying to find Key: " << Key[8] << std::endl;
	std::cout << "Is the Key already in the Map: " << Map->FindKey(Key[8]) << std::endl;
	std::cout << "Getting Value At Key " << Key[12] << " : " << Map->GetValue(Key[12]) << std::endl;
	std::cout << "Removing element with Key: " << Key[17] << std::endl;
	Map->RemoveKVP(Key[2]);
	std::cout << "CLEARING MAP" << std::endl;
	Map->Clear();
	std::cout << "CurrentSize: " << Map->CurrentSize() << std::endl;
	count = 0;
	std::cout << "Is The Map Empty: " << Map->IsEmpty() << std::endl;
	delete (Map);
	Map = NULL;
	std::cout << "///////////////////////////////////////////" << std::endl;
}

/*Random Datat that will be used when it comes to testing*/
static int TestI[26] = { 90, 9, 97, 89, 36, 75, 51, 95, 12, 23, 91, 64, 40, 35, 94, 67, 96, 30, 63, 21, 33 , 323 , 321 , 232, 32,3232 };
static float TestF[26] = { 90.52f, 9.76f, 97.543f, 89.546f, 36.384f, 75.483f, 51.3454f, 97.6575f, 12.23f,
						   23.876f, 91.23f, 64.92f, 40.3f, 35.6f, 94.2f, 67.8f, 96.98f, 30.23f, 63.2f, 21.2f,
						   43.21, 434.52, 73.76, 23.57, 213.53, 583.91 };
static std::string TestS[26] = { "Kourtney Ellison" , "Danni Nixon", "Vera Wolf", "Casper Holloway", "Zahraa Mcmanus",
								 "Amani Foley", "Alba Strickland", "Fatma Rosa", "Lukasz Miles", "Sharna Morrison", "Graeme Conley",
								 "Osian Case", "Dora Legge", "Israr Chambers", "Hester Workman", "Chandni Stone", "Lea Childs",
								 "Sienna - Rose North", "Jasleen Phan", "Sheridan Mendoza", "Danny K", "Jack Q", "Hi Li", "Jerry A", "Who's Sam", "Lizard" };
static char TestC[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O','P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
static bool TestB[26] = { 0, 1 , 0, 1 , 0, 1 , 0, 1,0, 1,0, 1,0, 1,0, 1,0, 1,0, 1,0,1,0,1,0,1 };
static MyObject TestUDC[26] = { 44, 82, 8, 46, 27, 27, 32, 6, 20, 31, 18, 22, 4, 81,88, 78, 90, 41, 13, 58,32,57,124,676,324,7 };

/*Test Cases for Ints*/
void TestInts()
{
	std::cout << "ALL INT TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<int, int>(TestI, TestI);
	TestInterfaceMethods<int, float>(TestI, TestF);
	TestInterfaceMethods<int, std::string>(TestI, TestS);
	TestInterfaceMethods<int, char>(TestI, TestC);
	TestInterfaceMethods<int, bool>(TestI, TestB);
	TestInterfaceMethods<int, MyObject>(TestI, TestUDC);
}
/*Test Cases for Floats*/
void TestFloats()
{
	std::cout << "ALL FLOAT TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<float, int>(TestF, TestI);
	TestInterfaceMethods<float, float>(TestF, TestF);
	TestInterfaceMethods<float, std::string>(TestF, TestS);
	TestInterfaceMethods<float, char>(TestF, TestC);
	TestInterfaceMethods<float, bool>(TestF, TestB);
	TestInterfaceMethods<float, MyObject>(TestF, TestUDC);
}
/*Test Cases for Strings*/
void TestStrings()
{
	std::cout << "ALL STRING TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<std::string, int>(TestS, TestI);
	TestInterfaceMethods<std::string, float>(TestS, TestF);
	TestInterfaceMethods<std::string, std::string>(TestS, TestS);
	TestInterfaceMethods<std::string, char>(TestS, TestC);
	TestInterfaceMethods<std::string, bool>(TestS, TestB);
	TestInterfaceMethods<std::string, MyObject>(TestS, TestUDC);
}
/*Test Cases for Chars*/
void TestChars()
{
	std::cout << "ALL CHAR TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<char, int>(TestC, TestI);
	TestInterfaceMethods<char, float>(TestC, TestF);
	TestInterfaceMethods<char, std::string>(TestC, TestS);
	TestInterfaceMethods<char, char>(TestC, TestC);
	TestInterfaceMethods<char, bool>(TestC, TestB);
	TestInterfaceMethods<char, MyObject>(TestC, TestUDC);
}
/*Test Cases for Bools*/
void TestBool()
{
	std::cout << "ALL BOOL TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<bool, int>(TestB, TestI);
	TestInterfaceMethods<bool, float>(TestB, TestF);
	TestInterfaceMethods<bool, std::string>(TestB, TestS);
	TestInterfaceMethods<bool, char>(TestB, TestC);
	TestInterfaceMethods<bool, bool>(TestB, TestB);
	TestInterfaceMethods<bool, MyObject>(TestB, TestUDC);
}
/*Test Cases for User Defined Classes*/
void TestUDCs()
{
	std::cout << "ALL USER DEFINED CLASSES TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<MyObject, int>(TestUDC, TestI);
	TestInterfaceMethods<MyObject, float>(TestUDC, TestF);
	TestInterfaceMethods<MyObject, std::string>(TestUDC, TestS);
	TestInterfaceMethods<MyObject, char>(TestUDC, TestC);
	TestInterfaceMethods<MyObject, bool>(TestUDC, TestB);
	TestInterfaceMethods<MyObject, MyObject>(TestUDC, TestUDC);
}


int main()
{

	/*Will run through the test cases, stop so you can read them and then it clears them for the next lot of test cases*/
	TestInts();
	system("pause");
	system("CLS");
	TestFloats();
	system("pause");
	system("CLS");
	TestStrings();
	system("pause");
	system("CLS");
	TestChars();
	system("pause");
	system("CLS");
	TestBool();
	system("pause");
	system("CLS");
	TestUDCs();
	system("pause");
	system("CLS");
	_CrtDumpMemoryLeaks();
	return 0;
}
