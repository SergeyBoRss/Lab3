#include "postfix.h"
#include "TStack.h"

#include <gtest.h>
#include <cmath>

TEST(TArithmeticExpression, can_create_postfix) {
    ASSERT_NO_THROW(TArithmeticExpression test("1+2"));
}


TEST(TArithmeticExpression, get_infix) {
    TArithmeticExpression test("1+2");

    ASSERT_EQ("1+2", test.GetInfix());
}

TEST(TArithmeticExpression, get_postfix1) {
    TArithmeticExpression test("1+2");

    test.ToPostfix();
    ASSERT_EQ("1 2 + ", test.GetPostfix());
}


TEST(TArithmeticExpression, get_postfix2) {
    TArithmeticExpression test("1+(2+3)");

    test.ToPostfix();
    ASSERT_EQ("1 2 3 + + ", test.GetPostfix());
}

TEST(TArithmeticExpression, get_postfix3) {
    TArithmeticExpression test("1+(2+3)+4");

    test.ToPostfix();
    ASSERT_EQ("1 2 3 + + 4 + ", test.GetPostfix());
}

TEST(TArithmeticExpression, get_postfix_with_mul1) {
    TArithmeticExpression test("3*(1+2)");

    test.ToPostfix();
    ASSERT_EQ("3 1 2 + * ", test.GetPostfix());
}

TEST(TArithmeticExpression, get_postfix_with_mul2) {
    TArithmeticExpression test("1+2*3");

    test.ToPostfix();
    ASSERT_EQ("1 2 3 * + ", test.GetPostfix());
}

TEST(TArithmeticExpression, get_postfix_with_mul3) {
    TArithmeticExpression test("1+2*3/2");

    test.ToPostfix();
    ASSERT_EQ("1 2 3 * 2 / + ", test.GetPostfix());
}

TEST(TArithmeticExpression, get_postfix_with_mul4) {
    TArithmeticExpression test("(2+1)*1/2");

    test.ToPostfix();
    ASSERT_EQ("2 1 + 1 * 2 / ", test.GetPostfix());
}

TEST(TArithmeticExpression, get_postfix_with_all) {
    TArithmeticExpression test("1/(7-(1+1))*3-(2+(1+1))*1/(7-(2+1))*3-(2+(1+1))*(1/(7-(1+1)))*3+10");

    test.ToPostfix();
    double ans = round(test.Calculate() * 100.0) / 100.0;

    ASSERT_EQ(5.2, ans);

}

TEST(TArithmeticExpression, with_incorrect_parenthesis_sequence) {

    ASSERT_ANY_THROW(TArithmeticExpression test("((2+3)"));
}

TEST(TArithmeticExpression, incorrect_signs) {
    TArithmeticExpression test("2++3");
    test.ToPostfix();

    ASSERT_ANY_THROW(test.Calculate());
}


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
