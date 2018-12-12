#pragma once
#include <cstddef>
#include <stdlib.h>




template <class datatype>
class Queue
{
private:
	struct Node
	{
		datatype Element;
		struct Node * Next;
	};
	struct Node * First;
	struct Node * Last;
	int Count;

public:
	datatype Peek()
	{
		if (Count == 0)
		{
			throw std::out_of_range("Queue is empty");
		}
		Node * Temp = First;
		return Temp->Element;
	}

	void AddElement(datatype NewElement) {
		struct Node * NewNode = new struct Node;
		NewNode->Element = NewElement;
		NewNode->Next = NULL;
		Count++;
		if (First == NULL)
			First = NewNode;
		else
		{
			Last->Next = NewNode;
		}
		Last = NewNode;

	}
	bool RemoveElement()
	{
		if (First == NULL) return false;
		Node * temp = First;
		First = First->Next;
		delete temp;
		Count--;
		return true;
	}
	int ReturnCount()
	{
		return Count;
	}
	Queue() {
		Count = 0;
		First = NULL;
		Last = NULL;
	}

};