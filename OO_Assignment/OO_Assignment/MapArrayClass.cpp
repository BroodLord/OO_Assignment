#include "MapArrayClass.h"

/* This function will set up the Map when it is created */
template<typename TypeKey, typename TypeValue>
MapArray< TypeKey, TypeValue>::MapArray(int Size)
{
	ArraySize = Size; // Gets the size the user entered and assigns it to the ArraySize
	KeyValueArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize]; // This creates a new array of Keys and values
}
/* This is a deconstructor that is used to delete the Map. */
template<typename TypeKey, typename TypeValue>
MapArray< TypeKey, TypeValue>::~MapArray()
{
	delete[] KeyValueArray; // This will delete the Map
}
/* This function is used when we need to give the array more memory */
template<typename TypeKey, typename TypeValue>
void MapArray< TypeKey, TypeValue>::AddMemeory()
{

	ArraySize *= DYNAMIC_ARRAY_MULTIPLIER; // This makes the Array Size 5 times better
	if (ArraySize > MAX_SIZE)
	{
		ArraySize = MAX_SIZE; // Sets the Array to the max Size
		std::cout << "Array can't be incresed anymore due to the Max Size" << std::endl; // Lets the user know about the Array Size
	}
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
/* This function will let the user know if the Array is empty */
template<typename TypeKey, typename TypeValue>
bool MapArray<TypeKey, TypeValue>::IsEmpty()
{
	/* If the Top of the Array is equal or less then 0 then its true, else it false */
	if (CurrentArraySize <= 0)
	{
		std::cout << "Map is Empty" << std::endl; // Output message to the user
		return true;
	}
	else
	{
		return false;
	}
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
	if (!Added)
	{
		/* This will add a new Key and Value as a new element to the back of the Map
		   and after adding the data it will sort the data. */
		KeyValueArray[CurrentArraySize].Key = Key;
		KeyValueArray[CurrentArraySize].Value = Value;
		Sort();
		CurrentArraySize++;
	}
	/* Check to see if the top element is equal to the current array size and that the array size isn't equal to the Max Size */
	if (CurrentArraySize == ArraySize && ArraySize != MAX_SIZE)
	{
		AddMemeory(); // Will run the function to add memory
	}
}
/* This function will allow for the removal of an elements in the array */
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::RemoveKVP(TypeKey Key)
{
	/* Checks to see if the Array is empty */
	if (!IsEmpty())
	{
		int SavedIndex = 0; // Used to store the index of the removed Key
		bool KeyExsits = false; // Boolean to see if the Key exsists
		/* Runs through all the elements in the array */
		for (int i = 0; i < CurrentArraySize; i++)
		{
			/* This will check to see if the Key is in the array */
			if (!(KeyValueArray[i].Key < Key) && !(Key < KeyValueArray[i].Key))
			{
				SavedIndex = i; // Saves the current index
				KeyExsits = true; // Turns true so we know it exsits
				break; // break out
			}
		}
		/* If the Key is in the array */
		if (KeyExsits)
		{
			KeyValuePair<TypeKey, TypeValue>* KVPArray; // Create a new pointer of KVP
			KVPArray = new KeyValuePair<TypeKey, TypeValue>[ArraySize]; // Create a new array of KVP
			/* run throught all the elements in the array */
			for (int i = 0; i < CurrentArraySize; i++)
			{
				/* This will pass over all the elements in the array to the new array
				   apart from the element at the saved index */
				if (i != SavedIndex)
				{
					KVPArray[i].Key = KeyValueArray[i].Key;
					KVPArray[i].Value = KeyValueArray[i].Value;
				}
			}
			delete[] KeyValueArray; // Delete all the elements in the all array
			KeyValueArray = KVPArray; // Sets the pointer to look at the new array
			Sort(); // sorts the new array
			CurrentArraySize--; // Pops the top of array as its no longer an element
		}
		else
		{
			/* Tells the user that the key doesn't exisit in the map */
			std::cout << "Key Doesn't exsits in the Map" << std::endl;
		}

	}
}
/* This function is used to reset the array */
template<typename TypeKey, typename TypeValue>
void MapArray<TypeKey, TypeValue>::Clear()
{
	/* This will delete the array and reset it back to current max size */
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
		if (!(KeyValueArray[i].Key < Key) && !(Key < KeyValueArray[i].Key))
		{
			return KeyValueArray[i].Value;
			break;
		}
	}
}
template<typename TypeKey, typename TypeValue>
bool MapArray<TypeKey, TypeValue>::FindKey(TypeKey Key)
{
	for (int i = 0; i < CurrentArraySize; i++)
	{
		if (!(KeyValueArray[i].Key < Key) && !(Key < KeyValueArray[i].Key))
		{
			return true;
		}
	}
	return false;
}