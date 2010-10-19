#include"cube.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	srand(time(NULL));
	char *solution="WWWWWWWWRRRRRRRRBBBBBBBBGGGGGGGGOOOOOOOOYYYYYYYY";
	int n; cout<<"How many moves? "; cin>>n;
	char *path="cube.pattern";
	bool stop=false;
	while(!stop){
		cube rubik(path);
		for(int i=0;i<n;i++){
			int move=rand()%18;
			switch(move){
				case  0:{rubik.u();cout<<"u ";break;}
				case  1:{rubik.f();cout<<"f ";break;}
				case  2:{rubik.r();cout<<"r ";break;}
				case  3:{rubik.l();cout<<"l ";break;}
				case  4:{rubik.b();cout<<"b ";break;}
				case  5:{rubik.d();cout<<"d ";break;}
				case  6:{rubik.U();cout<<"U ";break;}
				case  7:{rubik.F();cout<<"F ";break;}
				case  8:{rubik.R();cout<<"R ";break;}
				case  9:{rubik.L();cout<<"L ";break;}
				case 10:{rubik.B();cout<<"B ";break;}
				case 11:{rubik.D();cout<<"D ";break;}
				case 12:{rubik.U2();cout<<"U2 ";break;}
				case 13:{rubik.F2();cout<<"F2 ";break;}
				case 14:{rubik.R2();cout<<"R2 ";break;}
				case 15:{rubik.L2();cout<<"L2 ";break;}
				case 16:{rubik.B2();cout<<"B2 ";break;}
				case 17:{rubik.D2();cout<<"D2 ";break;}
			}
		}
		cout<<endl;
		if(rubik.dist(solution)==0){
			stop=true;
			cout<<"That's it!\n";
		}
	}
	return 0;
}
