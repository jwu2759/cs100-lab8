#include "visitor.hpp"
#include "base.hpp"
void VisitorLatex::visit_op(Op* node){
	std::cout << "{" << node->stringify() << "}";
}
void VisitorLatex::visit_rand(Rand* node){
	std::cout << "{" << node->stringify() << "}";
}
void VisitorLatex::visit_add_begin(Add* node){
	std::cout << "{(";
}
void VisitorLatex::visit_add_middle(Add* node){
	std::cout << "+";
}
void VisitorLatex::visit_add_end(Add* node){
	std::cout << ")}";
}
void VisitorLatex::visit_sub_begin(Sub* node){
	std::cout << "{(";
}
void VisitorLatex::visit_sub_middle(Sub* node){
	std::cout << "-";
}
void VisitorLatex::visit_sub_end(Sub* node){
	std::cout << ")}";
}
void VisitorLatex::visit_mult_begin(Mult* node){
	std::cout << "{(";
}
void VisitorLatex::visit_mult_middle(Mult* node){
	std::cout << "\\cdot";
}
void VisitorLatex::visit_mult_end(Mult* node){
	std::cout << ")}";
}
void VisitorLatex::visit_div_begin(Div* node){
	std::cout << "{\\frac";
}
void VisitorLatex::visit_div_middle(Div* node){
}
void VisitorLatex::visit_div_end(Div* node){
	std::cout << "}";
}
void VisitorLatex::visit_pow_begin(Pow* node){
	std::cout << "{(";
}
void VisitorLatex::visit_pow_middle(Pow* node){
	std::cout << "^";
}
void VisitorLatex::visit_pow_end(Pow* node){
	std::cout << ")}";
}
