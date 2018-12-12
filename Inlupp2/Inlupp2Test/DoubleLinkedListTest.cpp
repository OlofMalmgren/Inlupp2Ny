#include "gtest/gtest.h"
#include "pch.h"
#include "../Inlupp2/DoubleLinkedList.h"
TEST(DoubleLinkedListTest, OneAddedIntIdShouldBeEqualTooOne) {
	DoubleLinkedlist<int> dll;
	dll.AddInBeginning(1);
	EXPECT_EQ(1, dll.GetSizeOfDoubleLinkedList());
}
TEST(DoubleLinkedListTest, AddHigherThanOneShouldReturnNULL) {
	DoubleLinkedlist<int> dll;

	EXPECT_THROW(dll.AddByIndex(2, 2), std::out_of_range);
}

TEST(DoubleLinkedListTest, IfIntIdEquallToGetIntIdThenTrue) {
	DoubleLinkedlist<int> dll;
	dll.AddInBeginning(1);
	dll.AddByIndex(2, 1);
	dll.AddByIndex(3, 2);
	dll.AddByIndex(4, 3);
	dll.AddByIndex(10, 2);

	EXPECT_EQ(10, dll.GetIteamById(10));
}
TEST(DoubleLinkedListTest, ShouldNotBeAbleToGetId3) {
	DoubleLinkedlist<int> dll;
	dll.AddInBeginning(1);
	dll.AddByIndex(2, 1);
	dll.AddByIndex(3, 2);
	dll.AddByIndex(4, 3);
	dll.AddByIndex(5, 4);
	dll.AddByIndex(6, 2);
	dll.DeleteIteam(3);

	EXPECT_THROW(dll.GetIteamById(3), std::out_of_range);
}
TEST(DoubleLinkedListTest, AddString) {
	DoubleLinkedlist<std::string> dll;
	dll.AddInBeginning("a");

	EXPECT_EQ("a", dll.GetIteamById("a"));
}
TEST(DoubleLinkedListTest, ShouldNotBeAbleToGetStringA) {
	DoubleLinkedlist<std::string> dll;
	dll.AddInBeginning("a");
	dll.AddByIndex("b", 1);
	dll.DeleteIteam("b");


	EXPECT_THROW(dll.GetIteamById("b"), std::out_of_range);
}

TEST(DoubleLinkedListTest, FiveAddedStringShouldBeEqualTooFive)
{
	DoubleLinkedlist<std::string> dll;
	dll.AddInBeginning("a");
	dll.AddByIndex("b", 1);
	dll.AddByIndex("c", 2);
	dll.AddByIndex("d", 3);
	dll.AddByIndex("e", 4);

	EXPECT_EQ(5, dll.GetSizeOfDoubleLinkedList());
}
TEST(DoubleLinkedListTest, ShouldNotBeAbleToPrintList)
{
	DoubleLinkedlist<std::string> dll;


	EXPECT_THROW(dll.print(), std::out_of_range);
}
