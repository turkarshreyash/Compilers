%{
    int pos_num = 0;
    int neg_num = 0;
    int pos_frac = 0;
    int neg_frac = 0;
%}

%%
[-][0-9]*[.][0-9]+ {neg_frac++;}
[+]?[0-9]*[.][0-9]+ {pos_frac++;}
[-][0-9]+ {neg_num++;}
[+]?[0-9]+ {pos_num++;}
\n {return;}
%%


int yywrap(){}
int main(){
    yylex();
    printf("Positive Numbers : %d\n Negative Numbers : %d\n",pos_num,neg_num);
    printf("Positive Fractions : %d\n Negative Fractions : %d\n",pos_frac,neg_frac);
    return;
}










