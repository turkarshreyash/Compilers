#include<iostream>

int main(){ 
	
	{int a = 0;
while(a < 5){

		std::cout<<"OUTTER LOOP a = "<<a<<"\n";
		int b;
		{b = 0;
while(b < 2){
			std::cout<<"INNER LOOP 1 b = "<<b<<"\n";
		b++;
}
}


		int c = 0;
		{
while(c<3){
			std::cout<<"INNER LOOP 2 c = "<<c<<"\n";
		c++;
}
}

		int d = 0;
		{
while(1){
			std::cout<<"INNER LOOP 3 d = "<<d<<"\n";
			if(d<4){ 
				break;
			}

		d++;
}
}

		int e = 0;
		{
while(1){
			std::cout<<"INNER LOOP 4 e = "<<e<<"\n";
			if(e<4){ 
				break;
			}

			e++;
		}
}


		int f = 0;
		while(1){
			std::cout<<"INNER LOOP 5 f = "<<f<<"\n";
			f++;
		if(!(f<2)){
break;
}
}




	a++;
}
}



	char *b = "for (int j = 0; j < 3; j++){";
	// above loop simply prints the value of a
}
