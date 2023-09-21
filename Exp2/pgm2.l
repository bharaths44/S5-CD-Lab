%%
"hello world" printf("Goodbye");
%%

int main()
{
	printf("Enter string :");
	yylex();
}
int yywrap()
{
	return 1;
}
