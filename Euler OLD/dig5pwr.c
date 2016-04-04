#include <stdio.h>
#include <math.h>
#include <limits.h>

int nPwrDigSum(int n, int pwr){
	int digits = (int)ceil( log10( (double)n ) );
	int temp = n;
	int i;
	int digSum=0;
	for(i=1; i<=digits; i++){
		digSum += pow( (double)(temp%10), pwr );
		temp /= 10;
	}
	return digSum;
}

int main(){
	int i;
	int sum=0;
	for(i=2; i<355000; i++){
		int dig = nPwrDigSum(i,5);
		printf("%i: %i\n",i, dig);
		if(dig==i)
			sum += i;
	}
	printf("%i", sum);
	return 0;
}