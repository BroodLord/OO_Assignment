#pragma once
#include <iterator>
#include <ostream>
#include <iostream>

/* This is a template class for the interface of the Map Class */
template<typename TypeKey, typename TypeValue>
class MapArray
{
	/* All Private variables aren't for interface use */
private:
	/* This Template Class is used to store a key and value. */
	template<typename TypeKey, typename TypeValue>
	struct KeyValuePair
	{
	public:
		TypeKey Key; // Key for the Map, Can be any type.
		TypeValue Value; // Value for the Map, Can be any type.
	};

	/*This class allows me to use Iterators to run through the map*/
	template<typename TypeKey, typename TypeValue>
	struct MyIterator
	{
	public:
		MyIterator() {} // Default constructor
		MyIterator(KeyValuePair<TypeKey, TypeValue>* Ptr) : MyIteratorPtr(Ptr) {}
		KeyValuePair<TypeKey, TypeValue>* operator->() {return MyIteratorPtr;} // Reutns either of the Key or Value
		/*Override function to see if the iterator is equal to a ptr*/
		bool operator ==(const MyIterator<TypeKey, TypeValue>& KVP) { return MyIteratorPtr == KVP.MyIteratorPtr; }
		/*Override function to see if the iterator isn't equal to a ptr*/
		bool operator !=(const MyIterator<TypeKey, TypeValue>& KVP) { return MyIteratorPtr != KVP.MyIteratorPtr; }
		/* These override function will increment and decrement where to point to in the map */
		MyIterator<TypeKey, TypeValue>& operator ++() { MyIteratorPtr++; return *this; }
		MyIterator<TypeKey, TypeValue>& operator --() { MyIteratorPtr--; return *this; }
	private:
		/* Pointer which is used to data and increment where to point in the map*/
		KeyValuePair<TypeKey, TypeValue>* MyIteratorPtr;
	};

	const int MAX_SIZE = 2000000; // Total number of elements in the array.
	const int DEFAULT_SIZE = 20; // Default starting size.
	const int DYNAMIC_ARRAY_MULTIPLIER = 5; // Number that mulitples the new array size.
	int ArraySize; // Gets track of the ArraySize.
	int CurrentArraySize = 0; // Keeps track of the amount of elements
	void AddMemeory(); // Adds memory to the array to support dynamic memory allocation.
	void Sort(); // Sorts the Array.
	KeyValuePair<TypeKey, TypeValue>* KeyValueArray; // A pointer that is used to point to the Array of KVP.

	/* Public functions avaiable to the Map user */
public:
	using Iterator = MyIterator<TypeKey, TypeValue>;
	MapArray(); // Constructor to set up the Array with a default size.
	~MapArray(); // Deconstructor to delete the Array.
	MyIterator <TypeKey, TypeValue> Begin(){ return &KeyValueArray[0]; };
	MyIterator <TypeKey, TypeValue> End() {	return &KeyValueArray[CurrentArraySize]; };
	bool IsEmpty(); // Function that checks to see if the Array is empty.
	void AddKVP(TypeKey Key, TypeValue Value); // This will allow the user to add a key and value to the top of the Map.
	void RemoveKVP(TypeKey Key); // This will search through the array for and key and remove it from the list.
	void Clear(); // This will run through each element in the array and reset it.
	int CurrentSize(); // This will return the amount of elements in the array.
	bool FindKey(TypeKey Key); // returns if the key already exists.
	TypeValue GetValue(TypeKey Key); // This will allow the user to search for a value by passing a key,
};


