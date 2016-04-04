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
	double max=0.0;
	int culprit=0;

	int i;
	for(i=2; i<=1000000; i++){
		double test = nOverPhi(i);
		if(test>max){
			max=test;
			culprit=i;
		}
	}
	printf("%d produces the biggest ratio of %f", culprit, max);
}