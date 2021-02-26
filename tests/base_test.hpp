#ifndef __BASE_TEST_HPP__
#define __BASE_TEST_HPP__

#include "gtest/gtest.h"
#include "../base.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, StringifyDouble) {
    Op* test = new Op(8.5);
    EXPECT_EQ(test->stringify(), "8.5");
}

TEST(OpTest, StringifyNegDouble){
    Op* test = new Op(-8.5);
    EXPECT_EQ(test->stringify(), "-8.5");
}

TEST(OpTest, StringifyInt){
    Op* test = new Op(4);
    EXPECT_EQ(test->stringify(), "4");
}

TEST(AddTest, AddEvaluateFive){
	Op* test1 = new Op(3);
	Op* test2 = new Op(2);
	Add* add = new Add(test1, test2);
	EXPECT_EQ(add->evaluate(), 5.0);
	EXPECT_EQ(add->stringify(), "(3+2)");
}

TEST(AddTest, AddEvaluateZero){
	Op* test1 = new Op(0);
	Op* test2 = new Op(0); 
	Add* add = new Add(test1, test2);
	EXPECT_EQ(add->evaluate(), 0.0);
	EXPECT_EQ(add->stringify(), "(0+0)");
}

TEST(AddTest, AddEvaluateRecursive){
	Op* test1 = new Op(3);
	Op* test2 = new Op(2);
	Op* test3 = new Op(2);
	Add* add1 = new Add(test1, test2);
	Add* add2 = new Add(add1, test3);
	EXPECT_EQ(add2->evaluate(), 7.0);
	EXPECT_EQ(add2->stringify(), "((3+2)+2)");
}

TEST(SubTest, SubTwoOneAndFiveTwo){
	Op* left = new Op(2.1);
	Op* right = new Op(5.2);
	Sub* subTest = new Sub(left, right);
	EXPECT_EQ(subTest->evaluate(), -3.1);
}

TEST(SubTest, SubTwoOneAndFiveTwoStringify){
	Op* left = new Op(2.1);
	Op* right = new Op(5.2);
	Sub* subTest = new Sub(left, right);
	EXPECT_EQ(subTest->stringify(), "(2.1-5.2)");
}

TEST(SubTest, SubFiveTwoAndTwoOne){
	Op* left = new Op(5.2);
	Op* right = new Op(2.1);
	Sub* subTest = new Sub(left, right);
	EXPECT_EQ(subTest->evaluate(), 3.1);
}

TEST(SubTest, SubFiveTwoAndTwoOneStringify){
	Op* left = new Op(5.2);
	Op* right = new Op(2.1);
	Sub* subTest = new Sub(left, right);
	EXPECT_EQ(subTest->stringify(), "(5.2-2.1)");
}

TEST(SubTest, SubRecursive){
	Op* left = new Op(5.2);
	Op* right = new Op(2.2);
	Sub* sub1 = new Sub(left, right);
	Sub* sub2 = new Sub(sub1, right);
	EXPECT_DOUBLE_EQ(sub2->evaluate(), 0.8);	
}

TEST(SubTest, SubRecursiveStringify){
	Op* left = new Op(5.2);
	Op* right = new Op(2.2);
	Sub* sub1 = new Sub(left, right);
	Sub* sub2 = new Sub(sub1, right);
	EXPECT_EQ(sub2->stringify(), "((5.2-2.2)-2.2)");	
}

TEST(MultTest, DivEvaluateZero){
	Op* x1 = new Op(0);
	Op* x2 = new Op(5);
	Mult* mult = new Mult(x1, x2);
	EXPECT_DOUBLE_EQ(mult->evaluate(), 0);
	EXPECT_EQ(mult->stringify(), "(0*5)");
}

TEST(MultTest, MultEvaluateNonZero){
        Op* x1 = new Op(5);
        Op* x2 = new Op(3);
        Mult* mult = new Mult(x1, x2);
        EXPECT_DOUBLE_EQ(mult->evaluate(), 15);
        EXPECT_EQ(mult->stringify(), "(5*3)");
}

