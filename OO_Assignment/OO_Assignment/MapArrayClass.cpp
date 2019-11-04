#include "MapArrayClass.h"

template<typename TypeKey, typename TypeValue>
MapArray< TypeKey, TypeValue>::MapArray(int Size)
{
	ArraySize = Size;
	KeyValueArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize];
}
template<typename TypeKey, typename TypeValue>
MapArray< TypeKey, TypeValue>::~MapArray()
{
	delete[] KeyValueArray;
	std::cout << "MapArray Deleted" << std::endl;
}
template<typename TypeKey, typename TypeValue>
void MapArray< TypeKey, TypeValue>::AddMemeory()
{
	ArraySize *= DYNAMIC_ARRAY_MULTIPLIER;
	if(ArraySize > MAX_SIZE)
	{
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
void MapArray<TypeKey, TypeValue>::Sort()
{
	int min, i, j;
	TypeKey temp;
	for (i = 0; i < CurrentArraySize - 1; i++)
	{
		min = i;
		for (j = i + 1; j < CurrentArraySize; j++)
		{
			if (KeyValueArray[j].Key > KeyValueArray[min].Key)
			{
				min = j;
			}
		}
		temp = KeyValueArray[i].Key;
		KeyValueArray[i].Key = KeyValueArray[min].Key;
		KeyValueArray[i].Value = KeyValueArray[min].Value;
		KeyValueArray[min].Key = temp;
	}
}
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::AddKVP(TypeKey Key, TypeValue Value)
{
	KeyValueArray[CurrentArraySize].Key = Key;
	KeyValueArray[CurrentArraySize].Value = Value;
	CurrentArraySize++;
	Sort();
	if (CurrentArraySize == ArraySize)
	{
		AddMemeory();
	}
}
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::RemoveKVP(TypeKey Key)
{
	if (!IsEmpty())
	{
		int SavedIndex = 0;
		for (int i = 0; i < CurrentArraySize; i++)
		{
			if (KeyValueArray[i].Key == Key)
			{
				SavedIndex = i;
				break;
			}
		}
		KeyValuePair<TypeKey, TypeValue>* KVPArray;
		KVPArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize];
		for (int i = 0; i < CurrentArraySize; i++)
		{
			if (i != SavedIndex)
			{
				KVPArray[i].Key = KeyValueArray[i].Key;
				KVPArray[i].Value = KeyValueArray[i].Value;
			}
		}
		delete[] KeyValueArray;
		KeyValueArray = KVPArray;
		Sort();
		CurrentArraySize--;
		
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