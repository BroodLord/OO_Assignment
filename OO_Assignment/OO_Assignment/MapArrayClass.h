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
	class KeyValuePair
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
		KeyValuePair<TypeKey, TypeValue>* operator->() { return MyIteratorPtr; } // Reutns either of the Key or Value
		/*Override function to see if the iterator is equal to a ptr*/
		bool operator ==(const MyIterator<TypeKey, TypeValue>& KVP) { return (MyIteratorPtr == KVP.MyIteratorPtr); }
		/*Override function to see if the iterator isn't equal to a ptr*/
		bool operator !=(const MyIterator<TypeKey, TypeValue>& KVP) { return !(MyIteratorPtr == KVP.MyIteratorPtr); }
		/* These override function will increment and decrement where to point to in the map */
		MyIterator<TypeKey, TypeValue>& operator ++() { MyIteratorPtr++; return *this; }
		MyIterator<TypeKey, TypeValue>& operator --() { MyIteratorPtr--; return *this; }
	private:
		/* Pointer which is used to data and increment where to point in the map*/
		KeyValuePair<TypeKey, TypeValue>* MyIteratorPtr;
	};
	const int DEFAULT_SIZE = 20; // Default starting size.
	const int DYNAMIC_ARRAY_MULTIPLIER = 5; // Number that mulitples the new array size.
	const std::string MEMORY_MESSAGE = "MEMORY CANNOT BE ALLOCATED ANYMORE";
	const std::string MAP_CREATED_MESSAGE = "MAP HAS BEEN CREATED";
	const std::string MAP_DELETED_MESSAGE = "MAP HAS BEEN DELETED";
	const std::string KEY_NOT_FOUND_MESSAGE = "KEY HASN'T BEEN FOUND";
	int ArraySize; // Gets track of the ArraySize.
	int CurrentArraySize = 0; // Keeps track of the amount of elements
	/* This function is used when we need to give the array more memory */
	void AddMemory()
	{
		//int SavedSized;
		//SavedSized = ArraySize;
		ArraySize *= DYNAMIC_ARRAY_MULTIPLIER; // This makes the Array Size 5 times better
		/*TRY CATCH FUNCTION TO TEST MEMEORY ALLOCATION*/
		try
		{
			KeyValuePair<TypeKey, TypeValue>* KVPArray; // Creates a new pointer of KeyValueArray
			KVPArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize] {}; // Sets up a new Array of the new size


		/* Runs through the old Array and assigns all the data to the new Array */
			for (int i = 0; i < CurrentArraySize; i++)
			{
				KVPArray[i].Key = KeyValueArray[i].Key;
				KVPArray[i].Value = KeyValueArray[i].Value;
			}
			delete[] KeyValueArray; // Deletes the old array assign to the pointer
			KeyValueArray = KVPArray; // makes the old ponter look at the new Array.
		}
		catch (std::bad_array_new_length & e)
		{
			KeyValueArray = NULL;
			std::cout << MEMORY_MESSAGE << std::endl;
		}

	}
	/* This function is a linear sort to sort all the elements it the array*/
	void Sort()
	{
		if (!IsEmpty())
		{
			int min, i, j; // Variables so I can keep track of indexs to change
			TypeKey tempKey; // Temp variable to sort the Key
			TypeValue tempValue; // Temp variable to sort the Value
			/* Runs through all the elements in the array */
			for (i = 0; i < CurrentArraySize - 1; i++)
			{
				min = i; // Sets min to the currenty index that needs sorting
				for (j = i + 1; j < CurrentArraySize; j++)
				{
					/* Check to see if the current index is less then any value in the array */
					if (KeyValueArray[min].Key < KeyValueArray[j].Key)
					{
						min = j; // Sets the min to equal the J
					}
				}
				tempKey = KeyValueArray[i].Key; // Sets the temp key to the current I.
				tempValue = KeyValueArray[i].Value; // Sets the temp value to the current I.
				KeyValueArray[i].Key = KeyValueArray[min].Key; // Sets what the index Key will be.
				KeyValueArray[i].Value = KeyValueArray[min].Value; // Sets what the index Value will be.
				KeyValueArray[min].Key = tempKey; // Sets the Key in index min to temp
				KeyValueArray[min].Value = tempValue; // Sets the Value in index min to temp
			}
		}
	}
	KeyValuePair<TypeKey, TypeValue>* KeyValueArray; // A pointer that is used to point to the Array of KVP.

	/* Public functions avaiable to the Map user */
