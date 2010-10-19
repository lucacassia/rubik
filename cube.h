#include<iostream>
#include<fstream>
#include<math.h>

class cube{

	char c[48];

    public:

	cube(char*path){
		std::ifstream inputfile;
		inputfile.open(path);
		if(inputfile.is_open())
			for(int i=0;(i<48)and(!inputfile.eof());i++)
				inputfile >> std::skipws >> c[i];
		else
			std::cout<<"I/O Error: input file missing!\n";
		inputfile.close();
	}
	
	void save(char*path){
		std::ofstream outputfile;
		outputfile.open(path);
		for(int i=0;i<48;i++)
			outputfile << c[i] << " ";
		outputfile.close();
	}
	
	int out(){

		std::cout<<"\n               "<<c[0]<<" "<<c[1]<<" "<<c[2]
		<<"\n               "<<c[7]<<" "<< "W" <<" "<<c[3]
		<<"\n               "<<c[6]<<" "<<c[5]<<" "<<c[4]<<"\n";

		std::cout<<"\n     "<<c[3*8+0]<<" "<<c[3*8+1]<<" "<<c[3*8+2]<<"     "<<c[8+0]<<" "<<c[8+1]<<" "<<c[8+2]<<"     "<<c[2*8+0]<<" "<<c[2*8+1]<<" "<<c[2*8+2]<<"     "<<c[4*8+0]<<" "<<c[4*8+1]<<" "<<c[4*8+2]
		<<"\n     "<<c[3*8+7]<<" "<< "G" <<" "<<c[3*8+3]<<"     "<<c[8+7]<<" "<< "R" <<" "<<c[8+3]<<"     "<<c[2*8+7]<<" "<< "B" <<" "<<c[2*8+3]<<"     "<<c[4*8+7]<<" "<< "O" <<" "<<c[4*8+3]
		<<"\n     "<<c[3*8+6]<<" "<<c[3*8+5]<<" "<<c[3*8+4]<<"     "<<c[8+6]<<" "<<c[8+5]<<" "<<c[8+4]<<"     "<<c[2*8+6]<<" "<<c[2*8+5]<<" "<<c[2*8+4]<<"     "<<c[4*8+6]<<" "<<c[4*8+5]<<" "<<c[4*8+4]<<"\n";

		std::cout<<"\n               "<<c[5*8+0]<<" "<<c[5*8+1]<<" "<<c[5*8+2]
		<<"\n               "<<c[5*8+7]<<" "<< "Y" <<" "<<c[5*8+3]
		<<"\n               "<<c[5*8+6]<<" "<<c[5*8+5]<<" "<<c[5*8+4]<<"\n";

		std::cout<<"\n\n";
		return 0;
	}

	int u(){
		char buffer[3]={c[0],c[1],0};
		for(int i=7;i>1;i--)
			c[(i+2)%8]=c[i];
		c[3]=buffer[1];
		c[2]=buffer[0];

		buffer[0]=c[8+0];	c[8+0]=c[2*8+0];	c[2*8+0]=c[4*8+0];	c[4*8+0]=c[3*8+0];	c[3*8+0]=buffer[0];
		buffer[1]=c[8+1];	c[8+1]=c[2*8+1];	c[2*8+1]=c[4*8+1];	c[4*8+1]=c[3*8+1];	c[3*8+1]=buffer[1];
		buffer[2]=c[8+2];	c[8+2]=c[2*8+2];	c[2*8+2]=c[4*8+2];	c[4*8+2]=c[3*8+2];	c[3*8+2]=buffer[2];
	
		return 0;
	}

	int f(){
		char buffer[3]={c[8+0],c[8+1],0};
		for(int i=7;i>1;i--)
			c[8+(i+2)%8]=c[8+i];
		c[8+3]=buffer[1];
		c[8+2]=buffer[0];

		buffer[0]=c[4];	c[4]=c[3*8+2];	c[3*8+2]=c[5*8+0];	c[5*8+0]=c[2*8+6];	c[2*8+6]=buffer[0];
		buffer[1]=c[5];	c[5]=c[3*8+3];	c[3*8+3]=c[5*8+1];	c[5*8+1]=c[2*8+7];	c[2*8+7]=buffer[1];
		buffer[2]=c[6];	c[6]=c[3*8+4];	c[3*8+4]=c[5*8+2];	c[5*8+2]=c[2*8+0];	c[2*8+0]=buffer[2];
	
		return 0;
	}

