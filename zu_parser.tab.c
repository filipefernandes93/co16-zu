/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20150711

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "zu_parser.y"
/* $Id: zu_parser.y,v 1.34 2016/05/20 05:19:25 ist173253 Exp $*/
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 14 "zu_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int                   i;	/* integer value */
  double		d;
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  zu::lvalue_node  *lvalue;
  basic_type *t;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 55 "zu_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 52 "zu_parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define tINTEGER 257
#define tIDENTIFIER 258
#define tSTRING 259
#define tDOUBLE 260
#define tBREAK 261
#define tCONTINUE 262
#define tRETURN 263
#define tPRINTLN 264
#define tGE 265
#define tLE 266
#define tEQ 267
#define tNE 268
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    7,    7,    1,    1,    2,    2,    6,    6,   12,
   12,   13,   13,    3,    3,    3,    3,    3,    3,    4,
    9,    9,    5,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,   14,   14,   14,   14,   11,   11,    8,
    8,   10,   10,   21,   21,   21,   21,   22,   22,   22,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   18,   18,   18,   15,   15,   16,
   16,   19,   19,   20,   20,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    2,    1,    3,    5,    3,    5,    1,
    3,    3,    0,    6,    6,    7,    7,    8,    9,    4,
    2,    0,    2,    2,    2,    1,    1,    1,    5,    5,
    7,    1,    8,    1,    1,    3,    0,    1,    0,    1,
    0,    1,    3,    1,    1,    1,    3,    1,    1,    0,
    1,    2,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    1,    3,    3,
    3,    2,    1,    4,    1,    1,    1,    1,    0,    1,
    3,    1,    4,    1,    2,
};
static const YYINT yydefred[] = {                         0,
    0,   45,    0,   44,   46,    0,    2,    0,    5,    0,
    0,    0,    0,    4,    3,    0,   47,   48,   49,    0,
    0,    0,    0,    0,    0,    0,   40,    0,   75,   84,
   76,    7,    0,    0,    0,    0,    0,   85,    0,   11,
   13,   17,    0,    0,   16,    0,    0,    0,    0,    0,
   19,   12,    0,   26,   27,   28,    0,    0,    0,    0,
    0,   20,   73,   32,   21,    0,   51,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   25,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   23,   24,   54,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   66,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   74,    0,   67,   36,    0,    0,
    0,    0,    0,    0,   83,    9,    0,    0,    0,   29,
    0,    0,    0,   31,   33,
};
static const YYINT yydgoto[] = {                          6,
    7,   25,    9,   64,   65,   48,   10,   26,   49,  130,
  131,   27,   46,   77,  100,  101,   66,   67,   68,   33,
   28,   20,
};
static const YYINT yysindex[] = {                       179,
  113,    0, -234,    0,    0,    0,    0,  -26,    0,  179,
 -209,  -10,  -28,    0,    0,  -28,    0,    0,    0,   50,
   10,  113,  -59,  113,   12,   35,    0, -151,    0,    0,
    0,    0, -137,   87,  113,   15,  -28,    0,  -57,    0,
    0,    0,   78,  -59,    0,  113,   15,   86,  613, -111,
    0,    0,  142,    0,    0,    0,  596,  596,  596,  752,
  596,    0,    0,    0,    0,  166,    0,    4,  -28,  596,
  596,  687,   63,   63,  140,  145,  138,  450,  543,    0,
  596,  596,  596,  596,  596,  596,  596,  596,  596,  596,
  596,  596,  596,  596,    0,    0,    0,  596,  125,  161,
  174,  652,  583,  113,  596,  596,  -16,    0,  663,  687,
  756,  756,  756,  756,  756,  756,   63,   63,  119,  119,
  119,  595,  652,  -59,    0,  596,    0,    0,  652,  145,
  160,  652,  741,  741,    0,    0,  652,  596,  162,    0,
  128,  741,  741,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  222,
    0,    0,  184,    0,    0,   30,    0,    0,    0,    0,
  170,  190,    0,  190,   62,    0,    0,    0,    0,    0,
    0,    0,    1,    0,    0,   22,  146,    0,   51,    0,
    0,    0,  111,    0,    0,  705,  358,    0,    0,    0,
    0,    0,   36,    0,    0,    0,    0,    0,    0,  173,
    0,    0,    0,    0,    0,    0,    0,   71,  186,  197,
    0,  -18,  237,  250,  182,  185,    0,  -19,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   75,    0,
  208,   82,    0,    0,    0,  194,  217,    0,  124,  147,
  346,  382,  405,  414,  498,  507,  288,  311,  -31,   99,
  134,    0,  283,    0,    0,    0,    0,    0,   58,  -29,
    0,   76,    0,    0,    0,    0,  112,  163,  713,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  251,   17,    0,  127,  109,  203,    0,  248,    0,  213,
  136,  -32,    0,    0,    0,    0,  851,  -23,    0,    0,
    8,   16,
};
#define YYTABLESIZE 1012
static const YYINT yytable[] = {                         32,
   77,   57,   40,   44,   19,   57,   57,   11,   12,   57,
   57,   57,   57,   57,   72,   57,    8,   11,  134,   72,
   47,   15,   72,   13,   42,   72,    8,   57,   57,   38,
   57,   21,   14,   77,   18,   77,   77,   77,   77,   42,
   72,   77,   77,   77,   77,   77,  133,   77,   16,   24,
   14,   17,   43,   50,   15,   35,   15,   15,   15,   77,
   77,   57,   77,   38,   98,   41,   97,   50,   82,   50,
   23,  128,   82,   82,   72,   36,   82,   82,   82,   82,
   82,   15,   82,   14,   99,   14,   14,   14,   50,   22,
   50,   77,   57,   77,   82,   82,   82,   82,   82,   93,
  136,   43,   10,   68,   91,   72,   37,   68,   68,   92,
   14,   68,   68,   68,   68,   68,   43,   68,    8,   42,
   10,   38,   80,   77,   77,   80,   82,   39,   82,   68,
   68,   58,   68,    8,   42,   58,   58,   41,   23,   58,
   58,   58,   58,   58,   52,   58,   69,    4,    5,    2,
   43,    6,   81,   94,    6,   81,   70,   58,   58,   82,
   58,   68,   42,   68,   70,   45,   59,   70,   42,    6,
   59,   59,    1,   51,   59,   59,   59,   59,   59,   71,
   59,   70,   70,  104,   71,  124,   50,   71,  105,   50,
   71,   58,   59,   59,   68,   59,  106,   29,   96,   30,
   31,  125,   93,   82,   50,   71,   50,   91,   89,   94,
   90,    3,   92,    4,    5,    2,   70,  126,  138,  142,
  143,    1,   58,   50,   95,   88,   59,   87,    6,   50,
   41,   37,   57,   57,   57,   57,   57,   79,    1,   71,
   35,  139,  140,   34,   50,   72,   50,   70,   78,   67,
  144,  145,   39,   67,   67,   39,   94,   59,   67,   67,
   15,   67,   75,   67,   77,   77,   77,   77,   77,   53,
   71,   34,   76,  141,   53,   67,   67,   53,   67,   53,
   53,   53,   52,    0,    0,    0,    0,   52,    0,   81,
   52,    0,   52,   52,   52,   53,   53,    0,   53,   82,
   82,   82,   82,   82,    0,    0,    0,   67,   52,   52,
    0,   52,    0,    0,    0,   69,    0,    0,    0,    0,
   55,    0,    0,   69,    0,   55,   69,    0,   55,   53,
   55,   55,   55,    0,   68,   68,   68,   68,   68,    0,
   67,   69,   52,   56,    0,    0,   55,   55,   56,   55,
    0,   56,    0,   56,   56,   56,    0,   18,    0,    0,
   53,    0,   58,   58,   58,   58,   58,    0,    0,   56,
   56,    0,   56,   52,    0,   69,    0,    0,   62,    0,
   55,    0,    0,   62,    0,    0,   62,   70,    0,   62,
   18,    0,   18,   18,   18,    0,    0,   59,   59,   59,
   59,   59,    0,   56,   62,   62,    0,   62,    0,    0,
   71,   55,    0,    0,   63,    0,    0,   18,    0,   63,
    0,    0,   63,    0,    0,   63,    0,    0,    0,   80,
   83,   84,   85,   86,   56,    0,    0,   65,   62,    0,
   63,   63,   65,   63,    0,   65,   64,    0,   65,    0,
    0,   64,    0,    0,   64,    0,    0,   64,    0,    0,
    0,    0,    0,   65,   65,    0,   65,    0,    0,   62,
    0,    0,   64,   64,   63,   64,    0,    0,    0,    0,
   67,   67,   67,   67,   67,    0,   93,   82,    0,    0,
    0,   91,   89,    0,   90,    0,   92,   65,    0,    0,
   53,   53,   53,   53,   53,   63,   64,    0,    0,   88,
    0,   87,    0,   52,   52,   52,   52,   52,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   65,    0,
   61,    0,    0,    0,    0,   61,    0,   64,   61,   60,
   94,   61,  107,    0,   60,    0,   69,   60,    0,    0,
   60,   55,   55,   55,   55,   55,   61,   61,    0,   61,
    0,    0,    0,    0,    0,   60,   60,    0,   60,    0,
    0,    0,    0,   81,   56,   56,   56,   56,   56,   93,
   82,    0,    0,  108,   91,   89,    0,   90,    0,   92,
   61,    0,    0,    0,    0,    0,    0,    0,    0,   60,
    0,    0,   88,    0,   87,    0,    0,    0,    0,   62,
   62,   62,   62,   62,    0,    0,    0,    0,    0,   93,
   82,   61,    0,    0,   91,   89,    0,   90,    0,   92,
   60,   93,   82,   94,    0,   61,   91,   89,   58,   90,
   59,   92,   88,    0,   87,   63,   63,   63,   63,   63,
    0,    0,   61,    0,   88,   58,   87,   59,    0,   63,
    0,    0,    0,    0,    0,    0,   81,    0,   65,   65,
   65,   65,   65,   94,    0,  127,   63,   64,   64,   64,
   64,   64,    0,    0,    0,   94,   71,  135,   93,   82,
    0,    0,    0,   91,   89,    0,   90,    0,   92,   93,
   82,    0,    0,   60,   91,   89,   81,   90,    0,   92,
    0,   88,    0,   87,   83,   84,   85,   86,   81,    0,
    0,   57,   88,   93,   87,    0,    0,    0,   91,   89,
    0,   90,    0,   92,    0,   41,    0,   62,   57,    0,
    0,    0,   94,    0,   22,    0,   88,   22,   87,   22,
    0,    0,   30,   94,    0,   30,    0,   30,    0,    0,
    0,   61,   61,   61,   61,   61,    0,    0,   22,    0,
   60,   60,   60,   60,   60,   81,   30,   94,    0,    0,
   61,    0,    0,   58,    0,   59,    4,    5,    2,    0,
    0,   61,   93,    0,   58,   22,   59,   91,   89,    0,
   90,    0,   92,   30,   63,    0,    0,   83,   84,   85,
   86,    1,    0,    0,    0,   63,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   22,    0,   22,
   22,   60,    0,    0,    0,   30,    0,   30,   30,    0,
    0,    0,   71,    0,    0,    0,   94,   83,   84,   85,
   86,    0,   29,   53,   30,   31,    0,    0,    0,   83,
   84,   85,   86,   41,    0,    0,   57,    0,    0,   29,
   53,   30,   31,   54,   55,   56,    0,   57,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   72,   73,   74,
   78,   79,    0,    0,    0,    0,   83,   84,   85,   86,
  102,  103,    0,    0,    0,    0,    0,   83,   84,   85,
   86,  109,  110,  111,  112,  113,  114,  115,  116,  117,
  118,  119,  120,  121,  122,    0,    0,    0,  123,    0,
    0,   83,   84,   85,   86,  129,  132,    0,    0,    0,
    0,   22,   22,   22,   22,   22,   22,   22,    0,   30,
   30,   30,   30,   30,   30,   30,  137,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  132,    0,
    0,    0,    0,    0,    0,    0,    0,   29,   53,   30,
   31,   54,   55,   56,    0,    0,    0,    0,   29,   53,
   30,   31,
};
static const YYINT yycheck[] = {                         23,
    0,   33,   35,   61,   33,   37,   38,    0,    1,   41,
   42,   43,   44,   45,   33,   47,    0,   10,   35,   38,
   44,    0,   41,  258,   44,   44,   10,   59,   60,   59,
   62,   16,   59,   33,   63,   35,   36,   37,   38,   59,
   59,   41,   42,   43,   44,   45,   63,   47,  258,   40,
    0,   62,   37,   46,   33,   44,   35,   36,   37,   59,
   60,   93,   62,   93,   61,  123,   63,   60,   33,   40,
   61,  104,   37,   38,   93,   41,   41,   42,   43,   44,
   45,   60,   47,   33,   69,   35,   36,   37,   59,   40,
   61,   91,  124,   93,   59,   60,   61,   62,   63,   37,
  124,   44,   41,   33,   42,  124,  258,   37,   38,   47,
   60,   41,   42,   43,   44,   45,   59,   47,   44,   44,
   59,  259,   41,  123,  124,   44,   91,   41,   93,   59,
   60,   33,   62,   59,   59,   37,   38,  123,   61,   41,
   42,   43,   44,   45,   59,   47,  258,   35,   36,   37,
   93,   41,   41,   91,   44,   44,   33,   59,   60,  124,
   62,   91,   36,   93,   41,   39,   33,   44,   93,   59,
   37,   38,   60,   47,   41,   42,   43,   44,   45,   33,
   47,   40,   59,   44,   38,   61,   41,   41,   44,   44,
   44,   93,   59,   60,  124,   62,   59,  257,   33,  259,
  260,   41,   37,   38,   59,   59,   61,   42,   43,   91,
   45,   33,   47,   35,   36,   37,   93,   44,   59,   58,
   93,    0,  124,   40,   59,   60,   93,   62,   59,   44,
   41,   59,  264,  265,  266,  267,  268,   41,   60,   93,
   59,  133,  134,   59,   59,  264,   61,  124,   41,   33,
  142,  143,   59,   37,   38,   93,   91,  124,   42,   43,
   10,   45,   60,   47,  264,  265,  266,  267,  268,   33,
  124,   24,   60,  138,   38,   59,   60,   41,   62,   43,
   44,   45,   33,   -1,   -1,   -1,   -1,   38,   -1,  124,
   41,   -1,   43,   44,   45,   59,   60,   -1,   62,  264,
  265,  266,  267,  268,   -1,   -1,   -1,   91,   59,   60,
   -1,   62,   -1,   -1,   -1,   33,   -1,   -1,   -1,   -1,
   33,   -1,   -1,   41,   -1,   38,   44,   -1,   41,   93,
   43,   44,   45,   -1,  264,  265,  266,  267,  268,   -1,
  124,   59,   93,   33,   -1,   -1,   59,   60,   38,   62,
   -1,   41,   -1,   43,   44,   45,   -1,    0,   -1,   -1,
  124,   -1,  264,  265,  266,  267,  268,   -1,   -1,   59,
   60,   -1,   62,  124,   -1,   93,   -1,   -1,   33,   -1,
   93,   -1,   -1,   38,   -1,   -1,   41,  264,   -1,   44,
   33,   -1,   35,   36,   37,   -1,   -1,  264,  265,  266,
  267,  268,   -1,   93,   59,   60,   -1,   62,   -1,   -1,
  264,  124,   -1,   -1,   33,   -1,   -1,   60,   -1,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,  264,
  265,  266,  267,  268,  124,   -1,   -1,   33,   93,   -1,
   59,   60,   38,   62,   -1,   41,   33,   -1,   44,   -1,
   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,
   -1,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,  124,
   -1,   -1,   59,   60,   93,   62,   -1,   -1,   -1,   -1,
  264,  265,  266,  267,  268,   -1,   37,   38,   -1,   -1,
   -1,   42,   43,   -1,   45,   -1,   47,   93,   -1,   -1,
  264,  265,  266,  267,  268,  124,   93,   -1,   -1,   60,
   -1,   62,   -1,  264,  265,  266,  267,  268,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,
   33,   -1,   -1,   -1,   -1,   38,   -1,  124,   41,   33,
   91,   44,   93,   -1,   38,   -1,  264,   41,   -1,   -1,
   44,  264,  265,  266,  267,  268,   59,   60,   -1,   62,
   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,
   -1,   -1,   -1,  124,  264,  265,  266,  267,  268,   37,
   38,   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,
   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,
   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,  264,
  265,  266,  267,  268,   -1,   -1,   -1,   -1,   -1,   37,
   38,  124,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
  124,   37,   38,   91,   -1,   40,   42,   43,   43,   45,
   45,   47,   60,   -1,   62,  264,  265,  266,  267,  268,
   -1,   -1,   40,   -1,   60,   43,   62,   45,   -1,   64,
   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,  264,  265,
  266,  267,  268,   91,   -1,   93,   64,  264,  265,  266,
  267,  268,   -1,   -1,   -1,   91,   91,   93,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   37,
   38,   -1,   -1,   91,   42,   43,  124,   45,   -1,   47,
   -1,   60,   -1,   62,  265,  266,  267,  268,  124,   -1,
   -1,  126,   60,   37,   62,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,  123,   -1,  125,  126,   -1,
   -1,   -1,   91,   -1,   40,   -1,   60,   43,   62,   45,
   -1,   -1,   40,   91,   -1,   43,   -1,   45,   -1,   -1,
   -1,  264,  265,  266,  267,  268,   -1,   -1,   64,   -1,
  264,  265,  266,  267,  268,  124,   64,   91,   -1,   -1,
   40,   -1,   -1,   43,   -1,   45,   35,   36,   37,   -1,
   -1,   40,   37,   -1,   43,   91,   45,   42,   43,   -1,
   45,   -1,   47,   91,   64,   -1,   -1,  265,  266,  267,
  268,   60,   -1,   -1,   -1,   64,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,
  126,   91,   -1,   -1,   -1,  123,   -1,  125,  126,   -1,
   -1,   -1,   91,   -1,   -1,   -1,   91,  265,  266,  267,
  268,   -1,  257,  258,  259,  260,   -1,   -1,   -1,  265,
  266,  267,  268,  123,   -1,   -1,  126,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,   -1,  126,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   57,   58,   59,
   60,   61,   -1,   -1,   -1,   -1,  265,  266,  267,  268,
   70,   71,   -1,   -1,   -1,   -1,   -1,  265,  266,  267,
  268,   81,   82,   83,   84,   85,   86,   87,   88,   89,
   90,   91,   92,   93,   94,   -1,   -1,   -1,   98,   -1,
   -1,  265,  266,  267,  268,  105,  106,   -1,   -1,   -1,
   -1,  257,  258,  259,  260,  261,  262,  263,   -1,  257,
  258,  259,  260,  261,  262,  263,  126,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  138,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,  263,   -1,   -1,   -1,   -1,  257,  258,
  259,  260,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 268
#define YYUNDFTOKEN 293
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'","'$'","'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,
0,0,0,0,0,0,0,0,0,"':'","';'","'<'","'='","'>'","'?'","'@'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tINTEGER",
"tIDENTIFIER","tSTRING","tDOUBLE","tBREAK","tCONTINUE","tRETURN","tPRINTLN",
"tGE","tLE","tEQ","tNE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : declarations",
"declarations : decl",
"declarations : declarations decl",
"decl : vdecl ';'",
"decl : fdecl",
"vdecl : type tIDENTIFIER scope",
"vdecl : type tIDENTIFIER scope '=' literal",
"vdecl_b : type tIDENTIFIER scope",
"vdecl_b : type tIDENTIFIER scope '=' literal",
"vdecls : vdecl",
"vdecls : vdecl ',' vdecls",
"vdecl_block : vdecl_block vdecl_b ';'",
"vdecl_block :",
"fdecl : type tIDENTIFIER scope '(' optional_args ')'",
"fdecl : '!' tIDENTIFIER scope '(' optional_args ')'",
"fdecl : type tIDENTIFIER scope '(' optional_args ')' block",
"fdecl : '!' tIDENTIFIER scope '(' optional_args ')' block",
"fdecl : type tIDENTIFIER scope '(' optional_args ')' '=' literal",
"fdecl : type tIDENTIFIER scope '(' optional_args ')' '=' literal block",
"block : '{' vdecl_block instructions_block '}'",
"instructions_block : instructions_block instruction",
"instructions_block :",
"instruction : expr ';'",
"instruction : expr '!'",
"instruction : expr tPRINTLN",
"instruction : tBREAK",
"instruction : tCONTINUE",
"instruction : tRETURN",
"instruction : '[' expr ']' '#' instruction",
"instruction : '[' expr ']' '?' instruction",
"instruction : '[' expr ']' '?' instruction ':' instruction",
"instruction : block",
"instruction : '[' optional_things ';' optional_exprs ';' optional_exprs ']' instruction",
"optional_things : exprs",
"optional_things : vdecl_b",
"optional_things : vdecl_b ',' vdecls",
"optional_things :",
"optional_exprs : exprs",
"optional_exprs :",
"optional_args : vdecls",
"optional_args :",
"exprs : expr",
"exprs : exprs ',' expr",
"type : '#'",
"type : '%'",
"type : '$'",
"type : '<' type '>'",
"scope : '?'",
"scope : '!'",
"scope :",
"expr : literal",
"expr : '-' expr",
"expr : '+' expr",
"expr : lval '?'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr tGE expr",
"expr : expr tLE expr",
"expr : expr tNE expr",
"expr : expr tEQ expr",
"expr : '(' expr ')'",
"expr : '[' expr ']'",
"expr : lval",
"expr : lval '=' expr",
"expr : expr '|' expr",
"expr : expr '&' expr",
"expr : '~' expr",
"expr : '@'",
"expr : tIDENTIFIER '(' funcall_args ')'",
"literal : tINTEGER",
"literal : tDOUBLE",
"literal : stringa",
"funcall_args : f_args",
"funcall_args :",
"f_args : expr",
"f_args : f_args ',' expr",
"lval : tIDENTIFIER",
"lval : expr '[' expr ']'",
"stringa : tSTRING",
"stringa : stringa tSTRING",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 59 "zu_parser.y"
	{compiler->ast(yystack.l_mark[0].sequence);}
break;
case 2:
#line 62 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 3:
#line 63 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 4:
#line 66 "zu_parser.y"
	{yyval.node = yystack.l_mark[-1].node;}
break;
case 5:
#line 67 "zu_parser.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 6:
#line 70 "zu_parser.y"
	{ yyval.node = new zu::variable_node(LINE, 1, yystack.l_mark[-2].t, yystack.l_mark[-1].s, nullptr);}
break;
case 7:
#line 71 "zu_parser.y"
	{ yyval.node = new zu::variable_node(LINE, 1, yystack.l_mark[-4].t, yystack.l_mark[-3].s, yystack.l_mark[0].expression);}
break;
case 8:
#line 74 "zu_parser.y"
	{ yyval.node = new zu::variable_node(LINE, 3 /*$3*/, yystack.l_mark[-2].t, yystack.l_mark[-1].s, nullptr);}
break;
case 9:
#line 75 "zu_parser.y"
	{ yyval.node = new zu::variable_node(LINE, 3 /*$3*/, yystack.l_mark[-4].t, yystack.l_mark[-3].s, yystack.l_mark[0].expression);}
break;
case 10:
#line 78 "zu_parser.y"
	{yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node);}
