#ifndef __ZU_CONTINUE_H__
#define __ZU_CONTINUE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/basic_node.h>

namespace zu {

  class continue_node: public cdk::basic_node {
	int _n;
    
  public:
    inline continue_node(int lineno, int n=1) :
        cdk::basic_node(lineno), _n(n)  {
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_continue_node(this, level);
    }

	    int value() {return _n;}
  };

} // zu

#endif
