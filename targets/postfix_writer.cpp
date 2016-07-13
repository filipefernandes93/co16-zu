// $Id: postfix_writer.cpp,v 1.32 2016/05/20 06:37:10 ist173253 Exp $ -*- c++ -*-
#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "ast/all.h"  // all.h is automatically generated
#include "symbol.h"
#include "pf_size_calculator.h"

 // #include "cdk/basic_type.h"




const std::string calculate_function_label(const std::string &s) {
  if (s == "zu") /*|| (s == "main"))*/ {
    return std::string("_main");
  } else if (s == "_main") {
    return std::string("._main");
  } else {
    return s;
  }
}



//---------------------------------------------------------------------------
//     THIS IS THE VISITOR'S DEFINITION
//---------------------------------------------------------------------------

void zu::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  _pf.INT(node->value()); // push an integer
}

void zu::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1 = ++_lbl;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1)); // give the string a name
  _pf.STR(node->value()); // output string characters

  /* leave the address on the stack */
  _pf.TEXT(); // return to the TEXT segment
  _pf.ALIGN();
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
}

void zu::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {
  int lbl = ++_lbl;

  _pf.RODATA();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
  _pf.DOUBLE(node->value());

  _pf.TEXT();
  _pf.ALIGN();
  _pf.ADDR(mklbl(lbl));
  _pf.DLOAD();
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value
  if (is_int(node->type())) {
    _pf.NEG();
    return;
  }

  if (is_double(node->type())) {
    _pf.DNEG();
    return;
  }
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);

  if (is_int(node->type())) {
    node->left()->accept(this, lvl + 2);
    node->right()->accept(this, lvl + 2);
    _pf.ADD();
    return;
  }

  if (is_double(node->type())) {
    node->left()->accept(this, lvl + 2);
	if (is_int(node->left()->type())){
		_pf.I2D();
	}

    node->right()->accept(this, lvl + 2);
	if (is_int(node->right()->type())){
		_pf.I2D();
	}
    _pf.DADD();
    return;
  }
}
void zu::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	
	if (is_int(node->type())) {  
		node->left()->accept(this, lvl);
		node->right()->accept(this, lvl);
		_pf.SUB();
		return;
	}

	if (is_double(node->type())) {
		node->left()->accept(this, lvl + 2);
		if (is_int(node->left()->type())){
			_pf.I2D();
		}

		node->right()->accept(this, lvl + 2);
		if (is_int(node->right()->type())){
			_pf.I2D();
		}
			
		_pf.DSUB();
		return;
	}

}
void zu::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);

  if (is_int(node->type())) {
    node->left()->accept(this, lvl);
    node->right()->accept(this, lvl);
    _pf.MUL();
    return;
  }

  if (is_double(node->type())) {
		node->left()->accept(this, lvl + 2);
		if (is_int(node->left()->type())){
			_pf.I2D();
		}

		node->right()->accept(this, lvl + 2);
		if (is_int(node->right()->type())){
			_pf.I2D();
		}
		
		_pf.MUL();
		return;
  }
}

void zu::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);

  if (is_int(node->type())) {
    node->left()->accept(this, lvl);
    node->right()->accept(this, lvl);
    _pf.DIV();
    return;
  }

  if (is_double(node->type())) {
		node->left()->accept(this, lvl + 2);
		if (is_int(node->left()->type())){
			_pf.I2D();
		}

		node->right()->accept(this, lvl + 2);
		if (is_int(node->right()->type())){
			_pf.I2D();
		}
		
		_pf.DDIV();
		return;
  }
}
void zu::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}