break;
case 11:
#line 79 "zu_parser.y"
	{yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[-2].node, yystack.l_mark[0].sequence);}
break;
case 12:
#line 82 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[-1].node, yystack.l_mark[-2].sequence);}
break;
case 13:
#line 83 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, new cdk::nil_node(LINE)); }
break;
case 14:
#line 87 "zu_parser.y"
	{yyval.node = new zu::function_declaration_node(LINE, yystack.l_mark[-3].i, yystack.l_mark[-5].t, yystack.l_mark[-4].s, yystack.l_mark[-1].sequence); }
break;
case 15:
#line 90 "zu_parser.y"
	{yyval.node = new zu::function_declaration_node(LINE, yystack.l_mark[-3].i, new basic_type(0, basic_type::TYPE_VOID), yystack.l_mark[-4].s, yystack.l_mark[-1].sequence); }
break;
case 16:
#line 93 "zu_parser.y"
	{yyval.node = new zu::function_definition_node(LINE, yystack.l_mark[-4].i, yystack.l_mark[-6].t, yystack.l_mark[-5].s, yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].node); }
break;
case 17:
#line 96 "zu_parser.y"
	{yyval.node = new zu::function_definition_node(LINE, yystack.l_mark[-4].i, new basic_type(0, basic_type::TYPE_VOID), yystack.l_mark[-5].s, yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].node); }
