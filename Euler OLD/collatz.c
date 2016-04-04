#include <stdio.h>

int main(){
	int chain=1;
	int biggestChain=1;
	int biggest=1;
	int i;
	for(i=13; i<1000000; i++){
		long long int key=i;
		while(key!=1){
			key = (key%2==0) ? key/2 : 3*key+1;
			chain++;
			/*if(key<1000000 && terminations[key])
				chain+=terminations[key];*/
		}
		//terminations[i]=chain;
		if(chain>biggestChain){
			biggestChain=chain;
			biggest=i;
		}
		printf("%i makes a chain of %i \n", i, chain);
		chain=1;
	}
	printf("%i makes the biggest chain of %i.", biggest, biggestChain);
}