	int r(){
		char buffer[3]={c[2*8+0],c[2*8+1],0};
		for(int i=7;i>1;i--)
			c[2*8+(i+2)%8]=c[2*8+i];
		c[2*8+3]=buffer[1];
		c[2*8+2]=buffer[0];

		buffer[0]=c[2];	c[2]=c[8+2];	c[8+2]=c[5*8+2];	c[5*8+2]=c[4*8+6];	c[4*8+6]=buffer[0];
		buffer[1]=c[3];	c[3]=c[8+3];	c[8+3]=c[5*8+3];	c[5*8+3]=c[4*8+7];	c[4*8+7]=buffer[1];
		buffer[2]=c[4];	c[4]=c[8+4];	c[8+4]=c[5*8+4];	c[5*8+4]=c[4*8+0];	c[4*8+0]=buffer[2];
	
		return 0;
	}

	int l(){
		char buffer[3]={c[3*8+0],c[3*8+1],0};
		for(int i=7;i>1;i--)
			c[3*8+(i+2)%8]=c[3*8+i];
		c[3*8+3]=buffer[1];
		c[3*8+2]=buffer[0];

		buffer[0]=c[6];	c[6]=c[4*8+2];	c[4*8+2]=c[5*8+6];	c[5*8+6]=c[8+6];	c[8+6]=buffer[0];
		buffer[1]=c[7];	c[7]=c[4*8+3];	c[4*8+3]=c[5*8+7];	c[5*8+7]=c[8+7];	c[8+7]=buffer[1];
		buffer[2]=c[0];	c[0]=c[4*8+4];	c[4*8+4]=c[5*8+0];	c[5*8+0]=c[8+0];	c[8+0]=buffer[2];
	
		return 0;
	}


	int b(){
		char buffer[3]={c[4*8+0],c[4*8+1],0};
		for(int i=7;i>1;i--)
			c[4*8+(i+2)%8]=c[4*8+i];
		c[4*8+3]=buffer[1];
		c[4*8+2]=buffer[0];

		buffer[0]=c[0];	c[0]=c[2*8+2];	c[2*8+2]=c[5*8+4];	c[5*8+4]=c[3*8+6];	c[3*8+6]=buffer[0];
		buffer[1]=c[1];	c[1]=c[2*8+3];	c[2*8+3]=c[5*8+5];	c[5*8+5]=c[3*8+7];	c[3*8+7]=buffer[1];
		buffer[2]=c[2];	c[2]=c[2*8+4];	c[2*8+4]=c[5*8+6];	c[5*8+6]=c[3*8+0];	c[3*8+0]=buffer[2];
	
		return 0;
	}


	int d(){
		char buffer[3]={c[5*8+0],c[5*8+1],0};
		for(int i=7;i>1;i--)
			c[5*8+(i+2)%8]=c[5*8+i];
		c[5*8+3]=buffer[1];
		c[5*8+2]=buffer[0];

		buffer[0]=c[8+6];	c[8+6]=c[3*8+6];	c[3*8+6]=c[4*8+6];	c[4*8+6]=c[2*8+6];	c[2*8+6]=buffer[0];
		buffer[1]=c[8+5];	c[8+5]=c[3*8+5];	c[3*8+5]=c[4*8+5];	c[4*8+5]=c[2*8+5];	c[2*8+5]=buffer[1];
		buffer[2]=c[8+4];	c[8+4]=c[3*8+4];	c[3*8+4]=c[4*8+4];	c[4*8+4]=c[2*8+4];	c[2*8+4]=buffer[2];
		
		return 0;
	}

	void U2(){u();u();}
	void F2(){f();f();}
	void R2(){r();r();}
	void L2(){l();l();}
	void B2(){b();b();}
	void D2(){d();d();}
	void U(){U2();u();}
	void F(){F2();f();}
	void R(){R2();r();}
	void L(){L2();l();}
	void B(){B2();b();}
	void D(){D2();d();}
	
	float dist(char s[]){
		float d=0;
		for(int i=0;i<48;i++)
			d+=(c[i]-s[i])*(c[i]-s[i]);
		return sqrt(d);		
	}
	
	int fit(char s[]){
		int d=0;
		for(int i=0;i<48;i++)
			d+=(c[i]==s[i]);
		return 48-d;
	}

};
