%{
    #include<stdio.h>
    #include<string.h>
    int isKeyword(char *str);
%}

%%

[a-zA-Z]+ { isKeyword(yytext)?printf("%s -> Keyword!\n",yytext):printf("%s -> Valid ID!\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("%s -> Valid ID!\n",yytext);}
\n {return;}
. {}
%%

int isKeyword(char* str) 
{ 
    if (!strcmp(str, "for")||!strcmp(str, "if") || !strcmp(str, "else") || 
        !strcmp(str, "while") || !strcmp(str, "do") ||  
        !strcmp(str, "break") ||  
         !strcmp(str, "continue") || !strcmp(str, "int") 
        || !strcmp(str, "double") || !strcmp(str, "float") 
        || !strcmp(str, "return") || !strcmp(str, "char") 
        || !strcmp(str, "case") || !strcmp(str, "char") 
        || !strcmp(str, "sizeof") || !strcmp(str, "long") 
        || !strcmp(str, "short") || !strcmp(str, "typedef") 
        || !strcmp(str, "switch") || !strcmp(str, "unsigned") 
        || !strcmp(str, "void") || !strcmp(str, "static") 
        || !strcmp(str, "struct") || !strcmp(str, "goto")) 
        return (1); 
    return (0); 
} 

int yywrap(){}

int main(){
    yylex();
    return;
}