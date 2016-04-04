#include <stdio.h>
#include <math.h>

int isPrime(int n){
	int ret=1;
	if(n<=1)
		return 0;
	int i;
	for(i=2; i<=(int)sqrt((double)n); i++){
		if(n%i == 0){
			ret=0;
			break;
		}
	}
	return ret;
}

int isPPower(int n){
	int ret=1;
	if(n<=1)
		return 0;
	int i=2;
	int found=0;
	while(found<2 && i<=(int)sqrt((double)n)){
		if(isPrime(i) && n%i==0){
			found++;
		}
	}
	if(found>=2)
		return 0;
	return 1;
}

int main(){
	int i;
	int terms=0;
	for(i=2; i<=100; i++){
		if(isPrime(i)){
			int pwr=2;
			while( (int)pow((double)i, (double)pwr)<100 ){
				terms +=
			}
		}
		//non prime pwr case
	}


	return 0;
}