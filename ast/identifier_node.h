// $Id: identifier_node.h,v 1.5 2016/04/13 09:20:08 ist173253 Exp $ -*- c++ -*-
#ifndef __ZU_EXPRESSION_IDENTIFIER_H__
#define __ZU_EXPRESSION_IDENTIFIER_H__

#include "lvalue_node.h"
#include <string>

namespace zu {

  class identifier_node : public lvalue_node {
    std::string _identifier;

  public:
    inline identifier_node(int lineno, const std::string &identifier) :
        lvalue_node(lineno), _identifier(identifier) {
    }

  public:
    inline const std::string &identifier() {
      return _identifier;
    }

    virtual void accept(basic_ast_visitor *sp, int level) override {
      return sp->do_identifier_node(this, level);
    }

  };

  /**
   * Class for describing syntactic tree leaves for holding identifier
   * values.
   */
/*
  class identifier_node: public lvalue_node {
  public:
    inline identifier_node(int lineno, const char *s) :
        lvalue_node(lineno, s) {
    }
    inline identifier_node(int lineno, const std::string &s) :
        lvalue_node(lineno, s) {
    }
    inline identifier_node(int lineno, const std::string *s) :
        lvalue_node(lineno, *s) {
    }
*/
    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */

 /*   
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_identifier_node(this, level);
    }

  };
*/
} // zu

#endif
