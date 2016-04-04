#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* rots(int n){
	int digs = (int)log10((double)n)+1;
	int* ret = malloc(sizeof(int)*(digs+1));
	ret[0]=digs;
	int i=0;
	//rotate digits(abcd, bcda, cdab, dabc) some shit with pwrs of 10 and mods on mods
	for(i=1; i<digs+1; i++){//each rotation
		int rot=0;
		int temp=n;
		int j;
		for(j=0; j<digs; j++){//each digit
			rot += (temp%10)*(int)pow((double)10, (double)((i+j-1)%digs));
			temp /= 10;
		}
		ret[i]=rot;
	}
	return ret;
}

int isPrime(int n){
	int i=2;
	int ret=1;
	if(n<=2)
		return 1;
	while(i<=(int)sqrt((double)n) && ret==1){
		ret = (n%i==0) ? 0 : 1;
		i++;
	}
	return ret;
}

int isCircPrime(int n){
	int *nums = rots(n);
	int ret=1;
	int i=1;
	while(i<nums[0]+1 && ret==1){
		ret = (isPrime(nums[i])) ? 1 : 0;
		i++;
	}
	return ret;
}

int main(){
	int circs=0;
	int i;
	for(i=2; i<=999983; i++)
		circs += (isCircPrime(i)) ? 1 : 0;

	printf("%i", circs);

	return 0;
}