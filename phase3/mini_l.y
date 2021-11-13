%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(const char *msg);

extern int numline;
extern int numcol;

extern int yylex();
extern int yyparse();

void yyerror(const char* msg);
FILE * yyin;

%}

%union {
    int num_val;
    char* id_val;
}

%error-verbose 

%start prog_start
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY ENUM OF IF THEN ENDIF ELSE WHILE DO BEGIN_LOOP END_LOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN END

%token <id_val> IDENT
%token <num_val> NUMBER

%right ASSIGN
%left OR
%left AND
%right NOT
%left NEQ EQ GTE GT LTE LT
%left ADD SUB
%left MULT DIV MOD

%%
prog_start: Functions
	;
Functions: 
	| Function
	| Function Functions
	; 
Function: FUNCTION identifier SEMICOLON BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY 
	;
Declarations: declaration SEMICOLON Declarations
	;
declaration: Identifiers COLON ENUM L_PAREN Identifiers R_PAREN
	| Identifiers COLON INTEGER
	| Identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
	;
Identifiers: identifier
	| identifier COMMA Identifiers
	;
identifier: IDENT
Statements: statement SEMICOLON Statements
	|   statement SEMICOLON
	;
statement: Var ASSIGN Expression
	| IF Bool_Expr THEN Statements ENDIF
	| IF Bool_Expr THEN Statements ELSE Statements ENDIF
	| WHILE Bool_Expr BEGIN_LOOP Statements END_LOOP
	| DO BEGIN_LOOP Statements END_LOOP WHILE Bool_Expr
	| READ Vars
	| WRITE Vars
	| CONTINUE
	| RETURN Expression 
	;
Vars: Var 
	| Var COMMA Vars
	;
Var: identifier
	| identifier L_SQUARE_BRACKET Expression R_SQUARE_BRACKET
	;
Bool_Expr: Relation_And_Expr OR Bool_Expr
	| Relation_And_Expr
	;
Relation_And_Expr: Relation_Expr AND Relation_And_Expr
	| Relation_Expr
	;
Relation_Expr: Expression Comp Expression
	| TRUE 
	| FALSE 
	| L_PAREN Bool_Expr R_PAREN 
	| NOT Expression Comp Expression 
	| NOT TRUE 
	| NOT FALSE 
	| NOT L_PAREN Bool_Expr R_PAREN
	;
Comp: EQ 
	| NEQ 
	| LT
	| GT 
	| GTE 
	| LTE
	;
Expressions: 
	| Expression 
	| Expression COMMA Expressions 
	;
Expression: Multiplicative_Expr 
	| Multiplicative_Expr ADD Expression 
	| Multiplicative_Expr SUB Expression
	;
Multiplicative_Expr: Term 
	| Term MULT Multiplicative_Expr
	| Term DIV Multiplicative_Expr
	| Term MOD Multiplicative_Expr
	;
Term: Var 
	| SUB Var 
	| NUMBER 
	| SUB NUMBER
	| L_PAREN Expression R_PAREN 
	| SUB L_PAREN Expression R_PAREN
	| identifier L_PAREN Expressions R_PAREN
	;

%%

int main(int argc, char** argv) {
	if (argc > 1) {
	    yyin = fopen(argv[1], "r");
	    if (yyin == NULL) {
		printf("Syntax: %s filename", argv[0]);
	    }
	}
	yyparse();
	return 0;
}

void yyerror(const char *msg) {
	printf("Error: line %d, position: %d: %s \n", numline, numcol, msg);
	exit(1);
}
