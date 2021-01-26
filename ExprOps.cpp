// 1f3f0cf7a91b9d72bf734d3a2e74a655

#include "ExprTree.h"
#include "ExprOps.h"
#include <cassert>
#include <string>
#include <iostream>

// You will want to implement these functions within this file.

using exprtree::Environment;
using exprtree::ExprVisitor;
using exprtree::Expression;
using exprtree::Literal;
using exprtree::Operation;
using exprtree::OpCode;
using exprtree::Symbol;
  
namespace exprtree {


std::optional<int64_t>
evaluate(const ExprTree& tree, const Environment& environment) {	

	EvaluateVisitor evalute_visitor(environment);
	tree.accept(evalute_visitor);
	return {};
}


std::unordered_map<std::string,size_t>
countSymbols(const ExprTree& tree) {
  return {};
}


std::unordered_map<OpCode,size_t>
countOps(const ExprTree& tree) {
  return {};
}


}


class EvaluateVisitor : public ExprVisitor {

	public:         
		Environment environment;  
		EvaluateVisitor(Environment environment) { // Constructor with parameters
			environment = environment;
		}

private:
	std::optional<int64_t> value;
	virtual void visitImpl(const Literal& literal) {
		value = literal.value;
	}
	virtual void visitImpl(const Symbol& symbol) { 
		std::string name = symbol.name;
		value = environment.get(name);
	}

	virtual void visitImpl(const Operation& operation) { 
		const OpCode opCode = operation.opCode;
		operation.rhs.accept(*this);
		std::optional<int64_t> rhs_value = *value;
		std::cout << *value;
		operation.lhs.accept(*this);
		std::cout << *value;
		std::optional<int64_t> lhs_value = *value;		

		std::cout << opCode;
			// بچه راستیش 
			// بچه چپش
			// Return نتیجه
		
	}
};

