#ifndef __ZU_FUNCTION_DEFINITION_H__
#define __ZU_FUNCTION_DEFINITION_H__

#include <cdk/basic_type.h>
#include "function_declaration_node.h"

namespace zu {

      class function_definition_node : public function_declaration_node {
        cdk::expression_node *_default_return;
        cdk::basic_node *_body;

    public:
        function_definition_node(int lineno, int flag, basic_type *return_type, const std::string *function, cdk::sequence_node *parameters, cdk::expression_node *default_return, cdk::basic_node *body)
	: function_declaration_node(lineno, flag, return_type, function, parameters), _default_return(default_return), _body(body) { }

        cdk::expression_node *default_return() {
            return _default_return;
        }
        
        void default_return(cdk::expression_node *def_ret) {
          _default_return = def_ret;
        }

        cdk::basic_node *body() {
            return _body;
        }

        void accept(basic_ast_visitor *sp, int level) {
            sp->do_function_definition_node(this, level);
        }
    };
} // zu

#endif
