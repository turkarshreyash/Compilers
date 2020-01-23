%{
    #include<stdio.h>
%}

%%
[a-zA-Z]{3} {printf("%s",yytext);}
[a-zA-Z]{4} {printf("%s",yytext);}
[a-zA-Z]{5} {printf("%s",yytext);}
[a-zA-Z]* {}
\n {return;}
%%

int yywrap(){}

int main(){
    yylex();
}