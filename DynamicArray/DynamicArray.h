/**
*
* Implementation of Template Dynamic Array DS
* With a method to sort the array
* @author Simona Tsenova
* @compiler VC
*
*/

#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <string>
template <class Type>
class DynamicArray
{
private:
	Type* data;
	int capacity;
	int usedElements;

public:
	DynamicArray();
	~DynamicArray();
	Type& operator[](int);
	const Type& operator[](int index) const;
	DynamicArray(const DynamicArray& object);
	DynamicArray& operator=(const DynamicArray& object);

	void push(const Type&);
	void removeFromPosition(int);
	int findPosition(const Type& element);

	int getCapacity();
	int getUsedElements() const;

	bool isEmpty();
	bool isFull();

	//Resizes the dynamic array when it is already full
	void resize();

	void displayArray();
	void sortArray();
};

#endif // !DYNAMIC_ARRAY_H
