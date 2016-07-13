 #include "pf_size_calculator.h"

void zu::pf_size_calculator::do_function_definition_node(zu::function_definition_node * const node, int lvl) {
    _total_need = 0;

    if(node->body() == nullptr) {
  	return;
    }

    node->body()->accept(this, lvl + 2);

}

void zu::pf_size_calculator::do_block_node(zu::block_node * const node, int lvl) {
    if(node->decls() != nullptr) {
  	node->decls()->accept(this, lvl+2);
    }

    if(node->stmts() != nullptr) {
  	node->stmts()->accept(this, lvl+2);
    }
}



void zu::pf_size_calculator::do_variable_node(zu::variable_node* const node, int lvl) {
    _total_need += node->var_type()->size();
}


void zu::pf_size_calculator::do_sequence_node(cdk::sequence_node *const node, int lvl) {
    for(auto n : node->nodes()) {
  	n->accept(this, lvl+2);
    }
}

size_t zu::pf_size_calculator::total_need() const {
    return _total_need;
}

void zu::pf_size_calculator::do_for_node(zu::for_node * const node, int lvl) {
    node->block()->accept(this, 0);
}

void zu::pf_size_calculator::do_if_node(zu::if_node * const node, int lvl) {
    node->block()->accept(this, 0);
}

void zu::pf_size_calculator::do_if_else_node(zu::if_else_node * const node, int lvl) {
    node->thenblock()->accept(this, 0);
    node->elseblock()->accept(this, 0);
}