break;
case 18:
#line 99 "zu_parser.y"
	{yyval.node = new zu::function_definition_node(LINE, yystack.l_mark[-5].i, yystack.l_mark[-7].t, yystack.l_mark[-6].s, yystack.l_mark[-3].sequence, yystack.l_mark[0].expression, nullptr); }
break;
case 19:
#line 102 "zu_parser.y"
	{yyval.node = new zu::function_definition_node(LINE, yystack.l_mark[-6].i, yystack.l_mark[-8].t, yystack.l_mark[-7].s, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].node); }
break;
case 20:
#line 105 "zu_parser.y"
	{ yyval.node = new zu::block_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-1].sequence); }
break;
case 21:
#line 109 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence);}
break;
case 22:
#line 110 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, new cdk::nil_node(LINE)); }
break;
case 23:
#line 113 "zu_parser.y"
	{yyval.node = new zu::evaluation_node(LINE, yystack.l_mark[-1].expression);}
break;
case 24:
#line 117 "zu_parser.y"
	{yyval.node = new zu::print_node(LINE, yystack.l_mark[-1].expression, false);}
break;
case 25:
#line 118 "zu_parser.y"
	{yyval.node = new zu::print_node(LINE, yystack.l_mark[-1].expression, true);}
break;
case 26:
#line 119 "zu_parser.y"
	{yyval.node = new zu::break_node(LINE);}
