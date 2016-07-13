#ifndef __ZU_VARIABLE_H__
#define __ZU_VARIABLE_H__

#include "cdk/ast/basic_node.h"
#include "cdk/ast/expression_node.h"
#include "cdk/basic_type.h"

namespace zu {


  class variable_node: public cdk::basic_node{
	int _flag;
	basic_type *_var_type;
	std::string _var_identifier;
	cdk::expression_node *_value;


  public:
    inline variable_node(int lineno, int flag, basic_type *var_type, std::string &var_identifier, cdk::expression_node *value) :
        cdk::basic_node(lineno), _flag(flag), _var_type(var_type), _var_identifier(var_identifier), _value(value) {}
    inline variable_node(int lineno, int flag, basic_type *var_type, std::string *var_identifier, cdk::expression_node *value) :
        cdk::basic_node(lineno), _flag(flag), _var_type(var_type), _var_identifier(*var_identifier), _value(value) {}



  public:

	basic_type *var_type() {
		return _var_type;
	}

	int flag() {
		return _flag;
	}

     std::string &var_identifier()  {
      return _var_identifier;
    }

    cdk::expression_node *value()  {
      return _value;
    }

    const char *name()  {
            return "Variable";
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_node(this, level);
    }

  };




} // zu

#endif
