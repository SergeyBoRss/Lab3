#include "TStack.h"

#include <gtest.h>


TEST(TStack, can_create_stack) {
    ASSERT_NO_THROW(TStack<int> s);
}

TEST(TStack, can_create_copied_stack) {
    TStack<int> s;
    ASSERT_NO_THROW(TStack<int> s1(s));
}

TEST(TStack, can_is_empty) {
    TStack<int> s;
    ASSERT_TRUE(s.isEmpty());
}

TEST(TStack, can_is_full) {
    TStack<int> s;
    s.Push(1);
    ASSERT_TRUE(s.isFull());
}

TEST(TStack, can_push) {
    TStack<int> s;
    s.Push(1);
    ASSERT_EQ(1, s.Top());
}

TEST(TStack, throw_top_with_empty) {
    TStack<int> s;
    ASSERT_ANY_THROW(s.Top());
}

TEST(TStack, can_pop) {
    TStack<int> s;
    s.Push(1);
    ASSERT_NO_THROW(s.Pop());
}

TEST(TStack, throw_pop_with_empty) {
    TStack<int> s;
    ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, can_compare_stack) {
    TStack<int> s1;
    s1.Push(1);
    TStack<int> s2;
    s2.Push(1);
    ASSERT_TRUE(s1 == s2);
}

TEST(TStack, can_asign_stack) {
    TStack<int> s1;
    s1.Push(1);
    TStack<int> s2;
    s2 = s1;
    ASSERT_EQ(1, s2.Top());
}
