%{
    #include<stdio.h>
    #include<regex.h>
    #include"linkedlist.h"
    #include"stack.h"
   
    
    node *map_head = NULL;
    stack_node *stack_head = NULL;
    int stack=0;
%}

%%

#define.* { map_head = insert(map_head,yytext);}
[a-zA-Z0-9_]+ {stack_head = push_stack(stack_head,map_head,yytext);}
["]([^"]*\n?)*["] { if(stack_head == NULL){printf("%s",yytext);}else{stack_head=add_args(stack_head,yytext);}}
[(] {if(stack_head == NULL){printf("%s",yytext);}}
[)] {if(stack_head == NULL){printf("%s",yytext);}else{stack_head = pop_stack(stack_head);}}
[,] {if(stack_head == NULL){printf("%s",yytext);}}
. {printf("%s",yytext);}
\n {printf("%s",yytext);}

%%


int yywrap(){}

int main(int argc, char *argv[]){
    if(argc<3){
        printf("Too few arguments\n");
        exit(0);
    }
    extern FILE *yyin, *yyout;
    yyin=fopen(argv[1],"r"); 
    yyout=fopen(argv[2],"w"); 
    yylex();
}


