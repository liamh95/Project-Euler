#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int n){
	int i=2;
	int ret=1;
	if(n<2)
		return 0;
	if(n==2)
		return 1;
	while(i<=(int)sqrt((double)n) && ret==1){
		ret = (n%i==0) ? 0 : 1;
		i++;
	}
	return ret;
}

int lTrunc(int n){//Truncation works
	int digits = (int)log10((double)n)+1;
	int* truncs = malloc(sizeof(int)*digits);
	int i;
	for(i=0; i<digits; i++)
		truncs[i]=0;
	for(i=0; i<digits; i++){
		int j;
		int temp=n;
		for(j=0; j<digits-i; j++){
			truncs[i] += (temp%10)*(int)pow(10, j);
			temp /= 10;
		}
	}
	i=0;
	while(i<digits && isPrime(truncs[i]))
		i++;
	return (i==digits) ? 1 : 0;
}

int rTrunc(int n){//Truncation works
	int digits = (int)log10((double)n)+1;
	int* truncs = malloc(sizeof(int)*digits);
	int i;
	int temp=n;
	truncs[0]=n;
	for(i=1; i<digits; i++){
		temp -= (temp%10);
		temp /= 10;
		truncs[i]=temp;
	}
	i=0;
	while(i<digits && isPrime(truncs[i]))
		i++;
	return (i==digits) ? 1 : 0;
}

int main(){
	int sum=0;
	int t=0;
	int i;
	for(i=10; i<999999; i++){
		if(isPrime(i) && lTrunc(i) && rTrunc(i)){
			sum += i;
			t++;
		}
	}	
	printf("%i, %i",sum,t);
	return 0;
}