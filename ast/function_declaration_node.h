#ifndef __ZU_FUNCTIONDECLARATIONNODE_H__
#define __ZU_FUNCTIONDECLARATIONNODE_H__

#include <cdk/basic_type.h>
#include <cdk/ast/basic_node.h>
	//#include <string>

namespace zu {

    class function_declaration_node : public cdk::basic_node {
        basic_type *_return_type;
        std::string _function;
        cdk::sequence_node *_parameters;
        int _scope;

    public:
        function_declaration_node(int lineno, int flag, basic_type *return_type, const std::string *function, cdk::sequence_node *parameters)
	: cdk::basic_node(lineno), _return_type(return_type), _function(*function), _parameters(parameters), _scope(flag) { }

        int flag() const {
            return _scope;
        }
        void flag(int newscope) {
            _scope = newscope;
        }

        basic_type *return_type() {
            return _return_type;
        }

        const std::string &function() {
            return _function;
        }

        cdk::sequence_node *parameters() {
            return _parameters;
        }

        void accept(basic_ast_visitor *sp, int level) {
            sp->do_function_declaration_node(this, level);
        }
    };

} // zu

#endif
