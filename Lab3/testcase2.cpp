#include<iostream>

int main(){

		int a = 0;
		do{
			std::cout<<"OUTTER LOOP 1 a = "<<a<<"\n";

            int b = 0;
            do{
                std::cout<<"INNER LOOP 1 b = "<<b<<"\n";
                b++;
            }while(b<2);

			a++;
		}while(a<2);




	}


	char *b = "for (int j = 0; j < 3; j++){";
	// above loop simply prints the value of a
}