%{
// $Id: zu_parser.y,v 1.34 2016/05/20 05:19:25 ist173253 Exp $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!
%}

%union {
  int                   i;	/* integer value */
  double		d;
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  zu::lvalue_node  *lvalue;
  basic_type *t;
};

%token <i> tINTEGER
%token <s> tIDENTIFIER tSTRING
%token <d> tDOUBLE
%token tBREAK tCONTINUE tRETURN tPRINTLN


%nonassoc '?'
%nonassoc ':'

%right '='
%left '|'
%left '&'
%nonassoc '~'
%left tGE tLE tEQ tNE '>' '<'
%left '+' '-'
%left '*' '/' '%'

%nonassoc '['	/**/


%type <node> file decl vdecl fdecl block instruction vdecl_b

%type <sequence> declarations optional_args instructions_block exprs optional_exprs vdecls vdecl_block optional_things funcall_args f_args
%type <expression> expr /*funcall*/ literal
%type <lvalue> lval
%type <s> stringa
%type <t> type
%type <i> scope;

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file	: declarations 		{compiler->ast($1);}
	;

declarations	: decl			{ $$ = new cdk::sequence_node(LINE, $1); }
		| declarations decl	{ $$ = new cdk::sequence_node(LINE, $2, $1); }
		;

decl	: vdecl ';'			{$$ = $1;}
	| fdecl				{$$ = $1;}
	;

vdecl	: type tIDENTIFIER scope		{ $$ = new zu::variable_node(LINE, 1, $1, $2, nullptr);}
	| type tIDENTIFIER scope '=' literal	{ $$ = new zu::variable_node(LINE, 1, $1, $2, $5);}
	;

vdecl_b	: type tIDENTIFIER scope		{ $$ = new zu::variable_node(LINE, 3 /*$3*/, $1, $2, nullptr);}
	| type tIDENTIFIER scope '=' literal	{ $$ = new zu::variable_node(LINE, 3 /*$3*/, $1, $2, $5);}
	;

vdecls	: vdecl 		{$$ = new cdk::sequence_node(LINE, $1);}
	| vdecl ',' vdecls	{$$ = new cdk::sequence_node(LINE, $1, $3);} 
	;

vdecl_block	: vdecl_block vdecl_b ';'	{ $$ = new cdk::sequence_node(LINE, $2, $1);}
		|				{ $$ = new cdk::sequence_node(LINE, new cdk::nil_node(LINE)); }
		;


fdecl	: type tIDENTIFIER scope '(' optional_args ')' {$$ = new zu::function_declaration_node(LINE, $3, $1, $2, $5); }

	| '!' tIDENTIFIER scope '(' optional_args ')'
		{$$ = new zu::function_declaration_node(LINE, $3, new basic_type(0, basic_type::TYPE_VOID), $2, $5); }
	
	| type tIDENTIFIER scope '(' optional_args ')' block 
		{$$ = new zu::function_definition_node(LINE, $3, $1, $2, $5, nullptr, $7); }
	
	| '!' tIDENTIFIER scope '(' optional_args ')' block 
		{$$ = new zu::function_definition_node(LINE, $3, new basic_type(0, basic_type::TYPE_VOID), $2, $5, nullptr, $7); }

	| type tIDENTIFIER scope '(' optional_args ')' '=' literal
		{$$ = new zu::function_definition_node(LINE, $3, $1, $2, $5, $8, nullptr); }
	
	| type tIDENTIFIER scope '(' optional_args ')' '=' literal block 
		{$$ = new zu::function_definition_node(LINE, $3, $1, $2, $5, $8, $9); }
	;

block	: '{' vdecl_block instructions_block '}'	{ $$ = new zu::block_node(LINE, $2, $3); }
	;


instructions_block	: instructions_block instruction	{ $$ = new cdk::sequence_node(LINE, $2, $1);}
			|					{ $$ = new cdk::sequence_node(LINE, new cdk::nil_node(LINE)); }
			;

instruction	: expr ';'						{$$ = new zu::evaluation_node(LINE, $1);}
		/*| funcall ';'						{$$ = $1;}
		| funcall '!'						{$$ = new zu::print_node(LINE, $1, false);}
		| funcall tPRINTLN					{$$ = new zu::print_node(LINE, $1, true);}*/
		| expr '!'						{$$ = new zu::print_node(LINE, $1, false);}
		| expr tPRINTLN						{$$ = new zu::print_node(LINE, $1, true);}
		| tBREAK						{$$ = new zu::break_node(LINE);}
		| tCONTINUE						{$$ = new zu::continue_node(LINE);}
		| tRETURN						{$$ = new zu::return_node(LINE);}
		| '[' expr ']'  '#' instruction 			{$$ = new zu::if_node(LINE, $2, $5);}
		| '[' expr ']'  '?' instruction	/*%prec '?'*/		{$$ = new zu::if_node(LINE, $2, $5);}
		| '[' expr ']'  '?' instruction ':' instruction		{$$ = new zu::if_else_node(LINE, $2, $5, $7);}
		| block							{$$ = $1;}
		| '[' optional_things ';' optional_exprs ';' optional_exprs ']' instruction
									{$$ = new zu::for_node(LINE, $2, $4, $6, $8);}
		;


