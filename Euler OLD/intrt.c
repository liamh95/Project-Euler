#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
a=s^2-t^2, 
b=2st, 
c=s^2+t^2, ONLY GIBS PRIMITIVE

want a+b+c=p
max solutions to that
a+b+c = 2(s^2)+2st = 2s(s+t) = p
*/


int main(){
	int maxP=0;
	int maxSol=0;
	int p;
	for(p=12; p<=1000; p++){
		int s;
		int sols=0;
		for(s=2; s<(int)sqrt((double)p); s++){
			int t;
			for(t=1; t<s; t++){
				if(p%(2*s*(s+t))==0){
					sols++;
				}
			}
		}
		if(sols>maxSol){
			maxSol=sols;
			maxP=p;
		}
	}

	printf("%i: %i sols.", maxP, maxSol);
	return 0;
}