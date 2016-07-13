#ifndef __ZU_RETURN_H__
#define __ZU_RETURN_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/basic_node.h>

namespace zu {

  class return_node: public cdk::basic_node {
	 
    
  public:
    inline return_node(int lineno) :
        basic_node(lineno) {
    }

    const char *name() const {
        return "Variable";
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }

  };

} // zu

#endif
