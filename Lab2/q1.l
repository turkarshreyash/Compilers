%{
    int vowels = 0;
    int consonants = 0;
%}

%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {consonants++;}
\n {return;}
%%

int yywrap(){}
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    yylex();
    printf("Vowels : %d\n Consonants : %d",vowels,consonants);
    return;
}