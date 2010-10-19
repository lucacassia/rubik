#include<iostream>
#include<stdlib.h>

class cube{

	typedef struct ltc{
		int x,y,z,parity;
	}ltc;

	ltc c[3][3][3];

	void shift(ltc*a,ltc*b,ltc*c,ltc*d){
		ltc buffer=*a;
		*a=*b;
		*b=*c;
		*c=*d;
		*d=buffer;
	}

    public:

	cube(){
		for(int k=0;k<3;k++)
			for(int j=0;j<3;j++)
				for(int i=0;i<3;i++){
					c[i][j][k].x=i;
					c[i][j][k].y=j;
					c[i][j][k].z=k;
					c[i][j][k].parity=0;
				}
	}

	void U(){

		shift(&c[1][0][0],&c[0][1][0],&c[1][2][0],&c[2][1][0]);

		if(c[1][0][0].z==1)	c[1][0][0].parity=!c[1][0][0].parity;
		if(c[0][1][0].z==1)	c[0][1][0].parity=!c[0][1][0].parity;
		if(c[1][2][0].z==1)	c[1][2][0].parity=!c[1][2][0].parity;
		if(c[2][1][0].z==1)	c[2][1][0].parity=!c[2][1][0].parity;

		shift(&c[0][0][0],&c[0][2][0],&c[2][2][0],&c[2][0][0]);

		c[1][1][0].parity=(c[1][1][0].parity+1)%4;
	}

	void F(){

		shift(&c[1][0][2],&c[0][0][1],&c[1][0][0],&c[2][0][1]);

		if(c[1][0][2].y==1)	c[1][0][2].parity=!c[1][0][2].parity;
		if(c[0][0][1].y==1)	c[0][0][1].parity=!c[0][0][1].parity;
		if(c[1][0][1].y==1)	c[1][0][1].parity=!c[1][0][1].parity;
		if(c[2][0][1].y==1)	c[2][0][1].parity=!c[2][0][1].parity;

		shift(&c[0][0][2],&c[0][0][0],&c[2][0][0],&c[2][0][2]);

		c[1][0][1].parity=(c[1][0][1].parity+1)%4;
	}

	void L(){

		shift(&c[0][1][2],&c[0][2][1],&c[0][1][0],&c[0][0][1]);
	
		if(c[0][1][2].x==1)	c[0][1][2].parity=!c[0][1][2].parity;
		if(c[0][2][1].x==1)	c[0][2][1].parity=!c[0][2][1].parity;
		if(c[0][1][0].x==1)	c[0][1][0].parity=!c[0][1][0].parity;
		if(c[0][0][1].x==1)	c[0][0][1].parity=!c[0][0][1].parity;

		shift(&c[0][2][2],&c[0][2][0],&c[0][0][0],&c[0][0][2]);

		c[0][1][1].parity=(c[0][1][1].parity+1)%4;
	}

	void d(){

		shift(&c[1][0][2],&c[0][1][2],&c[1][2][2],&c[2][1][2]);

		if(c[1][0][2].z==1)	c[1][0][2].parity=!c[1][0][2].parity;
		if(c[0][1][2].z==1)	c[0][1][2].parity=!c[0][1][2].parity;
		if(c[1][2][2].z==1)	c[1][2][2].parity=!c[1][2][2].parity;
		if(c[2][1][2].z==1)	c[2][1][2].parity=!c[2][1][2].parity;

		shift(&c[0][0][2],&c[0][2][2],&c[2][2][2],&c[2][0][2]);

		c[1][1][2].parity=(c[1][1][2].parity-1)%4;
	}

	void b(){

		shift(&c[1][2][2],&c[0][2][1],&c[1][2][0],&c[2][2][1]);

		if(c[1][2][2].y==1)	c[1][2][2].parity=!c[1][2][2].parity;
		if(c[0][2][1].y==1)	c[0][2][1].parity=!c[0][2][1].parity;
		if(c[1][2][1].y==1)	c[1][2][1].parity=!c[1][2][1].parity;
		if(c[2][2][1].y==1)	c[2][2][1].parity=!c[2][2][1].parity;

		shift(&c[0][2][2],&c[0][2][0],&c[2][2][0],&c[2][2][2]);

		c[1][2][1].parity=(c[1][2][1].parity-1)%4;
	}

	void r(){

		shift(&c[2][1][2],&c[2][2][1],&c[2][1][0],&c[2][0][1]);

		if(c[2][1][2].x==1)	c[2][1][2].parity=!c[2][1][2].parity;
		if(c[2][2][1].x==1)	c[2][2][1].parity=!c[2][2][1].parity;
		if(c[2][1][0].x==1)	c[2][1][0].parity=!c[2][1][0].parity;
		if(c[2][0][1].x==1)	c[2][0][1].parity=!c[2][0][1].parity;

		shift(&c[2][2][2],&c[2][2][0],&c[2][0][0],&c[2][0][2]);

		c[2][1][1].parity=(c[2][1][1].parity-1)%4;
	}

	void u(){U();U();U();}	void U2(){U();U();}
	void f(){F();F();F();}	void F2(){F();F();}
	void R(){r();r();r();}	void R2(){r();r();}
	void D(){d();d();d();}	void D2(){d();d();}
	void B(){b();b();b();}	void B2(){b();b();}
	void l(){L();L();L();}	void L2(){L();L();}

	void out(){
		for(int k=0;k<3;k++){
			for(int j=2;j>=0;j--){
				std::cout<<"\n\t";
				for(int i=0;i<3;i++)
					std::cout<<" "<<c[i][j][k].x<<c[i][j][k].y<<c[i][j][k].z<<":"<<c[i][j][k].parity<<":";
			}
			std::cout<<"\n";
		}
		std::cout<<"\n";
	}
};

int main(){
	cube cubo;
	cubo.out();
	cubo.r();cubo.L();cubo.b();cubo.r();cubo.L();cubo.d();cubo.r();cubo.L();cubo.F2();
	cubo.R();cubo.l();cubo.d();cubo.R();cubo.l();cubo.b();cubo.R();cubo.l();cubo.U2();
	cubo.out();
	return 0;
}
