#include "MapArrayClass.h"

/* This function will set up the Map when it is created */
template<typename TypeKey, typename TypeValue>
MapArray< TypeKey, TypeValue>::MapArray()
{
		ArraySize = DEFAULT_SIZE; // Gets the size the user entered and assigns it to the ArraySize
		KeyValueArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize]; // This creates a new array of Keys and values
		std::cout << "Map is being created" << std::endl;
}
/* This is a deconstructor that is used to delete the Map. */
template<typename TypeKey, typename TypeValue>
MapArray< TypeKey, TypeValue>::~MapArray()
{
	std::cout << "Map is being deleted" << std::endl;
}
/* This function is used when we need to give the array more memory */
template<typename TypeKey, typename TypeValue>
void MapArray< TypeKey, TypeValue>::AddMemory()
{
	int SavedSized;
	SavedSized = ArraySize;
	ArraySize *= DYNAMIC_ARRAY_MULTIPLIER; // This makes the Array Size 5 times better
	/*TRY CATCH FUNCTION TO TEST MEMEORY ALLOCATION*/
	try
	{
		KeyValuePair<TypeKey, TypeValue>* KVPArray; // Creates a new pointer of KeyValueArray
		KVPArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize]; // Sets up a new Array of the new size


	/* Runs through the old Array and assigns all the data to the new Array */
		for (int i = 0; i < CurrentArraySize; i++)
		{
			KVPArray[i].Key = KeyValueArray[i].Key;
			KVPArray[i].Value = KeyValueArray[i].Value;
		}
		delete[] KeyValueArray; // Deletes the old array assign to the pointer
		KeyValueArray = KVPArray; // makes the old ponter look at the new Array.
	}
	catch (std::bad_array_new_length &e)
	{
		KeyValueArray = NULL;
		std::cout << "MEMORY CANNOT BE ALLOCATED ANYMORE" << std::endl;
	}

}
/* This function will let the user know if the Array is empty */
template<typename TypeKey, typename TypeValue>
bool MapArray<TypeKey, TypeValue>::IsEmpty()
{
	/* If the Top of the Array is equal or less then 0 then its true, else it false */
	if (CurrentArraySize <= 0){return true;}
	else{return false;}
}
/* This function is a linear sort to sort all the elements it the array*/
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::Sort()
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
/* This function will allow data to be add to the map class */
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::AddKVP(TypeKey Key, TypeValue Value)
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
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::RemoveKVP(TypeKey Key)
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
			KeyValuePair<TypeKey, TypeValue>* KVPArray; // Create a new pointer of KVP
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
			std::cout << "KEY DOESN'T EXSIST IN THE MAP" << std::endl;
		}

	}
}
/* This function is used to reset the array */
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::Clear()
{
	/* This will delete the array and reset it back to current max size, also creates a new array at the correct size*/
	delete[] KeyValueArray;
	CurrentArraySize = 0;
	try
	{
		KeyValueArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize];
	}
	catch (std::bad_array_new_length & e)
	{
		std::cout << "ARRAY HAS NO MEMORY" << std::endl;
	}

}
/* This function will just return the current size of the map */
template<typename TypeKey, typename TypeValue>
int MapArray<TypeKey, TypeValue>::CurrentSize()
{
	return CurrentArraySize;
}
/* This function will return the Value asscoited to a Key */
template<typename TypeKey, typename TypeValue>
TypeValue MapArray<TypeKey, TypeValue>::GetValue(TypeKey Key)
{
	/* Runs through all the Keys to see if the passed Key is equal to any in the map */
	for (int i = 0; i < CurrentArraySize; i++)
	{
		/* Check to see if the passed Key is equal to the Key in the array*/
		if (!(KeyValueArray[i].Key < Key) && !(Key < KeyValueArray[i].Key))
		{
			/* Returns what value is associated to the Key */
			return KeyValueArray[i].Value;
		}
	}
}
/*This function will return true or false depending if the key alredy exsists*/
template<typename TypeKey, typename TypeValue>
bool MapArray<TypeKey, TypeValue>::FindKey(TypeKey Key)
{
	/*Runs through all the current Keys in the map*/
	for (int i = 0; i < CurrentArraySize; i++)
	{
		/* Check to see if the passed Key is equal to the Key in the array*/
		if (!(KeyValueArray[i].Key < Key) && !(Key < KeyValueArray[i].Key))
		{
			return true;
		}
	}
	return false;
}