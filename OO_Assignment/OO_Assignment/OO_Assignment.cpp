// OO_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define NULLSTRING "null_string";

#include <iostream>
template<typename TypeKey, typename TypeValue>
class KeyValuePair
{
public:
	TypeKey Key;
	TypeValue Value;
};


template<typename TypeKey, typename KeyValue>
class MapArray
{
private:
	int ArraySize;
	int CurrentSize = 0;
	KeyValuePair<TypeKey, KeyValue>* KeyValueArray;
public:
	MapArray(int Size);
	bool IsEmpty();
	void Push(TypeKey Key, KeyValue Value);
	void Pop();
	void Clear();
	bool CompareKey(TypeKey Key);
	void GetData();
	int Count();

};

template<typename TypeKey, typename TypeValue>
MapArray< TypeKey, TypeValue>::MapArray(int Size)
{
	ArraySize = Size;
	KeyValueArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize];
}

template<typename TypeKey, typename TypeValue>
bool MapArray<TypeKey, TypeValue>::IsEmpty()
{
	if (Count <= 0)
	{
		std::cout << "Map is Empty" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::Push(TypeKey Key, TypeValue Value)
{
	KeyValueArray[Count].Key = Key;
	KeyValueArray[Count].Value = Value;
	Count++;

}
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::Pop()
{
	Count--;
	KeyValueArray[Count].Key = NULL;
	KeyValueArray[Count].Value = NULLSTRING;

}
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::Clear()
{
	for (int i = 0; i <= Count; i++)
	{
		Pop();
	}

}
template<typename TypeKey, typename TypeValue>
bool MapArray<TypeKey, TypeValue>::CompareKey(TypeKey Key)
{
	for (int i = 0; i < Count; i++)
	{
		if (KeyValueArray[i].Key == Key)
		{
			std::cout << "Key Already In Use" << std::endl;
			return true;
		}
		else
		{
			return false;
		}
	}
}
template<typename TypeKey, typename TypeValue>
int MapArray<TypeKey, TypeValue>::Count()
{
	return CurrentSize;
}

int main()
{
	return 0;
}
