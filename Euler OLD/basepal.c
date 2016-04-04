#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int b10Pal(int n){
	int temp=n;
	int digs = (int)log10((double)n)+1;
	int comp=0;
	int i;
	for(i=0; i<digs; i++){
		comp += (temp%10)*(int)pow((double)10,(double)(digs-i-1));
		temp /=10;
	}
	return (comp==n) ? 1 : 0;
}

int* toBin(int n){
	int bindigs = (int)(log(n)/log(2))+1;
	int i;
	int* ret = malloc(sizeof(int)*(bindigs+1));
	ret[0]=bindigs;
	int temp=n;
	for(i=1; i<bindigs+1; i++){
		ret[i]=temp/(int)pow((double)2, (double)(bindigs-i));
		temp -= ret[i]*(int)pow((double)2, (double)(bindigs-i));
	}
	return ret;
}

int b2Pal(int n){
	//Convert to binary
	int* bin = toBin(n);
	int i=1;
	while(i<=ceil(bin[0]/2) && (bin[i]==bin[bin[0]-i+1]))
		i++;
	return (i==ceil(bin[0]/2)+1) ? 1 : 0;
}

int main(){
	/*int test=8;
	printf("%i: %i\n", test, b2Pal(test));
	int i;
	int* bin = toBin(test);
	for(i=1; i<bin[0]+1; i++)
		printf("%i",bin[i]);*/
	int i;
	int sum=0;
	for(i=1; i<=999999; i++)
		sum += (b2Pal(i)&&b10Pal(i)) ? i : 0;
	printf("%i",sum);
	return 0;
}