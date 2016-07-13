#ifndef __ZU_INDEX_H__
#define __ZU_INDEX_H__

#include <cdk/ast/expression_node.h>
#include "lvalue_node.h"

namespace zu {

  class index_node: public lvalue_node {
      cdk::expression_node *_pointer;
      cdk::expression_node *_index;
  
    public:
        inline index_node(int lineno, cdk::expression_node *pointer, cdk::expression_node *index) :
            lvalue_node(lineno), _pointer(pointer), _index(index) {
            }

    public:
        inline cdk::expression_node *pointer() {
            return _pointer;
        }
        inline cdk::expression_node *index() {
            return _index;
        }
        
    void accept(basic_ast_visitor *sp, int level) override {
        return sp->do_index_node(this, level);
    }
  };

} // zu

#endif
