
%code{
   // All includes go here
   #include<string>
   #include<stack>
   #include<iostream>
   #include<utility>
   #include "phase3.tab.h"
   #include "phase2.tab.h"
   using namespace std;
 
   // All lines below come from sample doc
  void yyerror(const char *msg);
   extern int yylex();
   extern int currLine;
   int myError = 0;
   int otherError = 0;

   char *identToken;	
   int numberToken;
   int productionID = 0;

   char list_of_function_names[100][100];
   int count_names = 0; 


	// Global Variables
    int count = 0;
    //int expressionCount = 0;
    //bool read_bool = false;
    //bool is_array = false;
    //char string[100][20] = {'\0'};
    int index_ident = 0;
    char string_var[100][20] = {'\0'};
    int index_var = 0;
	int index_label = 0;
	int index_end_label = 0;
	//pair<string,string> str_int_pair;

   	stack<string> varsStack;
	stack<string> termStack;
	stack<string> identifierStack;
	stack<string> compStack;
}


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
%type <op_val> statement
%type <op_val> bool_exp
%type <op_val> relation_exp
%type <op_val> relation_and_exp
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
	
	| functions prog_start{}

functions: 
	/* epsilon */
		
	| function functions 
	{
		
	}
		

function: 
	FUNCTION ident SEMICOLON 
	{
	   printf("func %s\n", $2);
	}
	BEGIN_PARAMS declarations END_PARAMS
	{
		
	}
	BEGIN_LOCALS declarations END_LOCALS
	{
		
	}
	BEGIN_BODY statements END_BODY 
	{
		cout << "endfunc" << endl;
	}

ident:
	IDENT
		{$$ = $1;}

declarations: 
	/* epsilon */
	| declaration SEMICOLON declarations
		

declaration: 
	identifiers COLON INTEGER
	{
	 while(!identifierStack.empty()) {
		 cout << ". " << identifierStack.top() << endl;
		 identifierStack.pop();
	 	}
	}
		
	| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
	{
	while(!identifierStack.empty())	{
		cout << ".[] " << identifierStack.top() <<"," << $5 << endl;
		identifierStack.pop();
		}
	}

identifiers: 
	ident
	{
        identifierStack.push($1);
	}
	| ident COMMA identifiers
	{	
		identifierStack.push($1);	  
	}


statement: 
	var ASSIGN expression
{
  char *dest = $1;
  char *src  = $3;
  printf("= %s, %s\n", dest, src);
}

	| IF bool_exp {cout << "! " << $2 << ", " << $2 << endl; cout << "?:= " << "label" << index_label << ", " << $2 << endl;} THEN statements { cout << ":= end"<< index_end_label << endl; }
	 ELSE {cout << ": label" << index_label++ << endl;} statements ENDIF {cout << ": end" << index_end_label++ << endl;}
	
	| IF bool_exp {cout <<"! " << $2 << ", " << $2 << endl; cout << "?:= " << "label" << index_label << ", " << $2 << endl;} THEN statements ENDIF
		{ cout << ": label" << index_label++ << endl;}
	
	| WHILE {cout << ": label" << index_label << endl;} relation_exp 
	{
		// push stack
		//cout << ": label" << index_label << endl;
		cout << "?:= loop_body, " << $3 << endl;
		cout << ":= loop_end" << index_end_label << endl;
		cout << ": loop_body" << endl;
	}
        BEGINLOOP statements
	{
    // loop body.
	} 
	ENDLOOP
	{
   		// end of the loop
		cout << ":= label" << index_label << endl;
   		cout << ": loop_end" << index_end_label << endl;
		// pop stack
	}
	| DO BEGINLOOP statements ENDLOOP WHILE bool_exp
		{
			
		}
	| READ IDENT
		{
			printf(".< %s\n", $2);
		}
	| WRITE IDENT
		{
			printf(".> %s\n", $2);
		}
	| CONTINUE
		{
			
		}
	| RETURN expression
		{
			
		};


	
statements: 
	statement SEMICOLON/* epsilon */
		
	| statement SEMICOLON statements
		