public:
	using Iterator = MyIterator<TypeKey, TypeValue>;
	MyIterator <TypeKey, TypeValue> Begin() { return &KeyValueArray[0]; };
	MyIterator <TypeKey, TypeValue> End() { return &KeyValueArray[CurrentArraySize]; };

	/* This function will set up the Map when it is created */
	MapArray()
	{
		ArraySize = DEFAULT_SIZE; // Gets the size the user entered and assigns it to the ArraySize
		KeyValueArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize]; // This creates a new array of Keys and values
		std::cout << MAP_CREATED_MESSAGE << std::endl;
	}
	/* This is a deconstructor that is used to delete the Map. */
	~MapArray()
	{
		delete[] KeyValueArray;
		std::cout << MAP_DELETED_MESSAGE << std::endl;
	}
	/* This function will let the user know if the Array is empty */
	bool IsEmpty()
	{
		/* If the Top of the Array is equal or less then 0 then its true, else it false */
		if (CurrentArraySize <= 0) { return true; }
		else { return false; }
	}
	/* This function will allow data to be add to the map class */
	void AddKVP(TypeKey Key, TypeValue Value)
	{
		bool Added = false; // Boolean to see if the data has already been added
		/* Runs through all the elements in the array */
		for (int i = 0; i < CurrentArraySize; i++)
		{
			/* This checks to see if the Key already exsists */
			if (!(KeyValueArray[i].Key < Key) && !(Key < KeyValueArray[i].Key))
			{
				/* This will add the new value to the key and set the added bool to true */
				KeyValueArray[i].Value = Value;
				Added = true;
				break;
			}
		}
		/* check to see if the data hasn't been added */
		if (!Added && KeyValueArray != NULL)
		{
			/* This will add a new Key and Value as a new element to the back of the Map
			   and after adding the data it will sort the data. */
			KeyValueArray[CurrentArraySize].Key = Key;
			KeyValueArray[CurrentArraySize].Value = Value;

			CurrentArraySize++;
			Sort();
		}
		/* Check to see if the top element is equal to the current array size and that the array size isn't equal to the Max Size */
		if (CurrentArraySize == ArraySize) { AddMemory(); } // Will run the function to add memory
	}
	/* This function will allow for the removal of an elements in the array */
	void RemoveKVP(TypeKey Key)
	{
		/* Checks to see if the Array is empty */
		if (!IsEmpty())
		{
			int SavedIndex = 0; // Used to store the index of the removed Key
			bool KeyExists = false; // Boolean to see if the Key exsists
			/* Runs through all the elements in the array */
			for (int i = 0; i < CurrentArraySize; i++)
			{
				/* This will check to see if the Key is in the array */
				if (!(KeyValueArray[i].Key < Key) && !(Key < KeyValueArray[i].Key))
				{
					SavedIndex = i; // Saves the current index
					KeyExists = true; // Turns true so we know it exsits
					break; // break out
				}
			}
			/* If the Key is in the array */
			if (KeyExists)
			{
				KeyValuePair<TypeKey, TypeValue>* KVPArray;
				KVPArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize]; // Create a new array of KVP
				/* run throught all the elements in the array */
				for (int i = 0; i < CurrentArraySize; i++)
				{
					/* This will pass over all the elements in the array to the new array
					   apart from the element at the saved index */
					if (i != SavedIndex && KeyValueArray != NULL)
					{
						KVPArray[i].Key = KeyValueArray[i].Key;
						KVPArray[i].Value = KeyValueArray[i].Value;
					}
				}
				delete[] KeyValueArray; // Delete all the elements in the all array
				if (KeyValueArray != NULL)
				{
					KeyValueArray = KVPArray; // Sets the pointer to look at the new array
				}
				Sort(); // sorts the new array
				CurrentArraySize--; // Pops the top of array as its no longer an element
			}
			else
			{
				/* Tells the user that the key doesn't exisit in the map */
				std::cout << KEY_NOT_FOUND_MESSAGE << std::endl;
			}
		}
	}
	/* This function is used to reset the array */
	void Clear()
	{
		/* This will delete the array and reset it back to current max size, also creates a new array at the correct size*/
		delete[] KeyValueArray;
		KeyValueArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize] {}; // This creates a new array of Keys and values
		CurrentArraySize = 0;
	}
	/* This function will just return the current size of the map */
	int CurrentSize()
	{
		return CurrentArraySize;
	}
	/* This function will return the Value asscoited to a Key */
	TypeValue GetValue(TypeKey Key)
	{
		bool KeyInMap = false;
		/* Runs through all the Keys to see if the passed Key is equal to any in the map */
		for (int i = 0; i < CurrentArraySize; i++)
		{
			/* Check to see if the passed Key is equal to the Key in the array*/
			if (!(KeyValueArray[i].Key < Key) && !(Key < KeyValueArray[i].Key))
			{
				/* Returns what value is associated to the Key */
				KeyInMap = true;
				return KeyValueArray[i].Value;
			}
		}
		if (!KeyInMap)
		{
			/* Tells the user that the key doesn't exisit in the map */
			std::cout << KEY_NOT_FOUND_MESSAGE << std::endl;
		}
		return NULL;
	}
	/*This function will return true or false depending if the key alredy exsists*/
	bool FindKey(TypeKey Key)
	{
		bool KeyInMap = false;
		/*Runs through all the current Keys in the map*/
		for (int i = 0; i < CurrentArraySize; i++)
		{
			/* Check to see if the passed Key is equal to the Key in the array*/
			if (!(KeyValueArray[i].Key < Key) && !(Key < KeyValueArray[i].Key))
			{
				KeyInMap = true;
				return true;
			}
		}
		if (!KeyInMap)
		{
			/* Tells the user that the key doesn't exisit in the map */
			std::cout << KEY_NOT_FOUND_MESSAGE << std::endl;
		}
		return false;
	}
};


