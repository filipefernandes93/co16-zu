// $Id: read_node.h,v 1.2 2016/04/13 09:27:56 ist173253 Exp $ -*- c++ -*-
#ifndef __ZU_READNODE_H__
#define __ZU_READNODE_H__

#include "ast/lvalue_node.h"

namespace zu {

  class read_node: public cdk::expression_node {

  public:
    inline read_node(int lineno) :
        cdk::expression_node(lineno){
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_read_node(this, level);
    }

  };

  /**
   * Class for describing read nodes.
   */
/*
  class read_node: public cdk::basic_node {
    lvalue_node *_argument;

  public:
    inline read_node(int lineno, lvalue_node *argument) :
        cdk::basic_node(lineno), _argument(argument) {
    }

  public:
    inline lvalue_node *argument() {
      return _argument;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_read_node(this, level);
    }

  };
*/

} // zu

#endif
