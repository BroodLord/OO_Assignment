#pragma once

using namespace std;
/* This Template Class is used to store a key and value. */
template<typename TypeKey, typename TypeValue>
struct KeyValuePair
{
	TypeKey Key; // Key for the Map, Can be any type.
	TypeValue Value; // Value for the Map, Can be any type.
};

template<typename TypeKey, typename TypeValue>
struct MyIterator
{
public:
	MyIterator(){}
	MyIterator(KeyValuePair<TypeKey, TypeValue>* Ptr) : ptr(Ptr) {}
	KeyValuePair<TypeKey, TypeValue>* operator->() 
	{ 
		return ptr; 
	}
	bool operator ==(const MyIterator<TypeKey, TypeValue>& KVP) { return ptr == KVP.ptr; }
	bool operator !=(const MyIterator<TypeKey, TypeValue>& KVP) { return ptr != KVP.ptr; }
	MyIterator<TypeKey, TypeValue>& operator ++() { ptr++; return *this; }
	MyIterator<TypeKey, TypeValue>& operator --() { ptr--; return *this; }
private:
	KeyValuePair<TypeKey, TypeValue>* ptr;
};