break;
case 27:
#line 120 "zu_parser.y"
	{yyval.node = new zu::continue_node(LINE);}
break;
case 28:
#line 121 "zu_parser.y"
	{yyval.node = new zu::return_node(LINE);}
break;
case 29:
#line 122 "zu_parser.y"
	{yyval.node = new zu::if_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[0].node);}
break;
case 30:
#line 123 "zu_parser.y"
	{yyval.node = new zu::if_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[0].node);}
break;
case 31:
#line 124 "zu_parser.y"
	{yyval.node = new zu::if_else_node(LINE, yystack.l_mark[-5].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 32:
#line 125 "zu_parser.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 33:
#line 127 "zu_parser.y"
	{yyval.node = new zu::for_node(LINE, yystack.l_mark[-6].sequence, yystack.l_mark[-4].sequence, yystack.l_mark[-2].sequence, yystack.l_mark[0].node);}
break;
case 34:
#line 131 "zu_parser.y"
	{yyval.sequence = yystack.l_mark[0].sequence;}
break;
case 35:
#line 132 "zu_parser.y"
	{yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node);}
break;
case 36:
#line 133 "zu_parser.y"
	{yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[-2].node, yystack.l_mark[0].sequence);}
break;
case 37:
#line 134 "zu_parser.y"
	{yyval.sequence = new cdk::sequence_node(LINE, new cdk::nil_node(LINE));}
