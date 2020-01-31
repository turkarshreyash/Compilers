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
    extern FILE *yyin;
    yyin = fopen("testfile.txt","r");
    
    yylex();
    return;
}