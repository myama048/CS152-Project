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
"function"	printf("FUNCTION\n"); numcol += yyleng;
"beginparams"	printf("BEGIN_PARAMS\n"); numcol += yyleng;
"endparams"	printf("END_PARAMS\n"); numcol += yyleng;
"beginlocals"	printf("BEGIN_LOCALS\n"); numcol += yyleng;
"endlocals"	printf("END_LOCALS\n"); numcol += yyleng;
"beginbody"	printf("BEGIN_BODY\n"); numcol += yyleng;
"endbody"	printf("END_BODY\n"); numcol += yyleng;
"integer"	printf("INTEGER\n"); numcol += yyleng;
"array"		printf("ARRAY\n"); numcol += yyleng;
"of"		printf("OF\n"); numcol += yyleng;
"if"		printf("IF\n"); numcol += yyleng;
"then"		printf("THEN\n"); numcol += yyleng;
"endif"		printf("ENDIF\n"); numcol += yyleng;
"else"		printf("ELSE\n"); numcol += yyleng;
"while"		printf("WHILE\n"); numcol += yyleng;
"do"		printf("DO\n"); numcol += yyleng;
"beginloop"	printf("BEGINLOOP\n"); numcol += yyleng;
"endloop"	printf("ENDLOOP\n"); numcol += yyleng;
"continue"	printf("CONTINUE\n"); numcol += yyleng;
"read"		printf("READ\n"); numcol += yyleng;
"write"		printf("WRITE\n"); numcol += yyleng;
"an"		printf("AND\n"); numcol += yyleng;
"or"		printf("OR\n"); numcol += yyleng;
"not"		printf("NOT\n"); numcol += yyleng;
"true"		printf("TRUE\n"); numcol += yyleng;
"false"		printf("FALSE\n"); numcol += yyleng;
"return"	printf("RETURN\n"); numcol += yyleng;
"-"		printf("SUB\n"); numcol += yyleng;
"+"		printf("ADD\n"); numcol += yyleng;
"*"		printf("MULT\n"); numcol += yyleng;
"/"		printf("DIV\n"); numcol += yyleng;
"%"		printf("MOD\n"); numcol += yyleng;
"=="		printf("EQ\n"); numcol += yyleng;
"<>"		printf("NEQ\n"); numcol += yyleng;
"<"		printf("LT\n"); numcol += yyleng;
">"		printf("GT\n"); numcol += yyleng;
"<="		printf("LTE\n"); numcol += yyleng;
">="		printf("GTE\n"); numcol += yyleng;
";"		printf("SEMICOLON\n"); numcol += yyleng;
":"		printf("COLON\n"); numcol += yyleng;
","		printf("COMMA\n"); numcol += yyleng;
"("		printf("L_PAREN\n"); numcol += yyleng;
")"		printf("R_PAREN\n"); numcol += yyleng;
"["		printf("L_SQUARE_BRACKET\n"); numcol += yyleng;
"]"		printf("R_SQUARE_BRACKET\n"); numcol += yyleng;
":="		printf("ASSIGN\n"); numcol += yyleng;
{signedNatural}	printf("NUMBER %s\n", yytext); numcol += yyleng;
{identity}	printf("IDENT %s\n", yytext); numcol += yyleng;
.		printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", numline, numcol, yytext); return -1;
%%

/*int main(){
	//printf("Give me your input\n");
	int numline = 1;
	yylex();
	return 0;
}*/
