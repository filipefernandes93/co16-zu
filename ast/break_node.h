#ifndef __ZU_BREAK_H__
#define __ZU_BREAK_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/basic_node.h>

namespace zu {

  class break_node: public cdk::basic_node {
   int _n;

  public:
    inline break_node(int lineno, int n = 1) :
        basic_node(lineno) , _n(n) {
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_break_node(this, level);
    }

    int value() {return _n;}
  };

} // zu

#endif
