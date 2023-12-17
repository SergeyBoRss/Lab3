#include "postfix.h"

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
