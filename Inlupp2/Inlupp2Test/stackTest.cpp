#include <gtest/gtest.h>
#include "../Inlupp2/Stack.h"


TEST(VectorStackListTest, PushFunctionShouldFillTheStack)
{
	StackV<int> stacklist;
	stacklist.push(1);
	stacklist.push(2);
	stacklist.push(3);
	EXPECT_EQ(3, stacklist.size());

}

TEST(VectorStackListTest, PushFunctionShouldFillTheStackWithString)
{
	StackV<string> stacklist;
	stacklist.push("sdadsf");
	stacklist.push("asdsa");
	stacklist.push("asdasd");
	EXPECT_EQ(3, stacklist.size());

}


TEST(VectorStackListTest, RemoveTheFirstElement)
{
	StackV<int> stacklist;
	stacklist.push(1);
	stacklist.push(2);
	stacklist.push(3);
	stacklist.push(4);
	stacklist.pop(1);
	EXPECT_EQ(3, stacklist.size());

}


TEST(VectorStackListTest, IfTheListIsEmpty)
{
	StackV<int> stacklist;
	stacklist.push(2);
	EXPECT_EQ(false, stacklist.empty());
}