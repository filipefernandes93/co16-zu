%option c++ yyclass="zu_scanner" outfile="zu_scanner.cpp"
%option stack noyywrap yylineno 8bit
%{ 
/* $Id: zu_scanner.l,v 1.12 2016/05/15 15:25:00 ist173253 Exp $ */
// make relevant includes before including the parser's tab file
#include <string>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "zu_scanner.h"
#include "zu_parser.tab.h"

// don't change this
#define yyerror LexerError
%}

%x X_STRING X_COMMENT 
       
HEX			[0-9a-fA-F]
NUMBER			0|([1-9][0-9]*)
DIGIT			[0-9]

%%
    {set_debug(1);}
"//".*			; /* ignore comments */
"/*"			yy_push_state(X_COMMENT);

">="			return tGE; 
"<="			return tLE; 
"=="			return tEQ; 
"!="			return tNE;
	/*new tokens:*/
"><" 			return tBREAK;
"<>" 			return tCONTINUE;
"!!!" 			return tRETURN;
"!!" 			return tPRINTLN;

[A-Za-z_][A-Za-z0-9_]*  yylval.s = new std::string(yytext); return tIDENTIFIER;

\"                     yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\"           yy_pop_state(); return tSTRING;

 /*<X_STRING>\\\"         *yylval.s += yytext + 1;*/
<X_STRING>\\{HEX}{HEX}?	*yylval.s += static_cast<char>(strtol(yytext+1, nullptr, 16));

<X_STRING>\\\"		*yylval.s += "\"";
<X_STRING>\\\\		*yylval.s += "\\";
<X_STRING>\\n		*yylval.s += "\n";
<X_STRING>\\r		*yylval.s += "\r";
<X_STRING>\\t		*yylval.s += "\t";
<X_STRING>.		*yylval.s += yytext;
<X_STRING>\n		yyerror("newline in string");

<X_COMMENT>"/*"		yy_push_state(X_COMMENT);
<X_COMMENT>"*/"		yy_pop_state();
<X_COMMENT>.|\n		;

{NUMBER}					yylval.i = strtol(yytext, nullptr, 10); return tINTEGER;
[0][Xx][1-9a-fA-F]{HEX}*			yylval.i = strtol(yytext, nullptr, 16); return tINTEGER;

((({NUMBER})?\.{NUMBER})|{NUMBER})([Ee][+-]?{NUMBER})? yylval.d = strtod(yytext, nullptr); return tDOUBLE;


[-()<>=+*/%;{}.?!:\[\]#$,@~&|]       return *yytext;// /"?


[ \t\n\r]+               ; /* ignore whitespace */

.                      yyerror("Unknown character");

%%
// Very, very dirty hack: flex is a mess generating C++ scanners.
int zu_scanner::yywrap() { return 1; }
