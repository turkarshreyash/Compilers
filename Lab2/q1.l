%{
    int vowels = 0;
    int consonants_vowels = 0;
%}

%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {consonants_vowels++;}
\n {return;}
%%

int yywrap(){}
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    yylex();
    printf("Vowels : %d\n Consonants : %d",vowels,max(consonants_vowels-vowels,0));
    return;
}