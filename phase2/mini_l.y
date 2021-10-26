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
FILE *yyin;
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
%token SEMICOLON FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY ENUM OF IF THEN ENDIF ELSE WHILE DO BEGIN_LOOP END_LOOP CONTINUE READ WRITE TRUE FALSE RETURN COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET END FOR
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
prog_start: 	Functions {printf("prog_start -> Functions\n");}
	;
Functions:  {printf("functions -> epsilon\n");}
	| Function Functions {printf("Functions -> Function Functions\n");}
	; 
Function: FUNCTION identifier SEMICOLON BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY {printf("Function -> FUNCTION identifier SEMICOLON BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY \n");}
	;
Declarations: declaration SEMICOLON Declarations  {printf("Declarations -> declaration SEMICOLON Declarations \n");}
	| {printf("Declarations -> epsilon \n");}
	;
declaration: Identifiers COLON ENUM L_PAREN Identifiers R_PAREN {printf("declaration ->  Identifiers COLON ENUM L_PAREN Identifiers R_PAREN \n");}
	| Identifiers COLON INTEGER {printf("declaration -> Identifiers COLON INTEGER\n");}
	| Identifiers COLON ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER {printf("declaration -> Identifiers COLON ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER\n");}
	;
Identifiers: identifier {printf("Identifiers -> identifier \n");} 
	| identifier COMMA Identifiers {printf("Identifiers -> identifier COMMA Identifiers \n");}
	;
identifier: IDENT {printf("identifier -> IDENT %s\n", $1);}
Statements: statement SEMICOLON Statements {printf("Statements -> statement SEMICOLON Statements \n");}  
	| {printf("Statements -> epsilon \n");}
	;
statement: Var ASSIGN Expression {printf("statement -> Var ASSIGN Expression \n");}
	| IF Bool_Exprs THEN Statements ENDIF {printf("statement -> IF Bool_Expr THEN Statements ENDIF \n");}
	| IF Bool_Exprs THEN Statements ELSE Statements ENDIF {printf("statement -> IF Bool_Expr THEN Statements ELSE Statements ENDIF\n");}
	| WHILE Bool_Exprs BEGINLOOP Statements ENDLOOP {printf("statement -> WHILE Bool_Expr BEGINLOOP Statements ENDLOOP\n");}
	| DO BEGINLOOP Statements ENDLOOP WHILE Bool_Exprs {printf("statement -> DO BEGINLOOP Statements ENDLOOP WHILE Bool_Expr\n");}
	| READ Vars {printf("statement -> READ Vars\n");}
	| WRITE Vars {printf("statement -> WRITE Vars\n");}
	| CONTINUE {printf("statement -> CONTINUE\n");}
	| RETURN Expression {printf("statement -> RETURN Expression\n");}
	;
Vars: Var {printf("Vars -> Var\n");}
	| Var COMMA Vars {printf("Vars -> Var COMMA Vars");}
	;
Var: identifier {printf("Var -> identifier\n");}
	| identifier L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {printf("Var -> identifier L_SQUARE_BRACKET Expression R_SQUARE_BRACKET \n");}
	;
Bool_Exprs: Bool_Expr {printf("Bool_Exprs -> Bool_Expr\n");}
	| Bool_Expr OR Bool_Exprs {printf("Bool_Exprs -> Bool_Expr OR Bool_Exprs \n");}
	;
Bool_Expr: Relation_And_Exprs {printf("Bool_Expr -> Relation_And_Expr \n");}
	;
Relation_And_Exprs: Relation_And_Expr {printf("Relation_And_Exprs -> Relation_And_Expr\n");}
	| Relation_And_Expr AND Relation_And_Exprs {printf("Relation_And_Exprs -> Relation_And_Expr AND Relation-And-Exprs\n");}
	;
Relation_And_Expr: Relation_Expr {printf("Relation_And_Expr -> Relation_Expr\n");}
	;
Relation_Expr: Expression Comp Expression {printf("Relation_Expr -> Expression Comp Expression \n");}
	| TRUE {printf("Relation_Expr -> TRUE\n");}
	| FALSE {printf("Relation -> FALSE \n");}
	| L_PAREN Bool_Exprs R_PAREN {printf("Relation_Expr -> L_PAREN Bool_Expr R_PAREN\n");}
	| NOT Expression Comp Expression {printf("Relation_Expr -> NOT Expression Comp Expression \n");}
	| NOT TRUE {printf("Relation_Expr -> NOT TRUE\n");}
	| NOT FALSE {printf("Relation -> NOT FALSE \n");}
	| NOT L_PAREN Bool_Exprs R_PAREN {printf("Relation_Expr -> NOT L_PAREN Bool_Expr R_PAREN\n");}
	;
Comp: EQ {printf("Comp -> EQ\n");}
	| NEQ {printf("Comp -> NEQ\n");}
	| LT {printf("Comp -> LT\n");}
	| GT {printf("Comp -> GT\n");}
	| GTE {printf("Comp -> GTE\n");}
	| LTE {printf("Comp -> LTE\n");}
	;
Expressions: {printf("Expressions -> epsilon\n");}
	| Expression {printf("Expressions -> Expression\n");}
	| Expression COMMA Expressions {printf("Expressions -> Expression COMMA Expression\n");}
	;
Expression: Multiplicative_Expr {printf("Expression -> Multiplicative_Expr\n");}
	| Multiplicative_Expr ADD Expression {printf("Expression -> Multiplicative_Expr ADD Expression\n");}
	| Multiplicative_Expr SUB Expression {printf("Expression -> Multiplicative_Expr SUB Expression\n");}
	;
Multiplicative_Expr: Term {printf("Multiplicative_Expr -> Term\n");}
	| Term MULT Multiplicative_Expr {printf("Multiplicative_Expr -> Term MULT Multiplicative_Expr\n");}
	| Term DIV Multiplicative_Expr {printf("Multiplicative_Expr -> Term DIV Multiplicative_Expr\n");}
	| Term MOD Multiplicative_Expr {printf("Multiplicative_Expr -> Term MOD Multiplicative_Expr\n");}
	;
Term: Var {printf("Term -> Var\n");}
	| SUB Var {printf("Term -> SUB Var\n");}
	| number {printf("Term -> number \n");}
	| SUB number {printf("Term -> SUB number\n");}
	| L_PAREN Expression R_PAREN {printf("Term -> L_PAREN Expression R_PAREN\n");}
	| SUB L_PAREN Expression R_PAREN {printf("Term -> SUB L_PAREN Expression R_PAREN\n");}
	| identifier L_PAREN Expressions R_PAREN {printf("Term -> identifier L_PAREN Expressions R_PAREN\n");}
	;
number: NUMBER {printf("NUMBER %d \n", $1);}



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
