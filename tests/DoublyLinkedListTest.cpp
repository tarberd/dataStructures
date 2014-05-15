#include <gtest/gtest.h>

#include <stdexcept>
#include "DoublyLinkedList.h"

using structures::DoublyLinkedList;

class DoublyLinkedListTest : public testing::Test {
public:
	DoublyLinkedList<int> list;
};

TEST_F(DoublyLinkedListTest, emptyListIsEmpty)
{
	EXPECT_TRUE(list.isEmpty());
}

TEST_F(DoublyLinkedListTest, sizeOfEmptyListEqualsZero)
{
	EXPECT_EQ(0, list.size());
}

TEST_F(DoublyLinkedListTest, pushPopFrontOneElement)
{
	list.pushFront(42);
	EXPECT_EQ(1, list.size());
	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(42, list.popFront());
	EXPECT_EQ(0, list.size());
	EXPECT_TRUE(list.isEmpty());
}

TEST_F(DoublyLinkedListTest, popFrontFromEmptyList)
{
	EXPECT_THROW(list.popFront(), std::length_error);
}

TEST_F(DoublyLinkedListTest, pushPopFrontManyElements)
{
	list.pushFront(42);
	list.pushFront(1908);
	list.pushFront(9);
	EXPECT_EQ(3 , list.size());
	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(9, list.popFront());
	EXPECT_EQ(1908, list.popFront());
	EXPECT_EQ(42, list.popFront());
	EXPECT_EQ(0, list.size());
	EXPECT_TRUE(list.isEmpty());
}

TEST_F(DoublyLinkedListTest, pushPopBackOneElement)
{
	list.pushBack(42);
	EXPECT_EQ(1, list.size());
	EXPECT_EQ(42, list.popBack());
	EXPECT_EQ(0, list.size());
}

TEST_F(DoublyLinkedListTest, pushPopBackManyElements)
{
	list.pushBack(42);
	list.pushBack(1908);
	list.pushBack(9);
	EXPECT_EQ(3 , list.size());
	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(9, list.popBack());
	EXPECT_EQ(1908, list.popBack());
	EXPECT_EQ(42, list.popBack());
	EXPECT_EQ(0, list.size());
	EXPECT_TRUE(list.isEmpty());
}