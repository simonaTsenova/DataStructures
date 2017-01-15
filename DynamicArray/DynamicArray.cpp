/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Simona Tsenova
* @idnumber 61946
* @task 4
* @compiler VC
*
*/

#include "stdafx.h"
#include <iostream>
#include "DynamicArray.h"
using namespace std;

template <class Type>
DynamicArray<Type>::DynamicArray()
{
	usedElements = 0;
	capacity = 1;
	data = new Type[capacity];
}

template <class Type>
DynamicArray<Type>::~DynamicArray()
{
	delete[] data;
	usedElements = 0;
	capacity = 0;
}

template <class Type>
Type& DynamicArray<Type>::operator[](int index)
{
	if (index < this->usedElements && index >= 0)
		return data[index];
	else
	{
		cout << "No such index " << index << ". \n";
	}
}

template <class Type>
const Type& DynamicArray<Type>::operator[](int index) const
{
	if (index < this->usedElements && index >= 0)
		return data[index];
	else
		cout << "No such index. \n";
}

template<class Type>
DynamicArray<Type>::DynamicArray(const DynamicArray& object)
{
	this->capacity = object.capacity;
	data = new Type[this->capacity];
	this->usedElements = object.usedElements;

	for (int i = 0; i < this->usedElements; i++)
	{
		data[i] = object.data[i];
	}
}

template<class Type>
DynamicArray<Type>& DynamicArray<Type>::operator=(const DynamicArray& object)
{
	if (this != &object)
	{
		delete[] data;
		capacity = object.capacity;
		data = new Type[this->capacity];
		usedElements = object.usedElements;

		for (int i = 0; i < usedElements; i++)
		{
			data[i] = object.data[i];
		}
	}

	return *this;
}

template <class Type>
void DynamicArray<Type>::push(const Type& newElement)
{
	if (isFull())
	{
		resize();
	}

	data[usedElements] = newElement;
	++usedElements;
}

template <class Type>
void DynamicArray<Type>::removeFromPosition(int position)
{
	if (position >= usedElements)
	{
		cout << "No such index " << position << ". \n";
		exit(-1);
	}
	else
	{
		for (int i = position; i <= usedElements - 2; i++)
		{
			data[i] = data[i + 1];
		}
		usedElements--;
	}
}

template<class Type>
int DynamicArray<Type>::findPosition(const Type& element)
{
	for (int i = 0; i < this->usedElements; i++)
	{
		if (data[i] == element)
		{
			return i;
		}
	}
	return -1;
}

template <class Type>
int DynamicArray<Type>::getCapacity()
{
	return this->capacity;
}

template <class Type>
int DynamicArray<Type>::getUsedElements() const
{
	return this->usedElements;
}

template <class Type>
bool DynamicArray<Type>::isEmpty()
{
	if (this->usedElements <= 0)
		return true;
	else
		return false;
}

template <class Type>
bool DynamicArray<Type>::isFull()
{
	if (this->usedElements >= capacity)
		return 1;
	else
		return 0;
}

template <class Type>
void DynamicArray<Type>::resize()
{
	int newCapacity = capacity * 2;
	Type* newArray = new Type[newCapacity];
	for (int i = 0; i < usedElements; i++)
	{
		newArray[i] = data[i];
	}
	delete[] data;
	data = newArray;
	capacity = newCapacity;
}

template <class Type>
void DynamicArray<Type>::displayArray()
{
	cout << "capacity: " << capacity << endl;
	cout << "elements in array count: " << usedElements << endl;
	for (int i = 0; i < usedElements; i++)
	{
		cout << data[i] << endl;
	}
}

template<class Type>
void DynamicArray<Type>::sortArray()
{
	for (int i = 0; i < this->usedElements - 1; i++)
	{
		int minPosition = i;
		for (int j = i + 1; j < this->usedElements; j++)
		{
			if (this->data[j] < this->data[minPosition])
			{
				minPosition = j;
			}
		}

		Type swap = this->data[i];
		this->data[i] = this->data[minPosition];
		this->data[minPosition] = swap;	
	}
}