void zu::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);

	if (is_int(node->type())) {
		node->left()->accept(this, lvl);
		node->right()->accept(this, lvl);
		_pf.LT();
		return;
	}

	node->left()->accept(this, lvl + 2);
		if (is_int(node->left()->type())){
		_pf.I2D();
	}

	node->right()->accept(this, lvl + 2);
		if (is_int(node->right()->type())){
		_pf.I2D();
	}

	_pf.DCMP();
	_pf.INT(0);
	_pf.LT();
	return;
}
void zu::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);

	if (is_int(node->type())) {
		node->left()->accept(this, lvl);
		node->right()->accept(this, lvl);
		_pf.LE();
		return;
	}

	node->left()->accept(this, lvl + 2);
		if (is_int(node->left()->type())){
		_pf.I2D();
	}

	node->right()->accept(this, lvl + 2);
		if (is_int(node->right()->type())){
		_pf.I2D();
	}

	_pf.DCMP();
	_pf.INT(0);
	_pf.LE();
	return;
}
void zu::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);

	if (is_int(node->type())) {
		node->left()->accept(this, lvl);
		node->right()->accept(this, lvl);
		_pf.GE();
		return;
	}

	node->left()->accept(this, lvl + 2);
		if (is_int(node->left()->type())){
		_pf.I2D();
	}

	node->right()->accept(this, lvl + 2);
		if (is_int(node->right()->type())){
		_pf.I2D();
	}

	_pf.DCMP();
	_pf.INT(0);
	_pf.GE();
	return;
}
void zu::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);

	if (is_int(node->type())) {
		node->left()->accept(this, lvl);
		node->right()->accept(this, lvl);
		_pf.GT();
		return;
	}

	node->left()->accept(this, lvl + 2);
		if (is_int(node->left()->type())){
		_pf.I2D();
	}

	node->right()->accept(this, lvl + 2);
		if (is_int(node->right()->type())){
		_pf.I2D();
	}

	_pf.DCMP();
	_pf.INT(0);
	_pf.GT();
	return;
}

void zu::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);

	if (is_int(node->type())) {
		node->left()->accept(this, lvl);
		node->right()->accept(this, lvl);
		_pf.NE();
		return;
	}

	node->left()->accept(this, lvl + 2);
		if (is_int(node->left()->type())){
		_pf.I2D();
	}

	node->right()->accept(this, lvl + 2);
		if (is_int(node->right()->type())){
		_pf.I2D();
	}

	_pf.DCMP();
	_pf.INT(0);
	_pf.NE();
	return;
}
void zu::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);

	if (is_int(node->type())) {
		node->left()->accept(this, lvl);
		node->right()->accept(this, lvl);
		_pf.EQ();
		return;
	}

	node->left()->accept(this, lvl + 2);
		if (is_int(node->left()->type())){
		_pf.I2D();
	}

	node->right()->accept(this, lvl + 2);
		if (is_int(node->right()->type())){
		_pf.I2D();
	}

	_pf.DCMP();
	_pf.INT(0);
	_pf.EQ();
	return;
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_rvalue_node(zu::rvalue_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->lvalue()->accept(this, lvl);
	switch (node->type()->size()) {
		case 8:
		_pf.DLOAD();
		break;
		
		case 4:
		_pf.LOAD();
		break;
	}
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_identifier_node(zu::identifier_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);

  const std::string &id = node->identifier();
  auto sym = _symtab.find(id);

  //if (sym == NULL) {/*error*/}

  if (sym->flag() == 3) {
    _pf.LOCAL(sym->value());
  } else {
    _pf.ADDR(sym->label());
  }
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_assignment_node(zu::assignment_node * const node, int lvl) {
//FIXME
  CHECK_TYPES(_compiler, _symtab, node);

  size_t lvalue_size = 0;

  if (dynamic_cast<identifier_node *>(node->lvalue())) {
    identifier_node *id = dynamic_cast<identifier_node *>(node->lvalue());
    lvalue_size = _symtab.find(id->identifier())->type()->size();
  } else if (dynamic_cast<index_node *>(node->lvalue())) {
    lvalue_size = std::unique_ptr<basic_type>(new basic_type(sizeof(double), basic_type::TYPE_DOUBLE))->size();
  }

  size_t rvalue_size = node->rvalue()->type()->size();

  node->rvalue()->accept(this, lvl+2);

  if ( lvalue_size == 4 && rvalue_size == 4) {
    _pf.DUP();
    node->lvalue()->accept(this, lvl+2);
    _pf.STORE();
  } else if (lvalue_size == 4 && rvalue_size == 8) {
    _pf.D2I();
    _pf.DUP();
     node->lvalue()->accept(this, lvl+2);
    _pf.STORE();
  } else if (lvalue_size == 8 && rvalue_size == 4) {
    _pf.I2D();
    _pf.DDUP();
     node->lvalue()->accept(this, lvl+2);
    _pf.DSTORE();
  } else if (lvalue_size == 8 && rvalue_size == 8) {
    _pf.DDUP();
    node->lvalue()->accept(this, lvl+2);
    _pf.DSTORE();
  }

}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_evaluation_node(zu::evaluation_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl);
  _pf.TRASH(node->argument()->type()->size());
}

