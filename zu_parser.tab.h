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
extern YYSTYPE yylval;
