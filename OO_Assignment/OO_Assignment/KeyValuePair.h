#pragma once

/* This Template Class is used to store a key and value. */
template<typename TypeKey, typename TypeValue>
struct KeyValuePair
{
	TypeKey Key; // Key for the Map, Can be any type.
	TypeValue Value; // Value for the Map, Can be any type.
};