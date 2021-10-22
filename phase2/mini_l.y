%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);


extern int numCount;
extern int parenCount;
extern int opCount;
extern int equalsCount;
%}

%left LEFT_PAREN RIGHT_PAREN
%left PLUS
%left MINUS
%left MULT
%left DIVIDE

%right EQUAL
%token DIGIT

%start expr

%%

expr: LEFT_PAREN expr RIGHT_PAREN expr
    | DIGIT expr
    | PLUS expr
    | MINUS expr
    | MULT expr
    | DIVIDE expr
    | EQUAL expr
    |
 ;

%%

int main() {
  yyin = stdin;

  do {
	printf("Parse.\n");
        yyparse();
   } while(!feof(yyin));
   printf("Parenthesis are balanced!\n");
   printf("Nums: %d\n", numCount);
   printf("Ops: %d\n", opCount);
   printf("Eqs: %d\n", equalsCount);
   printf("Parens: %d\n", parenCount);
   return 0;
}

void yyerror(const char* s) {
  fprintf(stderr, "Parse error: %s. Parenthesis are not balanced!\n", s);
  exit(1);
}
