digit		[0-9]
nat		{digit}+
signedNat	(+|-)?{nat}
signedNatural   [+-]?[0-9]+({whitespace}?)
alpha		[a-fA-F]
letter		[a-zA-Z]
hextail		({digit}|{alpha}){1,8}
hex		0[xX]{hextail}
ident		{letter}({letter|digit|_}*{letter|digit})
identity        [a-zA-Z]([a-zA-Z|0-9|_]*[a-zA-Z|0-9])?
newline		"\n"
blank		" "
tab		"	"
comment		"##[^{newline}]*"
comment2	##.*
whitespace	({newline}|{blank}|{tab}|{comment})+
error1		[+-]?[0-9]+{letter}		
error2          [a-zA-Z]([a-zA-Z|0-9|_]*[_])
%{
	#include "y.tab.h"
	int numline = 1;
        int numcol = 1;
%}

%%
{error1}	printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", numline, numcol, yytext); return -1;
{error2}	printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", numline, numcol, yytext); return -1;
{newline}	numline++; numcol=1;
{blank}		numcol++;
{comment2} 	numcol += yyleng;
{tab}		numcol += yyleng;
"function"	printf("FUNCTION\n"); numcol += yyleng; return FUNCTION;
"beginparams"	printf("BEGIN_PARAMS\n"); numcol += yyleng; return BEGIN_PARAMS;
"endparams"	printf("END_PARAMS\n"); numcol += yyleng; return END_PARAMS;
"beginlocals"	printf("BEGIN_LOCALS\n"); numcol += yyleng; return BEGIN_LOCALS;
"endlocals"	printf("END_LOCALS\n"); numcol += yyleng; return END_LOCALS;
"beginbody"	printf("BEGIN_BODY\n"); numcol += yyleng; return BEGIN_BODY;
"endbody"	printf("END_BODY\n"); numcol += yyleng; return END_BODY;
"integer"	printf("INTEGER\n"); numcol += yyleng; return INTEGER;
"array"		printf("ARRAY\n"); numcol += yyleng; return ARRAY;
"of"		printf("OF\n"); numcol += yyleng; return OF;
"if"		printf("IF\n"); numcol += yyleng; return IF;
"then"		printf("THEN\n"); numcol += yyleng; return THEN;
"endif"		printf("ENDIF\n"); numcol += yyleng; return ENDIF;
"else"		printf("ELSE\n"); numcol += yyleng; return ELSE;
"while"		printf("WHILE\n"); numcol += yyleng; return WHILE;
"do"		printf("DO\n"); numcol += yyleng; return DO;
"beginloop"	printf("BEGINLOOP\n"); numcol += yyleng; return BEGIN_LOOP;
"endloop"	printf("ENDLOOP\n"); numcol += yyleng; return END_LOOP;
"continue"	printf("CONTINUE\n"); numcol += yyleng; return CONTINUE;
"read"		printf("READ\n"); numcol += yyleng; return READ;
"write"		printf("WRITE\n"); numcol += yyleng; return WRITE;
"and"		printf("AND\n"); numcol += yyleng; return AND;
"or"		printf("OR\n"); numcol += yyleng; return OR;
"not"		printf("NOT\n"); numcol += yyleng; return NOT;
"true"		printf("TRUE\n"); numcol += yyleng; return TRUE;
"false"		printf("FALSE\n"); numcol += yyleng; return FALSE;
"return"	printf("RETURN\n"); numcol += yyleng; return RETURN;
"-"		printf("SUB\n"); numcol += yyleng; return SUB;
"+"		printf("ADD\n"); numcol += yyleng; return ADD;
"*"		printf("MULT\n"); numcol += yyleng; return MULT;
"/"		printf("DIV\n"); numcol += yyleng; return DIV;
"%"		printf("MOD\n"); numcol += yyleng; return MOD;
"=="		printf("EQ\n"); numcol += yyleng; return EQ;
"<>"		printf("NEQ\n"); numcol += yyleng; return NEQ;
"<"		printf("LT\n"); numcol += yyleng; return LT;
">"		printf("GT\n"); numcol += yyleng; return GT;
"<="		printf("LTE\n"); numcol += yyleng; return LTE;
">="		printf("GTE\n"); numcol += yyleng; return GTE;
";"		printf("SEMICOLON\n"); numcol += yyleng; return SEMICOLON;
":"		printf("COLON\n"); numcol += yyleng; return COLON;
","		printf("COMMA\n"); numcol += yyleng; return COMMA;
"("		printf("L_PAREN\n"); numcol += yyleng; return L_PAREN;
")"		printf("R_PAREN\n"); numcol += yyleng; return R_PAREN;
"["		printf("L_SQUARE_BRACKET\n"); numcol += yyleng; return L_SQUARE_BRACKET;
"]"		printf("R_SQUARE_BRACKET\n"); numcol += yyleng; return R_SQUARE_BRACKET;
":="		printf("ASSIGN\n"); numcol += yyleng; return ASSIGN;
{digit}+	printf("NUMBER %s\n", yytext); numcol += yyleng; return NUMBER;
{identity}      printf("IDENT %s\n", yytext); numcol += yyleng; yylval.id_val=yytext; return IDENT;
.		printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", numline, numcol, yytext); return -1;
%%

/*int main(){
	//printf("Give me your input\n");
	int numline = 1;
	yylex();
	return 0;
}*/
