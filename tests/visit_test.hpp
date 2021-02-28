#ifndef __VISIT_TEST__
#define __VISIT_TEST__
#include "gtest/gtest.h"
#include <bits/stdc++.h>
#include "../base.hpp"
#include "../visitor.hpp"
#include "../iterator.hpp"

std::string PrintLaTeX(Base* ptr);

TEST(VisitTest, VisitOp) {
	VisitorLatex v;
	Op* test = new Op(3);
	EXPECT_EQ(PrintLaTeX(test), "${3}$");
}

TEST(VisitTest, VisitRand) {
	VisitorLatex v;
	Op* test = new Op(3);
	EXPECT_EQ(PrintLaTeX(test), "${3}$");
}

//TEST(VisitTest, VisitRand){
	//it doesn't make sense to test rand???	
//}

TEST(VisitTest, VisitAdd){
	VisitorLatex v;
	Add* test = new Add(new Op(3), new Op(5));
	EXPECT_EQ(PrintLaTeX(test), "${({3}+{5})}$");
}

TEST(VisitTest, VisitSub){
	VisitorLatex v;
	Sub* test = new Sub(new Op(3), new Op(5));
	EXPECT_EQ(PrintLaTeX(test), "${({3}-{5})}$");

}

TEST(VisitTest, VisitMult){
	VisitorLatex v;
	Mult* test = new Mult(new Op(3), new Op(5));
	EXPECT_EQ(PrintLaTeX(test), "${({3}\\cdot{5})}$");
}

TEST(VisitTest, VisitDiv){
	VisitorLatex v;
	Div* test = new Div(new Op(3), new Op(5));
	EXPECT_EQ(PrintLaTeX(test), "${\\frac{3}{5}}$");
}


TEST(VisitTest, VisitPow){
	VisitorLatex v;
	Pow* test = new Pow(new Op(3), new Op(5));
	EXPECT_EQ(PrintLaTeX(test), "${({3}^{5})}$");
}

std::string PrintLaTeX(Base* ptr){
	VisitorLatex v;
	std::string output;
	Iterator iter(ptr);
	while(!iter.is_done()){
		iter.current_node()->accept(&v, iter.current_index());	
		iter.next();
	}
	v.getLatex(output);
	return output;
}
#endif
