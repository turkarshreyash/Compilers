%{
#include<stdio.h> 
#include<string.h>

#include"for_to_while.h"

struct node *head = NULL;

%}


%%
for([ ]*\n?)*[(](([^(])*\n?)*[)]([ ]*\n?)*[{] {head = replace_init(yyout, yytext,yyleng,head);}
do([^{]*\n?)*[{] {fprintf(yyout,"while(1){");}
[}]([ ]*\n?)*while([^(]*\n?)*[(]([^)]*\n?)*[)]([ ]*\n?)*[;] {replace(yyout,yytext,yyleng);}
[}] {head=replace_stop(yyout,head);}
[{] {fprintf(yyout,"{ ");head=push(head,0,NULL);}
["]([^"]*\n?)*["] {fprintf(yyout,"%s",yytext);}
.   {fprintf(yyout,"%s",yytext);}
\n  {fprintf(yyout,"\n");}
%%


int yywrap(){}
int main(int argc, char*argv[]) { 
    if(argc<3){
        printf("Too few arguments\n");
        exit(0);
    }
    extern FILE *yyin, *yyout;
    yyin=fopen(argv[1],"r"); 
    yyout=fopen(argv[2],"w");
    printf("Processing. . .\n"); 
    yylex();
    printf("Done!\n");
} 