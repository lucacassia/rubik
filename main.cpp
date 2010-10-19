#include"class.h"
using namespace std;

int main(){
	matrix *a=new matrix(9,9,9);
	a->print();
	a->gauss();
	a->print();
	cout<<endl;
	return 0;
}
