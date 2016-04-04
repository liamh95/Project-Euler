#include <stdio.h>

int fact(int n){
	if(n<=1)
		return 1;
	else
		return n*fact(n-1);
}

int main(){
	int i;
	int sum=0;
	for(i=10; i<999999; i++){
		int s=0;
		int temp=i;
		while(temp>0){
			s += fact(temp%10);
			temp /= 10;
		}
		sum += (s==i) ? i : 0;
	}
	printf("%i",sum);
	return 0;
}