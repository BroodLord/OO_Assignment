#pragma once
#include "KeyValuePair.h"
#include "Consts.h"
template<typename TypeKey, typename TypeValue>
class MapArray
{
private:
	int ArraySize;
	int CurrentArraySize = 0;
	void AddMemeory();
	KeyValuePair<TypeKey, TypeValue>* KeyValueArray;
public:
	MapArray(int Size);
	bool IsEmpty();
	void Push(TypeKey Key, TypeValue Value);
	void Pop();
	void Clear();
	int CurrentSize();
	TypeValue GetValue(TypeKey Key);
};