break;
case 38:
#line 137 "zu_parser.y"
	{ yyval.sequence = yystack.l_mark[0].sequence;}
break;
case 39:
#line 138 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, new cdk::nil_node(LINE));}
break;
case 40:
#line 141 "zu_parser.y"
	{ yyval.sequence = yystack.l_mark[0].sequence; }
break;
case 41:
#line 142 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, new cdk::nil_node(LINE));}
break;
case 42:
#line 145 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression);}
break;
case 43:
#line 146 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-2].sequence);}
break;
case 44:
#line 149 "zu_parser.y"
	{ yyval.t = new basic_type(sizeof(int), basic_type::TYPE_INT);}
break;
case 45:
#line 150 "zu_parser.y"
	{ yyval.t = new basic_type(sizeof(double), basic_type::TYPE_DOUBLE);}
break;
case 46:
#line 151 "zu_parser.y"
	{ yyval.t = new basic_type(sizeof(std::string), basic_type::TYPE_STRING);}
break;
case 47:
#line 152 "zu_parser.y"
	{ yyval.t = new basic_type(sizeof(void*), basic_type::TYPE_POINTER);}
break;
case 48:
#line 155 "zu_parser.y"
	{ yyval.i = 2;}
break;
case 49:
#line 156 "zu_parser.y"
	{ yyval.i = 1;}
