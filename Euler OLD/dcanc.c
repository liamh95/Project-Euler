#include <stdio.h>

int main(){

	int numers[4];
	int denoms[4];
	int i;
	for(i=0; i<4; i++){
		numers[i]=0;
		denoms[i]=0;
	}

	int den;
	int n=0;
	int d=0;
	for(den=12; den<=99; den++){
		int num;
		for(num=11; num<=den-1; num++){
			if(den%10!=0 && num%10!=0){
				double frac=(double)num/(double)den;
				double mm=(double)(num%10)/(double)(den%10);
				double md=(double)(num%10)/(double)(den/10);
				double dm=(double)(num/10)/(double)(den%10);
				double dd=(double)(num/10)/(double)(den/10);
				if( (num/10==den/10 && frac==mm) || (num%10==den%10 && frac==dd) || (num/10==den%10 && frac==md) || (num%10==den/10 && frac==dm) ){
					numers[n]=num;
					denoms[d]=den;
					n++;
					d++;
				}
			}
		}
	}
	printf("%i / %i", numers[0]*numers[1]*numers[2]*numers[3], denoms[0]*denoms[1]*denoms[2]*denoms[3]);

	return 0;
}