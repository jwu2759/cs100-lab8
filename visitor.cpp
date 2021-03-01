#include "visitor.hpp"
#include "base.hpp"
void VisitorLatex::visit_op(Op* node){
	//std::cout << "{" << node->stringify() << "}";
	os += "{" +  node->stringify() + "}";
}
void VisitorLatex::visit_rand(Rand* node){
	//std::cout << "{" << node->stringify() << "}";
	os += "{" + node->stringify() + "}";
}
void VisitorLatex::visit_add_begin(Add* node){
	//std::cout << "{(";
	os += "{(";
}
void VisitorLatex::visit_add_middle(Add* node){
	//std::cout << "+";
	os += "+";
}
void VisitorLatex::visit_add_end(Add* node){
	//std::cout << ")}";
	os += ")}";
}
void VisitorLatex::visit_sub_begin(Sub* node){
	//std::cout << "{(";
	os += "{(";
}
void VisitorLatex::visit_sub_middle(Sub* node){
	//std::cout << "-";
	os += "-";
}
void VisitorLatex::visit_sub_end(Sub* node){
	//std::cout << ")}";
	os += ")}";
}
void VisitorLatex::visit_mult_begin(Mult* node){
	//std::cout << "{(";
	os += "{(";
}
void VisitorLatex::visit_mult_middle(Mult* node){
	//std::cout << "\\cdot";
	os += "\\cdot";
}
void VisitorLatex::visit_mult_end(Mult* node){
	//std::cout << ")}";
	os += ")}";
}
void VisitorLatex::visit_div_begin(Div* node){
	//std::cout << "{\\frac";
	os += "{\\frac";
}
void VisitorLatex::visit_div_middle(Div* node){
}
void VisitorLatex::visit_div_end(Div* node){
	//std::cout << "}";
	os +=  "}";
}
void VisitorLatex::visit_pow_begin(Pow* node){
	//std::cout << "{(";
	os += "{(";
}
void VisitorLatex::visit_pow_middle(Pow* node){
	//std::cout << "^";
	os += "^";
}
void VisitorLatex::visit_pow_end(Pow* node){
	//std::cout << ")}";
	os += ")}";
}

void VisitMathML::visit_op(Op* node){
        os += tab() + "<cn>" +  node->stringify() + "</cn>\n";
}
void VisitMathML::visit_rand(Rand* node){
        os += tab() + "<cn>" + node->stringify() + "</cn>\n";
}
void VisitMathML::visit_add_begin(Add* node){
        os += tab() + "<apply>\n";
	incTabs();
	os += tab() + "<plus/>\n";
}
void VisitMathML::visit_add_middle(Add* node){
        
}
void VisitMathML::visit_add_end(Add* node){
	decTabs();
        os += tab() + "</apply>\n";
}
void VisitMathML::visit_sub_begin(Sub* node){
        os += tab() + "<apply>\n";
	incTabs();
	os += tab() + "<minus/>\n";
}
void VisitMathML::visit_sub_middle(Sub* node){
}
void VisitMathML::visit_sub_end(Sub* node){
	decTabs();
        os += tab() + "</apply>\n";
}
void VisitMathML::visit_mult_begin(Mult* node){
        os += tab() + "<apply>\n";
	incTabs();
	os += tab() + "<times/>\n";
}
void VisitMathML::visit_mult_middle(Mult* node){
     
}
void VisitMathML::visit_mult_end(Mult* node){
 	decTabs();
        os += tab() + "</apply>\n";
}
void VisitMathML::visit_div_begin(Div* node){
        os += tab() + "<apply>\n";
	incTabs();
	os += tab() + "<divide/>\n";
}
void VisitMathML::visit_div_middle(Div* node){
	
}
void VisitMathML::visit_div_end(Div* node){
     	decTabs();
	os +=  tab() + "</apply>\n";
}
void VisitMathML::visit_pow_begin(Pow* node){
        os += tab() + "<apply>\n";
	incTabs();
	os += tab() + "<power/>\n";
}
void VisitMathML::visit_pow_middle(Pow* node){
        
}
void VisitMathML::visit_pow_end(Pow* node){
	decTabs();
	os += tab() + "</apply>\n";
}



