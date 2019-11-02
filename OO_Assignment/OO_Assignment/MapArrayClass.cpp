#include "MapArrayClass.h"
#include <iostream>
#include <typeinfo>
template<typename TypeKey, typename TypeValue>
MapArray< TypeKey, TypeValue>::MapArray(int Size)
{
	ArraySize = Size;
	KeyValueArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize];
}
template<typename TypeKey, typename TypeValue>
void MapArray< TypeKey, TypeValue>::AddMemeory()
{
	ArraySize *= DYNAMIC_ARRAY_MULTIPLIER;
	if (ArraySize > MAX_SIZE)
	{
		ArraySize = MAX_SIZE;
		std::cout << "Array is at Max Size" << std::endl;
	}
	else
	{
		KeyValuePair<TypeKey, TypeValue>* KVPArray;
		KVPArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize];
		for (int i = 0; i < CurrentArraySize; i++)
		{
			KVPArray[i].Key = KeyValueArray[i].Key;
			KVPArray[i].Value = KeyValueArray[i].Value;
		}
		delete[] KeyValueArray;
		KeyValueArray = KVPArray;
	}

}
template<typename TypeKey, typename TypeValue>
bool MapArray<TypeKey, TypeValue>::IsEmpty()
{
	if (CurrentArraySize <= 0)
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
	KeyValueArray[CurrentArraySize].Key = Key;
	KeyValueArray[CurrentArraySize].Value = Value;
	CurrentArraySize++;
	if (CurrentArraySize == ArraySize)
	{
		AddMemeory();
	}
}
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::Pop()
{
	if (!IsEmpty())
	{
		CurrentArraySize--;
		KeyValuePair<TypeKey, TypeValue>* KVPArray;
		KVPArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize];
		for (int i = 0; i < CurrentArraySize; i++)
		{
			KVPArray[i].Key = KeyValueArray[i].Key;
			KVPArray[i].Value = KeyValueArray[i].Value;
		}
		delete[] KeyValueArray;
		KeyValueArray = KVPArray;
	}
}
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::Clear()
{
	delete[] KeyValueArray;
	KeyValueArray = new KeyValuePair<TypeKey, TypeValue>(ArraySize);

}
template<typename TypeKey, typename TypeValue>
int MapArray<TypeKey, TypeValue>::CurrentSize()
{
	return CurrentArraySize;
}
template<typename TypeKey, typename TypeValue>
TypeValue MapArray<TypeKey, TypeValue>::GetValue(TypeKey Key)
{
	for (int i = 0; i < CurrentArraySize; i++)
	{
		if (KeyValueArray[i].Key == Key)
		{
			return KeyValueArray[i].Value;
			break;
		}
	}
}