// Includes stuff
%{
#include <stdio.h>
#include <stdlib.h>
//#include "y.tab.h"

extern int yylex();
extern int yyparse();

void yyerror(const char* msg);

extern int numline;
extern int numcol;
FILE *yyin;i
%}


// Assigning value to property of yyval
%union {
  int num_val;
  char* id_val;
}

%error-verbose
// Define tokens

%start prog_start
// All tokens same as Phase 1
%token SEMICOLON FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY ENUM OF IF THEN ENDIF ELSE WHILE DO BEGIN_LOOP END_LOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN END FOR
%token <num_val> NUMBER
%token <id_val> IDENT

%right ASSIGN
%left OR
%left AND
%right NOT
%left NEQ EQ GTE GT LTE LT
%left ADD SUB
%left MULT DIV MOD

// Grammer defined below
%%

prog_start:   functions { printf("prog_start -> functions\n");}
	;

functions:	/*empty*/{printf("functions -> epsilon\n");}
	| function functions {printf("functions -> function functions\n");}
	;

function:	FUNCTION identifier SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY {printf("function -> FUNCTION identifier SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY\n");}
	;

declarations:	/*empty*/{printf("declarations -> epsilon\n");}
	| declaration SEMICOLON declarations {printf("declarations -> declaration SEMICOLON declarations\n");}
	;

declaration:	identifiers COLON INTEGER {printf("declaration -> identifiers COLON INTEGER\n");}
	| identifiers COLON ENUM L_PAREN identifiers R_PAREN {printf("declaration -> identifiers COLON ENUM L_PAREN identifiers R_PAREN\n");}
	| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {printf("declaration -> identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
	;

statements:	statement SEMICOLON {printf("statements -> statement SEMICOLON\n");}
	| statement SEMICOLON statements {printf("statements -> statement SEMICOLON statements\n");}
	;

statement:	var ASSIGN expression {printf("statement -> var ASSIGN expression\n");}
	| IF bool_exp THEN statements ENDIF {printf("statement -> IF bool_exp THEN statements ENDIF\n");}
	| IF bool_exp THEN statements ELSE statements ENDIF {printf("statement -> IF bool_exp THEN statements ELSE statements ENDIF\n");}
	| WHILE bool_exp BEGIN_LOOP statements END_LOOP {printf("statement -> WHILE bool_exp BEGINLOOP statements ENDLOOP\n");}
	| DO BEGIN_LOOP statements END_LOOP WHILE bool_exp {printf("statement -> DO BEGINLOOP statement_loop ENDLOOP WHILE bool_exp\n");}
	| FOR vars ASSIGN NUMBER SEMICOLON bool_exp SEMICOLON vars ASSIGN expression BEGIN_LOOP statements END_LOOP {printf("statement -> FOR vars ASSIGN NUMBER SEMICOLON bool_exp SEMICOLON vars ASSIGN expression BEGINLOOP statements ENDLOOP\n");}
	| READ vars {printf("statement -> READ vars\n");}
	| WRITE vars {printf("statement -> WRITE vars\n");}
	| CONTINUE {printf("statement -> CONTINUE \n");}
	| RETURN expression {printf("statement -> RETURN expression\n");}
	;

bool_exp:	relation_and_exp {printf("bool_exp -> relation_and_exp\n");}
	| relation_and_exp OR bool_exp {printf("bool_exp -> relation_and_exp OR bool_exp\n");}
	;

relation_and_exp:	relation_exp {printf("relation_and_exp -> relation_exp\n");}
	| relation_exp AND relation_and_exp {printf("relation_and_exp -> relation_exp AND relation_and_exp\n");}
	;

relation_exp:	expression comp expression {printf("relation_exp -> expression comp expression\n");}
	| TRUE {printf("relation_exp -> TRUE\n");}
	| FALSE {printf("relation_exp -> FALSE\n");}
	| L_PAREN bool_exp R_PAREN {printf("relation_exp -> L_PAREN bool_exp R_PAREN\n");}
	| NOT expression comp expression {printf("relation_exp -> NOT expression comp expression\n");}
	| NOT TRUE {printf("relation_exp -> NOT TRUE\n");}
	| NOT FALSE {printf("relation_exp -> NOT FALSE\n");}
	| NOT L_PAREN bool_exp R_PAREN {printf("relation_exp -> NOT L_PAREN bool_exp R_PAREN\n");}
	;

comp:	EQ {printf("comp -> EQ\n");}
	| NEQ {printf("comp -> NEQ\n");}
	| LT {printf("comp -> LT\n");}
	| GT {printf("comp -> GT\n");}
	| LTE {printf("comp -> LTE\n");}
	| GTE {printf("comp -> GTE\n");}
	;

expressions:	/*empty*/ {printf("expressions -> epsilon\n");}
	| expression {printf("expressions -> expression\n");}
	| expression COMMA expressions {printf("expressions -> expression COMMA expressions\n");}
	;

expression:	multiplicative_expr {printf("expression -> multiplicative_expr\n");}
	| multiplicative_expr ADD expression {printf("expression -> multiplicative_expr ADD expression\n");}
	| multiplicative_expr SUB expression {printf("expression -> multiplicative_expr SUB expression\n");}
	;

multiplicative_expr:	term {printf("multiplicative_expr -> term\n");}
	| term MULT multiplicative_expr {printf("multiplicative_expr -> term MULT multiplicative_expr\n");}
	| term DIV multiplicative_expr {printf("multiplicative_expr -> term DIV multiplicative_expr\n");}
	| term MOD multiplicative_expr {printf("multiplicative_expr -> term MOD multiplicative_expr\n");}
	;

term:	var {printf("term -> var\n");}
	| SUB var {printf("term -> SUB var\n");}
	| NUMBER {printf("term -> NUMBER %d\n", $1);}
	| SUB NUMBER {printf("term -> SUB NUMBER %d\n", $2);}
	| L_PAREN expression R_PAREN {printf("term -> L_PAREN expression R_PAREN\n");}
	| SUB L_PAREN expression R_PAREN {printf("term -> SUB L_PAREN expression R_PAREN\n");}
	| identifier L_PAREN expressions R_PAREN {printf("term -> identifier L_PAREN expressions R_PAREN\n");}

vars:	var {printf("vars -> var\n");}
	| var COMMA vars {printf("vars -> var COMMA vars\n");}
	;

var:	identifier {printf("var -> identifier\n");}
	| identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET {printf("var -> identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
	;

identifiers:	identifier {printf("identifiers -> IDENT\n");}
	| identifier COMMA identifiers {printf("identifiers -> IDENT COMMA identifiers\n");}
	;

identifier:	IDENT {printf("identifier -> IDENT %s\n", $1);}
	;

%%

// Main method
int main(int argc, char** argv) {
   yyparse();
   return 0;
}
// Error method
void yyerror(const char* msg) {
  printf("Error: line %d, position: %d: %s \n", numline, numcol, msg);
  exit(1);
}
