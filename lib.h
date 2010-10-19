#include<string.h>
int swap(void*vp1,void*vp2,int size){
	char buffer[size];
	memcpy(buffer,vp1,size);
	memcpy(vp1,vp2,size);
	memcpy(vp2,buffer,size);
	return 0;
}
int mcd(int a,int b){
	if(a<0) a*=-1;
	if(b<0) b*=-1;
	if(!(a*b)) return a+b+!(a+b);
	if(a<b) return mcd(b%a,a);
	return mcd(a%b,b);
}
int multimcd(int*v,int k){
	if(k==2) return mcd(v[0],v[1]);
	if(k%2==0) return mcd(multimcd(v,k/2),multimcd(v+k/2,k/2));
	return mcd(v[0],multimcd(v+1,k-1));
}
void reduce(int*v,int k){
	int j,d=multimcd(v,k);
	for(j=0;j<k;j++)
		v[j]/=d;
}
void reverse(void *v,int n,int size){
	swap(v,(char*)v+(n-1)*size,size);
	reverse((char*)v+size,n-2,size);
}
