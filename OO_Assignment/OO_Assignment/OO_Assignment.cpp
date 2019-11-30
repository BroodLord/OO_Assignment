// OO_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "MapArrayClass.h"
#include <string>
#include <typeinfo>

struct MyStruct
{

	float Testfloat;
public:
	MyStruct() {}
	MyStruct(float a) : Testfloat(a) {}

	/*The user has to provide these two function as this will allow them to compare and use the iterator*/
	bool operator < (MyStruct const& obj)
	{
		/*Compares*/
		return Testfloat < obj.Testfloat;
	}
	friend std::ostream& operator<<(std::ostream& os, const MyStruct& obj)
	{
		/*Allows for class output to console window*/
		os << obj.Testfloat;
		return os;
	}
};
/* This is class which is used for testing*/
class MyObject
{

	int TestInt;
public:
	MyObject() {}
	MyObject(int a) : TestInt(a) {}

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
		std::cout << "[" << count << "]" << "Key: " << It->Key << " ," << " Value: " << It->Value << std::endl;
		count++;
	}
	std::cout << "CurrentSize: " << Map->CurrentSize() << std::endl;
	std::cout << "Trying to find Key: " << Key[18] << std::endl;
	std::cout << "Is the Key already in the Map: " << Map->FindKey(Key[18]) << std::endl;
	std::cout << "Getting Value At Key " << Key[12] << " : " << Map->GetValue(Key[12]) << std::endl;
	std::cout << "Removing element with Key: " << Key[12] << std::endl;
	Map->RemoveKVP(Key[12]);
	count = 0;
	for (It = Map->Begin(); It != Map->End(); ++It)
	{
		std::cout << "[" << count << "]" << "Key: " << It->Key << " ," << " Value: " << It->Value << std::endl;
		count++;
	}
	std::cout << "Clearing Map" << std::endl;
	Map->Clear();
	std::cout << "Is The Map Empty: " << Map->IsEmpty() << std::endl;
	std::cout << "CurrentSize: " << Map->CurrentSize() << std::endl;
	count = 0;
	std::cout << "Adding New Data to Map: " << std::endl;
	for (int i = 0; i < 26; i++)
	{
		Map->AddKVP(Key[i], Value[i]);
	}
	std::cout << "CurrentSize: " << Map->CurrentSize() << std::endl;
	std::cout << "Clearing Map" << std::endl;
	delete (Map);
	Map = NULL;
	std::cout << "///////////////////////////////////////////" << std::endl;
}
struct TestData
{
	/*Random Datat that will be used when it comes to testing*/
	int TestI[26] = { 90, 9, 97, 89, 36, 75, 51, 95, 12, 23, 91, 64, 40, 35, 94, 67, 96, 30, 63, 21, 33 , 323 , 321 , 232, 32,3232 };
	float TestF[26] = { 90.52f, 9.76f, 97.543f, 89.546f, 36.384f, 75.483f, 51.3454f, 97.6575f, 12.23f,
					  23.876f, 91.23f, 64.92f, 40.3f, 35.6f, 94.2f, 67.8f, 96.98f, 30.23f, 63.2f, 21.2f,
					  43.21f, 434.52f, 73.76f, 23.57f, 213.53f, 583.91f };
	std::string TestS[26] = { "Is this a pigeon?" , "Scumbag Steve", "Grumpy Cat", "Darude Sandstorm", "China",
							"Ceiling Cat", "Trololo", "Chocolate Rain", "Dabbing", "Don't tase me bro", "Nick Young ???",
							"Its a trap", "Arthur Fist", "Thats what she said", "Doge", "Double Rainbow", "Kermit",
							"Nyan Cat", "Harambe", "Keyboard Cat", "RickRolling", "TrollFace", "Its just a prank bro", "Fail", "Who's Sam", "Motivational Lizard" };
	char TestC[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O','P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	bool TestB[26] = { 0, 1 , 0, 1 , 0, 1 , 0, 1,0, 1,0, 1,0, 1,0, 1,0, 1,0, 1,0,1,0,1,0,1 };
	double TestD[26] = { 84.252 ,92.422,129.853,128.271,123.173,109.645,163.864,123.503,1234.637,123.429,192.046,27.957
					,96.389,345.344,43.632,567.357,145.675,12.605,78.262,23.397,91.823,92.897,743.782,57.304,65.646,32.302 };
	MyObject TestUDC[26] = { 44, 82, 8, 46, 27, 27, 32, 6, 20, 31, 18, 22, 4, 81,88, 78, 90, 41, 13, 58,32,57,124,676,324,7 };
	MyStruct TestUDS[26] = { 1.2884f, 2.5758f,4.0896f,8.8450f,3.1414f,2.0118f,4.9658f,2.7377f,0.4315f,1.1002f,0.2174f,4.3410f,0.2292f,1.7685f,
						   3.7229f,9.0139f,6.7529f,1.0975f,2.6218f,5.6836f,0.0678f,1.4960f,8.3738f,8.2677f,1.4738f,0.6299f };

};

/*Test Cases for Ints*/
void TestInts(TestData& data)
{
	std::cout << "ALL INT TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<int, int>(data.TestI, data.TestI);
	TestInterfaceMethods<int, float>(data.TestI, data.TestF);
	TestInterfaceMethods<int, std::string>(data.TestI, data.TestS);
	TestInterfaceMethods<int, char>(data.TestI, data.TestC);
	TestInterfaceMethods<int, bool>(data.TestI, data.TestB);
	TestInterfaceMethods<int, double>(data.TestI, data.TestD);
	TestInterfaceMethods<int, MyObject>(data.TestI, data.TestUDC);
	TestInterfaceMethods<int, MyStruct>(data.TestI, data.TestUDS);
}

/*Test Cases for Floats*/
void TestFloats(TestData& data)
{
	std::cout << "ALL FLOAT TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<float, int>(data.TestF, data.TestI);
	TestInterfaceMethods<float, float>(data.TestF, data.TestF);
	TestInterfaceMethods<float, std::string>(data.TestF, data.TestS);
	TestInterfaceMethods<float, char>(data.TestF, data.TestC);
	TestInterfaceMethods<float, bool>(data.TestF, data.TestB);
	TestInterfaceMethods<float, double>(data.TestF, data.TestD);
	TestInterfaceMethods<float, MyObject>(data.TestF, data.TestUDC);
	TestInterfaceMethods<float, MyStruct>(data.TestF, data.TestUDS);
}
/*Test Cases for Strings*/
void TestStrings(TestData& data)
{
	std::cout << "ALL STRING TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<std::string, int>(data.TestS, data.TestI);
	TestInterfaceMethods<std::string, float>(data.TestS, data.TestF);
	TestInterfaceMethods<std::string, std::string>(data.TestS, data.TestS);
	TestInterfaceMethods<std::string, char>(data.TestS, data.TestC);
	TestInterfaceMethods<std::string, bool>(data.TestS, data.TestB);
	TestInterfaceMethods<std::string, double>(data.TestS, data.TestD);
	TestInterfaceMethods<std::string, MyObject>(data.TestS, data.TestUDC);
	TestInterfaceMethods<std::string, MyStruct>(data.TestS, data.TestUDS);
}
/*Test Cases for Chars*/
void TestChars(TestData& data)
{
	std::cout << "ALL CHAR TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<char, int>(data.TestC, data.TestI);
	TestInterfaceMethods<char, float>(data.TestC, data.TestF);
	TestInterfaceMethods<char, std::string>(data.TestC, data.TestS);
	TestInterfaceMethods<char, char>(data.TestC, data.TestC);
	TestInterfaceMethods<char, bool>(data.TestC, data.TestB);
	TestInterfaceMethods<char, double>(data.TestC, data.TestD);
	TestInterfaceMethods<char, MyObject>(data.TestC, data.TestUDC);
	TestInterfaceMethods<char, MyStruct>(data.TestC, data.TestUDS);
}
/*Test Cases for Doubles*/
void TestDoubles(TestData& data)
{
	std::cout << "ALL BOOL TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<double, int>(data.TestD, data.TestI);
	TestInterfaceMethods<double, float>(data.TestD, data.TestF);
	TestInterfaceMethods<double, std::string>(data.TestD, data.TestS);
	TestInterfaceMethods<double, char>(data.TestD, data.TestC);
	TestInterfaceMethods<double, bool>(data.TestD, data.TestB);
	TestInterfaceMethods<double, double>(data.TestD, data.TestD);
	TestInterfaceMethods<double, MyObject>(data.TestD, data.TestUDC);
	TestInterfaceMethods<double, MyStruct>(data.TestD, data.TestUDS);
}
/*Test Cases for User Defined Classes(CLASS)*/
void TestUDCs(TestData& data)
{
	std::cout << "ALL USER DEFINED CLASSES TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<MyObject, int>(data.TestUDC, data.TestI);
	TestInterfaceMethods<MyObject, float>(data.TestUDC, data.TestF);
	TestInterfaceMethods<MyObject, std::string>(data.TestUDC, data.TestS);
	TestInterfaceMethods<MyObject, char>(data.TestUDC, data.TestC);
	TestInterfaceMethods<MyObject, bool>(data.TestUDC, data.TestB);
	TestInterfaceMethods<MyObject, double>(data.TestUDC, data.TestD);
	TestInterfaceMethods<MyObject, MyObject>(data.TestUDC, data.TestUDC);
	TestInterfaceMethods<MyObject, MyStruct>(data.TestUDC, data.TestUDS);
}
/*Test Cases for User Defined Classes(STRUCT)*/
void TestUDSs(TestData& data)
{
	std::cout << "ALL USER DEFINED CLASSES TEST CASES" << std::endl;
	std::cout << "" << std::endl;
	TestInterfaceMethods<MyStruct, int>(data.TestUDS, data.TestI);
	TestInterfaceMethods<MyStruct, float>(data.TestUDS, data.TestF);
	TestInterfaceMethods<MyStruct, std::string>(data.TestUDS, data.TestS);
	TestInterfaceMethods<MyStruct, char>(data.TestUDS, data.TestC);
	TestInterfaceMethods<MyStruct, bool>(data.TestUDS, data.TestB);
	TestInterfaceMethods<MyStruct, double>(data.TestUDS, data.TestD);
	TestInterfaceMethods<MyStruct, MyObject>(data.TestUDS, data.TestUDC);
	TestInterfaceMethods<MyStruct, MyStruct>(data.TestUDS, data.TestUDS);
}


int main()
{
	/*Will run through the test cases, stop so you can read them and then it clears them for the next lot of test cases*/
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	{
		TestData data;
		TestInts(data);
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	system("CLS");
	{
		TestData data;
		TestFloats(data);
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	system("CLS");
	{
		TestData data;
		TestStrings(data);
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	system("CLS");
	{
		TestData data;
	TestChars(data);
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	system("CLS");
	{
		TestData data;
		TestDoubles(data);
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	system("CLS");
	{
		TestData data;
		TestUDCs(data);
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	system("CLS");
	return 0;
}
