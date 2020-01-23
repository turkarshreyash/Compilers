%{
#include<stdio.h> 
    int vowels = 0;
    int consonants = 0;
%}

%%

[aeiou]{vowels++;}
[^aeiou]{consonants++;}
\n {}





%%