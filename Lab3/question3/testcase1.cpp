#include<iostream>

#define DISPLAY(A)  std::cout<<(A)<<std::endl
#define INPUT(A)    std::cin>>A
#define ADD(A,B)  A+B
#define ADDTHREE(AA,BB,CC) AA+BB+CC

#define integer int

void fun(integer a){
    std::cout<<a<<std::endl;
}

int main(){
    DISPLAY(ADD(5,4));
    integer i;
    INPUT(i);
    integer j = ADD(ADDTHREE(4,5,6),i);
}