void zu::postfix_writer::do_print_node(zu::print_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value to print
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.CALL("printi");
    _pf.TRASH(4); // delete the printed value
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.CALL("prints");
    _pf.TRASH(4); // delete the printed value's address
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.CALL("printd");
    _pf.TRASH(8); 
  }
  else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }

	if(node->newline()){
	  _pf.CALL("println"); // print a newline
	}
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_read_node(zu::read_node * const node, int lvl) { //FIXME
 
CHECK_TYPES(_compiler, _symtab, node);
  _pf.CALL("readi");
  _pf.PUSH();
  //node->argument()->accept(this, lvl);
  _pf.STORE();

}


//---------------------------------------------------------------------------

void zu::postfix_writer::do_if_node(zu::if_node * const node, int lvl) {
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_if_else_node(zu::if_else_node * const node, int lvl) {
  int elseblock = ++_lbl;
  int endif = ++_lbl;

  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(elseblock));
  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(endif));
  _pf.ALIGN();
  _pf.LABEL(mklbl(elseblock));
  node->elseblock()->accept(this, lvl + 2);
  _pf.ALIGN();
  _pf.LABEL(mklbl(endif));
}

//
void zu::postfix_writer::do_and_node(zu::and_node * const node, int lvl) {

  CHECK_TYPES(_compiler, _symtab, node);

  int lbl = ++_lbl;

  node->left()->accept(this, lvl+2);
  _pf.DUP();
  _pf.JZ(mklbl(lbl));
  _pf.TRASH(node->type()->size());
  node->right()->accept(this, lvl+2);
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}

void zu::postfix_writer::do_or_node(zu::or_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);

  int lbl = ++_lbl;

  node->left()->accept(this, lvl+2);
  _pf.DUP();
  _pf.JNZ(mklbl(lbl));
  _pf.TRASH(node->type()->size());
  node->right()->accept(this, lvl+2);
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}

void zu::postfix_writer::do_function_call_node(zu::function_call_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);

  const std::string &id = calculate_function_label(node->name());
  std::shared_ptr<zu::symbol> symbol = _symtab.find(id);

  int args_size = 0;
  if (node->arguments()) {
    for (int i = node->arguments()->size() - 1; i >= 0; i--) {
      node->arguments()->node(i)->accept(this, lvl);
      args_size += ((cdk::expression_node *) node->arguments()->node(i))->type()->size();
    }
  }

  _pf.CALL(id);

  _pf.TRASH(args_size);

  if (is_int(symbol->type()) || is_pointer(symbol->type()) || is_string(symbol->type())) {
    _pf.PUSH();
  } else if (is_double(symbol->type())) {
    _pf.DPUSH();
  }

  //_called_functions.push_back(new std::string(id));
}

void zu::postfix_writer::do_function_declaration_node(zu::function_declaration_node * const node, int lvl) {
//TODO
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void zu::postfix_writer::do_function_definition_node(zu::function_definition_node * const node, int lvl) {
CHECK_TYPES(_compiler, _symtab, node);

_symtab.push();

_current_function_end_label = mklbl(++_lbl);

_pf.TEXT();
_pf.ALIGN();
const std::string &functionname = calculate_function_label(node->function());

if (node->flag() == 1){
_pf.GLOBAL (functionname, _pf.FUNC());
}

size_t localsize = 0;
  {
    auto calc = std::unique_ptr<pf_size_calculator>(new pf_size_calculator(_compiler));
    calc->do_function_definition_node(node, lvl);
    localsize = calc->total_need();
  }
localsize += (node->return_type() == nullptr ? 0 : node->return_type()->size());

size_t retsize = node->return_type()->size();
  _pf.ALIGN();
_pf.LABEL (functionname);
_pf.ENTER (localsize + retsize);

if (node->default_return() != nullptr) {
	node->default_return()->accept(this, lvl+2);
	_pf.LOCA(-retsize);
} else {
	switch (retsize) {
	case 4:
		_pf.LOCA(retsize);
		break;
	case 8:
		_pf.LOCAL(retsize);
		_pf.DSTORE();
		break;
	}
}

node->body()->accept(this, lvl+2);

switch (retsize) {
case 4:
	_pf.LOCV(-retsize);
	_pf.POP();
	break;
case 8:
	_pf.LOCV(-retsize);
	_pf.DPOP();
	break;
}

  _pf.ALIGN();
_pf.LABEL(_current_function_end_label);


//if Main:
//_pf.INT(0);
//_pf.POP();
//


_pf.LEAVE();
_pf.RET();

_symtab.pop();

_pf.EXTERN("readi");
_pf.EXTERN("printi");
_pf.EXTERN("prints");
_pf.EXTERN("println");
}/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void zu::postfix_writer::do_not_node(zu::not_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);

  int _label = ++_lbl;
  int _label_end = ++_lbl;

    node->argument()->accept(this, lvl + 1);
  _pf.JZ(mklbl(_label));
  _pf.INT(0);
  _pf.JMP(mklbl(_label_end));
  _pf.ALIGN();
  _pf.LABEL(mklbl(_label));
  _pf.INT(1);
  _pf.ALIGN();
  _pf.LABEL(mklbl(_label_end));

}

