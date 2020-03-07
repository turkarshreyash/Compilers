#include<iostream>

/*Marco Name: DISPLAY
Parameters (1) : A
Expansion: std::cout<<(A)<<std::endl*/

/*Marco Name: INPUT
Parameters (1) : A
Expansion: std::cin>>A*/

/*Marco Name: ADD
Parameters (2) : A B
Expansion: A+B*/

/*Marco Name: ADDTHREE
Parameters (3) : AA BB CC
Expansion: AA+BB+CC*/

/*Marco Name: PI
Expansion: 3.14*/

/*Marco Name: f
Parameters (1) : x
Expansion: x*x*/


/*Marco Name: integer
Expansion: int*/


void fun(int a){
    std::cout<<a<<std::endl;
}

int main(){
    std::cout<<(5+4)<<std::endl;
    int i;
    std::cin>>i;
    int j = 4+5+6+i;
}