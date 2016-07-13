// $Id: type_checker.cpp,v 1.19 2016/05/20 07:25:12 ist173253 Exp $ -*- c++ -*-
#include <string>
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

#define ASSERT_UNSPEC \
    { if (node->type() != nullptr && \
          node->type()->name() != basic_type::TYPE_UNSPEC) return; }

//---------------------------------------------------------------------------

void zu::type_checker::do_integer_node(cdk::integer_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void zu::type_checker::do_string_node(cdk::string_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(sizeof(std::string), basic_type::TYPE_STRING));
}

void zu::type_checker::do_double_node(cdk::double_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type( sizeof(double), basic_type::TYPE_DOUBLE ));
}

//---------------------------------------------------------------------------

inline void zu::type_checker::processUnaryExpression(cdk::unary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);

  auto node_type = node->argument()->type();
  if (is_int(node_type)) {
    node->type(new basic_type(sizeof(int), basic_type::TYPE_INT));
  } else if (is_double(node_type)) {
    node->type(new basic_type( sizeof(double), basic_type::TYPE_DOUBLE ));
  }
}

void zu::type_checker::do_neg_node(cdk::neg_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

inline void zu::type_checker::processBinaryExpression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() != basic_type::TYPE_INT)
    throw std::string("wrong type in left argument of binary expression");

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() != basic_type::TYPE_INT)
    throw std::string("wrong type in right argument of binary expression");

  // in Zu, expressions are always int
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void zu::type_checker::do_add_node(cdk::add_node * const node, int lvl) {
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
	if ( is_double(node->right()->type()) || is_double(node->left()->type()) ){
		node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
	} else {
		node->type(new basic_type(4, basic_type::TYPE_INT));
	}
}

void zu::type_checker::do_sub_node(cdk::sub_node * const node, int lvl) {
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
	if ( is_double(node->right()->type()) || is_double(node->left()->type()) ){
		node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
	} else {
		node->type(new basic_type(4, basic_type::TYPE_INT));
	}
}
void zu::type_checker::do_mul_node(cdk::mul_node * const node, int lvl) {
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
	if ( is_double(node->right()->type()) || is_double(node->left()->type()) ){
		node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
	} else {
		node->type(new basic_type(4, basic_type::TYPE_INT));
	}
}
void zu::type_checker::do_div_node(cdk::div_node * const node, int lvl) {
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
	if ( is_double(node->right()->type()) || is_double(node->left()->type()) ){
		node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
	} else {
		node->type(new basic_type(4, basic_type::TYPE_INT));
	}
}
void zu::type_checker::do_mod_node(cdk::mod_node * const node, int lvl) {

	node->left()->accept(this, lvl+2);
	node->right()->accept(this, lvl+2); 
	node->type(new basic_type(4, basic_type::TYPE_INT));
}

void zu::type_checker::processBinaryMulExpression(cdk::binary_expression_node * const node, int lvl) {
    if(node->type() != NULL) {
    return;
  }
  node->left()->accept(this, lvl+2);
  node->right()->accept(this, lvl+2);

  if((node->left()->type()->name() == basic_type::TYPE_STRING)
  || (node->right()->type()->name() == basic_type::TYPE_STRING)
  || (node->left()->type()->name() == basic_type::TYPE_VOID)
  || (node->right()->type()->name() == basic_type::TYPE_VOID)
  || (node->left()->type()->name() == basic_type::TYPE_ERROR)
  || (node->right()->type()->name() == basic_type::TYPE_ERROR)
  || (node->left()->type()->name() == basic_type::TYPE_POINTER)
  || (node->right()->type()->name() == basic_type::TYPE_POINTER)) {

    node->type(new basic_type(0, basic_type::TYPE_ERROR));
    throw std::string("wrong type in arguments of binary arithmetic expression");
  }

  if((node->left()->type()->name() == basic_type::TYPE_INT)
  || (node->right()->type()->name() == basic_type::TYPE_POINTER)) {

    node->type(new basic_type(4, basic_type::TYPE_POINTER));
  }

  if((node->left()->type()->name() == basic_type::TYPE_DOUBLE)
  || (node->right()->type()->name() == basic_type::TYPE_DOUBLE)) {
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  } else {
    node->type(new basic_type(4, basic_type::TYPE_INT));
  }
}

