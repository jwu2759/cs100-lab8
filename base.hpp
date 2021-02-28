#ifndef __BASE_HPP__
#define __BASE_HPP__

#include "visitor.hpp"
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
#include "visitor.hpp"

class Base {
    public:
        virtual ~Base() = default;

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
        virtual int number_of_children() = 0;
        virtual Base* get_child(int i) = 0;
	virtual void accept(Visitor* visitor, int index) = 0;
};

class Nullary : public Base{
   	protected:
      		double val;
      		std::ostringstream strs;
	public:
	virtual int number_of_children(){
		return 0;
	}
	virtual Base* get_child(int i){
		return nullptr;	//Nullary objects do not have any children
	}
};

class Binary : public Base{
	protected:
		Base* left;
		Base* right;
	public:
        ~Binary() {
		delete left;
		delete right;
	}	
	virtual int number_of_children(){
		return 2;	
		// this has to ALWAYS be 2 
		// the case with 1 does not exist.
	}
	virtual Base* get_child(int i){
		return (i==0)? left : right;
	}
};


class Op : public Nullary {
    public:
        Op(double value){
          	val = value;
		strs << val;
  	}
	virtual ~Op(){}
   	virtual double evaluate() { return val; }
   	virtual std::string stringify() { return strs.str(); }
	virtual void accept(Visitor* visitor, int index){
		if(index == 0)
			visitor->visit_op(this);
	}
};

class Rand : public Nullary{
   public:
      Rand(){
         val = (double)(std::rand() % 100);
         strs << val;
      }
      virtual double evaluate(){return val;}
      virtual std::string stringify(){return strs.str();}
	virtual void accept(Visitor* visitor, int index){
		if(index == 0)
			visitor->visit_rand(this);
	}
};

class Mult : public Binary{
   public: 
      Mult(Base* x1, Base* x2){
	 left = x1;
	 right = x2;
      }   
      virtual double evaluate(){
	 return left->evaluate() * right->evaluate();
      }
      virtual std::string stringify(){
	 return "(" + left->stringify() + "*" + right->stringify() + ")";
      }
	virtual void accept(Visitor* visitor, int index){
		if(index == 0)
			visitor->visit_mult_begin(this);
		else if(index == 1)
			visitor->visit_mult_middle(this);
		else
			visitor->visit_mult_end(this);
	}
};

class Add : public Binary{
   public:
      Add(Base* child1, Base* child2){
          left = child1;
          right = child2;
      }
      virtual double evaluate(){
	return left->evaluate() + right->evaluate();
      }
      virtual std::string stringify(){
	return "(" + left->stringify() + "+" + right->stringify() + ")";
      }
	virtual void accept(Visitor* visitor, int index){
		if(index == 0)
			visitor->visit_add_begin(this);
		else if(index == 1)
			visitor->visit_add_middle(this);
		else
			visitor->visit_add_end(this);
	}

};


class Sub : public Binary {
	public:
		Sub(Base* c1, Base* c2) {
			left = c1;
			right = c2;
		}
		virtual double evaluate(){
			return left->evaluate() - right->evaluate();
		}
		virtual std::string stringify(){
			return "(" + left->stringify() + "-" + right->stringify() + ")";
		}
	virtual void accept(Visitor* visitor, int index){
		if(index == 0)
			visitor->visit_sub_begin(this);
		else if(index == 1)
			visitor->visit_sub_middle(this);
		else
			visitor->visit_sub_end(this);
	}
};

class Div : public Binary{
   public:
      Div(Base* child1, Base* child2){
         left = child1;
	 right = child2;
      }
      virtual double evaluate(){
	 return left->evaluate() / right->evaluate();
      }
      virtual std::string stringify(){
	 return "(" + left->stringify() + "/" + right->stringify() + ")";
      }
	virtual void accept(Visitor* visitor, int index){
		if(index == 0)
			visitor->visit_div_begin(this);
		else if(index == 1)
			visitor->visit_div_middle(this);
		else
			visitor->visit_div_end(this);
	}
};

class Pow : public Binary {
	public:
		Pow(Base* l, Base* r){
			left = l;
			right = r;
		}
		virtual double evaluate(){
			return pow(left->evaluate(),right->evaluate());
		}
		virtual std::string stringify(){
			return "(" + left->stringify() + "**" + right->stringify() + ")";
		}
	virtual void accept(Visitor* visitor, int index){
		if(index == 0)
			visitor->visit_pow_begin(this);
		else if(index == 1)
			visitor->visit_pow_middle(this);
		else
			visitor->visit_pow_end(this);
	}
};
#endif //__BASE_HPP__