break;
case 50:
#line 157 "zu_parser.y"
	{ yyval.i = 0;}
break;
case 51:
#line 160 "zu_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression;}
break;
case 52:
#line 161 "zu_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 53:
#line 162 "zu_parser.y"
	{ yyval.expression = new zu::identity_node(LINE, yystack.l_mark[0].expression); }
break;
case 54:
#line 163 "zu_parser.y"
	{ yyval.expression = new zu::address_node(LINE, yystack.l_mark[-1].lvalue); }
break;
case 55:
#line 164 "zu_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 56:
#line 165 "zu_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 57:
#line 166 "zu_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 58:
#line 167 "zu_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 59:
#line 168 "zu_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 60:
#line 169 "zu_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 61:
#line 170 "zu_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 62:
#line 171 "zu_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 63:
#line 172 "zu_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 64:
#line 173 "zu_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 65:
#line 174 "zu_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 66:
#line 175 "zu_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 67:
#line 176 "zu_parser.y"
	{ yyval.expression = new zu::alloc_node(LINE, yystack.l_mark[-1].expression); }
break;
case 68:
#line 177 "zu_parser.y"
	{ yyval.expression = new zu::rvalue_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 69:
#line 178 "zu_parser.y"
	{ yyval.expression = new zu::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 70:
#line 179 "zu_parser.y"
	{ yyval.expression = new zu::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 71:
#line 180 "zu_parser.y"
	{ yyval.expression = new zu::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 72:
#line 181 "zu_parser.y"
	{ yyval.expression = new zu::not_node(LINE, yystack.l_mark[0].expression); }
break;
case 73:
#line 182 "zu_parser.y"
	{ yyval.expression = new zu::read_node(LINE); }
break;
case 74:
#line 183 "zu_parser.y"
	{ yyval.expression = new zu::function_call_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 75:
#line 186 "zu_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 76:
#line 187 "zu_parser.y"
	{ yyval.expression = new cdk::double_node(LINE, yystack.l_mark[0].d); }
break;
case 77:
#line 188 "zu_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 78:
#line 191 "zu_parser.y"
	{ yyval.sequence = yystack.l_mark[0].sequence; }
break;
case 79:
#line 192 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, new cdk::nil_node(LINE));}
break;
case 80:
#line 194 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression); }
break;
case 81:
#line 195 "zu_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-2].sequence); }
break;
case 82:
#line 198 "zu_parser.y"
	{ yyval.lvalue = new zu::identifier_node(LINE, *yystack.l_mark[0].s); }
break;
case 83:
#line 199 "zu_parser.y"
	{ yyval.lvalue = new zu::index_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[-1].expression); }
break;
case 84:
#line 202 "zu_parser.y"
	{ yyval.s = yystack.l_mark[0].s;}
break;
case 85:
#line 203 "zu_parser.y"
	{ yyval.s = new std::string(*yystack.l_mark[-1].s + *yystack.l_mark[0].s);}
break;
#line 1078 "zu_parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