expression: 
	multiplicative_expression
		{
			//std::cout<< "abcde"<<endl;
			$$ = $1; 
		}

 | multiplicative_expression ADD expression
	{
		char *src1 = $1;
		char *src2 = $3;
		char buffer[10];
		string *dest = new string; 
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << "+ " << *dest << ", " << *src1 << ", " << *src2 << endl;
		$$ = (char*)dest->c_str();
	}
	| multiplicative_expression SUB expression
	{
		char *src1 = $1;
		char *src2 = $3;
		char buffer[10];
		string *dest = new string; 
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << dest << endl;
		cout << "- " << dest << ", " << src1 << ", " << src2 << endl;
		$$ = (char*)dest->c_str();
	}

multiplicative_expression: 
	term
		{ 
			//cout<<"term: "<< $1 << endl; 
			$$ = $1;
		}	

	| term MULT multiplicative_expression
		{ 
		char *src1 = $1;
		char *src2 = $3;
		char buffer[10];
		string *dest = new string; 
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << "* " << *dest << ", " << src1 << ", " << src2 << endl;
		$$ = (char*)dest->c_str();
		}
	| term DIV multiplicative_expression
		{
		char *src1 = $1;
		char *src2 = $3;
		char buffer[10];
		string *dest = new string; 
		//*dest = "temp" + to_string(count++);
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << "/ " << *dest << ", " << src1 << ", " << src2 << endl;
		$$ = (char*)dest->c_str();
		}
	| term MOD multiplicative_expression
		{
		char *src1 = $1;
		char *src2 = $3;
		//char *dest = new char[10];
		//dest = "temp";
		char buffer[10];
		string *dest = new string; 
		//*dest = "temp" + to_string(count++);
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << "%" << *dest << ", " << src1 << ", " << src2 << endl;
		$$ = (char*)dest->c_str();
		}

term: 
	var
		{   
			//cout<<"var: " << $1 << endl;
			$$ = $1;

		}
	| NUMBER
		{
			//cout<<"Number: " << $1 << endl;
			$$ = $1;
		}
	| L_PAREN expression R_PAREN
	{
		$$ = $2;
	}		
	| ident {} L_PAREN expressions R_PAREN 
	{  
		char buffer[10]; // Create buffer
		string *dest = new string;
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout<< "call" << (char*)dest->c_str();
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

	}
		

bool_exp:
	relation_and_exp
	{
		$$ = $1;
	}
		
	| relation_and_exp OR bool_exp
		

relation_and_exp:
	relation_exp 
	{
		$$ = $1;
	}
		
	| relation_exp AND relation_and_exp
	{}

relation_exp:
	expression comp expression 
	{
		char *src1 = $1;
		char *src2 = $3;
		//char *sign = $2;
		char buffer[10];
		string *dest = new string; 
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << compStack.top();
		compStack.pop(); 
		cout << " " << *dest << ", " << src1 << ", " << src2 << endl; // == dest, src1, src2
		$$ = (char*)dest->c_str();
	}
		
	| NOT expression comp expression
		
	| TRUE
		
	| NOT TRUE
		
	| FALSE
		
	| NOT FALSE
		
	| L_PAREN bool_exp R_PAREN
		
	| NOT L_PAREN bool_exp R_PAREN


comp:
	EQ 
	{
		//$$=$1;
		compStack.push("==");
	}
		
	| NEQ
		{
			compStack.push("!=");
		}
	| LT
		{
			compStack.push("<");
		}
	| GT 
		{
			compStack.push(">");
		}
		
	| LTE
		{
			compStack.push("<=");
		}
		
	| GTE
		{
			compStack.push(">=");
		}
		

var: 
	ident 
	{
			//cout << "ident: " << $1 << endl;
			$$ = $1;
	}
	| ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET
	{ 
		char *src1 = $1;
		char *src2 = $3;
		char buffer[10];
		string *dest = new string; 
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << "=[]" << *dest << ", " << src1 << ", " << src2 << endl;
	}
		
vars:
	var
	{
		/*
		strcpy(string_var[index_var], $1)
		varsStack.push($1);
		index_var += 1;
		*/
	}	
	| var COMMA vars
	{
		/*
		strcpy(string_var[index_var], $1);
		index_var += 1;
		*/
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
