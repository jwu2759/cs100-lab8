#include <bits/stdc++.h>
#include "base.hpp"
#include "visitor.hpp"
#include "iterator.hpp"

std::string PrintLaTeX(Base* ptr){
	VisitorLatex v;
	std::string output;
	//std::cout << "$";
	Iterator iter(ptr);
	while(!iter.is_done()){
		iter.current_node()->accept(&v, iter.current_index());	
		iter.next();
	}
	v.getLatex(output);
	//std::cout << "$";
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

int main(){
	Add* a = new Add(new Op(3), new Op(5));
	Add* b = new Add(new Op(1),
			new Sub(new Op(5),
				new Op(0)));
	Mult* c = new Mult(new Op(2),
			new Op(5));
	Div* d = new Div(new Op(2),
			new Op(3));
	Div* e = new Div(
			new Mult(
				new Op(2),
				new Op(5)
			),
			new Pow(
				new Op(5),
				new Op(2)
			)
		);
	std::vector<std::string> latex;
	latex.push_back(PrintLaTeX(a));
	//std::cout << std::endl;
	latex.push_back(PrintLaTeX(b));
	//std::cout << std::endl;
	latex.push_back(PrintLaTeX(c));
	//std::cout << std::endl;
	latex.push_back(PrintLaTeX(d));
	//std::cout << std::endl;
	latex.push_back(PrintLaTeX(e));
	//std::cout << std::endl;

	std::vector<std::string> mathML;
	mathML.push_back(PrintMathML(a));
	mathML.push_back(PrintMathML(b));
	mathML.push_back(PrintMathML(c));
	mathML.push_back(PrintMathML(d));
	mathML.push_back(PrintMathML(e));

	std::cout << "All expressions:" << std::endl;
	for(int i = 0; i < latex.size(); ++i){
		std::cout << latex[i] << std::endl;
	}
	for(int i = 0; i < mathML.size(); i++){
		std::cout << mathML[i] << std::endl;
	}
	
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	return 0;
}
