digit	[0-9]
alpha	[a-zA-Z]
hextail	({digit}|{alpha}){1,8}
hex	0[xX]{hextail}
num	{digit}+

%%
.	printf("Invalid input\n"); return;
%%

main(){
	printf("Give me your input\n");
	yylex();
}
