#pragma once
#include "ast/all.h"
#include <vector>
#include <cstddef>

using std::size_t;

namespace zu {

class pf_size_calculator: public basic_ast_visitor {
	private:
		size_t _total_need;

	public:
		pf_size_calculator(std::shared_ptr<cdk::compiler> compiler) : basic_ast_visitor(compiler) {}

		void do_function_definition_node(zu::function_definition_node * const node, int lvl);
		void do_block_node(zu::block_node * const node, int lvl);
		void do_variable_node(zu::variable_node * const node, int lvl);
		void do_sequence_node(cdk::sequence_node * const node, int lvl);
		void do_for_node(zu::for_node * const node, int lvl);
		void do_if_node(zu::if_node * const node, int lvl);
		void do_if_else_node(zu::if_else_node * const node, int lvl);
		size_t total_need() const;
public:
    void do_integer_node(cdk::integer_node * const node, int lvl) {}
    void do_string_node(cdk::string_node * const node, int lvl) {}
    void do_neg_node(cdk::neg_node * const node, int lvl){}
    void do_add_node(cdk::add_node * const node, int lvl){}
    void do_sub_node(cdk::sub_node * const node, int lvl){}
    void do_mul_node(cdk::mul_node * const node, int lvl){}
    void do_div_node(cdk::div_node * const node, int lvl){}
    void do_mod_node(cdk::mod_node * const node, int lvl){}
    void do_lt_node(cdk::lt_node * const node, int lvl){}
    void do_le_node(cdk::le_node * const node, int lvl){}
    void do_ge_node(cdk::ge_node * const node, int lvl){}
    void do_gt_node(cdk::gt_node * const node, int lvl){}
    void do_ne_node(cdk::ne_node * const node, int lvl){}
    void do_eq_node(cdk::eq_node * const node, int lvl){}
    void do_identifier_node(zu::identifier_node * const node, int lvl){}
    void do_rvalue_node(zu::rvalue_node * const node, int lvl){}
    void do_evaluation_node(zu::evaluation_node * const node, int lvl){}
    void do_print_node(zu::print_node * const node, int lvl){}
    void do_read_node(zu::read_node * const node, int lvl){}
    void do_assignment_node(zu::assignment_node * const node, int lvl){}
    void do_and_node(zu::and_node * const node, int lvl){}
    void do_or_node(zu::or_node * const node, int lvl){}
    void do_function_call_node(zu::function_call_node * const node, int lvl){}
    void do_function_declaration_node(zu::function_declaration_node * const node, int lvl){}
    void do_not_node(zu::not_node * const node, int lvl){}
    void do_identity_node(zu::identity_node * const node, int lvl){}
    void do_alloc_node(zu::alloc_node * const node, int lvl){}
    void do_return_node(zu::return_node * const node, int lvl){}
    void do_continue_node(zu::continue_node * const node, int lvl){}
    void do_break_node(zu::break_node * const node, int lvl){}
    void do_index_node(zu::index_node * const node, int lvl){}
    void do_address_node(zu::address_node * const node, int lvl){}
};
} 
