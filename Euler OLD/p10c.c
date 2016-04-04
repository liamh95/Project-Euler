#include <stdio.h>
#include <math.h>

int isPrime(int n){
	int i=2;
	int ret = 1;
	if(n<2)
		return 0;
	if(n==2)
		return 1;
	while(i<=(int)sqrt((double)n) && ret){
		ret = !(n%i==0);
		i++;
	}
	return ret;
}

int main(){
	unsigned long sum=0;
	int i;
	for(i=2; i<2000000; i++)
		sum += (isPrime(i)) ? i : 0;
	printf("%lu", sum);
	return 0;
}