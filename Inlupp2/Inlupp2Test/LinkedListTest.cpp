#include "pch.h"
#include "../Inlupp2/LinkedList.h"


TEST(LinkedListTests, WhenAddingElementsCountShouldIncrease)
{
	LinkedList<int> CountIncreaseTest;
	CountIncreaseTest.AddElementAtStart(1);
	CountIncreaseTest.AddElementAtStart(2);
	EXPECT_EQ(2, CountIncreaseTest.ReturnCount());
}

TEST(LinkedListTests, WhenSubtractingElementsCountShouldDecrease)
{
	LinkedList<int> CountDecreaseTest;
	CountDecreaseTest.AddElementAtStart(1);
	CountDecreaseTest.AddElementAtStart(3);
	CountDecreaseTest.RemoveLastElement();
	EXPECT_EQ(1, CountDecreaseTest.ReturnCount());
}

TEST(LinkedListTests, TestForLinkedListWithString)
{
	LinkedList<std::string> StringTest;
	StringTest.AddElementAtStart("Hej");
	StringTest.AddElementAtStart("Hej igen");
	EXPECT_EQ("Hej igen", StringTest.PeekFirstElement());
}

TEST(LinkedListTests, TestForLinkedListWithInt)
{
	LinkedList<int> IntTest;
	IntTest.AddElementAtStart(1);
	IntTest.AddElementAtStart(5);
	EXPECT_EQ(5, IntTest.PeekFirstElement());
}

TEST(LinkedListTests, TestForLinkedListWithFloat)
{
	LinkedList<float> FloatTest;
	FloatTest.AddElementAtStart(1.3f);
	FloatTest.AddElementAtStart(4.6f);
	EXPECT_EQ(4.6f, FloatTest.PeekFirstElement());
}

TEST(LinkedListTests, PeekShouldNotChangeCount)
{
	LinkedList<int> PeekCountTest;
	PeekCountTest.AddElementAtStart(1);
	PeekCountTest.AddElementAtStart(5);
	PeekCountTest.PeekFirstElement();
	EXPECT_EQ(2, PeekCountTest.ReturnCount());
}

TEST(LinkedListTests, PeekShouldExitIfQueueIsEmpty)
{
	LinkedList<int> PeekEmptyQueue;
	EXPECT_THROW(PeekEmptyQueue.PeekFirstElement(), std::out_of_range);
}

TEST(LinkedListTests, PeekFirstElementShouldReturnFirstElementInList)
{
	LinkedList<int> PeekFirst;
	PeekFirst.AddElementAtStart(1);
	PeekFirst.AddElementAtStart(4);
	PeekFirst.AddElementAtStart(7);
	EXPECT_EQ(7, PeekFirst.PeekFirstElement());
}

TEST(LinkedListTests, PeekByPositionShouldReturnElementInGivenPosition)
{
	LinkedList<int> PeekByPosTest;
	PeekByPosTest.AddElementAtStart(1);
	PeekByPosTest.AddElementAtStart(2);
	PeekByPosTest.AddElementAtStart(5);
	PeekByPosTest.AddElementAtStart(6);
	EXPECT_EQ(2, PeekByPosTest.PeekByPosition(3));
}

TEST(LinkedListTests, PeekLastElementShouldReturnLastElementInList)
{
	LinkedList<int> PeekLast;
	PeekLast.AddElementAtStart(1);
	PeekLast.AddElementAtStart(4);
	PeekLast.AddElementAtStart(7);
	EXPECT_EQ(1, PeekLast.PeekLastElement());
}

TEST(LinkedListTests, RemoveElementAtPositionShouldRemoveElementAtGivenPosition)
{
	LinkedList<int> RemovePos;
	RemovePos.AddElementAtStart(4);
	RemovePos.AddElementAtStart(3);
	RemovePos.AddElementAtStart(2);
	RemovePos.AddElementAtStart(1);
	RemovePos.RemoveElementAtPosition(2);
	EXPECT_EQ(3, RemovePos.PeekByPosition(2));
}

TEST(LinkedListTests, RemoveElementAtPositionShouldThrowWhenPositionDoesntExist)
{
	LinkedList<int> RemovePosThrow;
	RemovePosThrow.AddElementAtStart(1);
	EXPECT_THROW(RemovePosThrow.RemoveElementAtPosition(2), std::out_of_range);
}

TEST(LinkedListTests, AddElementAtPositionShouldAddElementInGivenPosition)
{
	LinkedList<int> AddByPos;
	AddByPos.AddElementAtStart(1);
	AddByPos.AddElementAtStart(2);
	AddByPos.AddElementAtStart(3);
	AddByPos.AddElementAtPosition(15, 3);
	EXPECT_EQ(15, AddByPos.PeekByPosition(3));
}

//TEST(LinkedListTests, AddElementAtPositionShouldThrowIfPositionDoesntExist)
//{
//	LinkedList<int> AddElementAtPositionThrow;
//	EXPECT_THROW(AddElementAtPositionThrow.AddElementAtPosition(2, 2), std::out_of_range);
//}