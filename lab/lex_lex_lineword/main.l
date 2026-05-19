%{
#include<stdio.h>
int lines=1, words=0, chars=0;
FILE *yyin;
%}
%%
\n   {lines++;chars++;}
[\t]+ {chars+=yyleng;}
[^ \n \t]+ {words++;chars+=yyleng;}
.	{chars++;}
%%
int main(){
yyin=fopen("input.txt","r");
if (yyin==NULL) {
printf("Error: Could not open input.txt\n");
return 1;
}
yylex();
printf("Lines:%d\n",lines);
printf("Words:%d\n",words);
printf("Characters:%d\n",chars);
fclose(yyin);
return 0;
}
int yywrap() {
return 1;
}
