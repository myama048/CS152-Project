%{
   // ALl includes go here
   #include<stdio.h>
   #include<stdlib.h>
   #include<string.h>
   #include<fstream>
   #include<sstream>
   #include<iterator>
   // Call external files
   int yyerror(const char *msg);
   extern FILE *yyin;
   int yylex(void)
   extern int currLine;
   extern int currPos;

   int myError = 0;
   int otherError = 0;
   
   char *identToken;
   int numberToken;
   int productionID = 0;

   char list_of_function_names[100][100];
   int count_names = 0;

   // To make external file
    string outFile;
    ofstream myFile; 
    bool param = false;
    int paramVal;
    int numLabel;
    int varNum;

  template <typename T>
  string numTostring (T Convert)
 {
   ostringstream ss;
   ss << Convert;
   return ss.str();
 }

  // Define the 

//#define YYDEBUG 1
//yydebug=1;
%}

%union {
  char* id_val;
  int num_val;
}




%define parse.error verbose
%type <op_val> var
%type <op_val> ident
%type <op_val> expression
%type <op_val> multiplicative_expression
%type <op_val> term
%start prog_start
%token BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token FUNCTION RETURN MAIN
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token INTEGER ARRAY OF
%token IF THEN ENDIF ELSE
%token WHILE DO BEGINLOOP ENDLOOP  CONTINUE
%token READ WRITE
%token TRUE FALSE
%left AND OR
%right NOT ASSIGN
%left SUB ADD MULT DIV MOD
%left EQ NEQ LT GT LTE GTE
%token SEMICOLON COLON COMMA L_PAREN R_PAREN
%token <op_val> NUMBER
%token <op_val> IDENT
%%

prog_start: 
	functions
	{};	

functions: 
	/* epsilon */
		
	| function functions
		

function: 
	FUNCTION ident SEMICOLON
	BEGIN_PARAMS declarations END_PARAMS
	BEGIN_LOCALS declarations END_LOCALS
	BEGIN_BODY statements END_BODY

ident:
	IDENT
		{$$ = $1; };

declarations: 
	/* epsilon */
	| declaration SEMICOLON declarations
		

declaration: 
	identifiers COLON INTEGER
	{
	 char *token = $1;
	 printf(". %s\n", token);
	}
		
	| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
	{
	char *token = $1;
	char *index = $5;
	print(".[] %s, %s", token, index);
	};	

identifiers: 
	ident
	| ident COMMA identifiers
	{	
	  
	}

statement: 
	var ASSIGN expression
	{
	char *dest = $1;
	char *src = $3;
 	printf("= %s, %s\n", dest, src);
	}	
	| IF bool_exp THEN statements ENDIF
	{

	}
		
	| IF bool_exp THEN statements ELSE statements ENDIF
		
	| WHILE bool_exp BEGINLOOP statements ENDLOOP
		
	| DO BEGINLOOP statements ENDLOOP WHILE bool_exp
		
	| READ vars
	{
	char *vars = $2;
	printf(".< %s", vars);
	
	}
		
	| WRITE vars
	{
	 char *vars = $2;
	 printf(".> %s", vars);
	}
		
	| CONTINUE
		
	| RETURN expression
		
	
statements: 
	statement SEMICOLON/* epsilon */
		
	| statement SEMICOLON statements
		

expression: 
	multiplicative_expression
		{$$ = $1; }
		
	| multiplicative_expression ADD expression
	{
	char *src1 = $1;
	char *src2 = $3;
	char *dest = "_temp";
	printf("+ %s, %s, %s\n", dest, src1, src2);
	$$ = dest;
	}
		
	| multiplicative_expression SUB expression
	{
	char *src1 = $1;
	char *src2 = $3;
	char *dest = "_temp";
	printf("- %s, %s, %s\n", dest, src1, src2);
	$$ = dest;
	};

multiplicative_expression: 
	term
		{ $$ = $1;}	
	| term MULT multiplicative_expression
		{ 
		char *src1 = $1;
		char *src2 = $3;
		char *dest = "_temp";
		printf("* %s, %s, %s\n", dest, src1, src2);
		$$ = dest;
		}
	| term DIV multiplicative_expression
		{
		char *src1 = $1;
		char *src2 = $3;
		char *dest = "_temp";
		printf("/ %s, %s, %s\n", dest, src1, src2);
		$$ = dest;
		}
	| term MOD multiplicative_expression
		{
		char *src1 = $1;
		char *src2 = $3;
		char *dest = "_temp";
		printf(" / %s, %s, %s\n", dest, src1, src2);
		$$ = dest;
		}

term: 
	var
	
	{$$ = $1;}
		
	| SUB var
	{
	char* var = $2;
	printf("-%s", var);
	}
		
	| NUMBER
	{
	$$ = $1;
	}
		
	| SUB NUMBER
	{
	char* var = $2;

	}
		
	| L_PAREN expression R_PAREN
		
	| SUB L_PAREN expression R_PAREN
		
	| ident L_PAREN expressions R_PAREN
		

expressions: 
	/* epsilon */
		
	| comma_sep_expressions
		

comma_sep_expressions: 
	expression
		
	| expression COMMA comma_sep_expressions
		

bool_exp:
	relation_and_exp
		
	| relation_and_exp OR bool_exp
		

relation_and_exp:
	relation_exp
		
	| relation_exp AND relation_and_exp
		

relation_exp:
	expression comp expression
		
	| NOT expression comp expression
		
	| TRUE
		
	| NOT TRUE
		
	| FALSE
		
	| NOT FALSE
		
	| L_PAREN bool_exp R_PAREN
		
	| NOT L_PAREN bool_exp R_PAREN


comp:
	EQ
		
	| NEQ

	| LT
		
	| GT
		
	| LTE
		
	| GTE
		

var: 
	ident
		
	| ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET
		
vars:
	var
	
	| var COMMA vars
		
	

%%

int main(int argc, char **argv)
{
   yyparse();

   return 0;
}

void yyerror(const char *msg)
{
   if(myError == 0)
   {
      printf("** Line %d: %s\n", currLine, msg);
      otherError = 1;
   }
   else
   {
      if(otherError == 1)
      {
         printf("   (%s)\n", msg);
         otherError = 0;
      }
   }
   myError = 0;
}
