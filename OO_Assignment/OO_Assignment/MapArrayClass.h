#pragma once
#include "KeyValuePair.h"
#include "Consts.h"
#include <iterator>
#include <iostream>

/* This is a template class for the interface of the Map Class */
template<typename TypeKey, typename TypeValue>
class MapArray
{
	/* All Private variables aren't for interface use */
private:
	int ArraySize; // Gets track of the ArraySize.
	int CurrentArraySize = 0; // Keeps track of the amount of elements
	void AddMemeory(); // Adds memory to the array to support dynamic memory allocation.
	void Sort(); // Sorts the Array.
	KeyValuePair<TypeKey, TypeValue>* KeyValueArray; // A pointer that is used to point to the Array of KVP.

	/* Public functions avaiable to the Map user */
public:
	using Iterator = MyIterator<TypeKey, TypeValue>;
	MyIterator <TypeKey, TypeValue> Begin(){ return &KeyValueArray[0]; };
	MyIterator <TypeKey, TypeValue> End() {	return &KeyValueArray[CurrentArraySize]; };
	MapArray(int Size); // Constructor to set up the Array with a default size.
	~MapArray(); // Deconstructor to delete the Array.
	bool IsEmpty(); // Function that checks to see if the Array is empty.
	void AddKVP(TypeKey Key, TypeValue Value); // This will allow the user to add a key and value to the top of the Map.
	void RemoveKVP(TypeKey Key); // This will search through the array for and key and remove it from the list.
	void Clear(); // This will run through each element in the array and reset it.
	int CurrentSize(); // This will return the amount of elements in the array.
	bool FindKey(TypeKey Key); // returns if the key already exists.
	TypeValue GetValue(TypeKey Key); // This will allow the user to search for a value by passing a key,

};


