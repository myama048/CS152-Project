%{
    #include "y.tab.h"
    int curr_line = 1; int curr_pos = 1;
%}

DIGIT        [0-9]
CHAR         [a-zA-Z]
IDENT        [a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9] 
LETTER_START [_0-9][[a-zA-Z]|[0-9]|[_]]*
UNDERSCORE   [a-zA-Z][_a-zA-Z0-9]*[_]

%%
function    {curr_pos += yyleng; return FUNCTION;}
beginparams {curr_pos += yyleng; return BEGIN_PARAMS;}
endparams   {curr_pos += yyleng; return END_PARAMS;}
beginlocals {curr_pos += yyleng; return BEGIN_LOCALS;}
endlocals   {curr_pos += yyleng; return END_LOCALS;}
beginbody   {curr_pos += yyleng; return BEGIN_BODY;}
endbody     {curr_pos += yyleng; return END_BODY;}
integer     {curr_pos += yyleng; return INTEGER;}
array       {curr_pos += yyleng; return ARRAY;}
enum        {curr_pos += yyleng; return ENUM;}
of          {curr_pos += yyleng; return OF;}
if          {curr_pos += yyleng; return IF;}
then        {curr_pos += yyleng; return THEN;}
endif       {curr_pos += yyleng; return ENDIF;}
else        {curr_pos += yyleng; return ELSE;}
while       {curr_pos += yyleng; return WHILE;}
do          {curr_pos += yyleng; return DO;}
beginloop   {curr_pos += yyleng; return BEGINLOOP;}
endloop     {curr_pos += yyleng; return ENDLOOP;}
continue    {curr_pos += yyleng; return CONTINUE;}
read        {curr_pos += yyleng; return READ;}
write       {curr_pos += yyleng; return WRITE;}
and         {curr_pos += yyleng; return AND;}
or          {curr_pos += yyleng; return OR;}
not         {curr_pos += yyleng; return NOT;}
true        {curr_pos += yyleng; return TRUE;}
false       {curr_pos += yyleng; return FALSE;}
return      {curr_pos += yyleng; return RETURN;}

"-"         {curr_pos += yyleng; return SUB;}
"+"         {curr_pos += yyleng; return ADD;}
"*"         {curr_pos += yyleng; return MULT;}
"/"         {curr_pos += yyleng; return DIV;}
"%"         {curr_pos += yyleng; return MOD;}

"=="        {curr_pos += yyleng; return EQ;}
"<>"        {curr_pos += yyleng; return NEQ;}
"<"         {curr_pos += yyleng; return LT;}
">"         {curr_pos += yyleng; return GT;}
"<="        {curr_pos += yyleng; return LTE;}
">="        {curr_pos += yyleng; return GTE;}

(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-])?([0-9]+)?) {curr_pos += yyleng; yylval.num_val = atoi(yytext); return NUMBER;}
{IDENT}     {curr_pos += yyleng; yylval.id_val = strdup(yytext); return IDENT;}
{CHAR}      {curr_pos += yyleng; yylval.id_val = strdup(yytext); return IDENT;}
"##".*      {curr_line++; curr_pos = 1;}

";"         {curr_pos += yyleng; return SEMICOLON;}
":"         {curr_pos += yyleng; return COLON;}
","         {curr_pos += yyleng; return COMMA;}
"("         {curr_pos += yyleng; return L_PAREN;}
")"         {curr_pos += yyleng; return R_PAREN;}
"["         {curr_pos += yyleng; return L_SQUARE_BRACKET;}
"]"         {curr_pos += yyleng; return R_SQUARE_BRACKET;}
":="        {curr_pos += yyleng; return ASSIGN;}

[ \t]+      {curr_pos += yyleng;}
"\n"        {curr_line++; curr_pos = 1;}

{UNDERSCORE} {printf("Error at line %d, column %d: identifier \"%s\" cannot end with underscore \n", curr_line, curr_pos, yytext);exit(1);}

{LETTER_START} {printf("Error at line %d, column %d: identifer \"%s\" must begin with a letter\n", curr_line, curr_pos, yytext); exit(1);} 

. {printf("Error at line %d, column %d: Unrecognized symbol \"%s\"\n", curr_line, curr_pos, yytext); exit(1);}

%%
