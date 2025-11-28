// тесты для стека

#include "stack.h"
#include <gtest.h>

TEST(stack, can_create_stack)
{
	ASSERT_NO_THROW(stack<int> a());
}
TEST(stack, can_add_elements_to_stack)
{
	stack<int> a;
	a.push(1);
	EXPECT_EQ(a.get(), 1);
}
TEST(stack, can_return_size)
{
	stack<int> a;
	EXPECT_EQ(a.size(), 0);
	a.push(1);
	EXPECT_EQ(a.size(), 1);
	a.push(2);
	EXPECT_EQ(a.size(), 2);
}
TEST(stack, throws_if_trying_to_get_from_empty_stack)
{
	stack<int> a;
	ASSERT_ANY_THROW(a.get());
}
TEST(stack, throw_if_pop_from_empty_stack)
{
	stack<int> a;
	ASSERT_ANY_THROW(a.pop());
}
TEST(stack, can_clear_stack)
{
	stack<int> a;
	a.push(1);
	a.clear();
	EXPECT_EQ(a.size(), 0);
}
TEST(stack, can_push_and_pop_many)
{
	stack<int> a;
	for (int i = 0; i < 1000; i++) {
		ASSERT_NO_THROW(a.push(i));
	}
	for (int i = 999; i>=500; i--) {
		EXPECT_EQ(a.pop(), i);
	}
	EXPECT_EQ(a.size(), 500);
}
TEST(stack, can_check_if_empty)
{
	stack<int> a;
	EXPECT_EQ(a.is_empty(), true);
	a.push(1);
	EXPECT_EQ(a.is_empty(), false);
}