#include <bits/stdc++.h>
#include "base.hpp"
#include "visitor.hpp"
#include "iterator.hpp"

void PrintLaTeX(Base* ptr){
	VisitorLatex v;
	std::cout << "$";
	Iterator iter(ptr);
	while(!iter.is_done()){
		iter.current_node()->accept(&v, iter.current_index());	
		iter.next();
	}
	std::cout << "$";

}

int main(){
	Add* a = new Add(new Op(3), new Op(5));
	Add* b = new Add(new Op(1),
			new Sub(new Op(5),
				new Op(0)));
	PrintLaTeX(a);
	std::cout << std::endl;
	PrintLaTeX(b);
	std::cout << std::endl;
	return 0;
}