void zu::type_checker::do_lt_node(cdk::lt_node * const node, int lvl) {
  processBinaryCompareExpression(node, lvl);
}
void zu::type_checker::do_le_node(cdk::le_node * const node, int lvl) {
  processBinaryCompareExpression(node, lvl);
}
void zu::type_checker::do_ge_node(cdk::ge_node * const node, int lvl) {
  processBinaryCompareExpression(node, lvl);
}
void zu::type_checker::do_gt_node(cdk::gt_node * const node, int lvl) {
  processBinaryCompareExpression(node, lvl);
}
void zu::type_checker::do_ne_node(cdk::ne_node * const node, int lvl) {
  processBinaryCompareExpression(node, lvl);
}
void zu::type_checker::do_eq_node(cdk::eq_node * const node, int lvl) {
  processBinaryCompareExpression(node, lvl);
}


void zu::type_checker::processBinaryCompareExpression(cdk::binary_expression_node * const node, int lvl) {

  node->left()->accept(this, lvl+2);
  node->right()->accept(this, lvl+2);

  node->type(new basic_type(4, basic_type::TYPE_INT));
}


//---------------------------------------------------------------------------

void zu::type_checker::do_rvalue_node(zu::rvalue_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl);
  node->type(new basic_type(*node->lvalue()->type()));
}

//---------------------------------------------------------------------------

void zu::type_checker::do_identifier_node(zu::identifier_node * const node, int lvl) { //FIXME

  ASSERT_UNSPEC;
  auto &id = node->identifier();
  auto symbol = _symtab.find(id);

  if (symbol == nullptr) {
    throw id + " undeclared";
  }

  node->type(symbol->type());
}

//---------------------------------------------------------------------------

void zu::type_checker::do_assignment_node(zu::assignment_node * const node, int lvl) { //FIXME
	ASSERT_UNSPEC;
	node->lvalue()->accept(this, lvl + 2);
	node->rvalue()->accept(this, lvl + 2);
	node->type(node->lvalue()->type());

}

//---------------------------------------------------------------------------

void zu::type_checker::do_evaluation_node(zu::evaluation_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

void zu::type_checker::do_print_node(zu::print_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void zu::type_checker::do_read_node(zu::read_node * const node, int lvl) {
  //FIXME
}

//---------------------------------------------------------------------------

void zu::type_checker::do_if_node(zu::if_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

void zu::type_checker::do_if_else_node(zu::if_else_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}


void zu::type_checker::do_and_node(zu::and_node * const node, int lvl) {
  node->type(new basic_type(4, basic_type::TYPE_INT));
}
void zu::type_checker::do_or_node(zu::or_node * const node, int lvl) {
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void zu::type_checker::do_function_call_node(zu::function_call_node * const node, int lvl) {
//TODO
}

void zu::type_checker::do_function_declaration_node(zu::function_declaration_node * const node, int lvl) {
//TODO
}

void zu::type_checker::do_function_definition_node(zu::function_definition_node * const node, int lvl) {
//TODO
}

void zu::type_checker::do_not_node(zu::not_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  node->type(new basic_type(sizeof(int), basic_type::TYPE_INT));
}

void zu::type_checker::do_identity_node(zu::identity_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);

  if (is_int(node->argument()->type())) {
    node->type(new basic_type(sizeof(int), basic_type::TYPE_INT));
  } else if (is_double(node->argument()->type())) {
    node->type(new basic_type(sizeof(double), basic_type::TYPE_DOUBLE));
  }
}

void zu::type_checker::do_block_node(zu::block_node * const node, int lvl) {}

void zu::type_checker::do_variable_node(zu::variable_node * const node, int lvl) {
	if (node->value() != nullptr) {
		node->value()->accept(this, lvl+2);
	}
}

void zu::type_checker::do_alloc_node(zu::alloc_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  node->type( new basic_type(sizeof(void*), basic_type::TYPE_POINTER) );
}

void zu::type_checker::do_return_node(zu::return_node * const node, int lvl) {}

void zu::type_checker::do_for_node(zu::for_node * const node, int lvl) {
  if (node->condition() != nullptr) {
    node->condition()->accept(this, lvl+2);
  }
}

void zu::type_checker::do_continue_node(zu::continue_node * const node, int lvl) {}

void zu::type_checker::do_break_node(zu::break_node * const node, int lvl) {}

void zu::type_checker::do_index_node(zu::index_node * const node, int lvl) {
  node->pointer()->accept(this, lvl+2);
  node->index()->accept(this, lvl+2);

}

void zu::type_checker::do_address_node(zu::address_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  node->type(new basic_type(sizeof(void*), basic_type::TYPE_POINTER));
}
