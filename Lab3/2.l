%{
    #include<stdio.h>
    int isKeyword(char* str);
%}
%%
[A-za-z]+[(] {printf("%s",yytext);}
[a-zA-Z]+ {isKeyword(yytext)? printf("%s<KW>\n",yytexstr,"continue")||!strcmp(str,"int")||
    !strcmp(str,"float")||!strcmp(str,"double")||!strcmp(str,"return")||!strcmp(str,"char")||
    !strcmp(str,"long")||!strcmp(str,"sizeof")||!strcmp(str,"case")||!strcmp(str, "typedef")||
    !strcmp(str,"unsigned")){
        return 1;
    }
    else{
        return 0;
    }
}
void main()
{
    yylex();
}
    yylex();
}