void zu::postfix_writer::do_identity_node(zu::identity_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl+2);
}

void zu::postfix_writer::do_block_node(zu::block_node * const node, int lvl) {
CHECK_TYPES(_compiler, _symtab, node);
  _symtab.push();
  //if (node->decls())
    node->decls()->accept(this, lvl);
  //if (node->stmts())
    node->stmts()->accept(this, lvl);
  _symtab.pop();
}

void zu::postfix_writer::do_variable_node(zu::variable_node * const node, int lvl) {
//FIXME
  std::string &id = node->var_identifier();
  std::shared_ptr<symbol> symb = _symtab.find_local(id);
  
  if (symb == nullptr) {
    switch (node->flag()) {
      case 1://public
        symb = std::shared_ptr<symbol> (new symbol(
        node->flag(),//flag
        node->var_type(),
        id,//name
        id,//label
        0
    	));
        break;
      case 0://local
        symb = std::shared_ptr<symbol> (new symbol(
        node->flag(),//flag
        node->var_type(),
        id,//name
        id,//label
        0
    	));
        break;
      case 2://extern
        symb = std::shared_ptr<symbol> (new symbol(
        node->flag(),//flag
        node->var_type(),
        id,//name
        id,//label
        0
    	));
        break;
      case 3://block
        _last_var_addr -= node->var_type()->size();
        symb = std::shared_ptr<symbol> (new symbol(
        node->flag(),//flag
        node->var_type(),
        id,//name
        id,//label
        _last_var_addr
    	));
        break;

    }
    _symtab.insert(id, symb);
  }



  CHECK_TYPES(_compiler, _symtab, node);

  switch(node->flag()) {
  case 0: //private
			if (node->value() == nullptr) {
				_pf.BSS();
    			_pf.ALIGN();
    			_pf.LABEL(symb->label());
    			_pf.BYTE(symb->type()->size());
    			return;
			} else if ( dynamic_cast<cdk::string_node *>(node->value())) {
				int str_data_lbl = _lbl++;

				_pf.DATA();
				_pf.ALIGN();
				_pf.LABEL(mklbl(str_data_lbl));
				_pf.STR(dynamic_cast<cdk::string_node *>(node->value())->value());

			} else {
				_pf.RODATA();
				_pf.ALIGN();
				_pf.LABEL(symb->label());
				if (dynamic_cast<cdk::integer_node *>(node->value())) {
					if (is_double(node->var_type()))
					_pf.DOUBLE(dynamic_cast<cdk::integer_node *>(node->value())->value());
					else
					_pf.CONST(dynamic_cast<cdk::integer_node *>(node->value())->value());
				
				}else if (dynamic_cast<cdk::double_node *>(node->value())) {
					_pf.DOUBLE(dynamic_cast<cdk::double_node *>(node->value())->value());
				}
			}
  case 1:
			_pf.GLOBAL(symb->label(), _pf.OBJ());
			if (node->value() == nullptr) {
				_pf.BSS();
    			_pf.ALIGN();
    			_pf.LABEL(symb->label());
    			_pf.BYTE(symb->type()->size());
    			return;
			} else if ( dynamic_cast<cdk::string_node *>(node->value())) {
				int str_data_lbl = _lbl++;

				_pf.RODATA();
				_pf.ALIGN();
				_pf.LABEL(mklbl(str_data_lbl));
				_pf.STR(dynamic_cast<cdk::string_node *>(node->value())->value());
_pf.DATA();
_pf.ALIGN();
_pf.LABEL(node->var_identifier());
_pf.ID(mklbl(str_data_lbl));
			} else {
				_pf.DATA();
				_pf.ALIGN();
				_pf.LABEL(symb->label());
				if (dynamic_cast<cdk::integer_node *>(node->value())) {
					if (is_double(node->var_type()))
					_pf.DOUBLE(dynamic_cast<cdk::integer_node *>(node->value())->value());
					else
					_pf.CONST(dynamic_cast<cdk::integer_node *>(node->value())->value());
				
				}else if (dynamic_cast<cdk::double_node *>(node->value())) {
					_pf.DOUBLE(dynamic_cast<cdk::double_node *>(node->value())->value());
				}
			}
    break;
  
  case 2:
	//_pf.GLOBAL(symb->label(), _pf.OBJ());
	_pf.EXTERN(node->var_identifier());
    break;
  
  case 3:
	

	if(node->var_type()->name()== basic_type::TYPE_INT){
		if(node->value() == nullptr) {
			_pf.BSS();
			_pf.ALIGN();
			_pf.LABEL(node->var_identifier());
			_pf.BYTE(4);
			//return;
		}else{
			_pf.INT(dynamic_cast<cdk::integer_node*>(node->value())->value());
			_pf.LOCA(- node->var_type()->size());
			//offset -=4;
		}
	}
  }
}

