#include <stdio.h>
#include <math.h>

int isPrime(int n){
	int i=2;
	int ret=1;
	if(n<=2)
		return 1;
	while(i<=(int)ceil(sqrt((double)n)) && ret==1){
		ret = (n%i==0) ? 0 : 1;
		i = (i==2) ? i+1: i+2;
	}
	return ret;
}

int phi(int n){
	int p=2;
	int tot=1;
	while( p<=(int)ceil(sqrt((double)n)) ){
		if(isPrime(p) && n%p==0){//p divides it
			int str=0;//how hard does p divide n
			int test=n;
			while(test%p==0){
				test /= p;
				str++;
			}
			tot *= (int)pow(p, str-1)*(p-1);
		}
		p = (p==2) ? p+1: p+2;
	}
	return (isPrime(n)) ? n-1 : tot;
}

double nOverPhi(int n){
	int p=2;
	double ret=1.0;
	while( p<=(int)ceil(sqrt((double)n)) ){
		if(isPrime(p) && n%p==0)
			ret *= (double)p / (double)(p-1);
		p = (p==2) ? p+1: p+2;
	}
	return (isPrime(n)) ? (double)n / (double)(n-1): ret;
}

int main(){
	int i;
	int j;
	for(i=1; i<=10000000;i++){
		if(i%10000==0)
			printf("%d\n", i);
		j=phi(i);
	}
}