optional_things	: exprs			{$$ = $1;}
		| vdecl_b		{$$ = new cdk::sequence_node(LINE, $1);}
		| vdecl_b ',' vdecls	{$$ = new cdk::sequence_node(LINE, $1, $3);}
		|			{$$ = new cdk::sequence_node(LINE, new cdk::nil_node(LINE));}
		;

optional_exprs	: exprs		{ $$ = $1;}
		|		{ $$ = new cdk::sequence_node(LINE, new cdk::nil_node(LINE));}
		;

optional_args	: vdecls	{ $$ = $1; }
         	|		{ $$ = new cdk::sequence_node(LINE, new cdk::nil_node(LINE));}
        	;

exprs	: expr 			{ $$ = new cdk::sequence_node(LINE, $1);}
	| exprs ',' expr	{ $$ = new cdk::sequence_node(LINE, $3, $1);}
	;

type	: '#'					{ $$ = new basic_type(sizeof(int), basic_type::TYPE_INT);}
	| '%'					{ $$ = new basic_type(sizeof(double), basic_type::TYPE_DOUBLE);}
	| '$'					{ $$ = new basic_type(sizeof(std::string), basic_type::TYPE_STRING);}			
	| '<' type '>'				{ $$ = new basic_type(sizeof(void*), basic_type::TYPE_POINTER);}
	;

scope	: '?'					{ $$ = 2;}    // externa
	| '!'					{ $$ = 1;}    // publica
	|					{ $$ = 0;}    // privada
	;

expr	: literal 				{ $$ = $1;}
	| '-' expr				{ $$ = new cdk::neg_node(LINE, $2); }
	| '+' expr				{ $$ = new zu::identity_node(LINE, $2); }
	| lval '?'				{ $$ = new zu::address_node(LINE, $1); }
	| expr '+' expr				{ $$ = new cdk::add_node(LINE, $1, $3); }
	| expr '-' expr				{ $$ = new cdk::sub_node(LINE, $1, $3); }
	| expr '*' expr				{ $$ = new cdk::mul_node(LINE, $1, $3); }
 	| expr '/' expr				{ $$ = new cdk::div_node(LINE, $1, $3); }
	| expr '%' expr				{ $$ = new cdk::mod_node(LINE, $1, $3); }
	| expr '<' expr				{ $$ = new cdk::lt_node(LINE, $1, $3); }
	| expr '>' expr				{ $$ = new cdk::gt_node(LINE, $1, $3); }
	| expr tGE expr				{ $$ = new cdk::ge_node(LINE, $1, $3); }
	| expr tLE expr				{ $$ = new cdk::le_node(LINE, $1, $3); }
	| expr tNE expr				{ $$ = new cdk::ne_node(LINE, $1, $3); }
	| expr tEQ expr				{ $$ = new cdk::eq_node(LINE, $1, $3); }
	| '(' expr ')'				{ $$ = $2; }
	| '[' expr ']'				{ $$ = new zu::alloc_node(LINE, $2); } //?
	| lval					{ $$ = new zu::rvalue_node(LINE, $1); }  //FIXME?
	| lval '=' expr				{ $$ = new zu::assignment_node(LINE, $1, $3); }
	| expr '|' expr				{ $$ = new zu::or_node(LINE, $1, $3); } //
	| expr '&' expr				{ $$ = new zu::and_node(LINE, $1, $3); } //
	| '~' expr				{ $$ = new zu::not_node(LINE, $2); } //
	| '@'					{ $$ = new zu::read_node(LINE); } //
	| tIDENTIFIER '(' funcall_args ')'	{ $$ = new zu::function_call_node(LINE, $1, $3); }
	;

literal : tINTEGER				{ $$ = new cdk::integer_node(LINE, $1); }
	| tDOUBLE				{ $$ = new cdk::double_node(LINE, $1); }
	| stringa 				{ $$ = new cdk::string_node(LINE, $1); }
	;

funcall_args	: f_args	{ $$ = $1; }
		|		{ $$ = new cdk::sequence_node(LINE, new cdk::nil_node(LINE));}
		;
f_args	: expr			{ $$ = new cdk::sequence_node(LINE, $1); }
	| f_args ',' expr	{ $$ = new cdk::sequence_node(LINE, $3, $1); }
	;

lval	: tIDENTIFIER		{ $$ = new zu::identifier_node(LINE, *$1); }
	| expr '[' expr ']'	{ $$ = new zu::index_node(LINE, $1, $3); } //FIXME FIXME FIXME FIXME
	;

stringa : tSTRING               { $$ = $1;}
	| stringa tSTRING	{ $$ = new std::string(*$1 + *$2);}
	;

%%
