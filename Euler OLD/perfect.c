#include <stdio.h>
int main(){
	int sum;
	int num=28;
	while(sum != num){
		sum=0;
		num++;
		int i;
		for(i=1; i<(num/2)+1; i++)
			sum += (num%i==0) ? i : 0;
	}
	printf("%i", num);
	return 0;
}