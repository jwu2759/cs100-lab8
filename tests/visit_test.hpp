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

std::string PrintMathML(Base* ptr){
	VisitMathML v;
	std::string output;
	Iterator iter(ptr);
        while(!iter.is_done()){
                iter.current_node()->accept(&v, iter.current_index());
		
                iter.next();
        }
	v.getMathML(output);
	return output;
}

TEST(mathMLTest, mathMLAdd){
	VisitMathML v;
	Add* test = new Add(new Op(3), new Op(2));
	EXPECT_EQ(PrintMathML(test), "<math>\n\t<apply>\n\t\t<plus/>\n\t\t<cn>3</cn>\n\t\t<cn>2</cn>\n\t</apply>\n</math>\n");
}

TEST(mathMLTest, mathMLMult){
	VisitMathML v;
	Mult* test = new Mult(new Op(3), new Op(2));
        EXPECT_EQ(PrintMathML(test), "<math>\n\t<apply>\n\t\t<times/>\n\t\t<cn>3</cn>\n\t\t<cn>2</cn>\n\t</apply>\n</math>\n");
}

TEST(mathMLTest, mathMLSub){
	VisitMathML v;
	Sub* test = new Sub(new Op(3), new Op(2));
	EXPECT_EQ(PrintMathML(test), "<math>\n\t<apply>\n\t\t<minus/>\n\t\t<cn>3</cn>\n\t\t<cn>2</cn>\n\t</apply>\n</math>\n");
}

TEST(mathMLTest, mathMLDiv){
        VisitMathML v;
        Div* test = new Div(new Op(3), new Op(2));
        EXPECT_EQ(PrintMathML(test), "<math>\n\t<apply>\n\t\t<divide/>\n\t\t<cn>3</cn>\n\t\t<cn>2</cn>\n\t</apply>\n</math>\n");
}

TEST(mathMLTest, mathMLPow){
        VisitMathML v;
        Pow* test = new Pow(new Op(3), new Op(2));
        EXPECT_EQ(PrintMathML(test), "<math>\n\t<apply>\n\t\t<power/>\n\t\t<cn>3</cn>\n\t\t<cn>2</cn>\n\t</apply>\n</math>\n");
}








#endif