TEST(MultTest, MultEvaluateRecursive){
        Op* x1 = new Op(3);
        Op* x2 = new Op(5);
	Op* x3 = new Op(2);
        Mult* mult = new Mult(x1, x2);
	Mult* mult1 = new Mult(mult, x3);
        EXPECT_DOUBLE_EQ(mult1->evaluate(), 30);
        EXPECT_EQ(mult1->stringify(), "((3*5)*2)");
}

TEST(DivTest, DivEvaluateTwo){
	Op* x1 = new Op(10);
	Op* x2 = new Op(5);
	Div* div = new Div(x1, x2);
	EXPECT_DOUBLE_EQ(div->evaluate(), 2);
	EXPECT_EQ(div->stringify(), "(10/5)");
}

TEST(DivTest, DivEvaluateZero){
        Op* x1 = new Op(0);
        Op* x2 = new Op(3);
        Div* div = new Div(x1, x2);
        EXPECT_DOUBLE_EQ(div->evaluate(), 0);
        EXPECT_EQ(div->stringify(), "(0/3)");
}

TEST(DivTest, DivEvaluateRecursive){
        Op* x1 = new Op(10);
        Op* x2 = new Op(5);
	Op* x3 = new Op(2);
        Div* div = new Div(x1, x2);
	Div* div1 = new Div(div, x3);
        EXPECT_DOUBLE_EQ(div1->evaluate(), 1);
        EXPECT_EQ(div1->stringify(), "((10/5)/2)");
}

TEST(PowTest, PowDoubleToDouble){
	Op* test1 = new Op(2.5);
	Op* test2 = new Op(1.5);
	Pow* powTest = new Pow(test1,test2);
	EXPECT_NEAR(powTest->evaluate(), 3.953, 0.001);
}

TEST(PowTest, PowDoubleToDoubleStringify){
	Op* test1 = new Op(2.5);
	Op* test2 = new Op(1.5);
	Pow* powTest = new Pow(test1,test2);
	EXPECT_EQ(powTest->stringify(), "(2.5**1.5)");
}

TEST(PowTest, PowDoubleToNegDouble){
	Op* test1 = new Op(2.5);
	Op* test2 = new Op(-1.5);
	Pow* powTest = new Pow(test1,test2);
	EXPECT_NEAR(powTest->evaluate(), 0.253, 0.001);
}

TEST(PowTest, PowDoubleToNegDoubleStringify){
	Op* test1 = new Op(2.5);
	Op* test2 = new Op(-1.5);
	Pow* powTest = new Pow(test1,test2);
	EXPECT_EQ(powTest->stringify(), "(2.5**-1.5)");
}

TEST(PowTest, PowDoubleToZero){
	Op* test1 = new Op(2.5);
	Op* test2 = new Op(0);
	Pow* powTest = new Pow(test1,test2);
	EXPECT_DOUBLE_EQ(powTest->evaluate(), 1);
}

TEST(PowTest, PowDoubleToZeroStringify){
	Op* test1 = new Op(2.5);
	Op* test2 = new Op(0);
	Pow* powTest = new Pow(test1,test2);
	EXPECT_EQ(powTest->stringify(), "(2.5**0)");
}

TEST(PowTest, PowZeroToDouble){
	Op* test1 = new Op(0);
	Op* test2 = new Op(1.5);
	Pow* powTest = new Pow(test1,test2);
	EXPECT_DOUBLE_EQ(powTest->evaluate(), 0);
}

TEST(PowTest, PowZeroToDoubleStringify){
	Op* test1 = new Op(0);
	Op* test2 = new Op(1.5);
	Pow* powTest = new Pow(test1,test2);
	EXPECT_EQ(powTest->stringify(), "(0**1.5)");
}

TEST(RandTest, RandTest1){
	Rand* x = new Rand();
	EXPECT_DOUBLE_EQ(x->evaluate(), 83);
}

TEST(RandTest, RandTest2){
        Rand* x = new Rand();
        EXPECT_DOUBLE_EQ(x->evaluate(), 86);
}

TEST(RandTest, RandTest3){
        Rand* x = new Rand();
        EXPECT_DOUBLE_EQ(x->evaluate(), 77);
}


#endif

