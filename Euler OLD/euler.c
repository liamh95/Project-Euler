#include <stdio.h>
#include <math.h>
int triangle(int n){
	return n*(n+1)/2;
}

int numFactors(int n){//give odd only
	int key = n;
	int i;
	int factors=1;
	if(n==1)
		return 1;
	for(i=3; i < n/2; i+=2){   //iterate over primes(hng)
		if(key%i==0){          //if this prime divides 
			int count=1;       //number of times i divides n
			key /= i;
			while(key%i==0){
				count++;
				key /= i;
			}
			factors *= count+1;
		}
	}
	return (factors==1)?2:factors;
}

int twoFacts(int n){//how many times 2 divides it
	int key=n/2;
	int count=1;
	while(key%2==0){
		count++;
		key /= 2;
	}
	return count;
}


int main(){
	int index=1;
	int factors=0;
	int twos=1;
	int odd=1;
	int prev=1;
	while(factors<=500){
		index++;
		if((index+1)%2==0){
			twos=twoFacts(index+1);
			odd=(index+1)/pow((double)2,(double)twos);
		}
		else
			odd=index+1;
		int save=numFactors(odd);
		factors=twos*save*prev;
		prev=save;
	}
	printf("%ith triangle number, %i, has %i factors.", index, index*(index+1)/2, factors);
	return 0;
}