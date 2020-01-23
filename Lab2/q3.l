%{
#include<stdio.h>
%}


%%
\n {return;}
[^a-zA-Z] {printf("%s",yytext);}
[a-zA-Z] {}
%%

int yywrap(){}
int main(){
    yylex();
    return;
}