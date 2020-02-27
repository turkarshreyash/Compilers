#include<iostream>

int main(){
	
	for(int a = 0; a < 5; a++){

		std::cout<<"OUTTER LOOP a = "<<a<<"\n";
		int b;
		for(b = 0; b < 2;b++){
			std::cout<<"INNER LOOP 1 b = "<<b<<"\n";
		}

		int c = 0;
		for(;c<3;c++){
			std::cout<<"INNER LOOP 2 c = "<<c<<"\n";
		}
		int d = 0;
		for(;;d++){
			std::cout<<"INNER LOOP 3 d = "<<d<<"\n";
			if(d<4){
				break;
			}
		}
		int e = 0;
		for(;;){
			std::cout<<"INNER LOOP 4 e = "<<e<<"\n";
			if(e<4){
				break;
			}
			e++;
		}

		int f = 0;
		do{
			std::cout<<"INNER LOOP 5 f = "<<f<<"\n";
			f++;
		}while(f<2);




	}


	char *b = "for (int j = 0; j < 3; j++){";
	// above loop simply prints the value of a
}