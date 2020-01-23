%{
#include<stdio.h> 
    int state = 0;
%}

%%
[a-zA-Z_] {state++;} 
[0-9] {if(state == 0)
        return -1;}
. {return -1;}
\n {return 1;}
%%


int yywrap(){}
int main(){
    state = yylex(); 
    if(state != -1){
    printf("Valid ID\n");
    }else{
    printf("Invalid ID\n");
    }
    return 0;
}