#ifndef __ZU_ALLOC_H__
#define __ZU_ALLOC_H__

#include <cdk/ast/unary_expression_node.h>

namespace zu {

  class alloc_node: public cdk::unary_expression_node {
  public:
    inline alloc_node(int lineno, expression_node *arg) :
        cdk::unary_expression_node(lineno, arg) {
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_alloc_node(this, level);
    }
  };

} // zu

#endif
