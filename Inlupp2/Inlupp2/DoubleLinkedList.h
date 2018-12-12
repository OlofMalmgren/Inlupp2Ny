#pragma once
#include <iostream>
using namespace std;


template <class Datatype>
class DoubleLinkedlist
{
public:

	void AddInBeginning(Datatype id)
	{
		struct Node* new_node = new struct Node;

		new_node->ID = id;
		new_node->Next = NULL;

		if (First == NULL)
		{
			Last = new_node;
		}
		else
		{
			First->Prev = new_node;
		}
		new_node->Next = First;
		First = new_node;
	}

	void AddByIndex(Datatype id, int position)
	{
		struct Node* insertBefore = NULL;
		struct Node* newNode = new struct Node;
		insertBefore = First;
		if (insertBefore == NULL)
		{
			throw std::out_of_range("Länkade listan är tom.");
		}
		for (int i = 1; i < position; i++)
		{
			insertBefore = insertBefore->Next;
		}
		newNode->ID = id;

		struct Node* insertAfter = NULL;
		if (position > 1)insertAfter = insertBefore->Prev;
		insertBefore->Prev = newNode;
		newNode->Next = insertBefore;
		if (position == 1) First = newNode;
		else
		{
			insertAfter->Next = newNode;
			newNode->Prev = insertAfter;
		}
	}


	void DeleteIteam(Datatype id)
	{
		Node*  Current = First;
		Node* Previous = NULL;

		if (First == NULL)
		{
			return;
		}

		while (Current->ID != id)
		{

			if (Current->Next == NULL)
			{
				return;
			}
			else {
				Previous = Current;

				Current = Current->Next;
			}
		}
		if (Current == First)
		{
			First = First->Next;
		}
		else
		{
			Current->Prev->Next = Current->Next;
		}
		if (Current == Last)
		{
			Last = Current->Prev;
		}
		else {
			Current->Next->Prev = Current->Prev;
		}

		return;

	}

	Datatype GetIteamById(Datatype id)
	{
		while (First != NULL)
		{
			if (First->ID == id)
			{

				return First->ID;
			}
			First = First->Next;
		}
		throw std::out_of_range("Id existerar inte.");
	}

	int GetSizeOfDoubleLinkedList()
	{
		int count = 0;
		Node* current = First;
		while (current != NULL)
		{
			count++;
			current = current->Next;
		}
		return count;
	}
	void print()
	{
		struct Node* temp = First;
		while (temp != NULL)
		{
			printf("%d", temp->ID);
			temp = temp->Next;
		}
		throw std::out_of_range("Länkade listan är tom.");

	}
private:
	struct Node
	{
		Datatype ID;
		struct Node *Next;
		struct Node* Prev;

	};
	struct Node* Last = NULL;
	struct Node* First = NULL;






};

