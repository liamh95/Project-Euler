#include <stdio.h>
#include <math.h>

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

int main(){
	int WOW=3;
	printf("%i: %i", WOW, isPrime(WOW));

	return 0;
}