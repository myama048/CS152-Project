%{
   // ALl includes go here
   #include<stdio.h>
   #include<stdlib.h>
   #include<stdbool.h>
   #include<string.h>
 
   // Call external files
   void yyerror(const char *msg);
   //extern FILE *yyin;
  // int yylex(void)
   extern int currLine;
   //extern int currPos;

   int myError = 0;
   int otherError = 0;
   
   char *identToken;
   int numberToken;
   int productionID = 0;

   char list_of_function_names[100][100] = {'\0'};
   int count_names = 0;

   // To make external file
    //string outFile;
    //ofstream myFile; 
    //bool param = false;
    //int paramVal;
    //int numLabel;
    //int varNum;

   // Global Variables
    int count = 0;
    int expressionCount = 0;
    bool read_bool = false;
    bool is_array = false;
    char string[1000][200] = {'\0'};
    int index_ident = 0;
    char string_var[100][20] = {'\0'};
    int index_var = 0;

//#define YYDEBUG 1
//yydebug=1;
%}

%union {
  int num_val;
  char *op_val;
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
%token <num_val> NUMBER
%token <op_val> IDENT
%%

prog_start: 
	functions 
	{
		
	}	
	| functions prog_start
functions: 
	/* epsilon */
		
	| function functions
		

function: 
	FUNCTION ident SEMICOLON 
	{
	   printf("func %s\n", $2);
	}
	BEGIN_PARAMS declarations END_PARAMS
	BEGIN_LOCALS declarations END_LOCALS
	BEGIN_BODY statements END_BODY

ident:
	IDENT
		{$$ = $1; }

declarations: 
	/* epsilon */
	| declaration SEMICOLON declarations
		

declaration: 
	identifiers COLON INTEGER
	{
	//char *token = $1;
	 //printf(". %s\n", token);
	int i;
	for(i = 0; i < index_ident; i++){
		printf(". %s\n", string[i]);
	}
	 index_ident = 0;
	}
		
	| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
	{
	//char *token = $1;
	//char *index = $5;
	//print(".[] %s, %s", token, index);
	int i;
	for(i = 0; i < index_ident; i++){
		printf(".[] %s, %s\n", string[i], $5);
	}
	index_ident = 0;
	}	

identifiers: 
	ident
	{
        //strcpy(string_var[index_ident], 'x');
	//printf(string[index_ident], $1);
	index_ident += 1;
	}

	| ident COMMA identifiers
	{	
	//strcpy(string_var[index_ident], 'x');
	//printf(string[index_ident], $1);
	index_ident += 1;		  
	}

statement:
	ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET ASSIGN expression
	{
	char* dest = $1;
	char* idx = $3;
	char* src = $6;
	printf("[]= %s, %s, %s\n", dest, idx, src);
	}

	| ident ASSIGN expression
	{
	char* dest = $1;
	char* src = $3; 
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
	//char *vars = $2;
	//printf(".< %s", vars);
	int i;
	for(i = 0; i < index_var; i++){
		printf(".< %s\n", string_var[i]);
	}	
	}
		
	| WRITE vars
	{
	 //char *vars = $2;
	 //printf(".> %s", vars);
	int i;
	for(i = 0; i < index_var; i++){
		printf(".> %s\n", string_var[i]);
	}
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
	}

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
		
		
	| NUMBER
	{$$ = &($1);}
			
	| L_PAREN expression R_PAREN
	{
	$$ = $2;
	
	}		
	| ident {} L_PAREN expressions R_PAREN 
	{ // 
           char* buffer = malloc(sizeof(char) * 20);
           sprintf("buffer %s%d", "temp", count++);
           $$ = buffer;
	   char* name = $1;
   	   printf("call %s, %s\n", name, buffer); 
	}
		

expressions: 
	/* epsilon */
		
	| comma_sep_expressions
		

comma_sep_expressions: 
	expression 
	{
	  
	  printf("param %s\n", $1);
	}
		
	| expression COMMA comma_sep_expressions 
	{
	 printf("");  
	}
		

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
	{$$ = $1;
	//is_array = false;
	}
			
	| ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET
	{ // a = b[2]
	//printf("ident %s\n", $1);
	//is_array = true;
	char* dst = malloc(sizeof(char) * 20);
	sprintf(dst, "%s%d", "temp", count++);
	$$ = dst;
	char* src = $1;
	char* idx = $3;
	printf("=[] %s, %s, %s", dst, src, idx);
	}
		
vars:
	var
	{
	strcpy(string_var[index_var], $1);
	index_var += 1;
	}	
	| var COMMA vars
	{
	strcpy(string_var[index_var], $1);
	index_var += 1;
	}
		
	

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
