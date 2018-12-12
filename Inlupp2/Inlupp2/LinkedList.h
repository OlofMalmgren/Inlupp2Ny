#pragma once
#include <cstddef>

template <class datatype>
class LinkedList
{
private:
	struct Node
	{
		datatype Element;
		struct Node * Next;
	};
	struct Node * First;
	struct Node * Last;
	int Counter;

public:
	LinkedList()
	{
		Counter = 0;
		First = NULL;
		Last = NULL;
	}
	void AddElementAtStart(datatype NewElement)
	{
		struct Node * NewNode = new struct Node;
		NewNode->Element = NewElement;
		if (First == NULL)
		{
			First = NewNode;
			Last = First;
			First->Next = NULL;
			Last->Next = NULL;
		}
		else
		{
			NewNode->Next = First;
			First = NewNode;
		}
		Counter++;
	}
	void AddElementAtEnd(datatype NewElement)
	{
		struct Node * NewNode = new struct Node;
		NewNode->Element = NewElement;
		if (First == NULL)
		{
			First = NewNode;
			Last = First;
			First->Next = NULL;
			Last->Next = NULL;
		}
		else
		{
			Last->Next = NewNode;
			Last = NewNode;
			Last->Next = NULL;
		}
		Counter++;
	}
	void AddElementAtPosition(datatype NewElement, int position)
	{
		if (position > Counter + 1 || position < 0)
		{
			throw std::out_of_range("Invalid position");
		}
		else if (position == 0)
		{
			AddElementAtStart(NewElement);
		}
		else if (position + 1 == Counter)
		{
			AddElementAtEnd(NewElement);
		}
		else
		{
			struct Node *previous = new struct Node;
			struct Node *current = new struct Node;
			struct Node *temp = new struct Node;
			temp->Element = NewElement;
			current = First;
			for (int i = 1; i < position; i++)
			{
				previous = current;
				current = current->Next;
			}
			previous->Next = temp;
			temp->Next = current;
			Counter++;
		}
	}
	void RemoveFirstElement()
	{
		if (First == NULL)
		{
			throw std::out_of_range("LinkedList is empty");
		}
		else if (Counter == 1)
		{
			delete First;
			delete Last;
			Counter--;
		}
		else
		{
			struct Node * Temp = new struct Node;
			Temp = First;
			First->Next = First;
			delete Temp;
			Counter--;
		}
	}
	void RemoveLastElement()
	{
		if (First == NULL)
		{
			throw std::out_of_range("LinkedList is empty");
		}
		else if (Counter == 1)
		{
			delete First;
			delete Last;
			Counter--;
		}
		else
		{
			struct Node * Current = new struct Node;
			struct Node * Previous = new struct Node;
			Current = First;
			while (Current->Next != NULL)
			{
				Previous = Current;
				Current = Current->Next;
			}
			Last = Previous;
			Previous->Next = NULL;
			delete Current;
			Counter--;
		}
	}
	void RemoveElementAtPosition(int position)
	{
		if (Counter < position)
		{
			throw std::out_of_range("LinkedList does not have that many elements");
		}
		struct Node * Current = new struct Node;
		struct Node * Previous = new struct Node;
		Current = First;
		for (int i = 1; i < position; i++)
		{
			Previous = Current;
			Current = Current->Next;
		}
		Previous->Next = Current->Next;
		delete Current;
		Counter--;
	}
	datatype PeekFirstElement()
	{
		if (Counter == 0)
		{
			throw std::out_of_range("Queue is empty");
		}
		struct Node * Temp = First;
		return Temp->Element;
	}
	int ReturnCount()
	{
		return Counter;
	}
	datatype PeekByPosition(int position)
	{
		if (Counter < position)
		{
			throw std::out_of_range("LinkedList does not have that many elements");
		}
		struct Node * Current = new struct Node;
		Current = First;
		for (int i = 1; i < position; i++)
		{
			Current = Current->Next;
		}
		return Current->Element;
	}
	datatype PeekLastElement()
	{
		if (Counter == 0)
		{
			throw std::out_of_range("Queue is empty");
		}
		struct Node * Temp = Last;
		return Temp->Element;
	}
};