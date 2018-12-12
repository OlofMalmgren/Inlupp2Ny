#include "pch.h"
#include "../Inlupp2/Queue.h"

TEST(QueueTests, WhenAddingElementsCountShouldIncrease)
{
	Queue<int> CountIncreaseTest;
	CountIncreaseTest.AddElement(1);
	CountIncreaseTest.AddElement(2);
	CountIncreaseTest.AddElement(3);
	EXPECT_EQ(3, CountIncreaseTest.ReturnCount());
}

TEST(QueueTests, WhenSubtractingElementsCountShouldDecrease)
{
	Queue<int> CountDecreaseTest;
	CountDecreaseTest.AddElement(1);
	CountDecreaseTest.AddElement(2);
	CountDecreaseTest.AddElement(3);
	CountDecreaseTest.RemoveElement();
	CountDecreaseTest.RemoveElement();
	EXPECT_EQ(1, CountDecreaseTest.ReturnCount());
}

TEST(QueueTests, TestForQueueWithString)
{
	Queue<std::string> StringTest;
	StringTest.AddElement("Hej");
	StringTest.AddElement("Hej2");
	EXPECT_EQ("Hej", StringTest.Peek());
}

TEST(QueueTests, TestForQueueWithInt)
{
	Queue<int> IntTest;
	IntTest.AddElement(1);
	IntTest.AddElement(2);
	EXPECT_EQ(1, IntTest.Peek());
}

TEST(QueueTests, TestForQueueWithFloat)
{
	Queue<float> FloatTest;
	FloatTest.AddElement(1.3f);
	FloatTest.AddElement(3.4f);
	EXPECT_EQ(1.3f, FloatTest.Peek());
}

TEST(QueueTests, PeekShouldReturnFirstAddedElement)
{
	Queue<int> PeekTest;
	PeekTest.AddElement(2);
	PeekTest.AddElement(3);
	EXPECT_EQ(2, PeekTest.Peek());
}

TEST(QueueTests, PeekShouldNotChangeCount)
{
	Queue<int> PeekCountTest;
	PeekCountTest.AddElement(1);
	PeekCountTest.AddElement(2);
	PeekCountTest.AddElement(3);
	PeekCountTest.Peek();
	EXPECT_EQ(3, PeekCountTest.ReturnCount());
}

TEST(QueueTests, RemoveFunctionShouldRemoveFirstAddedElement)
{
	Queue<int> RemoveTest;
	RemoveTest.AddElement(1);
	RemoveTest.AddElement(2);
	RemoveTest.RemoveElement();
	EXPECT_EQ(2, RemoveTest.Peek());
}

TEST(QueueTests, PeekShouldExitIfQueueIsEmpty)
{
	Queue<int> PeekEmptyQueue;
	EXPECT_THROW(PeekEmptyQueue.Peek(), std::out_of_range);
}