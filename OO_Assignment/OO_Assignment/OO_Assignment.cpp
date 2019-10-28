// OO_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<class T1, class T2>
class MapArray
{
private:
	int ArraySize;
	int Top = 0;
	T1* KeyArray;
	T2* ValueArray;
public:
	MapArray(int Size)
	{
		ArraySize = Size;
		KeyArray = new T1[ArraySize];
		ValueArray = new T2[ArraySize];
	}
	bool IsFull();
	bool IsEmpty();
	void Push(T1 Key, T2 Value);
	void Pop();
	void Clear();
	//void GetData();

};
template<class T1, class T2>
bool MapArray< T1, T2>::IsFull()
{
	if (Top >= ArraySize)
	{
		std::cout << "Map is Full of elements" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}
template<class T1, class T2>
bool MapArray<T1, T2>::IsEmpty()
{
	if (Top <= 0)
	{
		std::cout << "Map is Empty" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}
template<class T1, class T2>
void MapArray<T1, T2>::Push(T1 Key, T2 Value)
{
	KeyArray[Top] = Key;
	ValueArray[Top] = Value;
	Top++;

}
template<class T1, class T2>
void MapArray<T1, T2>::Pop()
{
	Top--;
	KeyArray[Top] = NULL;
	ValueArray[Top] = "";

}
template<class T1, class T2>
void MapArray<T1, T2>::Clear()
{
	for (int i = 0; i <= Top; i++)
	{
		Pop();
	}

}
//template<class T1, class T2>
//void MapArray<T1,T2>::GetData()
//{
//	for (int i = 0; i < ArraySize; i++)
//	{
//		std::cout << "Key: " << KeyArray[i] << std::endl;
//		std::cout << "Value: " << ValueArray[i] << std::endl;
//	}
//
//}

int main()
{
	MapArray<int, std::string> Map(2);
	Map.Push(104, "Danny Kavanagh");
	Map.Push(78, "YES QUEEN");
	//Map.GetData();
	Map.Clear();
	//Map.GetData();
	return 0;
}