void zu::postfix_writer::do_alloc_node(zu::alloc_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  node->accept(this, lvl);
  _pf.INT(8);
  _pf.MUL();  
  _pf.ALLOC();
  _pf.SP(); 
}

void zu::postfix_writer::do_return_node(zu::return_node * const node, int lvl) {
CHECK_TYPES(_compiler, _symtab, node);  
_pf.JMP(_current_function_end_label);
}

void zu::postfix_writer::do_for_node(zu::for_node * const node, int lvl) {//
  _symtab.push();

int condition = ++_lbl;
  int incr = ++_lbl;
  int forend = ++_lbl;

_incr_for_labels.push_back(incr);
_end_for_labels.push_back(forend);

  node->init()->accept(this, lvl);

  _pf.ALIGN();
  _pf.LABEL(mklbl(condition));
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(forend));
  node->block()->accept(this, lvl);
  _pf.ALIGN();
  _pf.LABEL(mklbl(incr));
  node->incr()->accept(this, lvl);
  _pf.JMP(mklbl(condition));
  _pf.ALIGN();
  _pf.LABEL(mklbl(forend));

_incr_for_labels.pop_back();
_end_for_labels.pop_back();
_symtab.pop();
}

void zu::postfix_writer::do_continue_node(zu::continue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);

  //unsigned int n = node->value();
  int lbl = ++_lbl;
  
  //for (unsigned int i = 0; i < n; i++) {
    lbl = _incr_for_labels.back();
    _incr_for_labels.pop_back();
    _end_for_labels.pop_back();
  //}
  
  _pf.JMP(mklbl(lbl));
}

void zu::postfix_writer::do_break_node(zu::break_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);

  //unsigned int n = node->value();
  int lbl;
  
 // for (unsigned int i = 0; i < n; i++) {
    lbl = _end_for_labels.back();
    _incr_for_labels.pop_back();
    _end_for_labels.pop_back();
  //}
  
  _pf.JMP(mklbl(lbl));
}

void zu::postfix_writer::do_index_node(zu::index_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);

  auto type = std::unique_ptr<basic_type>( new basic_type(sizeof(double), basic_type::TYPE_DOUBLE));

  node->pointer()->accept(this, lvl+2);
  node->index()->accept(this, lvl+2);
  _pf.INT(type->size());
  _pf.MUL();
  _pf.ADD();
}

void zu::postfix_writer::do_address_node(zu::address_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl+2);
}

/*void zu::postfix_writer::do_identifier_node(zu::identifier_node * const node, int lvl) {
//
}*/

