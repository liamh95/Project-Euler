#include <stdio.h>
#include <math.h>

int main(){
	double Phi = (1+sqrt(5))/2;
	double phi = Phi-1;

	double err = 999;
	double n=15;
	while(fabs(err)>1){
		n++;
		err = log10( (pow(phi,n) - pow(-1,n)/pow(phi,n) ) / sqrt(5) ) - 1000;
		printf("Trying n=%i. Err = %f\n", (int)n, err);
	}
	printf("%i", n);
	return 0;
}