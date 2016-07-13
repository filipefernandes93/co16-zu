#ifndef __ZU_FUNCTIONCALLNODE_H__
#define __ZU_FUNCTIONCALLNODE_H__

#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <string>

namespace zu {

  class function_call_node : public cdk::expression_node {
      std::string *_function;
      cdk::sequence_node *_arguments;
      
      
  public:
      inline function_call_node(int lineno, std::string *function, cdk::sequence_node *arguments) :
        cdk::expression_node(lineno),_function(function), _arguments(arguments) {
        }
        
  public:
      inline std::string *function() {
          return _function;
      }
      
      inline cdk::sequence_node *arguments() {
          return _arguments;
      }
      
      
      const char *name() const {
        return "FunctionCall";
      }
      
      void accept(basic_ast_visitor *sp, int level) {
            sp->do_function_call_node(this, level);
      }

  };

} // zu

#endif
